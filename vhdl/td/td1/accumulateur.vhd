entity accumulateur is 
	generic (N : natural :=2);
	port( 
		rst : in bit;
		ld : in bit;
		B : in natural range 0 to N-1;
		A : out natural range 0 to N-1
	);
end accumulateur;

architecture beh of accumulateur is
	begin
	p1: process(rst,ld)
		variable result : natural range 0 to N-1;
		begin
			if rst= '1' then 
				result := 0;
			elsif ld'event and ld= '1' then
				result:= result + B;
			end if;
			A <= result;
	end process;
end behv;
