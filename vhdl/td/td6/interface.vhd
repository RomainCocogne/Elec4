library ieee;
	use ieee.std_logic_1164.all;
	use ieee.std_logic_unsigned.all;

entity interfaceslave is
	port (
		valid:		std_logic;
		bus_data:	std_logic_vector (7 downto 0);
		lec_data:	out std_logic;
		buf:		out std_logic_vector (7 downto 0)
	);
end entity;

architecture beh of interfaceslave is
	
begin
	process
	begin
		lec_data	<=	'0';	
		wait until valid = '1';
		lec_data	<=	'1';
		wait for 20 ns;
		buf	<=	bus_data;
		wait for 10 ns;		
	end process;

end architecture;