############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project qrc_decoder
set_top qrc_decoder
add_files qrc_decoder/src/bch.c
add_files qrc_decoder/src/blocks.c
add_files qrc_decoder/src/data.c
add_files qrc_decoder/src/modules.c
add_files qrc_decoder/src/pbm.c
add_files qrc_decoder/src/qrc_decoder.c
add_files qrc_decoder/src/rs.c
add_files -tb qrc_decoder/src/qrc_decoder_test.c
open_solution "solution1"
set_part {xc7z020clg400-1} -tool vivado
create_clock -period 10 -name default
#source "./qrc_decoder/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
