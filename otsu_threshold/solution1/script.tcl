############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project otsu_threshold
set_top ov5640_otsu_threshold
add_files otsu_threshold/src/otsu_threshold.h
add_files otsu_threshold/src/otsu_threshold.cpp
add_files -tb otsu_threshold/src/lena.jpg -cflags "-Wno-unknown-pragmas"
add_files -tb otsu_threshold/src/otsu_threshold_tb.cpp -cflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7z020clg400-2} -tool vivado
create_clock -period 10 -name default
config_export -format ip_catalog -rtl verilog
#source "./otsu_threshold/solution1/directives.tcl"
csim_design -clean -O
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog
