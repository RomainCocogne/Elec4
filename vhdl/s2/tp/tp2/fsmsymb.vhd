library ieee;
	use ieee.std_logic_1164.all;
	use ieee.std_logic_unsigned.all;

--entity ctrlrs232c is
--	port(
--		dsr: out std_logic;
--		cts: out std_logic;
--		mam: out std_logic;
--		mad: out std_logic;
--		rst, clk :	in std_logic;
--		m, dtr, rts: in std_logic;
--	);
--end entity;

architecture symb of ctrlrs232c is
	type DEFETAT is (CONFIG, RECEP, EMIS, FD);
	signal etat_courrant : DEFETAT;
	signal etat_suivant : DEFETAT;
begin
	seq: process (clk, rst)
	begin
		if rst ='0' then 
			etat_courrant <= CONFIG;
			dsr <= '1';
			cts <= '0';
			mam <= '0';
			mad <= '0';
	   	elsif clk'event and clk = '1' and dtr = '1' then
			etat_courrant <= etat_suivant;
		end if;
	end process;


	suivant: process (etat_courrant)
	begin
		case (etat_courrant) is
			when CONFIG =>
				if dtr = '1' then 
					etat_suivant <= CONFIG
				elsif m = '1' then
					etat_suivant <= FD;
				else
					etat_suivant <= RECEP;
				end if;

			when FD =>
				if dtr = '1' then 
					etat_suivant <= CONFIG;
				else
					etat_suivant <= FD;
				end if;

			when RECEP =>
				if dtr = '1' then 
					etat_suivant <= CONFIG;
				elsif rts = '0' then 
					etat_suivant <= EMIS;
				else
					etat_suivant <= RECEP;
				end if;

			when EMIS =>
				if dtr = '1' then 
					etat_suivant <= CONFIG;
				elsif rts = '0' then 
					etat_suivant <= EMIS;
				else
					etat_suivant <= RECEP;
				end if;
		end case;
	end process;

	sorties: process (etat_courrant)
	begin
		case (etat_courrant) is
			when CONFIG =>
				mad <= '0';
				mam <= '0';
				dsr <= '1';

			when FD =>
				mad <= '1';
				mam <= '1';
				dsr <= '0';

			when RECEP =>
				mad <= '1';
				mam <= '0';
				cts <= '1';
				dsr <= '0';

			when EMIS =>
				mad <= '0';
				mam <= '1';
				cts <= '0';
				dsr <= '0';
		end case; 
	end process;

end architecture symb;