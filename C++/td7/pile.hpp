
#pragma once
#include <string>
#include <iostream>

template <typename T>
class Pile
{
protected:
	virtual std::string toString () = 0;
	void print_pile(std::ostream &st = std::cout){
		st << toString();
	}
public:
	Pile(){}
	virtual ~Pile(){}
	
	virtual bool estVide() const = 0;
	virtual	const T sommet () const = 0;
	virtual	void empiler (T e) = 0;
	virtual void depiler () = 0;

	friend std::ostream& operator << (std::ostream& f, Pile& p){
		p.print_pile(f);
		return f;
	}
};