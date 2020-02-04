library ieee;
	use ieee.std_logic_1164.all;
	use ieee.std_logic_unsigned.all;

entity test is
end entity;

architecture testbench of test is
component operateur is
	generic (N:	natural :=8);
	port(
		Cin:	std_logic;
		An,Bn:	std_logic_vector(N-1 downto 0);
		S:	std_logic_vector (1 downto 0);
		
		Cout:	out std_logic;
		Gn:	out std_logic_vector (N-1 downto 0)
	);
end component;

signal Cin,Cout:	std_logic;
signal An,Bn,Gn:	std_logic_vector (7 downto 0);
signal S:	std_logic_vector(1 downto 0);

begin
	
	UUT: operateur generic map (N =>8) port map (An=>An,Bn=>Bn,Cin=>Cin,Cout=>Cout,Gn=>Gn,S=>S);
	
	An <= "00001001";
	Bn <= "00000010";
	S <= "00", "01" after 10 ns, "11" after 20 ns, "10" after 30 ns, "00" after 40 ns;
	Cin <= '0', '1' after 30 ns;
	
end architecture;
