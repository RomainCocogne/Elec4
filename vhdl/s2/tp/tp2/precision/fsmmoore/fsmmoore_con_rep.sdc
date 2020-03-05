###################################################################################
# Mentor Graphics Corporation
#
###################################################################################

#################
# Attributes
#################
set_attribute -name pin_number -value "AF22" -port dsr -design rtl 
set_attribute -name pin_number -value "AE22" -port cts -design rtl 
set_attribute -name pin_number -value "U20" -port mam -design rtl 
set_attribute -name pin_number -value "T19" -port mad -design rtl 
set_attribute -name pin_number -value "W26" -port rst -design rtl 
set_attribute -name pin_number -value "N2" -port clk -design rtl 
set_attribute -name pin_number -value "V2" -port m -design rtl 
set_attribute -name pin_number -value "N25" -port dtr -design rtl 
set_attribute -name pin_number -value "N26" -port rts -design rtl 


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
