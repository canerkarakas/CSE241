#include<vector>
#include<iostream>
#include<string>
#ifndef POLYGONVECT_H_
#define POLYGONVECT_H_
#include"Rectangle.h"
#include"Circle.h"
#include"Triangle.h"
#include "Polygon.h"
using namespace std;

namespace gtuShape {

class PolygonVect: public Polygon {
public:
	PolygonVect();
	PolygonVect(Rectangle &);
	PolygonVect(Circle &);
	PolygonVect(Triangle &);

	const Point2D operator[](int);

	const int get_which() const{return 5;}

	void draw(ofstream &);

	const int whichShape() const{return -1;};
	const double area() const;
	const double perimeter() const;
	const Shape& operator ++();
	const Shape& operator ++(int);
	const Shape& operator --();
	const Shape& operator --(int);

private:
	vector<Point2D>coords;
	int which;
	Rectangle rect;
	Circle circ;
	Triangle tri;
};

}
#endif
