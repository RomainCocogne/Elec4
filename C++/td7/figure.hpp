#pragma once

#include <string>
#include <iostream>
class Figure
{
protected:
	virtual void print (std::ostream &f) = 0;
public:
	Figure(){}
	virtual ~Figure(){
		std::cout << "destruction figure" << std::endl;
	}
	virtual std::string type(){
		return "Figure";
	}
	virtual double perimetre ()const = 0;
	virtual double surface ()const = 0;
	friend std::ostream& operator << (std::ostream &f,Figure &fi){
		fi.print(f);
		return f;
	}
};