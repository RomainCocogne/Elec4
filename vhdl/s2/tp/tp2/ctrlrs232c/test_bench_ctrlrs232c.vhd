library ieee;
	use ieee.std_logic_1164.all;
	use ieee.std_logic_unsigned.all;

entity test is
end entity;

architecture bench_ctrlrs232c of test is

component ctrlrs232c is
	port(
		dsr: out std_logic;
		cts: out std_logic;
		mam: out std_logic;
		mad: out std_logic;
		rst, clk :	in std_logic;
		m, dtr, rts: in std_logic
	);
end component;



--for UUT1:ctrlrs232c use entity work.ctrlrs232c(moore);
--for UUT2:ctrlrs232c_comb use entity work.ctrlrs232c(moore);

signal clk:	std_logic:='0';
signal dtr, rst: std_logic;
signal m, rts, mam, mad, dsr, cts: std_logic;
begin
	UUT1:ctrlrs232c 
	port map (
		clk=>clk, 
		rst=>rst,
		m => m,
		dtr => dtr,
		rts => rts, 
		mam=> mam,
		mad=>mad,
		dsr => dsr,
		cts=> cts);
		rst <= '0', '1' after 3 ns;
	clk <= not clk after 12.5 ns;
	dtr <= '1', '0' after 75 ns, '1' after 125 ns, '0' after 175 ns ;
	rts <= '1', '0' after 90 ns;
	m <= '0', '1' after 180 ns;
		
end architecture;
