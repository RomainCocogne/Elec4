
entity bit0 is
	port(
		nraz,h:	bit;
		q0,c1:	out bit
	);
end entity;

entity biti is
	port(
		nraz,h,ci:	bit;
		qi,cip1:	out bit
	);
end entity;


architecture rtl of bit0 is
	signal qint:	bit;
begin
	qint <= not qint and nraz when h = '1' and h'event;
	c1 <= qint;
	q0 <= qint;
end rtl;

architecture rtl of biti is
	signal qint:	bit;
begin
	qint <= nraz and (qint xor ci) when h = '1' and h'event;
	cip1 <= qint and ci;
	qi <= qint;
end rtl;
