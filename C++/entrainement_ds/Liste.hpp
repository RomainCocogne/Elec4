#pragma once

template <typename T>
class Liste
{
public:
	Liste();
	virtual ~Liste();
	
	virtual int longueur ()const = 0;
	virtual void inserer(const T &x,const  int r) = 0;
	virtual void supprimer(const  int r) = 0;
	virtual const T &ieme(int r)const = 0;
};