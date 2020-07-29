<project xmlns="com.autoesl.autopilot.project" name="sobel_hls" top="ov5640_sobel">
    <files>
        <file name="../src/lena.jpg" sc="0" tb="1" cflags=" -Wno-unknown-pragmas"/>
        <file name="../src/ov5640_sobel_tb.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas"/>
        <file name="sobel_hls/src/ov5640_sobel.cpp" sc="0" tb="false" cflags=""/>
        <file name="sobel_hls/src/ov5640_sobel.h" sc="0" tb="false" cflags=""/>
    </files>
    <includePaths/>
    <libraryPaths/>
    <Simulation>
        <SimFlow name="csim" optimizeCompile="true" clean="true" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <solutions xmlns="">
        <solution name="solution1" status="active"/>
    </solutions>
</project>

