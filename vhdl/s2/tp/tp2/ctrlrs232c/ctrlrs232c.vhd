library ieee;
	use ieee.std_logic_1164.all;
	use ieee.std_logic_unsigned.all;

entity ctrlrs232c is
	port(
		dsr: out std_logic;
		cts: out std_logic;
		mam: out std_logic;
		mad: out std_logic;
		rst, clk :	in std_logic;
		m, dtr, rts: in std_logic
	);
end entity;