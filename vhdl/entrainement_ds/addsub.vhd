entity addsub is
	generic (N:	natural:=8);
	port(
		a,b:	bit_vector(N-1 downto 0);
		as:	bit;
		s:	out bit_vector(N-1 downto 0)
	);
end entity;

architecture bah of addsub is 
component fai is
	port(
		a,b,ci:	bit;
		co,s:	out bit
	);
end component;
component faf is
	port(
		a,b,ci:	bit;
		s:	out bit
	);
end component;
	
	signal x0:	bit_vector (N-1 downto 0);
	signal ci:	bit_vector (N-2 downto 0);
begin
	ci(0) <= as;
	xorin: for i in 0 to N-1 generate
		x0(i) <= as xor b(i);
	end generate;
	cellules: for i in 0 to N-2 generate
		celli: fai port map (a=>a(i),b=>x0(i),ci=>ci(i),co=>ci(i+1),s=>s(i));
	end generate;
	cellf: faf port map (a=>a(N-1),b=>x0(N-1),ci=>ci(N-1),s=>s(N-1));

end architecture;