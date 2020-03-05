if { ![project_exists {display}] } {
     project_new {display}
} else {
     project_open {display}
}
set_project_settings -cmp {display}
if { ![project_settings_exist -sim display] } {
        set_project_settings -sim display
}
set_global_assignment -section_id {display} -name {EDA_DESIGN_ENTRY_SYNTHESIS_TOOL} {PRECISION SYNTHESIS}
set_global_assignment -section_id {display} -name {EDA_SIMULATION_TOOL} {MODELSIM (VHDL OUTPUT FROM QUARTUS II)}
set_global_assignment -name {VQM_FILE} {display.vqm}
set_global_assignment -name {USE_TIMEQUEST_TIMING_ANALYZER} {ON}
set_global_assignment -section_id {eda_design_synthesis} -name {EDA_USE_LMF} {mentor.lmf}
set_global_assignment -section_id {eda_design_synthesis} -name {EDA_INPUT_GND_NAME} {GND}
set_global_assignment -section_id {eda_design_synthesis} -name {EDA_INPUT_VCC_NAME} {VCC}
set_global_assignment -section_id {eda_design_synthesis} -name {EDA_SHOW_LMF_MAPPING_MESSAGES} {OFF}
set_global_assignment -section_id {eda_design_synthesis} -name {EDA_RUN_TOOL_AUTOMATICALLY} {OFF}
set_global_assignment -section_id {eda_design_synthesis} -name {EDA_INPUT_DATA_FORMAT} {VQM}
set_global_assignment -section_id {eda_design_synthesis} -name {EDA_OUTPUT_DATA_FORMAT} {VQM}
set_global_assignment -section_id {eda_simulation} -name {EDA_FLATTEN_BUSES} {OFF}
set_global_assignment -section_id {eda_timing_analysis} -name {EDA_FLATTEN_BUSES} {OFF}
set_global_assignment -section_id {eda_design_synthesis} -name {AUTO_SHIFT_REGISTER_RECOGNITION} {OFF}
set_global_assignment -section_id {eda_design_synthesis} -name {AUTO_RAM_RECOGNITION} {OFF}
set_global_assignment -section_id {eda_design_synthesis} -name {AUTO_ROM_RECOGNITION} {OFF}
set_global_assignment -name {BLOCK_RAM_TO_MLAB_CELL_CONVERSION} {OFF}
set_global_assignment -name {READ_OR_WRITE_IN_BYTE_ADDRESS} {ON}
if { [file exists {display_altera.prop}] } {
  source display_altera.prop
}
set_global_assignment -name {FAMILY} {CYCLONE II}
set_global_assignment -section_id {display} -name {DEVICE} {EP2C35F672C6}
set_location_assignment PIN_V2 -to mode[1]
set_location_assignment PIN_V1 -to mode[0]
set_location_assignment PIN_N25 -to dtr
set_location_assignment PIN_W26 -to rst
set_location_assignment PIN_G26 -to clk
set_location_assignment PIN_L23 -to m[1]
set_location_assignment PIN_L20 -to m[0]
set_location_assignment PIN_V13 -to aff0[6]
set_location_assignment PIN_V14 -to aff0[5]
set_location_assignment PIN_AE12 -to aff0[4]
set_location_assignment PIN_AD11 -to aff0[3]
set_location_assignment PIN_AC12 -to aff0[2]
set_location_assignment PIN_AB12 -to aff0[1]
set_location_assignment PIN_AF10 -to aff0[0]
set_location_assignment PIN_AB24 -to aff1[6]
set_location_assignment PIN_AA23 -to aff1[5]
set_location_assignment PIN_AA24 -to aff1[4]
set_location_assignment PIN_Y22 -to aff1[3]
set_location_assignment PIN_W21 -to aff1[2]
set_location_assignment PIN_V21 -to aff1[1]
set_location_assignment PIN_V20 -to aff1[0]
set_location_assignment PIN_Y24 -to aff2[6]
set_location_assignment PIN_AB25 -to aff2[5]
set_location_assignment PIN_AB26 -to aff2[4]
set_location_assignment PIN_AC26 -to aff2[3]
set_location_assignment PIN_AC25 -to aff2[2]
set_location_assignment PIN_V22 -to aff2[1]
set_location_assignment PIN_AB23 -to aff2[0]
set_location_assignment PIN_W24 -to aff3[6]
set_location_assignment PIN_U22 -to aff3[5]
set_location_assignment PIN_Y25 -to aff3[4]
set_location_assignment PIN_Y26 -to aff3[3]
set_location_assignment PIN_AA26 -to aff3[2]
set_location_assignment PIN_AA25 -to aff3[1]
set_location_assignment PIN_Y23 -to aff3[0]
set_location_assignment PIN_T3 -to aff4[6]
set_location_assignment PIN_R6 -to aff4[5]
set_location_assignment PIN_R7 -to aff4[4]
set_location_assignment PIN_T4 -to aff4[3]
set_location_assignment PIN_U2 -to aff4[2]
set_location_assignment PIN_U1 -to aff4[1]
set_location_assignment PIN_U9 -to aff4[0]
set_location_assignment PIN_R3 -to aff5[6]
set_location_assignment PIN_R4 -to aff5[5]
set_location_assignment PIN_R5 -to aff5[4]
set_location_assignment PIN_T9 -to aff5[3]
set_location_assignment PIN_P7 -to aff5[2]
set_location_assignment PIN_P6 -to aff5[1]
set_location_assignment PIN_T2 -to aff5[0]
set_global_assignment -name {PROJECT_SHOW_ENTITY_NAME} {OFF}
set_global_assignment -name {SDC_FILE} {display_pnr_constraints.sdc}
export_assignment_files
package require ::quartus::flow
if { [catch {execute_module -tool map} result] } {
  puts "Error running quartus_map $result"
} elseif { [catch {execute_module -tool fit} result] } {
  puts "Error running quartus_fit $result"
} elseif { [catch {execute_module -tool sta -args --do_report_timing} result] } {
  puts "Error running quartus_sta $result"
} elseif { [catch {execute_module -tool asm} result] } {
  puts "Error running quartus_asm $result"
} elseif { [catch {execute_module -tool eda} result] } {
  puts "Error running quartus_eda $result"
}
project_close
