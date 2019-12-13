#pragma once
#include <ostream>
 class Point 
 {
 private: 
 	double x, y;
 public:
 	Point( const double a=0, const double b=0 ) : x(a), y(b) {}
 	double getX() const{return x;}
 	double getY() const{return y;}
 	void setX( const double x){}
 	void setY( const double y){}
 	double distance( const Point &p) const {return 0;};
 	friend std::ostream& operator << (std::ostream &f, const Point &p){
 		return f;
 	}
 };