
-- 
-- Definition of  display
-- 
--      02/20/20 17:34:40
--      
--      Precision RTL Synthesis, 64-bit 2017.1.0.15
-- 

library IEEE;library altera_mf;library lpm;library altera; 
 use IEEE.STD_LOGIC_1164.ALL;
 use altera_mf.altera_mf_components.all, lpm.lpm_components.all, altera.altera_primitives_components.all;
-- Library use clause for technology cells
library cycloneii ;
use cycloneii.cycloneii_components.all;

entity display is 
   port (
      mode : IN std_logic_vector (1 DOWNTO 0) ;
      dtr : IN std_logic ;
      rst : IN std_logic ;
      clk : IN std_logic ;
      m : OUT std_logic_vector (1 DOWNTO 0) ;
      aff0 : OUT std_logic_vector (6 DOWNTO 0) ;
      aff1 : OUT std_logic_vector (6 DOWNTO 0) ;
      aff2 : OUT std_logic_vector (6 DOWNTO 0) ;
      aff3 : OUT std_logic_vector (6 DOWNTO 0) ;
      aff4 : OUT std_logic_vector (6 DOWNTO 0) ;
      aff5 : OUT std_logic_vector (6 DOWNTO 0)) ;
end display ;

architecture beh_display of display is 
   signal mode_EXMPLR77: std_logic_vector (1 DOWNTO 0) ;
   
   signal dtr_EXMPLR30, rst_EXMPLR31, clk_EXMPLR32: std_logic ;
   
   signal m_dup_0: std_logic_vector (1 DOWNTO 0) ;
   
   signal mode_int: std_logic_vector (1 DOWNTO 0) ;
   
   signal dtr_int, rst_int, clk_int: std_logic ;
   
   signal m_EXMPLR78: std_logic_vector (1 DOWNTO 0) ;
   
   signal aff0_EXMPLR79: std_logic_vector (6 DOWNTO 0) ;
   
   signal aff1_EXMPLR80: std_logic_vector (6 DOWNTO 5) ;
   
   signal aff1_4_EXMPLR44, aff1_3_EXMPLR45, aff1_2_EXMPLR46, aff1_1_EXMPLR47, 
      aff1_0_EXMPLR48: std_logic ;
   
   signal aff2_EXMPLR81: std_logic_vector (6 DOWNTO 0) ;
   
   signal aff3_EXMPLR82: std_logic_vector (6 DOWNTO 0) ;
   
   signal aff4_EXMPLR83: std_logic_vector (6 DOWNTO 0) ;
   
   signal aff5_EXMPLR84: std_logic_vector (6 DOWNTO 0) ;
   
   signal aff2_dup_0_2, aff5_dup_0_0: std_logic ;
   
   signal aff1_dup_0: std_logic_vector (6 DOWNTO 5) ;
   
   signal nx59866z1: std_logic ;

