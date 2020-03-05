#script de synthèse syntheseTP1.tcl
cd C:/Users/gse4/Desktop/tp1/precision
set_input_dir C:/Users/gse4/Desktop/tp1/precision
setup_design -manufacturer Altera -family "CYCLONE II" -part EP2C35F672C -speed 6
setup_design -edif=true
setup_place_and_route -flow "Quartus II Modular" -command "Integrated Place and Route" -ba_format VHDL -install_dir C:/altera/13.0sp1/quartus
add_input_file {../display/display.vhd}
compile
create_clock {clk} _domain clockDomain0 -name clk -period 1000.0
set_output_delay 0.36 -clock clk {m(*)}
set_false_path -from {mode(0) mode(1) dtr}
set_false_path -to {aff2(0) aff2(2) aff2(3) aff2(4) aff2(5) aff3(1) aff3(2) aff5(0) aff5(1) aff5(2}}
update_constraint_file
synthesize

set_attribute -name pin_number -value "V2" -net -type string mode(1) -design rtl 
set_attribute -name pin_number -value "V1" -net -type string mode(0) -design rtl 
set_attribute -name pin_number -value "L23" -net -type string m(1) -design rtl 
set_attribute -name pin_number -value "L20" -net -type string m(0) -design rtl 
set_attribute -name pin_number -value "AB25" -net -type string aff2(5) -design rtl 
set_attribute -name pin_number -value "AB26" -net -type string aff2(4) -design rtl 
set_attribute -name pin_number -value "AC26" -net -type string aff2(3) -design rtl 
set_attribute -name pin_number -value "AC25" -net -type string aff2(2) -design rtl 
set_attribute -name pin_number -value "AB23" -net -type string aff2(0) -design rtl 
set_attribute -name pin_number -value "AA26" -net -type string aff3(2) -design rtl 
set_attribute -name pin_number -value "AA25" -net -type string aff3(1) -design rtl 
set_attribute -name pin_number -value "P7" -net -type string aff5(2) -design rtl 
set_attribute -name pin_number -value "P6" -net -type string aff5(1) -design rtl 
set_attribute -name pin_number -value "T2" -net -type string aff5(0) -design rtl 
set_attribute -name pin_number -value "AB24" -net -type string aff1(6) -design rtl 
set_attribute -name pin_number -value "V20" -net -type string aff1(5) -design rtl 
set_attribute -name pin_number -value "V2" -port -type string mode(1) -design rtl 
set_attribute -name pin_number -value "V1" -port -type string mode(0) -design rtl 
set_attribute -name pin_number -value "N25" -port -type string dtr -design rtl 
set_attribute -name pin_number -value "W26" -port -type string rst -design rtl 
set_attribute -name PIN_NUMBER -value "G26" -port clk -design rtl 
set_attribute -name pin_number -value "L23" -port -type string m(1) -design rtl 
set_attribute -name pin_number -value "L20" -port -type string m(0) -design rtl 
set_attribute -name pin_number -value "V13" -port -type string aff0(6) -design rtl 
set_attribute -name pin_number -value "V14" -port -type string aff0(5) -design rtl 
set_attribute -name pin_number -value "AE12" -port -type string aff0(4) -design rtl 
set_attribute -name pin_number -value "AD11" -port -type string aff0(3) -design rtl 
set_attribute -name pin_number -value "AC12" -port -type string aff0(2) -design rtl 
set_attribute -name pin_number -value "AB12" -port -type string aff0(1) -design rtl 
set_attribute -name pin_number -value "AF10" -port -type string aff0(0) -design rtl 
set_attribute -name pin_number -value "AB24" -port -type string aff1(6) -design rtl 
set_attribute -name pin_number -value "AA23" -port -type string aff1(5) -design rtl 
set_attribute -name pin_number -value "AA24" -port -type string aff1(4) -design rtl 
set_attribute -name pin_number -value "Y22" -port -type string aff1(3) -design rtl 
set_attribute -name pin_number -value "W21" -port -type string aff1(2) -design rtl 
set_attribute -name pin_number -value "V21" -port -type string aff1(1) -design rtl 
set_attribute -name pin_number -value "V20" -port -type string aff1(0) -design rtl 
set_attribute -name pin_number -value "Y24" -port -type string aff2(6) -design rtl 
set_attribute -name pin_number -value "AB25" -port -type string aff2(5) -design rtl 
set_attribute -name pin_number -value "AB26" -port -type string aff2(4) -design rtl 
set_attribute -name pin_number -value "AC26" -port -type string aff2(3) -design rtl 
set_attribute -name pin_number -value "AC25" -port -type string aff2(2) -design rtl 
set_attribute -name pin_number -value "V22" -port -type string aff2(1) -design rtl 
set_attribute -name pin_number -value "AB23" -port -type string aff2(0) -design rtl 
set_attribute -name pin_number -value "W24" -port -type string aff3(6) -design rtl 
set_attribute -name pin_number -value "U22" -port -type string aff3(5) -design rtl 
set_attribute -name pin_number -value "Y25" -port -type string aff3(4) -design rtl 
set_attribute -name pin_number -value "Y26" -port -type string aff3(3) -design rtl 
set_attribute -name pin_number -value "AA26" -port -type string aff3(2) -design rtl 
set_attribute -name pin_number -value "AA25" -port -type string aff3(1) -design rtl 
set_attribute -name pin_number -value "Y23" -port -type string aff3(0) -design rtl 
set_attribute -name pin_number -value "T3" -port -type string aff4(6) -design rtl 
set_attribute -name pin_number -value "R6" -port -type string aff4(5) -design rtl 
set_attribute -name pin_number -value "R7" -port -type string aff4(4) -design rtl 
set_attribute -name pin_number -value "T4" -port -type string aff4(3) -design rtl 
set_attribute -name pin_number -value "U2" -port -type string aff4(2) -design rtl 
set_attribute -name pin_number -value "U1" -port -type string aff4(1) -design rtl 
set_attribute -name pin_number -value "U9" -port -type string aff4(0) -design rtl 
set_attribute -name pin_number -value "R3" -port -type string aff5(6) -design rtl 
set_attribute -name pin_number -value "R4" -port -type string aff5(5) -design rtl 
set_attribute -name pin_number -value "R5" -port -type string aff5(4) -design rtl 
set_attribute -name pin_number -value "T9" -port -type string aff5(3) -design rtl 
set_attribute -name pin_number -value "P7" -port -type string aff5(2) -design rtl 
set_attribute -name pin_number -value "P6" -port -type string aff5(1) -design rtl 
set_attribute -name pin_number -value "T2" -port -type string aff5(0) -design rtl

place_and_route cl