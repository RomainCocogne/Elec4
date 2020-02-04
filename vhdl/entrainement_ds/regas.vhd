library ieee;
	use ieee.std_logic_1164.all;
	use ieee.std_logic_unsigned.all;

entity regas is
	port (
		a,b:	std_logic_vector (7 downto 0);
		s,ld,h:	std_logic;
		f:	out std_logic_vector (7 downto 0)
	);
end entity;

architecture dataflow of regas is
	constant tco:	time:= 3 ns;
	constant tcomb:	time:= 6 ns;
	signal as:	std_logic_vector (7 downto 0);
begin
	as <= a+b after tcomb when s = '0' else a-b after tcomb;
	f <= as after tco when ld = '1' and h='1' and h'event;
end architecture;