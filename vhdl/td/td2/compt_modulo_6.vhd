entity compteur is
	generic (N:		natural := 6);
	port (
		D:		natural range 0 to N-1;
		ld,clk,rst:	bit;
		Q:		out natural range 0 to N-1
	);
end entity;

architecture beh of compteur is
begin
	process (clk, rst) 
	variable t: natural range 0 to N-1;
	begin
		if rst = '0' then t :=0;
		elsif clk'event and clk = '1' then
			if ld = '0' then 
				t:= (t+1)mod 6;
			else
				t:=D;
			end if;
		end if;
		Q <= t;
	end process;
end architecture;