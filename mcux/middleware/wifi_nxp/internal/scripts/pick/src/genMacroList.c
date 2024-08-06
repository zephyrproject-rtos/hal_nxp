/*
 * File : genMacroList.c
 *
 * This program generates the list of macros that are listed
 * in <AllMacrosFileName> but not in <RelMacrosFileName>.
 *
 * In conjunction with 'grepMacros' tool, this program can be used
 * for generating the list of macros that are not defined for a
 * particular release. 
 *
 * BUILD:
 *         cc -o genMacroList genMacroList.c
 *
 * INPUT:
 * This program takes two filenames as command-line parameters.
 * Both these files are assumed to contain a list of macro names.
 * Each macro appears on a separate line.
 *
 * OUTPUT:
 * This program produces the list of macros that appear in 
 * <AllMacrosFileName> but not in <RelMacrosFileName>. The list
 * is printed on standard output.
 *
 * Please see 'scrubRelFiles' script for correct usage of this program.
 */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

//#define APP_DEBUG

#ifdef APP_DEBUG
#define dbg_printf   printf
#else
#define dbg_printf
#endif

#define MAX_MACRO_LENGTH   128
#define MAX_NUM_MACROS     512

char  gAllMacroDataBase[MAX_NUM_MACROS][MAX_MACRO_LENGTH];
int   gNumAllMacros = 0;
char  gRelMacroDataBase[MAX_NUM_MACROS][MAX_MACRO_LENGTH];
int   gNumRelMacros = 0;

int isMember(char * mName, char macroDb[][MAX_MACRO_LENGTH], int numMacros)
{
    int i;

    for (i=0; i<numMacros; i++)
    {
        if (!strcmp(mName, macroDb[i]))
            return 1;
    }
    return 0;
}

int addMacro(char * mName, char macroDb[][MAX_MACRO_LENGTH], int * pNumMacros)
{
    if (*pNumMacros == MAX_NUM_MACROS)
        return -1;

    strncpy(macroDb[*pNumMacros], mName, MAX_MACRO_LENGTH - 1);
    macroDb[*pNumMacros][MAX_MACRO_LENGTH - 1] = 0;
    (*pNumMacros) ++;

    return 0;
}

void printUsage(char * exeName)
{
    printf("\n");
    printf("Usage : %s  -a <AllMacrosFileName> -r <RelMacrosFileName>\n");
    printf("    <AllMacrosFileName>  : File containing all macros defined in this tree\n");
    printf("    <RelMacrosFileName>  : File containing macros needed for the release \n");

}


int main(int argc, char * argv[])
{
    int      i;
    int      getOptRet;
    int      gotOpts = 0;
    char     inputLine[512];
    char  *  endPtr;
    FILE  *  allFp = NULL;
    FILE  *  relFp = NULL;

    while ((getOptRet = getopt(argc, argv, "a:r:")) != -1)
    {
        switch (getOptRet)
        {
        case 'a':
            allFp = fopen(optarg, "r");
            if (allFp == NULL)
            {
                printf("\nCannot Open File %s\n", optarg);
                printUsage(argv[0]);
                exit(1);
            }
            gotOpts |= 1;
            break;
        case 'r':
            relFp = fopen(optarg, "r");
            if (relFp == NULL)
            {
                printf("\nCannot Open File %s\n", optarg);
                printUsage(argv[0]);
                exit(1);
            }
            gotOpts |= 2;
            break;
        default:
	    printUsage(argv[0]);
            exit(1);
        }
    }
    if (gotOpts != 3)
    {
        printf("\nInsufficient arguments\n");
        printUsage(argv[0]);
        exit(1);
    }

    // collect all macros from <RelMacrosFileName> file into rel-macros database
    while (fgets(inputLine, sizeof(inputLine), relFp) != NULL)
    {
        if (!isMember(inputLine, gRelMacroDataBase, gNumRelMacros))
        {
            addMacro(inputLine, gRelMacroDataBase, &gNumRelMacros);
        }
    }

    // collect all macros from <AllMacrosFileName> file into all-macros database
    while (fgets(inputLine, sizeof(inputLine), allFp) != NULL)
    {
        if (!isMember(inputLine, gAllMacroDataBase, gNumAllMacros))
        {
            addMacro(inputLine, gAllMacroDataBase, &gNumAllMacros);
        }
    }

    // print those macros from all-macros database that are not in the rel-macros database.
    for (i=0; i<gNumAllMacros; i++)
    {
        if (!isMember(gAllMacroDataBase[i], gRelMacroDataBase, gNumRelMacros))
        {
            // remove trailing newlines if any.

            // first clear all trailing white-space
            endPtr = & (gAllMacroDataBase[i] [strlen(gAllMacroDataBase[i]) - 1 ]);
            while (isspace(*endPtr))
                endPtr--;
            // now append a space and null-terminate
            *(endPtr +1) = ' ';
            *(endPtr +2) = 0;

            printf("%s", gAllMacroDataBase[i]);
        }
    }

    fclose(allFp);
    fclose(relFp);

}

