
log_wave [get_objects -filter {type == in_port || type == out_port || type == inout_port || type == port} /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/*]
set designtopgroup [add_wave_group "Design Top Signals"]
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set c_group [add_wave_group c(memory) -into $coutputgroup]
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/c_d0 -into $c_group -radix hex
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/c_we0 -into $c_group -color #ffff00 -radix hex
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/c_ce0 -into $c_group -color #ffff00 -radix hex
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/c_address0 -into $c_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set b_group [add_wave_group b(memory) -into $cinputgroup]
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/b_q0 -into $b_group -radix hex
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/b_ce0 -into $b_group -color #ffff00 -radix hex
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/b_address0 -into $b_group -radix hex
set a_group [add_wave_group a(memory) -into $cinputgroup]
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/a_q0 -into $a_group -radix hex
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/a_ce0 -into $a_group -color #ffff00 -radix hex
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/a_address0 -into $a_group -radix hex
set n_group [add_wave_group n(wire) -into $cinputgroup]
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/n -into $n_group -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake" -into $designtopgroup]
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/ap_start -into $blocksiggroup
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/ap_done -into $blocksiggroup
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/ap_idle -into $blocksiggroup
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/ap_ready -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/ap_rst -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_multiply_matrices_top/AESL_inst_multiply_matrices/ap_clk -into $clockgroup
save_wave_config multiply_matrices.wcfg
run all
quit

