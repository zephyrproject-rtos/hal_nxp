#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "hostcmd-generator.h"

char *mlan_config_get_line(FILE* fp, char *str, t_s32 size, int *lineno);
t_u32 a2hex_or_atoi(t_s8 *value);

static void display_hostcmd_gen_usage(void)
{
    printf("Usage:\r\n");
    printf("\thostcmd-generator <conf_file> <cmdname>\r\n");
}

/********************************************************
		Local Functions
********************************************************/
/** 
 *  @brief get hostcmd data
 *  
 *  @param ln			A pointer to line number
 *  @param buf			A pointer to hostcmd data
 *  @param size			A pointer to the return size of hostcmd buffer
 *  @return      		MLAN_STATUS_SUCCESS
 */
static int mlan_get_hostcmd_data(FILE *fp, int *ln, t_u8 *buf, t_u16 *size)
{
    t_s32	errors = 0, i;
    t_s8	line[512], *pos, *pos1, *pos2, *pos3;
    t_u16	len;


    while ((pos = mlan_config_get_line(fp, line, sizeof(line), ln))) {
        (*ln)++;
        if (strcmp(pos, "}") == 0) {
            break;
        }

        pos1 = strchr(pos, ':');
        if (pos1 == NULL) {
            printf("Line %d: Invalid hostcmd line '%s'\n", *ln, pos);
            errors++;
            continue;
        }
        *pos1++ = '\0';

        pos2 = strchr(pos1, '=');
        if (pos2 == NULL) {
            printf("Line %d: Invalid hostcmd line '%s'\n", *ln, pos);
            errors++;
            continue;
        }
        *pos2++ = '\0';

        len = a2hex_or_atoi(pos1);
        if (len < 1 || len > MRVDRV_SIZE_OF_CMD_BUFFER) {
            printf("Line %d: Invalid hostcmd line '%s'\n", *ln, pos);
            errors++;
            continue;
        }

        *size += len;

        if (*pos2 == '"') {
            pos2++;
            pos3 = strchr(pos2, '"');
            if (pos3 == NULL) {
                printf("Line %d: invalid quotation '%s'\n", *ln, pos);
                errors++;
                continue;
            }
            *pos3 = '\0';
            memset(buf, 0, len);
            memmove(buf, pos2, MIN(strlen(pos2),len));
            buf += len;
        }
        else if (*pos2 == '\'') {
            pos2++;
            pos3 = strchr(pos2, '\'');
            if (pos3 == NULL) {
                printf("Line %d: invalid quotation '%s'\n", *ln, pos);
                errors++;
                continue;
            }
            *pos3 = ',';
            for (i=0; i<len; i++) {
                pos3 = strchr(pos2, ',');
                if (pos3 != NULL) {
                    *pos3 = '\0';
                    *buf++ = (t_u8)a2hex_or_atoi(pos2);
                    pos2 = pos3 + 1;
                }
                else
                    *buf++ = 0;
            }
        }
        else if (*pos2 == '{') {
            t_u16 tlvlen = 0, tmp_tlvlen;
            mlan_get_hostcmd_data(fp, ln, buf+len, &tlvlen);
            tmp_tlvlen = tlvlen;
            while (len--) {
                *buf++ = (t_u8)(tmp_tlvlen & 0xff);
                tmp_tlvlen >>= 8;
            }
            *size += tlvlen;
            buf += tlvlen;
        }
        else {
            t_u32 value = a2hex_or_atoi(pos2);
            while (len--) {
                *buf++ = (t_u8)(value & 0xff);
                value >>= 8;
            }
        }
    }
    return MLAN_STATUS_SUCCESS;
}


/********************************************************
		Global Functions
********************************************************/
/** 
 *  @brief convert char to hex integer
 * 
 *  @param chr 		char to convert
 *  @return      	hex integer or 0
 */
int hexval(t_s32 chr)
{
	if (chr >= '0' && chr <= '9')
		return chr - '0';
	if (chr >= 'A' && chr <= 'F')
		return chr - 'A' + 10;
	if (chr >= 'a' && chr <= 'f')
		return chr - 'a' + 10;

	return 0;
}

/** 
 *  @brief Hump hex data
 *
 *  @param prompt	A pointer prompt buffer
 *  @param p		A pointer to data buffer
 *  @param len		the len of data buffer
 *  @param delim	delim char
 *  @return            	hex integer
 */
