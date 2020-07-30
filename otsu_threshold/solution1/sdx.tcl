# ==============================================================
# File generated on Mon Mar 30 11:12:01 +0800 2020
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
# SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
# IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
# Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
# ==============================================================
add_files -tb ../src/lena.jpg -cflags { -Wno-unknown-pragmas}
add_files -tb ../src/otsu_threshold_tb.cpp -cflags { -Wno-unknown-pragmas}
add_files otsu_threshold/src/otsu_threshold.h
add_files otsu_threshold/src/otsu_threshold.cpp
set_part xc7z020clg400-2
create_clock -name default -period 10
config_export -format=ip_catalog
config_export -rtl=verilog
