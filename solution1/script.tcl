############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project lab2
set_top multiply_matrices
add_files lab2/lab2.c
add_files lab2/lab2.h
add_files -tb lab2/in.dat -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb lab2/lab2_test.c -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb lab2/out.gold.dat -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7a100t-csg324-1} -tool vivado
create_clock -period 10 -name default
#source "./lab2/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level port
export_design -format ip_catalog
