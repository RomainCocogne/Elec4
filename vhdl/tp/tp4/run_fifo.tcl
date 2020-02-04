#On quitte la simulation en cours éventuelle
quit -sim
#directives de compilation des fichiers sources
vcom fifo.vhd
vcom testbench_fifo.vhd
#lancement du simulateur (résolution de 1ns)
vsim -t 1ns work.test(testbench_fifo)
#ajout des signaux dans la fenêtre de simulation
add wave -noupdate -divider {entree du bloc}

add wave -noupdate -radixshowbase 0 test/UUT/rst
add wave -noupdate -radixshowbase 0 test/UUT/H
add wave -noupdate -radixshowbase 0 test/UUT/rw
add wave -noupdate -radixshowbase 0 test/UUT/enable
add wave -noupdate -radix binary -radixshowbase 0 test/UUT/datain

add wave -noupdate -divider {sorties du bloc}
add wave -noupdate -radixshowbase 0 test/UUT/empty
add wave -noupdate -radixshowbase 0 test/UUT/full
add wave -noupdate -radix binary -radixshowbase 0 test/UUT/dataout

add wave -noupdate -divider {signaux internes}
add wave -noupdate -radix binary -radixshowbase 0 test/UUT/mux
add wave -noupdate -divider {memoire}
add wave -noupdate -radix binary -radixshowbase 0 test/UUT/reg
add wave -noupdate -divider {compteur}
add wave -noupdate -radix binary -radixshowbase 0 test/UUT/Qdeep

#simulation de 500ns
run 500ns
