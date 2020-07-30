// ==============================================================
// File generated on Mon Mar 30 11:11:57 +0800 2020
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xov5640_otsu_threshold.h"

extern XOv5640_otsu_threshold_Config XOv5640_otsu_threshold_ConfigTable[];

XOv5640_otsu_threshold_Config *XOv5640_otsu_threshold_LookupConfig(u16 DeviceId) {
	XOv5640_otsu_threshold_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XOV5640_OTSU_THRESHOLD_NUM_INSTANCES; Index++) {
		if (XOv5640_otsu_threshold_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XOv5640_otsu_threshold_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XOv5640_otsu_threshold_Initialize(XOv5640_otsu_threshold *InstancePtr, u16 DeviceId) {
	XOv5640_otsu_threshold_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XOv5640_otsu_threshold_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XOv5640_otsu_threshold_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

