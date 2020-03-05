library ieee;
	use ieee.std_logic_1164.all;
	use ieee.std_logic_unsigned.all;

--entity ctrlrs232c is
--	port(
--		dsr: out std_logic;
--		cts: out std_logic;
--		mam: out std_logic;
--		mad: out std_logic;
--		rst, clk:	std_logic;
--		m, dtr, rts:	std_logic;
--	);
--end entity;

architecture moore of ctrlrs232c is
	subtype DEFETAT is std_logic_vector(1 downto 0);
	constant CONFIG : DEFETAT := "00"; 
	constant FD : DEFETAT := "11"; 
	constant EMIS : DEFETAT := "01"; 
	constant RECEP : DEFETAT := "10"; 

	signal etat_courrant : DEFETAT;
	signal etat_suivant : DEFETAT;
begin
	seq: process (clk, rst)
	begin
		if rst ='0' then 
			etat_courrant <= CONFIG;
	   	elsif clk'event and clk = '1'  then
			etat_courrant <= etat_suivant;
		end if;
	end process;

	mad <= etat_courrant(0);
	mam <= etat_courrant(1);

	suivant: process (etat_courrant, dtr, rts, m)
	begin
	  etat_suivant <= etat_courrant;
		case (etat_courrant) is
			when CONFIG =>
				if dtr = '1' then 
					etat_suivant <= CONFIG;
				elsif m = '1' then
					etat_suivant <= FD;
				else
					etat_suivant <= RECEP;
				end if;
				dsr <= '1';
				cts <= '-';

			when FD =>
				if dtr = '1' then 
					etat_suivant <= CONFIG;
				else
					etat_suivant <= FD;
				end if;
				dsr <= '0';
				cts <= '-';

			when RECEP =>
				if dtr = '1' then 
					etat_suivant <= CONFIG;
				elsif rts = '0' then 
					etat_suivant <= EMIS;
				else
					etat_suivant <= RECEP;
				end if;
				cts <= '1';
				dsr <= '0';

			when EMIS =>
				if dtr = '1' then 
					etat_suivant <= CONFIG;
				elsif rts = '0' then 
					etat_suivant <= EMIS;
				else
					etat_suivant <= RECEP;
				end if;
				cts <= '0';
				dsr <= '0';
				
			when others => null;
		end case;
	end process;
	
end architecture moore;