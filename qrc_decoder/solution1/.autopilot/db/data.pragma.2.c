# 1 "qrc_decoder/src/data.c"
# 1 "qrc_decoder/src/data.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1






# 1 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/common/technology/autopilot\\etc/autopilot_ssdm_op.h" 1
# 300 "C:/yueqihong/MYSOFTWARE/Xilinx/Vivado/2018.3/common/technology/autopilot\\etc/autopilot_ssdm_op.h"
    void _ssdm_op_IfRead() __attribute__ ((nothrow));
    void _ssdm_op_IfWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanWrite() __attribute__ ((nothrow));


    void _ssdm_StreamRead() __attribute__ ((nothrow));
    void _ssdm_StreamWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanWrite() __attribute__ ((nothrow));




    void _ssdm_op_MemShiftRead() __attribute__ ((nothrow));

    void _ssdm_op_Wait() __attribute__ ((nothrow));
    void _ssdm_op_Poll() __attribute__ ((nothrow));

    void _ssdm_op_Return() __attribute__ ((nothrow));


    void _ssdm_op_SpecSynModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecTopModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDecl() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDef() __attribute__ ((nothrow));
    void _ssdm_op_SpecPort() __attribute__ ((nothrow));
    void _ssdm_op_SpecConnection() __attribute__ ((nothrow));
    void _ssdm_op_SpecChannel() __attribute__ ((nothrow));
    void _ssdm_op_SpecSensitive() __attribute__ ((nothrow));
    void _ssdm_op_SpecModuleInst() __attribute__ ((nothrow));
    void _ssdm_op_SpecPortMap() __attribute__ ((nothrow));

    void _ssdm_op_SpecReset() __attribute__ ((nothrow));

    void _ssdm_op_SpecPlatform() __attribute__ ((nothrow));
    void _ssdm_op_SpecClockDomain() __attribute__ ((nothrow));
    void _ssdm_op_SpecPowerDomain() __attribute__ ((nothrow));

    int _ssdm_op_SpecRegionBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecRegionEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopName() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopTripCount() __attribute__ ((nothrow));

    int _ssdm_op_SpecStateBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecStateEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecInterface() __attribute__ ((nothrow));

    void _ssdm_op_SpecPipeline() __attribute__ ((nothrow));
    void _ssdm_op_SpecDataflowPipeline() __attribute__ ((nothrow));


    void _ssdm_op_SpecLatency() __attribute__ ((nothrow));
    void _ssdm_op_SpecParallel() __attribute__ ((nothrow));
    void _ssdm_op_SpecProtocol() __attribute__ ((nothrow));
    void _ssdm_op_SpecOccurrence() __attribute__ ((nothrow));

    void _ssdm_op_SpecResource() __attribute__ ((nothrow));
    void _ssdm_op_SpecResourceLimit() __attribute__ ((nothrow));
    void _ssdm_op_SpecCHCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecFUCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIFCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIPCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecKeepValue() __attribute__ ((nothrow));
    void _ssdm_op_SpecMemCore() __attribute__ ((nothrow));

    void _ssdm_op_SpecExt() __attribute__ ((nothrow));




    void _ssdm_SpecArrayDimSize() __attribute__ ((nothrow));

    void _ssdm_RegionBegin() __attribute__ ((nothrow));
    void _ssdm_RegionEnd() __attribute__ ((nothrow));

    void _ssdm_Unroll() __attribute__ ((nothrow));
    void _ssdm_UnrollRegion() __attribute__ ((nothrow));

    void _ssdm_InlineAll() __attribute__ ((nothrow));
    void _ssdm_InlineLoop() __attribute__ ((nothrow));
    void _ssdm_Inline() __attribute__ ((nothrow));
    void _ssdm_InlineSelf() __attribute__ ((nothrow));
    void _ssdm_InlineRegion() __attribute__ ((nothrow));

    void _ssdm_SpecArrayMap() __attribute__ ((nothrow));
    void _ssdm_SpecArrayPartition() __attribute__ ((nothrow));
    void _ssdm_SpecArrayReshape() __attribute__ ((nothrow));

    void _ssdm_SpecStream() __attribute__ ((nothrow));

    void _ssdm_SpecExpr() __attribute__ ((nothrow));
    void _ssdm_SpecExprBalance() __attribute__ ((nothrow));

    void _ssdm_SpecDependence() __attribute__ ((nothrow));

    void _ssdm_SpecLoopMerge() __attribute__ ((nothrow));
    void _ssdm_SpecLoopFlatten() __attribute__ ((nothrow));
    void _ssdm_SpecLoopRewind() __attribute__ ((nothrow));

    void _ssdm_SpecFuncInstantiation() __attribute__ ((nothrow));
    void _ssdm_SpecFuncBuffer() __attribute__ ((nothrow));
    void _ssdm_SpecFuncExtract() __attribute__ ((nothrow));
    void _ssdm_SpecConstant() __attribute__ ((nothrow));

    void _ssdm_DataPack() __attribute__ ((nothrow));
    void _ssdm_SpecDataPack() __attribute__ ((nothrow));

    void _ssdm_op_SpecBitsMap() __attribute__ ((nothrow));
    void _ssdm_op_SpecLicense() __attribute__ ((nothrow));
