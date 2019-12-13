#pragma once
#include "Liste.hpp"
template < typename T>
class Pile: public Liste<T>
{
public:
	Pile();
	virtual ~Pile();
	void inserer(const T &x,const  int r) = delete;
	void supprimer(const  int r) = delete;
	const T &ieme(int r)const = delete;

	virtual int estVide() = 0;
	virtual void empiler (const T &x) = 0;
	virtual void depiler () = 0;
	virtual Pile &sommet () = 0;
};