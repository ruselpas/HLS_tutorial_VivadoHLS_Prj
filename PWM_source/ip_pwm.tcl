############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project -reset IP_PWM

add_files pwm.cpp
add_files pwm.hpp

add_files -tb pwm_test.cpp -cflags "-Wno-unknown-pragmas -Wno-unknown-pragmas"

set_top PWM
open_solution -reset "PWM"

set_part {xc7z007sclg225-1}
create_clock -period 10 -name default

config_rtl  -encoding onehot -reset control  -reset_level low  -vivado_impl_strategy default -vivado_phys_opt place -vivado_synth_design_args {-directive sdx_optimization_effort_high} -vivado_synth_strategy default

csynth_design
export_design -rtl verilog -format ip_catalog

set_top PWM_CTRL
open_solution -reset "PWM_CTRL"

set_part {xc7z007sclg225-1}
create_clock -period 10 -name default

config_rtl  -encoding onehot -reset control  -reset_level low  -vivado_impl_strategy default -vivado_phys_opt place -vivado_synth_design_args {-directive sdx_optimization_effort_high} -vivado_synth_strategy default

# Do not perform any other steps
#csim_design
#csynth_design
#cosim_design -trace_level all
#export_design -rtl verilog -format ip_catalog
exit