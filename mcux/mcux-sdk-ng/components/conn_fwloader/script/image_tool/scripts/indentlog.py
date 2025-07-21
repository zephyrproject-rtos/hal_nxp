#/*
# * Copyright 2024 NXP
# * 
# * SPDX-License-Identifier: BSD-3-Clause
# * The BSD-3-Clause license can be found at https://spdx.org/licenses/BSD-3-Clause.html
# */

import logging
import textwrap


class IndentLoggerAdapter(logging.LoggerAdapter):
    indent_string = '   '
    def __init__(self, logger):
        super().__init__(logger, {'indent_stack': [""]})

    def process(self, msg, kwargs):
        return textwrap.indent(msg, self.get_indent()), kwargs

    def indent(self):
        self.push(IndentLoggerAdapter.indent_string + self.get_indent())

    def unindent(self):
        self.pop()

    def get_indent(self):
        return self.extra['indent_stack'][-1]

    def push(self, indent):
        self.extra['indent_stack'].append(indent)

    def pop(self):
        return self.extra['indent_stack'].pop()


