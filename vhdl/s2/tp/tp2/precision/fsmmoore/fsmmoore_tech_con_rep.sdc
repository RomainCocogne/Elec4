###################################################################################
# Mentor Graphics Corporation
#
###################################################################################

#################
# Attributes
#################
set_attribute -name PIN_NUMBER -value "W26" -net rst -design gatelevel 
set_attribute -name PIN_NUMBER -value "N2" -net clk -design gatelevel 
set_attribute -name PIN_NUMBER -value "V2" -net m -design gatelevel 
set_attribute -name PIN_NUMBER -value "N25" -net dtr -design gatelevel 
set_attribute -name PIN_NUMBER -value "N26" -net rts -design gatelevel 
set_attribute -name PIN_NUMBER -value "AF22" -net dsr -design gatelevel 
set_attribute -name PIN_NUMBER -value "AE22" -net cts -design gatelevel 
set_attribute -name PIN_NUMBER -value "U20" -net mam -design gatelevel 
set_attribute -name PIN_NUMBER -value "T19" -net mad -design gatelevel 
set_attribute -name pin_number -value "AF22" -port dsr -design gatelevel 
set_attribute -name pin_number -value "AE22" -port cts -design gatelevel 
set_attribute -name pin_number -value "U20" -port mam -design gatelevel 
set_attribute -name pin_number -value "T19" -port mad -design gatelevel 
set_attribute -name pin_number -value "W26" -port rst -design gatelevel 
set_attribute -name pin_number -value "N2" -port clk -design gatelevel 
set_attribute -name INFF -value "FALSE" -port -type string clk -design gatelevel 
set_attribute -name pin_number -value "V2" -port m -design gatelevel 
set_attribute -name pin_number -value "N25" -port dtr -design gatelevel 
set_attribute -name pin_number -value "N26" -port rts -design gatelevel 


##################
# Clocks
##################
create_clock { clk } -name clk -period 1000.000000 -waveform { 0.000000 500.000000 } -design gatelevel 

##################
# Input delays
##################
set_input_delay 0.300 -clock clk -add_delay  -design gatelevel  {m}

###################
# Output delays
###################
set_output_delay 6.000 -clock clk -add_delay  -design gatelevel  {mad mam}
