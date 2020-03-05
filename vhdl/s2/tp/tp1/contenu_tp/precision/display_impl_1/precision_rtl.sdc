###################################################################################
# Mentor Graphics Corporation
#
# This file is not a constraints report, nor does it list all the
# RTL constraints in the design. This file is created and used by Precision
# to track user RTL constraints that are set during design iterations.
# You should not edit this file because doing so might cause improper
# constraints in the design.
#
# If you want to list all RTL design constraints, use the command
#       report_constraints -design rtl
# or double-click on the RTL Constraints Report node in the Output Files
# Folder in the GUI.
#
# For a detailed discussion of how to set constraints, please refer to
# Precision documentation which is available from the Help pulldown menu.
###################################################################################

#################
# Attributes
#################
set_attribute -name PIN_NUMBER -value "G26" -port clk -design rtl 


##################
# Clocks
##################
create_clock { clk } -name clk -period 1000.000000 -waveform { 0.000000 500.000000 } -design rtl 

###################
# Output delays
###################
set_output_delay 0.360 -clock clk -add_delay  -design rtl  {m(*)}
###########################
# False Paths / Multicycles
###########################
set_false_path -from { {dtr mode(0) mode(1) rst} } -to { {aff0(0) aff0(1) aff0(2) aff0(3) aff0(4) aff0(5) aff0(6) aff1(0) aff1(1) aff1(2) aff1(3) aff1(4) aff1(5) aff1(6) aff2(0) aff2(1) aff2(2) aff2(3) aff2(4) aff2(5) aff2(6) aff3(0) aff3(1) aff3(2) aff3(3) aff3(4) aff3(5) aff3(6) aff4(0) aff4(1) aff4(2) aff4(3) aff4(4) aff4(5) aff4(6) aff5(0) aff5(1) aff5(2) aff5(3) aff5(4) aff5(5) aff5(6) m(0) m(1)} } -design rtl
set_false_path -from { {dtr mode(0) mode(1) rst} } -to { {aff0(0) aff0(1) aff0(2) aff0(3) aff0(4) aff0(5) aff0(6) aff1(0) aff1(1) aff1(2) aff1(3) aff1(4) aff1(5) aff1(6) aff2(0) aff2(1) aff2(2) aff2(3) aff2(4) aff2(5) aff2(6) aff3(0) aff3(1) aff3(2) aff3(3) aff3(4) aff3(5) aff3(6) aff4(0) aff4(1) aff4(2) aff4(3) aff4(4) aff4(5) aff4(6) aff5(0) aff5(1) aff5(2) aff5(3) aff5(4) aff5(5) aff5(6) m(0) m(1)} } -design rtl
set_false_path -from { {dtr mode(0) mode(1) rst} } -to { {aff0(0) aff0(1) aff0(2) aff0(3) aff0(4) aff0(5) aff0(6) aff1(0) aff1(1) aff1(2) aff1(3) aff1(4) aff1(5) aff1(6) aff2(0) aff2(1) aff2(2) aff2(3) aff2(4) aff2(5) aff2(6) aff3(0) aff3(1) aff3(2) aff3(3) aff3(4) aff3(5) aff3(6) aff4(0) aff4(1) aff4(2) aff4(3) aff4(4) aff4(5) aff4(6) aff5(0) aff5(1) aff5(2) aff5(3) aff5(4) aff5(5) aff5(6) m(0) m(1)} } -design rtl
set_false_path -from { {mode(0) mode(1) dtr} } -design rtl
set_false_path -from { {dtr mode(0) mode(1) rst} } -to { {aff0(0) aff0(1) aff0(2) aff0(3) aff0(4) aff0(5) aff0(6) aff1(0) aff1(1) aff1(2) aff1(3) aff1(4) aff1(5) aff1(6) aff2(0) aff2(1) aff2(2) aff2(3) aff2(4) aff2(5) aff2(6) aff3(0) aff3(1) aff3(2) aff3(3) aff3(4) aff3(5) aff3(6) aff4(0) aff4(1) aff4(2) aff4(3) aff4(4) aff4(5) aff4(6) aff5(0) aff5(1) aff5(2) aff5(3) aff5(4) aff5(5) aff5(6) m(0) m(1)} } -design rtl
set_false_path -from { {dtr mode(0) mode(1)} } -design rtl
