
entity transcodeur is
	port (
		e0,e1,e2:	bit;
		s0,s1,s2:	out bit
	);
end entity;

architecture beh of transcodeur is

begin
process
begin
	s0 <= '0';
	s1 <= '0';
	s2 <= '0';
	case e2&e1&e0 is
		when "000" =>	s0 <= '0';
		when "001" =>	s0 <='1';	
		when "010" =>	s0 <='1';	s1 <='1';		
		when "011" =>	s1 <='1';		
		when "100" =>	s1 <='1';	s2 <='1';		
		when "101" =>	s0 <='1';	s1 <='1';	s2 <='1';		
		when "110" =>	s0 <='1';	s2 <='1';		
		when "111" =>	s2 <='1';		
	end case;
end process;
end architecture;