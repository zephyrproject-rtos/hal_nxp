#!/usr/bin/env ruby
#
# Copyright 2015,2016, Freescale Semiconductor, Inc.
# Copyright 2017,2020 NXP
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
# o Neither the name of the copyright holder nor the names of its
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
require 'benchmark'
require 'thread'

Encoding.default_internal = Encoding::UTF_8
Encoding.default_external = Encoding::UTF_8

# script check:
# - non-printable characters at the end of line
# - End of line (single empty line) at end of file
# - Unify lineendings through the file
# - Remove trailing whitespaces

# using:
# base-format.rb file_name.c
# text | ruby base-format.rb"
# Defined file will be rewritten by fixed version of file, but only in case of differences.


Verbose = false
content = ""
file = nil



if (ARGV[0])

    file = ARGV[0]
    if (!file)
        print "Filename argument was not specified\n"
        exit 3
    elsif (File.exists?(file))
        content = File.open(file,"rb").read
    else
        print "File not found: #{file}\n"
        exit 2
    end
else
    content=STDIN.read
end

lineend="\r\n"

# Getting endline info is based of most used lineending form
crlf = content.scan(/\r\n/).count
lf = content.scan(/\n/).count
# cr = content.scan(/\r/).count

if (crlf>=lf) # windows
    lineend="\r\n"
    print "The choosen line endings is: CRLF (WIN)\n" if Verbose
elsif (lf>crlf) # linux
    lineend="\n"
    print "The choosen line endings is: LF (LIN/MAC)\n" if Verbose
# elsif (cr>=lf && cr>=crlf) # mac
#     lineend="\r"
#     print "The choosen line endings is: CR (MAC)\n" if Verbose
end

new_content = ""

content.split(/\r\n|\r|\n/).each do | act_line |
    new_content += act_line.rstrip+lineend
end

new_content = new_content.rstrip + lineend

# rewrite file, in case that contains differences
if (file != nil && !content.eql?(new_content))
    print "Rewriting file\n" if Verbose
    File.open(file, 'wb+') { |f| f.write(new_content) }
    exit 1
elsif (file == nil)
    print new_content
end
exit 0