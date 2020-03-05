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
