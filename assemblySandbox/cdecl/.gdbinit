set disassembly-flavor intel
b fpuTest
display $xmm0.v4_float
display $xmm1.v4_float
display $st0
display $st1
display (float)*arg1
display (float)*arg2