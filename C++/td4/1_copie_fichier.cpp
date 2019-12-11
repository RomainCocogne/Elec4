#include <iostream>
#include <fstream>
#include <cstdlib>

#define BUFFSIZE 3

void copier (const std::string in, const std::string out){
	std::ifstream fios(in);
	if(!fios.is_open()){
		perror(in.c_str());
		exit(EXIT_FAILURE);
	}
	std::ofstream foos(out);
	if(!foos.is_open()){
		perror(out.c_str());
		exit(EXIT_FAILURE);
	}

	char c;
	while(fios.get(c))
		foos.put(c);

	fios.close();
	foos.close();
}

void copierBuf (const std::string in, const std::string out){
	std::ifstream fios(in);
	if(!fios.is_open()){
		perror(in.c_str());
		exit(EXIT_FAILURE);
	}
	std::ofstream foos(out);
	if(!foos.is_open()){
		perror(out.c_str());
		exit(EXIT_FAILURE);
	}

	while(!fios.eof()){
		char buf[BUFFSIZE];
		fios.read(buf,BUFFSIZE);
		foos.write(buf,fios.gcount());
	}

	fios.close();
	foos.close();
}


int main(int argc, char const *argv[])
{
	std::string fin, fout;
	std::cin >> fin;
	std::cin >> fout;
	copierBuf(fin,fout);
	return 0;
}