quit -sim
vcom display.vhd
vcom test_bench_diplay.vhd

vsim -t 1 ns work.test(bench_display)
add wave -noupdate -divider entrees du bloc display}
add wave -noupdate -radix binary -radixshowbase 0 test/UUT/dtr
add wave -noupdate -radix binary -radixshowbase 0 test/UUT/mode
add wave -noupdate -divider {sorties du bloc display}
add wave -noupdate -radix binary -radixshowbase 0 test/UUT/aff0
add wave -noupdate -radix binary -radixshowbase 0 test/UUT/aff1
add wave -noupdate -radix binary -radixshowbase 0 test/UUT/aff2
add wave -noupdate -radix binary -radixshowbase 0 test/UUT/aff3
add wave -noupdate -radix binary -radixshowbase 0 test/UUT/aff4
add wave -noupdate -radix binary -radixshowbase 0 test/UUT/aff5

run 1 us