library ieee;
	use ieee.std_logic_1164.all;
	use ieee.std_logic_unsigned.all;

entity operateur is
	generic (N:	natural :=8);
	port(
		Cin:	std_logic;
		An,Bn:	std_logic_vector(N-1 downto 0);
		S:	std_logic_vector (1 downto 0);
		
		Cout:	out std_logic;
		Gn:	out std_logic_vector (N-1 downto 0)
	);
end entity;

architecture operateur_dataflow of operateur is

component cell is
	port (
		A,B,Cin:	std_logic;
		S:	std_logic_vector (1 downto 0);
		G,Cout:	out std_logic
	);
end component;
	
	signal C:	std_logic_vector(N-1 downto 0);
begin
	cell0: cell port map (A=>An(0), B=>Bn(0), Cin=>Cin, S=>S, G=>Gn(0), Cout=>C(0));
	gene_cells: for i in 1 to N-1 generate
		celli: cell port map (A=>An(i), B=>Bn(i), Cin=>C(i-1), S=>S, G=>Gn(i), Cout=>C(i));
	end generate;
	--celln: cell port map (A=>An(N-1), B=>Bn(N-1), Cin=>C(N-2), S=>S, G=>Gn(N-1), Cout=>Cout);

	Cout <= C(N-1);

end architecture;
