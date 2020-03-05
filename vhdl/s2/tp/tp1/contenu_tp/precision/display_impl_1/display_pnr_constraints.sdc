###################################################################################
# Mentor Graphics Corporation
#
###################################################################################


##################
# Clocks
##################
create_clock { clk } -name clk -period 1000.000000

###################
# Output delays
###################
set_output_delay  -clock clk -add_delay 0.360 {m[*]}
###########################
# False Paths / Multicycles
###########################
set_false_path -from {dtr dtr_ibuf mode[0] mode[1] mode_ibuf_0_ mode_ibuf_1_ rst rst_ibuf} -to {aff0[0] aff0[1] aff0[2] aff0[3] aff0[4] aff0[5] aff0[6] aff1[0] aff1[1] aff1[2] aff1[3] aff1[4] aff1[5] aff1[6] aff1_obuf_5_ aff1_obuf_6_ aff2[0] aff2[1] aff2[2] aff2[3] aff2[4] aff2[5] aff2[6] aff2_obuf_2_ aff3[0] aff3[1] aff3[2] aff3[3] aff3[4] aff3[5] aff3[6] aff3_obuf_1_ aff4[0] aff4[1] aff4[2] aff4[3] aff4[4] aff4[5] aff4[6] aff5[0] aff5[1] aff5[2] aff5[3] aff5[4] aff5[5] aff5[6] aff5_obuf_0_ m[0] m[1] m_obuf_0_ m_obuf_1_}
set_false_path -from {dtr dtr_ibuf mode[0] mode[1] mode_ibuf_0_ mode_ibuf_1_}