t_void hexdump(t_s8 *prompt, t_void *p, t_s32 len, t_s8 delim)
{
	t_s32             i;
	t_u8  *s = p;
	
	if (prompt) {
		printf("%s: len=%d\n", prompt,(int)len);
	}
	for (i = 0; i < len; i++) {
		if (i != len - 1)
			printf("%02x%c", *s++, delim);
		else
			printf("%02x\n", *s);
		if((i+1)%16 == 0)
		       printf("\n");	
	}
    printf("\n");
}

/** 
 *  @brief convert char to hex integer
 *
 *  @param chr		char
 *  @return            	hex integer
 */
t_u8 hexc2bin(t_s8 chr)
{
	if (chr >= '0' && chr <= '9')
		chr -= '0';
	else if (chr >= 'A' && chr <= 'F')
		chr -= ('A' - 10);
	else if (chr >= 'a' && chr <= 'f')
		chr -= ('a' - 10);

	return chr;
}

/** 
 *  @brief convert string to hex integer
 *
 *  @param s		A pointer string buffer
 *  @return            	hex integer
 */
t_u32 a2hex(t_s8 *s)
{
	t_u32    val = 0;
	
	if (!strncasecmp("0x", s, 2)) {
		s += 2;
	}

	while (*s && isxdigit((unsigned char)*s)) {
		val = (val << 4) + hexc2bin(*s++);
	}

	return val;
}


/* 
 *  @brief convert String to integer
 *  
 *  @param value	A pointer to string
 *  @return             integer
 */
t_u32 a2hex_or_atoi(t_s8 *value)
{
	if (value[0] == '0' && (value[1] == 'X' || value[1] == 'x')) {
		return a2hex(value + 2);
    } else if (isdigit((unsigned char)*value)) {
        return atoi(value);
    } else {
        return *value;
    }
}


/** 
 *  @brief convert string to hex
 * 
 *  @param ptr		A pointer to data buffer
 *  @param chr 		A pointer to return integer
 *  @return      	A pointer to next data field
 */
t_s8 *convert2hex(t_s8 *ptr, t_u8 *chr)
{
	t_u8	val;

	for (val = 0; *ptr && isxdigit(*ptr); ptr++) {
		val = (val * 16) + hexval(*ptr);
	}

	*chr = val;

	return ptr;
}

/** 
 *  @brief Check the Hex String
 *  @param s  A pointer to the string      
 *  @return   MLAN_STATUS_SUCCESS --HexString, MLAN_STATUS_FAILURE --not HexString
 */
int ishexstring(t_s8 *s)
{
    int ret = MLAN_STATUS_FAILURE;
    t_s32 tmp;

    if (!strncasecmp("0x", s, 2)) {
        s += 2;
    }  
    while(*s) {
        tmp = toupper(*s);
        if (((tmp >= 'A') && (tmp <= 'F')) || ((tmp >= '0') && (tmp <= '9'))) {
            ret = MLAN_STATUS_SUCCESS;
        } else {
            ret = MLAN_STATUS_FAILURE;
            break;
        }       
        s++;
    }

    return ret;
}

/** 
 *  @brief Convert String to Integer
 *  @param buf      A pointer to the string      
 *  @return         Integer
 */
int atoval(t_s8 *buf)
{
    if (!strncasecmp(buf, "0x", 2))
        return a2hex(buf+2);
    else if (!ishexstring(buf))
        return a2hex(buf);
    else
        return atoi(buf);
}

#define DUMP_WRAPAROUND 16U

/** Dump buffer in hex format on console
 *
 * This function prints the received buffer in HEX format on the console
 *
 * \param[in] data Pointer to the data buffer
 * \param[in] len Length of the data
 */
static void dump_hex(const char *cmdname, const void *data, unsigned len)
{
    printf("const unsigned char %s = { ", cmdname);

    unsigned int i    = 0;
    const unsigned char *data8 = (const unsigned char *)data;
    while (i < len)
    {
	if(i == len - 1)
	{
            (void)printf("0x%02x ", data8[i++]);
	}
	else
	{
            (void)printf("0x%02x, ", data8[i++]);
	}

        if (!(i % DUMP_WRAPAROUND))
        {
            (void)printf("\n\r\t\t\t");
        }
    }

    (void)printf("};\n\r");
}

