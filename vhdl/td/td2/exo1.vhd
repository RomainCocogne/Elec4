
entity comb is
	port (
		a,b:	bit;
		s:	out bit
	);
end entity;

architecture beh of comb is
	signal x:	bit;
begin
	s <= x and b;
	x <= not a;
end beh;	