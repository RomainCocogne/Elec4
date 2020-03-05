library ieee;
	use ieee.std_logic_1164.all;
	use ieee.std_logic_unsigned.all;

entity test is
end entity;

architecture bench_ctrlrs232c of test is

component ctrlrs232c_symb is
	port(
		dsr: out std_logic;
		cts: out std_logic;
		mam: out std_logic;
		mad: out std_logic;
		rst, clk :	in std_logic;
		m, dtr, rts: in std_logic;
	);
end component;

component ctrlrs232c_comb is
	port(
		dsr: out std_logic;
		cts: out std_logic;
		mam: out std_logic;
		mad: out std_logic;
		rst, clk :	in std_logic;
		m, dtr, rts: in std_logic;
	);
end component;

for UUT:ctrlrs232c_symb use entity work.fsmmoore(symb);
for UUT:ctrlrs232c_comb use entity work.fsmsymb(moore);


signal clk:	std_logic:='1';
signal dtr, rst: std_logic;
signal m, rts, mam, mad, dsr, cts: std_logic;
begin
	UUT:ctrlrs232c_comb 
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
end architecture;