/** 
 *  @brief Get one line from the File
 *  
 *  @param fp       File handler
 *  @param str	    Storage location for data.
 *  @param size 	Maximum number of characters to read. 
 *  @param lineno	A pointer to return current line number
 *  @return         returns string or NULL 
 */
char *mlan_config_get_line(FILE* fp, char *str, t_s32 size, int *lineno)
{
    char *start, *end;
    int out, next_line;

    if (!fp || !str)
        return NULL;

    do {
read_line:
        if (!fgets(str, size, fp)) 
            break;
        start = str;
        start[size - 1] = '\0';
        end = start + strlen(str);
        (*lineno)++;

        out = 1;
        while (out && (start < end)) {
            next_line = 0;
            /* Remove empty lines and lines starting with # */
            switch (start[0]) {
                case ' ':  /* White space */
                case '\t': /* Tab */
                    start ++;
                    break;
                case '#':
                case '\n':
                case '\0':
                    next_line = 1;
                    break;
                case '\r':
                    if (start[1] == '\n')
                        next_line = 1;
                    else
                        start ++;
                    break;
                default:
                    out = 0;
                    break;
            }
            if (next_line)
                goto read_line;
        }

        /* Remove # comments unless they are within a double quoted
         * string. Remove trailing white space. */
        if ((end = strstr(start, "\""))) {
            if (!(end = strstr(end + 1, "\"")))
                end = start; 
        } else
            end = start;

        if ((end = strstr(end + 1, "#")))
            *end-- = '\0';
        else
            end = start + strlen(start) - 1;

        out = 1;
        while (out && (start < end)) {
            switch (*end) {
            case ' ':  /* White space */
            case '\t': /* Tab */
            case '\n':
            case '\r':
                *end = '\0';
                end --;
                break;
            default:
                out = 0;
                break;
            }
        }

        if (*start == '\0')
            continue;

        return start;
    } while(1);

    return NULL;
}

/** 
 *  @brief Prepare host-command buffer 
 *  @param fp		File handler
 *  @param cmd_name	Command name
 *  @param buf		A pointer to comand buffer    
 *  @return      	MLAN_STATUS_SUCCESS--success, otherwise--fail
 */
static int prepare_host_cmd_buffer(FILE* fp, char *cmd_name, t_u8 *buf)
{
	t_s8		line[256], cmdname[256], *pos, cmdcode[10];
	HostCmd_DS_GEN	*hostcmd;
	int 	ln = 0;
	int		cmdname_found = 0, cmdcode_found = 0;

	memset(buf, 0, MRVDRV_SIZE_OF_CMD_BUFFER);
	hostcmd = (HostCmd_DS_GEN*)buf;
	hostcmd->command = 0xffff;

	snprintf(cmdname, sizeof(cmdname), "%s={", cmd_name);
	cmdname_found = 0;
	while ((pos = mlan_config_get_line(fp, line, sizeof(line), &ln))) {
		if (strcmp(pos, cmdname) == 0) {
			t_u16 len = 0;
			cmdname_found = 1;
			snprintf(cmdcode, sizeof(cmdcode), "CmdCode=");
			cmdcode_found = 0;
			while ((pos = mlan_config_get_line(fp, line, sizeof(line), &ln))) {
				if (strncmp(pos, cmdcode, strlen(cmdcode)) == 0) {
					cmdcode_found = 1;
					hostcmd->command = a2hex_or_atoi(pos+strlen(cmdcode));
					hostcmd->size = S_DS_GEN;
					mlan_get_hostcmd_data(fp, &ln, buf+hostcmd->size, &len);
					hostcmd->size += len;
					break;
				}
			}
			if (!cmdcode_found) {
				fprintf(stderr, "mlanutl: CmdCode not found in conf file\n");
				return MLAN_STATUS_FAILURE;
			}
			break;
		}
	}

	if (!cmdname_found){
		fprintf(stderr, "mlanutl: cmdname '%s' is not found in conf file\n",cmd_name);
		return MLAN_STATUS_FAILURE;
	}

	hostcmd->seq_num = 0;
	hostcmd->result = 0;
	hostcmd->command = cpu_to_le16(hostcmd->command);
	hostcmd->size = cpu_to_le16(hostcmd->size);
	dump_hex(cmd_name, hostcmd, hostcmd->size);
	return MLAN_STATUS_SUCCESS;
}

