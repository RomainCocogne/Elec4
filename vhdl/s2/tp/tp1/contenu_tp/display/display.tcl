quit -sim
vcom display.vhd
vcom test_bench_display.vhd

vsim -t 1ns work.test(bench_display)
add wave -noupdate -divider {entrees du bloc display}
add wave -noupdate -radix binary test/UUT/dtr
add wave -noupdate -radix binary test/UUT/mode
add wave -noupdate -divider {sorties du bloc display}
add wave -noupdate -radix binary test/UUT/aff0
add wave -noupdate -radix binary test/UUT/aff1
add wave -noupdate -radix binary test/UUT/aff2
add wave -noupdate -radix binary test/UUT/aff3
add wave -noupdate -radix binary test/UUT/aff4
add wave -noupdate -radix binary test/UUT/aff5

run 1us