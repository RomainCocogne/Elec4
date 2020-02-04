entity test is
end test;

architecture bench of test is
	component accumulateur is
	generic (N : natural :=2);
		port (
			rst : bit;
			ld : bit;
			B : natural range 0 to N-1;
			A : out natural range 0 to N-1
		);
	end component;
	for UUT : accumulateur use entity work.accumulateur(beh);
	constant MAX : natural :=16;
	signal rst, clk : bit;
	signal A, B : natural range 0 to MAX;
	begin
		UUT : accumulateur generic map (MAX)
			port map (rst=>rst, ld=>clk,B=>B,A=>A);
		rst <= '1', '0' after 220 ns;
		clk <= not clk after 40 ns;
		B <= 0, 1 after 200 ns, 3 after 550 ns, 0 after 720 ns;
end bench;





























