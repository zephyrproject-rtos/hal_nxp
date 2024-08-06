#!/usr/bin/env ruby
#
# Copyright 2015,2016, Freescale Semiconductor, Inc.
# Copyright 2018,2020 NXP
# 
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:
# 
# o Redistributions of source code must retain the above copyright notice, this list
#   of conditions and the following disclaimer.
#
# o Redistributions in binary form must reproduce the above copyright notice, this
#   list of conditions and the following disclaimer in the documentation and/or
#   other materials provided with the distribution.
# 
# o Neither the name of the copyright holder, Inc. nor the names of its
#   contributors may be used to endorse or promote products derived from this
#   software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
# ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
# 
require 'fileutils'

STDOUT.sync = true
STDERR.sync = true

Encoding.default_internal = Encoding::UTF_8
Encoding.default_external = Encoding::UTF_8

def set_lineend(input)

    #if (RUBY_PLATFORM =~ /mswin|mingw|cygwin/) # windows
    #    input.gsub!(/\n/,"\r\n") unless input =~ /\r\n/
    #elsif (RUBY_PLATFORM =~ /linux|unix|darwin|mac os/) # linux/mac
    #    input.gsub!(/\r\n/,"\n")
    #end

    input.gsub!(/\r\n/,"\n")
    return input

end

Applicable_formats_clang = [".c", ".h", ".cpp", ".hpp"]
Applicable_formats_eol   = (Applicable_formats_clang | [".yml"])
Clang_version = "10.0.0"
Clang_format = "clang-format-10"
Ignore_list_path = "internal/scripts/clang/.clang-ignore"
Test = false
Verbose = false
# Prevent of formatting files
Debug = false
$number_cores = 4

if (ENV && ENV['NUMBER_OF_PROCESSORS'])
    $number_cores = ENV['NUMBER_OF_PROCESSORS'].to_i
end

puts "Using cores: #{$number_cores}" if Verbose==true

file = __FILE__
folder = File.dirname(__FILE__)


$Eol_format = "ruby #{folder}/base-format.rb"

print "$Eol_format: #{$Eol_format}\n" if Verbose


# search closest ignore file from deepest location to the cwd
def find_ignore_file(act_path)
    act_cwd = "#{Dir.pwd}"

#     bottom_limit = act_cwd.length+1
    bottom_limit = 0

#     act_path = "#{act_cwd}/#{act_path}"

    print "act_path: #{act_path}\n" if (Verbose)
    print "relative to repo root: #{act_path[bottom_limit..-1]}\n" if (Verbose)

    addr_parts = act_path[bottom_limit..-1].split("/")

    if (File.file?(act_path))
        addr_parts.delete_at(addr_parts.length-1)
    end

    limit_from = addr_parts.length
    (0..limit_from).reverse_each do | i |
       addr_parts.delete_at(i)
       print "addr_parts: #{addr_parts}\n" if (Verbose)
       new_path = "#{addr_parts.join("/")}/#{Ignore_list_path}" if addr_parts.length > 0

       new_path = "#{act_cwd}/#{Ignore_list_path}" if addr_parts.length == 0

       print "clang-ignore search: #{new_path}\n" if (Verbose)

        if File.file?(new_path)

           puts "Found ignorelist at #{new_path}" if (Verbose)
           return File.read(new_path)
       end

       # prevent of searching out of the master repo root
       break if (addr_parts.join("/") == act_cwd)

    end
    return 1

end


