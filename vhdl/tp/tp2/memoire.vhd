entity mem_control is
	port (
		ready, rw, h, rst:	bit;
		oe,we:			out bit
	);
end entity;


architecture beh_1 of mem_control is

	type defetat is (idle,decision,r,w);
	signal etat: defetat;
begin
	process (h,rst)
	begin
		if rst = '0' then etat <= idle;

		elsif h = '1' and h'event then
			oe <= '0';
			we <= '0';

			case etat is
				when idle => 
					if ready = '1'	then etat <= decision; end if;
				when decision =>
					if rw = '1'	then etat <= r;
					else etat <= w; end if;
				when r =>
					oe <= '1';
					if ready = '1'	then etat <= idle;
					else etat <= r; end if;
				when w => 
					we <= '1';
					if ready = '1'	then etat <= idle;
					else etat <= w; end if;
			end case;

		end if; 
	end process;
end architecture;


architecture beh_2 of mem_control is

	type defetat is (idle,decision,r,w);
	signal etat, netat: defetat;
begin
	m: process (h,rst)
	begin
		if rst='0' then etat <= idle;
		elsif h='1' and h'event then 
			etat <= netat;
		end if;
	end process;

	mem: process (ready, rw, etat)
	begin
		netat <= etat;
		oe <= '0';
		we <= '0';
	
		case etat is
			when idle => 
				if ready = '1' then netat <= decision;  end if;
			when decision =>
				if rw = '1' then netat <= r;
				else netat <= w; end if;
			when r =>
				oe <= '1';
				if ready = '1' then netat <= idle;
				else netat <= r; end if;
			when w => 
				we <= '1';
				if ready = '1' then netat <= idle;
				else netat <= w; end if;
		end case;
	end process;
end architecture;

