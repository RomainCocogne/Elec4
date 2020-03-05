###################################################################################
# Mentor Graphics Corporation
#
###################################################################################


##################
# Clocks
##################
create_clock { clk } -name clk -period 1000.000000

##################
# Input delays
##################
set_input_delay  -clock clk -add_delay 0.300 {m}

###################
# Output delays
###################
set_output_delay  -clock clk -add_delay 6.000 {mad mam}
