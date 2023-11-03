#
# Copyright 2021 Sendrato B.V. - https://sendrato.com
# All rights reserved.
#

zephyr_include_directories(.)

zephyr_library_sources(board.c)
zephyr_library_sources(board_utility.c)

zephyr_library_sources(mcux_zephyr.c)
