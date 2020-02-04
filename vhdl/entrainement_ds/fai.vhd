entity fai is
	port(
		a,b,ci:	bit;
		co,s:	out bit
	);
end entity;

architecture alg of fai is

begin
process
begin
	s <= a xor b xor ci;
	co <= (a and b) or (a and ci) or (b and ci);
end process;
end architecture;