int main(int argc, char* argv[])
{
    t_u8 *buffer = NULL, *raw_buf = NULL;
    //struct eth_priv_cmd *cmd = NULL;
    //struct ifreq ifr;
    FILE *fp = NULL;
    FILE *fp_raw = NULL;
    //FILE *fp_dtsi = NULL;
    char cmdname[256];
    boolean call_ioctl = TRUE;
    t_u32 buf_len = 0, i, j, k;
    char *line = NULL, *pos = NULL;
    int li = 0, blk_count = 0, ob = 0;
    int ret = MLAN_STATUS_SUCCESS;

    struct cmd_node {
        char cmd_string[256];
        struct cmd_node *next;
    };
    struct cmd_node *command = NULL, *header = NULL, *new_node = NULL;

    if (argc != 3) {
        printf("Error: Invalid no of arguments\n");
        display_hostcmd_gen_usage();
        ret = MLAN_STATUS_FAILURE;
        goto done;
    }

    snprintf(cmdname, sizeof(cmdname),"%s", argv[2]);

    if (!strcmp(cmdname, "generate_raw")) {
        call_ioctl = FALSE;
    }
    /*if (!call_ioctl && argc != 4) {
        printf("Error: invalid no of arguments\n");
        printf("Syntax: ./mlanutl mlanX hostcmd <hostcmd.conf> %s <raw_data_file>\n", cmdname);
        ret = MLAN_STATUS_FAILURE;
        goto done;
    }*/

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file %s\n", argv[1]);
        ret = MLAN_STATUS_FAILURE;
        goto done;
    }

    /* Initialize buffer */
    buffer = (t_u8 *) malloc(BUFFER_LENGTH);
    if (!buffer) {
        printf("ERR:Cannot allocate buffer for command!\n");
        fclose(fp);
        ret = MLAN_STATUS_FAILURE;
        goto done;
    }
    memset(buffer, 0, BUFFER_LENGTH);


    if (call_ioctl) {
        /* Prepare the hostcmd buffer */
        //prepare_buffer(buffer, argv[2], 0, NULL);
        if ( MLAN_STATUS_FAILURE == prepare_host_cmd_buffer(fp, cmdname, buffer)) {
            fclose(fp);
            ret = MLAN_STATUS_FAILURE;
            goto done;
        }
        fclose(fp);
    } 
