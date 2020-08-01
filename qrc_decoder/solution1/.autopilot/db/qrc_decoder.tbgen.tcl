set moduleName qrc_decoder
set isTaskLevelControl 1
set isCombinational 1
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {qrc_decoder}
set C_modelType { void 0 }
set C_modelArgList {
	{ pdata int 8 unused {array 441 { } 0 1 }  }
	{ dataout uint 8 unused  }
}
set C_modelArgMapList {[ 
	{ "Name" : "pdata", "interface" : "memory", "bitwidth" : 8, "direction" : "NONE", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "pdata","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 440,"step" : 1}]}]}]} , 
 	{ "Name" : "dataout", "interface" : "wire", "bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "dataout","cData": "unsigned char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} ]}
# RTL Port declarations: 
set portNum 15
set portList { 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ pdata_address0 sc_out sc_lv 9 signal 0 } 
	{ pdata_ce0 sc_out sc_logic 1 signal 0 } 
	{ pdata_we0 sc_out sc_logic 1 signal 0 } 
	{ pdata_d0 sc_out sc_lv 8 signal 0 } 
	{ pdata_q0 sc_in sc_lv 8 signal 0 } 
	{ pdata_address1 sc_out sc_lv 9 signal 0 } 
	{ pdata_ce1 sc_out sc_logic 1 signal 0 } 
	{ pdata_we1 sc_out sc_logic 1 signal 0 } 
	{ pdata_d1 sc_out sc_lv 8 signal 0 } 
	{ pdata_q1 sc_in sc_lv 8 signal 0 } 
	{ dataout sc_in sc_lv 8 signal 1 } 
}
set NewPortList {[ 
	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "pdata_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "pdata", "role": "address0" }} , 
 	{ "name": "pdata_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pdata", "role": "ce0" }} , 
 	{ "name": "pdata_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pdata", "role": "we0" }} , 
 	{ "name": "pdata_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pdata", "role": "d0" }} , 
 	{ "name": "pdata_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pdata", "role": "q0" }} , 
 	{ "name": "pdata_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "pdata", "role": "address1" }} , 
 	{ "name": "pdata_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pdata", "role": "ce1" }} , 
 	{ "name": "pdata_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "pdata", "role": "we1" }} , 
 	{ "name": "pdata_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pdata", "role": "d1" }} , 
 	{ "name": "pdata_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "pdata", "role": "q1" }} , 
 	{ "name": "dataout", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "dataout", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
		"CDFG" : "qrc_decoder",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "1",
		"VariableLatency" : "0", "ExactLatency" : "0", "EstimateLatencyMin" : "0", "EstimateLatencyMax" : "0",
		"Combinational" : "1",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "pdata", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "dataout", "Type" : "None", "Direction" : "I"}]}]}


set ArgLastReadFirstWriteLatency {
	qrc_decoder {
		pdata {Type X LastRead -1 FirstWrite -1}
		dataout {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "0", "Max" : "0"}
	, {"Name" : "Interval", "Min" : "1", "Max" : "1"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	pdata { ap_memory {  { pdata_address0 mem_address 1 9 }  { pdata_ce0 mem_ce 1 1 }  { pdata_we0 mem_we 1 1 }  { pdata_d0 mem_din 1 8 }  { pdata_q0 mem_dout 0 8 }  { pdata_address1 MemPortADDR2 1 9 }  { pdata_ce1 MemPortCE2 1 1 }  { pdata_we1 MemPortWE2 1 1 }  { pdata_d1 MemPortDIN2 1 8 }  { pdata_q1 MemPortDOUT2 0 8 } } }
	dataout { ap_none {  { dataout in_data 0 8 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
