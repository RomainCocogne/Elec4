library ieee;
	use ieee.std_logic_1164.all;
	use ieee.std_logic_unsigned.all;

entity cell is
	port (
		A,B,Cin:	std_logic;
		S:	std_logic_vector (1 downto 0);
		G,Cout:	out std_logic
	);
end entity;

architecture cell_dataflow of cell is
	signal Badd:	std_logic;
	signal Gint:	std_logic_vector(1 downto 0);
begin
	Badd	<=	(S(0) and B) or (S(1) and not B);
	Gint	<=	'0' & A + Badd + Cin;
	G	<=	Gint(0);
	Cout	<=	Gint(1);
end architecture;