#if 0    
    else
    {
        line = (char *) malloc(MAX_CONFIG_LINE);
        if (!line) {
            printf("ERR:Cannot allocate memory for line\n");
            fclose(fp);
            ret = MLAN_STATUS_FAILURE;
            goto done;
        }
        memset(line, 0, MAX_CONFIG_LINE);

        while (config_get_line(line, MAX_CONFIG_LINE, fp, &li, &pos)) {
            line = trim_spaces(line);
            if (line[strlen(line) - 1] == '{') {
                if (ob == 0) {
                    new_node = (struct cmd_node*) malloc(sizeof(struct cmd_node));
                    if (!new_node) {
                        printf("ERR:Cannot allocate memory for cmd_node\n");
                        fclose(fp);
                        ret = MLAN_STATUS_FAILURE;
                        goto done;
                    }
                    memset(new_node, 0, sizeof(struct cmd_node));
                    new_node->next = NULL;
                    if (blk_count == 0) {
                        header = new_node;
                        command = new_node;
                    } else {
                        command->next = new_node;
                        command = new_node;
                    }
                    strncpy(command->cmd_string, line, (strchr(line, '=')-line));
                    memmove(command->cmd_string, trim_spaces(command->cmd_string),
                            strlen(trim_spaces(command->cmd_string))+1);
                }
                ob++;
                continue;   /* goto while() */
            }
            if (line[strlen(line) - 1] == '}') {
                ob--;
                if (ob == 0)
                    blk_count++;
                continue;   /* goto while() */
            }
        }

        rewind(fp);         /* Set the source file pointer to the beginning again */
        command = header;   /* Set 'command' at the beginning of the command list */

        fp_raw = fopen(argv[5], "w");
        if (fp_raw == NULL) {
            fprintf(stderr, "Cannot open the destination raw_data file %s\n", argv[5]);
            fclose(fp);
            ret = MLAN_STATUS_FAILURE;
            goto done;
        }

        /* prepare .dtsi output */
        snprintf(cmdname, sizeof(cmdname), "%s.dtsi", argv[5]);
        fp_dtsi = fopen(cmdname, "w");
        if (fp_dtsi == NULL) {
            fprintf(stderr, "Cannot open the destination file %s\n", cmdname);
            fclose(fp);
            fclose(fp_raw);
            ret = MLAN_STATUS_FAILURE;
            goto done;
        }

        for (k = 0; k < (t_u32)blk_count && command != NULL; k++) {
            if (MLAN_STATUS_FAILURE == prepare_host_cmd_buffer(fp, command->cmd_string, buffer))
                memset(buffer, 0, BUFFER_LENGTH);

            memcpy(&buf_len, buffer, sizeof(t_u32));
            if (buf_len) {
                raw_buf = buffer + sizeof(t_u32);   /* raw_buf points to start of actual <raw data> */
                printf("buf_len = %d\n", (int)buf_len);
                if (k > 0)
                    fprintf(fp_raw, "\n\n");
                fprintf(fp_raw, "%s={\n", command->cmd_string);
                fprintf(fp_dtsi, "/ {\n\tmarvell_cfgdata {\n\t\tmarvell,%s = /bits/ 8 <\n", command->cmd_string);
                i = j = 0;
                while (i < buf_len) {
                    for (j = 0; j < 16; j++){
                        fprintf(fp_raw, "%02x ", *(raw_buf + i));
                        if (i >= 8) {
                            fprintf(fp_dtsi, "0x%02x", *(raw_buf + i));
                            if ((j < 16 - 1) && (i < buf_len - 1))
                                fprintf(fp_dtsi, " ");
                        }
                        if (++i >= buf_len)
                            break;
                    }
                    fputc('\n', fp_raw);
                    fputc('\n', fp_dtsi);
                }
                fprintf(fp_raw, "}");
                fprintf(fp_dtsi, "\t\t>;\n\t};\n};\n");
            }
            command = command->next;
            rewind(fp);
        }

        fclose(fp_dtsi);
        fclose(fp_raw);
        fclose(fp);
    }

    if (call_ioctl) {
#ifdef MLANUTL_LITE
        /* raw_buf points to start of command id */
        raw_buf = buffer + strlen(CMD_NXP) + strlen(argv[2])+ sizeof(t_u32);
        if (check_if_hostcmd_allowed(raw_buf) != MLAN_STATUS_SUCCESS) {
            printf("ERR:Entered hostcmd not allowed!\n");
            goto done;
        }
#endif
        cmd = (struct eth_priv_cmd *) malloc(sizeof(struct eth_priv_cmd));
        if (!cmd) {
            printf("ERR:Cannot allocate buffer for command!\n");
            ret = MLAN_STATUS_FAILURE;
            goto done;
        }

        /* Fill up buffer */
#ifdef USERSPACE_32BIT_OVER_KERNEL_64BIT
        memset(cmd, 0, sizeof(struct eth_priv_cmd));
        memcpy(&cmd->buf, &buffer, sizeof(buffer));
#else
        cmd->buf = buffer;
#endif
        cmd->used_len = 0;
        cmd->total_len = BUFFER_LENGTH;

        /* Perform IOCTL */
        memset(&ifr, 0, sizeof(struct ifreq));
        strncpy(ifr.ifr_ifrn.ifrn_name, dev_name, strlen(dev_name));
        ifr.ifr_ifru.ifru_data = (void *) cmd;

        if (ioctl(sockfd, MLAN_ETH_PRIV, &ifr)) {
            perror("mlanutl");
            fprintf(stderr, "mlanutl: hostcmd fail\n");
            ret = MLAN_STATUS_FAILURE;
            goto done;
        }

        /* Process result */
        process_host_cmd_resp(argv[2], buffer);
    }
#endif

done:
    while (header) {
        command = header;
        header = header->next;
        free(command);
    }
    if (line)
        free(line);
    if (buffer)
        free(buffer);
    //if (cmd)
    //    free(cmd);
    return 0;
}