begin
   mode_EXMPLR77(1) <= mode(1) ;
   mode_EXMPLR77(0) <= mode(0) ;
   dtr_EXMPLR30 <= dtr ;
   rst_EXMPLR31 <= rst ;
   clk_EXMPLR32 <= clk ;
   m(1) <= m_EXMPLR78(1) ;
   m(0) <= m_EXMPLR78(0) ;
   aff0(6) <= aff0_EXMPLR79(6) ;
   aff0(5) <= aff0_EXMPLR79(5) ;
   aff0(4) <= aff0_EXMPLR79(4) ;
   aff0(3) <= aff0_EXMPLR79(3) ;
   aff0(2) <= aff0_EXMPLR79(2) ;
   aff0(1) <= aff0_EXMPLR79(1) ;
   aff0(0) <= aff0_EXMPLR79(0) ;
   aff1(6) <= aff1_EXMPLR80(6) ;
   aff1(5) <= aff1_EXMPLR80(5) ;
   aff1(4) <= aff1_4_EXMPLR44 ;
   aff1(3) <= aff1_3_EXMPLR45 ;
   aff1(2) <= aff1_2_EXMPLR46 ;
   aff1(1) <= aff1_1_EXMPLR47 ;
   aff1(0) <= aff1_0_EXMPLR48 ;
   aff2(6) <= aff2_EXMPLR81(6) ;
   aff2(5) <= aff2_EXMPLR81(5) ;
   aff2(4) <= aff2_EXMPLR81(4) ;
   aff2(3) <= aff2_EXMPLR81(3) ;
   aff2(2) <= aff2_EXMPLR81(2) ;
   aff2(1) <= aff2_EXMPLR81(1) ;
   aff2(0) <= aff2_EXMPLR81(0) ;
   aff3(6) <= aff3_EXMPLR82(6) ;
   aff3(5) <= aff3_EXMPLR82(5) ;
   aff3(4) <= aff3_EXMPLR82(4) ;
   aff3(3) <= aff3_EXMPLR82(3) ;
   aff3(2) <= aff3_EXMPLR82(2) ;
   aff3(1) <= aff3_EXMPLR82(1) ;
   aff3(0) <= aff3_EXMPLR82(0) ;
   aff4(6) <= aff4_EXMPLR83(6) ;
   aff4(5) <= aff4_EXMPLR83(5) ;
   aff4(4) <= aff4_EXMPLR83(4) ;
   aff4(3) <= aff4_EXMPLR83(3) ;
   aff4(2) <= aff4_EXMPLR83(2) ;
   aff4(1) <= aff4_EXMPLR83(1) ;
   aff4(0) <= aff4_EXMPLR83(0) ;
   aff5(6) <= aff5_EXMPLR84(6) ;
   aff5(5) <= aff5_EXMPLR84(5) ;
   aff5(4) <= aff5_EXMPLR84(4) ;
   aff5(3) <= aff5_EXMPLR84(3) ;
   aff5(2) <= aff5_EXMPLR84(2) ;
   aff5(1) <= aff5_EXMPLR84(1) ;
   aff5(0) <= aff5_EXMPLR84(0) ;
   aff5_dup_0_0 <= NOT m_dup_0(1);
   aff1_dup_0(6) <= '1';
   aff1_dup_0(5) <= '0';
   rst_ibuf : cycloneii_io
      generic map (operation_mode => "input",
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( combout=>rst_int, padio=>rst_EXMPLR31);
   reg_mm_1 : cycloneii_lcell_ff port map ( regout=>m_dup_0(1), datain=>
      mode_int(1), clk=>clk_int, ena=>dtr_int, aclr=>rst_int);
   reg_mm_0 : cycloneii_lcell_ff port map ( regout=>m_dup_0(0), datain=>
      mode_int(0), clk=>clk_int, ena=>dtr_int, aclr=>rst_int);
   mode_ibuf_1 : cycloneii_io
      generic map (operation_mode => "input",
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( combout=>mode_int(1), padio=>mode_EXMPLR77(1));
   mode_ibuf_0 : cycloneii_io
      generic map (operation_mode => "input",
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( combout=>mode_int(0), padio=>mode_EXMPLR77(0));
   m_obuf_1 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>m_EXMPLR78(1), datain=>m_dup_0(1));
   m_obuf_0 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>m_EXMPLR78(0), datain=>m_dup_0(0));
   dtr_ibuf : cycloneii_io
      generic map (operation_mode => "input",
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( combout=>dtr_int, padio=>dtr_EXMPLR30);
   clk_ibuf : cycloneii_io
      generic map (operation_mode => "input",
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( combout=>clk_int, padio=>clk_EXMPLR32);
   aff5_obuf_6 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff5_EXMPLR84(6), datain=>aff1_dup_0(5));
   aff5_obuf_5 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff5_EXMPLR84(5), datain=>aff1_dup_0(5));
   aff5_obuf_4 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff5_EXMPLR84(4), datain=>aff1_dup_0(5));
   aff5_obuf_3 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff5_EXMPLR84(3), datain=>aff1_dup_0(6));
   aff5_obuf_2 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff5_EXMPLR84(2), datain=>m_dup_0(1));
   aff5_obuf_1 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff5_EXMPLR84(1), datain=>m_dup_0(1));
   aff5_obuf_0 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff5_EXMPLR84(0), datain=>aff5_dup_0_0);
   aff4_obuf_6 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff4_EXMPLR83(6), datain=>aff1_dup_0(5));
   aff4_obuf_5 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff4_EXMPLR83(5), datain=>aff1_dup_0(6));
   aff4_obuf_4 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff4_EXMPLR83(4), datain=>aff1_dup_0(5));
   aff4_obuf_3 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff4_EXMPLR83(3), datain=>aff1_dup_0(5));
   aff4_obuf_2 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff4_EXMPLR83(2), datain=>aff1_dup_0(5));
   aff4_obuf_1 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff4_EXMPLR83(1), datain=>aff1_dup_0(5));
   aff4_obuf_0 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff4_EXMPLR83(0), datain=>aff1_dup_0(6));
   aff3_obuf_6 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff3_EXMPLR82(6), datain=>aff1_dup_0(6));
   aff3_obuf_5 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff3_EXMPLR82(5), datain=>aff1_dup_0(6));
   aff3_obuf_4 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff3_EXMPLR82(4), datain=>aff1_dup_0(6));
   aff3_obuf_3 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff3_EXMPLR82(3), datain=>aff1_dup_0(6));
   aff3_obuf_2 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff3_EXMPLR82(2), datain=>nx59866z1);
   aff3_obuf_1 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff3_EXMPLR82(1), datain=>nx59866z1);
   aff3_obuf_0 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff3_EXMPLR82(0), datain=>aff1_dup_0(6));
   aff2_obuf_6 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff2_EXMPLR81(6), datain=>aff1_dup_0(5));
   aff2_obuf_5 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff2_EXMPLR81(5), datain=>aff2_dup_0_2);
   aff2_obuf_4 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff2_EXMPLR81(4), datain=>m_dup_0(1));
   aff2_obuf_3 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff2_EXMPLR81(3), datain=>m_dup_0(1));
   aff2_obuf_2 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff2_EXMPLR81(2), datain=>aff2_dup_0_2);
   aff2_obuf_1 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff2_EXMPLR81(1), datain=>aff1_dup_0(5));
   aff2_obuf_0 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff2_EXMPLR81(0), datain=>m_dup_0(1));
   aff1_obuf_6 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff1_EXMPLR80(6), datain=>aff1_dup_0(6));
   aff1_obuf_5 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff1_EXMPLR80(5), datain=>aff1_dup_0(5));
   aff1_obuf_4 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff1_4_EXMPLR44, datain=>aff1_dup_0(5));
   aff1_obuf_3 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff1_3_EXMPLR45, datain=>aff1_dup_0(5));
   aff1_obuf_2 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff1_2_EXMPLR46, datain=>aff1_dup_0(5));
   aff1_obuf_1 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff1_1_EXMPLR47, datain=>aff1_dup_0(5));
   aff1_obuf_0 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff1_0_EXMPLR48, datain=>aff1_dup_0(5));
   aff0_obuf_6 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff0_EXMPLR79(6), datain=>aff1_dup_0(6));
   aff0_obuf_5 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff0_EXMPLR79(5), datain=>aff1_dup_0(5));
   aff0_obuf_4 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff0_EXMPLR79(4), datain=>aff1_dup_0(5));
   aff0_obuf_3 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff0_EXMPLR79(3), datain=>aff1_dup_0(5));
   aff0_obuf_2 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff0_EXMPLR79(2), datain=>aff1_dup_0(5));
   aff0_obuf_1 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff0_EXMPLR79(1), datain=>aff1_dup_0(5));
   aff0_obuf_0 : cycloneii_io
      generic map (operation_mode => "output"
         ,
         output_register_mode => "none"
         ,
         tie_off_output_clock_enable => "false",
         oe_register_mode => "none",
         tie_off_oe_clock_enable => "false",
         input_register_mode => "none") 
       port map ( padio=>aff0_EXMPLR79(0), datain=>aff1_dup_0(5));
   ix59866z52923 : cycloneii_lcell_comb
      generic map (lut_mask => X"bbbb") 
       port map ( combout=>nx59866z1, dataa=>m_dup_0(1), datab=>m_dup_0(0));
   ix51444z52923 : cycloneii_lcell_comb
      generic map (lut_mask => X"4444") 
       port map ( combout=>aff2_dup_0_2, dataa=>m_dup_0(1), datab=>
      m_dup_0(0));
end beh_display ;