def ignore_file(file_path,ct=-1,total=-1)
#        puts "file_path: #{file_path}"
    act_ignore_list = find_ignore_file(file_path)
    return false if act_ignore_list == 1

    act_ignore_list.split("\n").each do |act_item|
        act_item.strip!
        next unless act_item.length > 0
        if ( file_path =~ /#{act_item}/ )
            if (ct>0 && total>0)
                puts "[#{ct}/#{total}][IGNORING] " + file_path if Verbose==true
            else
                puts "[IGNORING] " + file_path if Verbose==true
            end
            return true
        end
    end
    return false
end

def format_files_to_commit(dir = nil, master_repo_dir = "")
    ct_files_done = 0
    tot_ct_files_done = 0

    tot_ct_files_ignored_clang = 0
    tot_ct_files_formated_clang = 0
    tot_ct_files_already_formated_clang = 0
    tot_ct_files_formated_base = 0
    tot_ct_files_already_formated_base = 0


    puts "Scanning files..."
    files_modified = []
    if (dir == nil)

        puts "analysing git repository: #{Dir.pwd}#{master_repo_dir}..." if Verbose
        files_modified = `cd #{Dir.pwd}#{master_repo_dir} && git diff-index --cached --name-only HEAD`.split("\n")

    else

        if (File.file?(dir))
            # file mode
            files_modified.push(dir)
        elsif (File.directory?(dir))
            # folder mode
            files_modified = Dir.glob("#{dir}/**/*")
        end

    end

    # Total files/folders
    puts "Total files/folders: #{files_modified.length}"
    puts "Filtering files ..."

    # Array to queue
    files_modified_temp_q = Queue.new
    files_modified.each do | file_path |

        files_modified_temp_q.push(file_path)

    end

    # Remove files which should be ignored and files that are unsupported
    mutex = Mutex.new
    files_modified_q = Queue.new
    threads = (0...$number_cores).map do
        Thread.new do
            begin

                while file_path = files_modified_temp_q.pop(true)

                    next if file_path.size == 0
                    next unless (Applicable_formats_clang|Applicable_formats_eol).include? File.extname(file_path)

                    file_path = "#{master_repo_dir}/#{file_path}" if master_repo_dir!=""

                    next if !File.exist?("#{Dir.pwd}#{file_path}") && master_repo_dir != ""
                    next if !File.exist?("#{file_path}") && master_repo_dir == ""

                    # check if actual file is on the list of ignored files
                    next if ignore_file(file_path)

                    file_path = "#{Dir.pwd}/#{file_path}" if (master_repo_dir != "" || (master_repo_dir == "" && dir == nil))

                    # avoid checking of slashes at the beginning and end of given paths, force to clean double slashes
                    file_path = file_path.gsub("//","/")
                    mutex.synchronize do
                        files_modified_q.push(file_path)
                    end

                end

            rescue ThreadError
            end
        end
    end
    threads.map(&:join)




    progress_files = files_modified_q.length
    progress_files_done = 0

    modified_supported_files = files_modified_q.length
    puts "#{files_modified_q.length} file(s) will be checked"


    threads = (0...$number_cores).map do
        Thread.new do
            begin
                ct_files_done = 0

                while file_path = files_modified_q.pop(true)


                    bck_ct_files_done = ct_files_done

                    if (Applicable_formats_clang.include?(File.extname(file_path)))
                        begin
                            # run clang-format, get result into string and compare with original file

                            original_code = File.read(file_path)

                            File.open("#{file_path}.original_helper", 'wb+') { |f| f.write(original_code) } if Test

                            original_code.gsub!(/\r\n/,"\n")
                            original_code.gsub!(/\r/,"\n")
                            File.open("#{file_path}.original_lf_helper", 'wb+') { |f| f.write(original_code) }

                            command_dry_run = Clang_format+" \"" + file_path + ".original_lf_helper\""
    #                         original_code = File.read(file_path)
                            formated_code = `#{command_dry_run}`


                            File.open("#{file_path}.formated_code_helper", 'wb+') { |f| f.write(formated_code) } if Test


                            if (!formated_code.eql?(original_code))
                                # update file by clang-format
                                command_update = Clang_format+" -i \"" + file_path + ".original_lf_helper\""

                                `#{command_update}` if Debug == false

                                # second check, if formatter produce the same output as already formatted file or different.
                                # Different means that clang cannot format the file

                                formated_code2 = `#{command_dry_run}`
                                File.open("#{file_path}.formated2_code_helper", 'wb+') { |f| f.write(formated_code2) } if Test
                                if (!formated_code.eql?(formated_code2))
                                    # every formating produces modification, unformatable file
                                    print "[IGNORING][clang] Unformatable file #{file_path}\n"

                                    mutex.synchronize do
                                        tot_ct_files_ignored_clang += 1
                                    end

                                else
                                    # first formating was enough, so formatter does the job
                                    print "[FORMATTED][clang] #{file_path}\n"

                                    # ToDo rescue cycle to avoid crashing due file is locked by another process

                                    file = File.open("#{file_path}.original_lf_helper", "rb")
                                    retback_contents = file.read
                                    file.close

                                    File.open("#{file_path}", 'wb+') { |f| f.write(set_lineend(retback_contents)) }

                                    ct_files_done+=1
                                    mutex.synchronize do
                                        tot_ct_files_formated_clang += 1
                                    end
                                end

                            else
                                mutex.synchronize do
                                    tot_ct_files_already_formated_clang += 1
                                end
                            end
                            File.delete("#{file_path}.original_lf_helper") if (!Test && File.file?("#{file_path}.original_lf_helper")) unless Test
                        rescue Exception => e
                            print "[IGNORING][clang] Exception occured during formatting file #{file_path}\n"
                            File.delete("#{file_path}.original_lf_helper") if (!Test && File.file?("#{file_path}.original_lf_helper")) unless Test
                            mutex.synchronize do
                                tot_ct_files_ignored_clang += 1
                            end
                        end
                    end

                    mutex.synchronize do
                        print "Formatting files - #{progress_files_done}/#{progress_files} #{((progress_files_done/(progress_files*1.0))*100).round(1)}%\r"
                    end

                    if (Applicable_formats_eol.include?(File.extname(file_path)))

                        # update file by base-format

                        command_update = $Eol_format+" \"" + file_path + "\""

                        `#{command_update}`

                        if ($?.exitstatus!=0)
                            print "[FORMATTED][base-formater] #{file_path}\n"
                            ct_files_done+=1
                            mutex.synchronize do
                                tot_ct_files_formated_base += 1
                            end
                        else
                            mutex.synchronize do
                                tot_ct_files_already_formated_base += 1
                            end
                        end

                    end

                    mutex.synchronize do
                        progress_files_done += 1
                        print "Formatting files - #{progress_files_done}/#{progress_files} #{((progress_files_done/(progress_files*1.0))*100).round(1)}%\r"
                    end

                    # even more than one formatting or basically update of file can occure, only one change will be logged for a summary message
                    if (bck_ct_files_done != ct_files_done)
                        mutex.synchronize do
                            tot_ct_files_done += 1
                        end
                    end

                end
            rescue ThreadError
            end
        end
    end
    threads.map(&:join)

    if (tot_ct_files_done == 0)
        print "Checking files (#{progress_files}) done                     \n"
    else
        print "Formatting files (#{progress_files}) done                     \n"
    end


    if (files_modified.length == 0)
        print "\nNothing to do, there is no modified file\n"
    elsif (modified_supported_files == 0)
        print "\nNothing to do, there is no supported modified file\n"
    elsif (tot_ct_files_done == 0)
        print "\nNothing to do, all files are well formatted\n"
    end
end


def check_configuration

    ### clang-format version
    command = Clang_format + " --version 2>&1"
    puts "Executing command: " + command if (Verbose)
    local_clang_version = `#{command}`
    if (
        local_clang_version["is not recognized"] || # Windows
        local_clang_version["not found"] # Linux (: not found) and mac (: command not found)
        )

        print "\n\n"
        print ":::::::::::::::::::::::::::::::::::::::\n"
        print "::                                   ::\n"
        print "::     C O M M I T   D E N I E D     ::\n"
        print "::                                   ::\n"
        print "::          N O   C L A N G          ::\n"
        print "::                                   ::\n"
        print "::         I N S T A L L E D         ::\n"
        print "::                                   ::\n"
        print ":::::::::::::::::::::::::::::::::::::::\n"
        print "\n\n"
        print "Please follow steps on wiki page and install clang first\n"
        print "\nWiki link: https://confluence.sw.nxp.com/display/MCUXSDK/Clang+pre-commit+hook\n"

        return 1
    end


    unless local_clang_version.include? Clang_version then
        puts "Local clang version: " + local_clang_version if (Verbose)
        print "System configuration check failed:"
        print "\nYou have " + local_clang_version
        print "The only supported clang-format version is " + Clang_version + "."
        print "\nUse correct 'clang-format' version or add file to ignore list (.clang-ignore).\n"
        return 1
    end

    return 0
end


# Current position
cwd = Dir.pwd



def endwait
    if (!ARGV.include?("nopause"))
        puts("complete, press enter to end")
        $stdin.gets
    end
end

# There are only two arguments allowed. If argument is defined and is different of
# nopause, then directory is defined
act_dir_file = nil
master_repo_dir = ""

argvl = ARGV.length

ARGV.each do | act_arg |

    if (act_arg != "nopause")

        if (act_arg =~ /^DIR=.*$/)
            master_repo_dir = act_arg[4..-1]
            puts "Repository dir used: #{master_repo_dir}" if (Verbose)
        else
            act_dir_file = act_arg
            puts "Directory/file defined: #{act_dir_file}" if (Verbose)
        end
    end
end

# make path absolute
if (act_dir_file != nil && master_repo_dir!="" && !act_dir_file[master_repo_dir])
    act_dir_file = "#{master_repo_dir}/#{act_dir_file}"
end

if (act_dir_file != nil && !act_dir_file[cwd])
    act_dir_file = "#{cwd}/#{act_dir_file}"
    # avoid checking of slashes at the beginning and end of given paths, force to clean double slashes
    act_dir_file = act_dir_file.gsub("//","/")
end

if (act_dir_file != nil && !File.directory?(act_dir_file) && !File.file?(act_dir_file))
    print "File or directory does not exist\n"
    exit 2
end

ret_check = check_configuration
exit 1 if (ret_check == 1)

# clear master repo var to prevent double prepending. This relative diff is already part of cwd, no more required
master_repo_dir = "" if (act_dir_file != nil)

puts "act_dir_file: #{act_dir_file}" if (Verbose)
puts "master_repo_dir: #{master_repo_dir}" if (Verbose)
format_files_to_commit(act_dir_file, master_repo_dir)
endwait()