# 8 "<command line>" 2
# 1 "<built-in>" 2
# 1 "qrc_decoder/src/data.c" 2
# 19 "qrc_decoder/src/data.c"
const unsigned char pattern_finder[7][7] =
{
 { 1,1,1,1,1,1,1, },
 { 1,0,0,0,0,0,1, },
 { 1,0,1,1,1,0,1, },
 { 1,0,1,1,1,0,1, },
 { 1,0,1,1,1,0,1, },
 { 1,0,0,0,0,0,1, },
 { 1,1,1,1,1,1,1, },
};

const unsigned char pattern_alignment[5][5] =
{
 { 1,1,1,1,1, },
 { 1,0,0,0,1, },
 { 1,0,1,0,1, },
 { 1,0,0,0,1, },
 { 1,1,1,1,1, },
};

const char* charset_alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";

const unsigned char version_range[41] =
{
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
};


const unsigned char code_to_ecl[4] = { 1, 0, 3, 2 };
const unsigned char ecl_to_code[4] = { 1, 0, 3, 2 };

const unsigned char lenbits[5][3] =
{
 { 0 },
 { 10, 12, 14, },
 { 9, 11, 13, },
 { 0 },
 { 8, 16, 16, },
};

const unsigned long bch_format_gen = 0x537;
const unsigned long bch_format_mask = 0x5412;
const unsigned long bch_version_gen = 0x1f25;
const unsigned long bch_version_mask = 0x0;

const unsigned char pattern_alignment_pos[41][8] =
{
 { 0, },
 { 0, },
 { 6,18,0 },
 { 6,22,0 },
 { 6,26,0 },
 { 6,30,0 },
 { 6,34,0 },
 { 6,22,38,0 },
 { 6,24,42,0 },
 { 6,26,46,0 },
 { 6,28,50,0 },
 { 6,30,54,0 },
 { 6,32,58,0 },
 { 6,34,62,0 },
 { 6,26,46,66,0 },
 { 6,26,48,70,0 },
 { 6,26,50,74,0 },
 { 6,30,54,78,0 },
 { 6,30,56,82,0 },
 { 6,30,58,86,0 },
 { 6,34,82,90,0 },
 { 6,28,50,72, 94,0 },
 { 6,26,50,74, 98,0 },
 { 6,30,54,78,102,0 },
 { 6,28,54,80,106,0 },
 { 6,32,58,84,110,0 },
 { 6,30,58,86,114,0 },
 { 6,34,62,90,118,0 },
 { 6,26,50,74, 98,122,0 },
 { 6,30,54,78,102,126,0 },
 { 6,26,52,78,104,130,0 },
 { 6,30,56,82,108,134,0 },
 { 6,34,60,86,112,138,0 },
 { 6,30,58,86,114,142,0 },
 { 6,34,62,90,118,146,0 },
 { 6,30,54,78,102,126,150,0 },
 { 6,24,50,76,102,128,154,0 },
 { 6,28,54,80,106,132,158,0 },
 { 6,32,58,84,110,136,162,0 },
 { 6,26,54,82,110,138,166,0 },
 { 6,30,58,86,114,142,170,0 },
};

