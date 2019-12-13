#pragma once

#include "Point.hpp"
#include <vector>
class Polygone
{
private:
	std::vector<Point> sommets;
public:
	Polygone(std::vector<Point> s = {}): sommets(s) {}
	~Polygone();
	
	Point getsommet (int i) const {
		return this->sommets.at(i);
	}
	void setsommet (int i, Point p){
		this->sommets[i]= p;
	}

};