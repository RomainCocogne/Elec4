if { ![project_exists {fsmmoore}] } {
     project_new {fsmmoore}
} else {
     project_open {fsmmoore}
}
set_project_settings -cmp {fsmmoore}
if { ![project_settings_exist -sim fsmmoore] } {
        set_project_settings -sim fsmmoore
}
set_global_assignment -section_id {fsmmoore} -name {EDA_DESIGN_ENTRY_SYNTHESIS_TOOL} {PRECISION SYNTHESIS}
set_global_assignment -section_id {fsmmoore} -name {EDA_SIMULATION_TOOL} {MODELSIM (VHDL OUTPUT FROM QUARTUS II)}
set_global_assignment -name TOP_LEVEL_ENTITY ctrlrs232c
set_global_assignment -name {VQM_FILE} {fsmmoore.vqm}
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
if { [file exists {ctrlrs232c_altera.prop}] } {
  source ctrlrs232c_altera.prop
}
set_global_assignment -name {FAMILY} {CYCLONE II}
set_global_assignment -section_id {fsmmoore} -name {DEVICE} {EP2C35F672C6}
set_location_assignment PIN_W26 -to rst
set_location_assignment PIN_N2 -to clk
set_location_assignment PIN_V2 -to m
set_location_assignment PIN_N25 -to dtr
set_location_assignment PIN_N26 -to rts
set_location_assignment PIN_AF22 -to dsr
set_location_assignment PIN_AE22 -to cts
set_location_assignment PIN_U20 -to mam
set_location_assignment PIN_T19 -to mad
set_global_assignment -name {PROJECT_SHOW_ENTITY_NAME} {OFF}
set_global_assignment -name {SDC_FILE} {fsmmoore_pnr_constraints.sdc}
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
