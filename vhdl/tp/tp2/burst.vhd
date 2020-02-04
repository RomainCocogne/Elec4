entity mem_control_burst is
	port (
		ready, rw, h, rst, burst :	bit;
		oe, we :			out bit;
		adr :	out bit_vector (1 downto 0)
	);
end entity;

architecture beh of mem_control_burst is

	type defetat is (idle,decision,r0,r1,r2,r3,w);
	signal etat, netat: defetat;
begin
	m: process (h,rst)
	begin
		if rst='0' then etat <= idle;
		elsif h='1' and h'event then 
			etat <= netat;
		end if;
	end process;
	mem: process (ready, rw, etat, burst)
	begin
		netat <= etat;
		oe <= '0';
		we <= '0';
		case etat is
			when idle => 
				if ready = '1' then netat <= decision;  end if;
			when decision =>
				if rw = '1' then netat <= r0;
				else netat <= w; end if;
			when r0 =>
				oe <= '1';
				adr <= "00";
				if ready = '1' and burst = '1' then netat <= r1;
				elsif ready = '1' and burst = '0' then netat <= idle; end if;
			when r1 =>
				oe <= '1';
				adr <= "01";
				if ready = '1' then netat <= r2; end if;
			when r2 =>
				oe <= '1';
				adr <= "10";
				if ready = '1' then netat <= r3; end if;
			when r3 =>
				oe <= '1';
				adr <= "11";
				if ready = '1' then netat <= idle; end if;
			when w => 
				we <= '1';
				adr <= "00";
				if ready = '1' then netat <= idle; end if;
		end case;
	end process;
end architecture;
