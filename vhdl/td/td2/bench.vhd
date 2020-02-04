entity test is
end test;

architecture bench of test is
	component latch is
		port (
			d:		bit;
			clk, rst:	bit;
			q,qb:		out bit
		);
	end component;
	
	signal d,clk,rst,q,qb:	bit;
begin
	UUT:	latch port map (d,clk,rst,q,qb);
	clk <= '1' after 5 ns, '0' after 15 ns;
	rst <= '0';
	d <= '1', '0' after 8 ns;

end bench;

