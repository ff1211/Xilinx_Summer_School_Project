# ==============================================================
# File generated on Sat Aug 01 23:35:11 +0800 2020
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
# SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
# IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
# Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
# ==============================================================
CSIM_DESIGN = 1

__SIM_FPO__ = 1

__SIM_MATHHLS__ = 1

__SIM_OPENCV__ = 1

__SIM_FFT__ = 1

__SIM_FIR__ = 1

__SIM_DDS__ = 1

ObjDir = obj

HLS_SOURCES = ../../../src/qrc_decoder_test.c ../../../src/bch.c ../../../src/blocks.c ../../../src/data.c ../../../src/modules.c ../../../src/pbm.c ../../../src/qrc_decoder.c ../../../src/rs.c

TARGET := csim.exe

AUTOPILOT_ROOT := C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3
AUTOPILOT_MACH := win64
ifdef AP_GCC_M32
  AUTOPILOT_MACH := Linux_x86
  IFLAG += -m32
endif
ifndef AP_GCC_PATH
  AP_GCC_PATH := C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/msys64/mingw64/bin
endif
AUTOPILOT_TOOL := ${AUTOPILOT_ROOT}/${AUTOPILOT_MACH}/tools
AP_CLANG_PATH := ${AUTOPILOT_ROOT}/msys64/mingw64/bin
AUTOPILOT_TECH := ${AUTOPILOT_ROOT}/common/technology


IFLAG += -I "${AUTOPILOT_TOOL}/systemc/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include"
IFLAG += -I "${AUTOPILOT_ROOT}/include/opencv"
IFLAG += -I "${AUTOPILOT_ROOT}/include/ap_sysc"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_FP_comp"
IFLAG += -I "${AUTOPILOT_TECH}/generic/SystemC/AESL_comp"
IFLAG += -I "${AUTOPILOT_TOOL}/auto_cc/include"
IFLAG += -D__SIM_FPO__

IFLAG += -D__SIM_OPENCV__

IFLAG += -D__SIM_FFT__

IFLAG += -D__SIM_FIR__

IFLAG += -D__SIM_DDS__

IFLAG += -D__DSP48E1__
IFLAG += -g
IFLAG += -DNT
LFLAG += -Wl,--enable-auto-import 
DFLAG += -DAUTOCC
DFLAG += -D__xilinx_ip_top= -DAESL_TB
CCFLAG += 
TOOLCHAIN += 



include ./Makefile.rules

all: $(TARGET)



AUTOCC := cmd //c apcc.bat  

$(ObjDir)/qrc_decoder_test.o: ../../../src/qrc_decoder_test.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../src/qrc_decoder_test.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/qrc_decoder_test.d

$(ObjDir)/bch.o: ../../../src/bch.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../src/bch.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/bch.d

$(ObjDir)/blocks.o: ../../../src/blocks.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../src/blocks.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/blocks.d

$(ObjDir)/data.o: ../../../src/data.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../src/data.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/data.d

$(ObjDir)/modules.o: ../../../src/modules.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../src/modules.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/modules.d

$(ObjDir)/pbm.o: ../../../src/pbm.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../src/pbm.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/pbm.d

$(ObjDir)/qrc_decoder.o: ../../../src/qrc_decoder.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../src/qrc_decoder.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/qrc_decoder.d

$(ObjDir)/rs.o: ../../../src/rs.c $(ObjDir)/.dir
	$(Echo) "   Compiling(apcc) ../../../src/rs.c in $(BuildMode) mode" $(AVE_DIR_DLOG)
	$(Verb)  $(AUTOCC) -c -MMD  $(IFLAG) $(DFLAG) $< -o $@ ; \

-include $(ObjDir)/rs.d
