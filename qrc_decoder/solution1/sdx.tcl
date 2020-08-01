# ==============================================================
# File generated on Sat Aug 01 23:36:35 +0800 2020
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
# SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
# IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
# Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
# ==============================================================
add_files -tb ../src/qrc_decoder_test.c -cflags { -Wno-unknown-pragmas}
add_files qrc_decoder/src/rs.c
add_files qrc_decoder/src/qrc_decoder.c
add_files qrc_decoder/src/pbm.c
add_files qrc_decoder/src/modules.c
add_files qrc_decoder/src/data.c
add_files qrc_decoder/src/blocks.c
add_files qrc_decoder/src/bch.c
set_part xc7z020clg400-1
create_clock -name default -period 10
