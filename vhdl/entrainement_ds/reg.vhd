entity reg is
	generic (N:	natural:=8);
	port (
		e:	bit_vector (N-1 downto 0);
		s:	bit_vector (1 downto 0);
		il,ir,h:	bit;
		q:	out bit_vector (N-1 downto 0)
	);
end entity;

architecture beh of reg is

begin
process (h)
	variable v:	bit_vector (N-1 downto 0);
begin
	if h = '1' and h'event then
		case s is
			when "01" =>	v:=e;
			when "10" =>	v:=v(N-2 downto 0)&ir;
			when "11" =>	v:=il&v(N-1 downto 1);
			when others => null;
		end case;
	end if;
	q<=v;
end process;
end architecture;

architecture dataflow of reg is
	constant tcomb:	time:=3 ns;
	constant tco:	time:=3 ns;
	signal qint,sl,sr,m:	bit_vector (N-1 downto 0);
begin
	sl <= qint(N-2 downto 0)&ir;
	sr <= il&qint(N-1 downto 1);
	
	m <= e after tcomb when s="01" else sl after tcomb when s="10" else sr after tcomb when s="11";
	qint <= m after tco when h='1' and h'event;
	q <= qint;
end architecture;













