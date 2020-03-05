quit -sim
cd C:/Users/gse4/Desktop/tp2/precision/fsmmoore/simulation/modelsim 

vlib work 
vlib cycloneii 
vmap cycloneii cycloneii
#compilation des bibliothèques de cellules du cyclone II 
vcom -work cycloneii c:/altera/90sp2/quartus/eda/sim_lib/cycloneii_atoms.vhd 
vcom -work cycloneii c:/altera/90sp2/quartus/eda/sim_lib/cycloneii_components.vhd
#compilation du .vho 
vcom fsmmoore.vho
#compilation du testbench depuis le repertoire sources 
vcom ../../../../ctrlrs232c/test_bench_ctrlrs232c.vhd
add wave /*
#lancement du simulateur 
vsim -t 1ns work.test(bench_ctrlrs232c)