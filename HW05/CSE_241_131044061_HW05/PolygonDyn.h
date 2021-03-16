#include<vector>
#include<iostream>
#include<string>
#ifndef POLYGONDYN_H_
#define POLYGONDYN_H_
#include"Rectangle.h"
#include"Circle.h"
#include"Triangle.h"
#include "Polygon.h"
namespace gtuShape {

class PolygonDyn: public Polygon {
public:
	PolygonDyn();
	PolygonDyn(Rectangle &);
	PolygonDyn(Circle &);
	PolygonDyn(Triangle &);

	/*big tree*/
	PolygonDyn(const PolygonDyn &);
	~PolygonDyn();
	PolygonDyn& operator=(const PolygonDyn &);

	void set_ArrSize(int size) {coordsArrSize = size;}
	int get_ArrSize() const {return coordsArrSize;}
	void set_coords(const Point2D *, int, int);
	Point2D* get_coords() const {return coords;}
	const Point2D operator[](int);

	const int get_which() const{return 6;}
	void draw(ofstream &);
	const int whichShape() const{return -1;};
	const double area() const;
	const double perimeter() const;
	const Shape& operator ++();
	const Shape& operator ++(int);
	const Shape& operator --();
	const Shape& operator --(int);


private:
	Point2D *coords;
	int coordsArrSize, which;
	Rectangle rect;
	Circle circ;
	Triangle tri;
};

}
#endif
