entity faf is
	port(
		a,b,ci:	bit;
		s:	out bit
	);
end entity;

architecture dataflow of faf is
begin
	s <= a xor b xor ci;
end architecture;