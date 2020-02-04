library ieee;
	use ieee.std_logic_1164.all;
	use ieee.std_logic_unsigned.all;

entity ff is
	generic (tsetup, tco:	time);
	port (
		d, clk, rst, preset:	std_logic;
		q, qb:	out std_logic
	);
end entity;

architecture beh of ff is
begin
	process (clk, rst, preset)
	variable v:	std_logic;
	begin
		assert (rst = '1' or preset = '1') report "viol preset, reset" severity failure;

		if rst = '0' then v := '0';
		elsif preset = '0' then v := '1';
		elsif clk = '1' and clk'event then 
			assert d'stable(tsetup) report "viol tps setup" severity note ;
			v := d;
		end if;

		q	<=	v after tco;
		qb	<=	not v after tco;
	end process;

end architecture;