const unsigned char block_sizes[164][6] =
{

 {0}, {0}, {0}, {0},

 { 1, 26, 19, 0, 0, 0 },
 { 1, 26, 16, 0, 0, 0 },
 { 1, 26, 13, 0, 0, 0 },
 { 1, 26, 9, 0, 0, 0 },

 { 1, 44, 34, 0, 0, 0 },
 { 1, 44, 28, 0, 0, 0 },
 { 1, 44, 22, 0, 0, 0 },
 { 1, 44, 16, 0, 0, 0 },

 { 1, 70, 55, 0, 0, 0 },
 { 1, 70, 44, 0, 0, 0 },
 { 2, 35, 17, 0, 0, 0 },
 { 2, 35, 13, 0, 0, 0 },

 { 1,100, 80, 0, 0, 0 },
 { 2, 50, 32, 0, 0, 0 },
 { 2, 50, 24, 0, 0, 0 },
 { 4, 25, 9, 0, 0, 0 },

 { 1,134,108, 0, 0, 0 },
 { 2, 67, 43, 0, 0, 0 },
 { 2, 33, 15, 2, 33, 16 },
 { 2, 33, 11, 2, 34, 12 },

 { 2, 86, 68, 0, 0, 0 },
 { 4, 43, 27, 0, 0, 0 },
 { 4, 43, 19, 0, 0, 0 },
 { 4, 43, 15, 0, 0, 0 },

 { 2, 98, 78, 0, 0, 0 },
 { 4, 49, 41, 0, 0, 0 },
 { 2, 32, 14, 4, 33, 15 },
 { 4, 39, 13, 1, 40, 14 },

 { 2,121, 97, 0, 0, 0 },
 { 2, 60, 38, 2, 61, 39 },
 { 4, 40, 18, 2, 41, 19 },
 { 4, 40, 14, 2, 41, 15 },

 { 2,146,116, 0, 0, 0 },
 { 3, 58, 36, 2, 59, 37 },
 { 4, 36, 16, 4, 37, 17 },
 { 4, 36, 12, 4, 37, 13 },

 { 2, 86, 68, 2, 87, 69 },
 { 4, 69, 43, 1, 70, 44 },
 { 6, 43, 19, 2, 44, 20 },
 { 6, 43, 15, 2, 44, 16 },

 { 4,101, 81, 0, 0, 0 },
 { 1, 80, 50, 4, 81, 51 },
 { 4, 50, 22, 4, 51, 23 },
 { 3, 36, 12, 8, 37, 13 },

 { 2,116, 92, 2,117, 93 },
 { 6, 58, 36, 2, 59, 37 },
 { 4, 46, 20, 6, 47, 21 },
 { 7, 42, 14, 4, 43, 15 },

 { 4,133,107, 0, 0, 0 },
 { 8, 59, 37, 1, 60, 38 },
 { 8, 44, 20, 4, 45, 21 },
 {12, 33, 11, 4, 34, 12 },

 { 3,145,115, 1,146,116 },
 { 4, 64, 40, 5, 65, 41 },
 {11, 36, 16, 5, 37, 17 },
 {11, 36, 12, 5, 37, 13 },

 { 5,109, 87, 1,110, 88 },
 { 5, 65, 41, 5, 66, 42 },
 { 5, 54, 24, 7, 55, 25 },
 {11, 36, 12, 7, 37, 13 },

 { 5,122, 98, 1,123, 99 },
 { 7, 73, 45, 3, 74, 46 },
 {15, 43, 19, 2, 44, 20 },
 { 3, 45, 15, 13, 46, 16 },

 { 1,135,107, 5,136,108 },
 {10, 74, 46, 1, 75, 47 },
 { 1, 50, 22, 15, 51, 23 },
 { 2, 42, 14, 17, 43, 15 },

 { 5,150,120, 1,151,121 },
 { 9, 69, 43, 4, 70, 44 },
 {17, 50, 22, 1, 51, 23 },
 { 2, 42, 14, 19, 43, 15 },

 { 3,141,113, 4,142,114 },
 { 3, 70, 44, 11, 71, 45 },
 {17, 47, 21, 4, 48, 22 },
 { 9, 39, 13, 16, 40, 14 },

 { 3,135,107, 5,136,108 },
 { 3, 67, 41, 13, 68, 42 },
 {15, 54, 24, 5, 55, 25 },
 {15, 43, 15, 10, 44, 15 },

 { 4,144,116, 4,145,117 },
 {17, 68, 42, 0, 0, 0 },
 {17, 50, 22, 6, 51, 23 },
 {19, 46, 16, 6, 47, 17 },

 { 2,139,111, 7,140,112 },
 {17, 74, 46, 0, 0, 0 },
 { 7, 54, 24, 16, 55, 25 },
 {34, 37, 13, 0, 0, 0 },

 { 4,151,121, 5,152,122 },
 { 4, 75, 47, 14, 76, 48 },
 {11, 54, 24, 14, 55, 25 },
 {16, 45, 15, 14, 46, 16 },

 { 6,147,117, 4,148,118 },
 { 6, 73, 45, 14, 74, 46 },
 {11, 54, 24, 16, 55, 25 },
 {30, 46, 16, 2, 47, 17 },

 { 8,132,106, 4,133,107 },
 { 8, 64, 47, 13, 76, 48 },
 { 7, 54, 24, 22, 55, 25 },
 {22, 45, 15, 13, 46, 16 },

 {10,142,114, 2,143,115 },
 {19, 74, 46, 4, 75, 47 },
 {28, 50, 22, 6, 51, 23 },
 {33, 46, 16, 4, 47, 17 },

 { 8,152,122, 4,153,123 },
 {22, 73, 45, 3, 74, 46 },
 { 8, 53, 23, 26, 54, 24 },
 {12, 45, 15, 28, 46, 16 },

 { 3,147,117, 10,148,118 },
 { 3, 73, 45, 23, 74, 46 },
 { 4, 54, 24, 31, 55, 25 },
 {11, 45, 15, 31, 46, 16 },

 { 7,146,116, 7,147,117 },
 {21, 73, 45, 7, 74, 46 },
 { 1, 53, 23, 37, 54, 24 },
 {19, 45, 15, 26, 46, 16 },

 { 5,145,115, 10,146,116 },
 {19, 75, 47, 10, 76, 48 },
 {15, 54, 24, 25, 55, 25 },
 {23, 45, 15, 25, 46, 16 },

 {13,145,115, 3,146,116 },
 { 2, 74, 46, 29, 75, 47 },
 {42, 54, 24, 1, 55, 25 },
 {23, 45, 15, 28, 46, 16 },

 {17,145,115, 0, 0, 0 },
 {10, 74, 46, 23, 75, 47 },
 {10, 54, 24, 35, 55, 25 },
 {19, 45, 15, 35, 46, 16 },

 {17,145,116, 1,146,116 },
 {14, 73, 46, 21, 75, 47 },
 {29, 54, 24, 19, 55, 25 },
 {11, 45, 15, 46, 46, 16 },

 {13,145,115, 6,146,116 },
 {14, 74, 46, 23, 75, 47 },
 {44, 54, 24, 7, 55, 25 },
 {59, 46, 16, 1, 47, 17 },

 {12,151,121, 7,152,122 },
 {12, 75, 47, 26, 76, 48 },
 {39, 54, 24, 14, 55, 25 },
 {22, 45, 15, 41, 46, 16 },

 { 6,151,121, 14,152,122 },
 { 6, 75, 47, 34, 76, 48 },
 {46, 54, 24, 10, 55, 25 },
 { 2, 45, 15, 64, 46, 16 },

 {17,152,122, 4,153,123 },
 {29, 74, 46, 14, 75, 47 },
 {49, 54, 24, 10, 55, 25 },
 {24, 45, 15, 46, 46, 16 },

 { 4,152,122, 18,163,123 },
 {13, 74, 46, 32, 75, 47 },
 {48, 54, 24, 14, 55, 25 },
 {42, 45, 15, 32, 46, 16 },

 {20,147,117, 4,148,118 },
 {40, 74, 47, 7, 76, 48 },
 {43, 54, 24, 22, 55, 25 },
 {10, 45, 15, 67, 46, 16 },

 {19,148,118, 6,149,119 },
 {18, 75, 47, 31, 76, 48 },
 {34, 54, 24, 34, 55, 25 },
 {20, 45, 25, 61, 46, 16 },
};
