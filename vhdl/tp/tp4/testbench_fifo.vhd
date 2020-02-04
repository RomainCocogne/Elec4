library ieee;
	use ieee.std_logic_1164.all;
	use ieee.std_logic_unsigned.all;
entity test is
end entity;

architecture testbench_fifo of test is
component fifo is
	generic (
		deep:	natural :=1;
		wide:	natural :=1
	);
	port (
		rst,rw,enable,h:	std_logic;
		datain:	std_logic_vector (wide-1 downto 0);
		dataout:	out std_logic_vector (wide-1 downto 0);
		full,empty:	out std_logic		
	);
end component;

constant deep:	integer :=2;
constant wide:	integer :=8;

signal rw,enable,full,empty:	std_logic;
signal h:	std_logic :='0';
signal rst:	std_logic :='1';
signal datain, dataout:	std_logic_vector (wide-1 downto 0);

for UUT: fifo use entity work.fifo (rtl);

begin
	UUT: fifo generic map (deep=>deep, wide =>wide) 
		  port map (rst=>rst, rw=>rw, enable=>enable, h=>h, datain=>datain, 
			    dataout=>dataout, full=>full, empty=>empty);

	h	<=	not h after 20 ns;
	rst	<=	'0' after 6 ns;
	
	rw	<=	'1', '0' after 150 ns, '1' after 250 ns, '0' after 325 ns;
	enable	<=	'1';
	datain	<=	"11100000", "00100000" after 45 ns,"00000001" after 75 ns, 
			"01000100" after 90 ns, "01010101" after 290 ns;

		
end architecture;
