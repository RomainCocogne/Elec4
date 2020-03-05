###################################################################################
# Mentor Graphics Corporation
#
###################################################################################

#################
# Attributes
#################

##################
# Clocks
##################
create_clock { clk } -name clk -period 1000.000000 -waveform { 0.000000 500.000000 } -design rtl 

##################
# Input delays
##################
set_input_delay 0.300 -clock clk -add_delay  -design rtl  {m}

###################
# Output delays
###################
set_output_delay 6.000 -clock clk -add_delay  -design rtl  {mad mam}
