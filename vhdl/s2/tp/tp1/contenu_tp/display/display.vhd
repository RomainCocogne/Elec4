library ieee;
	use ieee.std_logic_1164.all;
	use ieee.std_logic_unsigned.all;

entity display is
	port(
		dsr: out std_logic;
		cts: out std_logic;
		mam: out std_logic;
		mad: out std_logic;
		rst, clk:	std_logic;
		m, dtr, rts:	std_logic;
	);
end entity;

architecture behavioral of display is
	type DEFETAT is (CONFIG, RECEP, EMIS, FD);
begin

end architecture behavioral;