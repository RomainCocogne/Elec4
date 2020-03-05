library ieee;
	use ieee.std_logic_1164.all;
	use ieee.std_logic_unsigned.all;

entity display is
	port(
		mode:	std_logic_vector (1 downto 0);
		dtr, rst, clk:	std_logic;
		m:	out std_logic_vector (1 downto 0);
		aff0,aff1,aff2,aff3,aff4,aff5:	out std_logic_vector (6 downto 0)
	);
end entity;

architecture beh_display of display is
signal mm:	std_logic_vector (1 downto 0);
begin
	seq: process (clk, rst)
	begin
		if clk'event and clk = '1' and dtr = '1' then
			mm <= mode;
		end if;
	end process;
	comb: process (mm)
	begin
		aff1 <= "1000000";
		aff0 <= "1000000";
		aff4 <= "0100001";
		case mm is
			when "00" =>
				aff5 <= "0001110";
				aff3 <= "1111111";
				aff2 <= "0011001";
			when "01" =>
				aff5 <= "0001001";
				aff3 <= "1111001";
				aff2 <= "0100100";
			when others =>
				aff5 <= "0001001";
				aff3 <= "1111111";
				aff2 <= "0000000";				
		end case;
	end process;
end architecture;