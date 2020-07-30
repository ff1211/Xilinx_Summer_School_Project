<project xmlns="com.autoesl.autopilot.project" name="otsu_threshold" top="ov5640_otsu_threshold">
    <files>
        <file name="../src/lena.jpg" sc="0" tb="1" cflags=" -Wno-unknown-pragmas"/>
        <file name="../src/otsu_threshold_tb.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas"/>
        <file name="otsu_threshold/src/otsu_threshold.h" sc="0" tb="false" cflags=""/>
        <file name="otsu_threshold/src/otsu_threshold.cpp" sc="0" tb="false" cflags=""/>
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

