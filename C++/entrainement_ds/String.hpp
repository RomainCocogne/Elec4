#pragma once

#include <iostream>
#include <cstring>
#include "..\td8\IndexException.hpp"

class String
{
private:
	char *s;
	int lg;
public:
	String(char* const str): s(str), lg(strlen(str)){}

	String (const String &str){
		this->s = new char[str.lg+1];
		this->lg=str.lg;
		for (int i = 0; i< str.lg; i++)
			this->s[i]= str.s[i];
		this->s[lg] = '\0';
	}
	~String(){}

	friend std::ostream& operator << (std::ostream &f, String &str){
		for (int i = 0; i < str.lg; ++i)
		{
			f << str.s[i];
		}
		return f;
	}
	char &operator [] (int i){
		if (i <0 || i>=lg) throw IndexException("Index error");
        return this->s[i];
	}

	String &operator= (const String &str){
		this->s = new char[str.lg+1];
		this->lg=str.lg;
		for (int i = 0; i< str.lg; i++)
			this->s[i]= str.s[i];
		this->s[lg] = '\0';
		return *this;
	}
	String operator+ (const String &str) const{
		char * news = new char[this->lg+str.lg+1];
		String nstr (strcat(strcat(news,this->s),str.s));
		return nstr;
	}
};
