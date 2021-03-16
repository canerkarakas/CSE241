#include <iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include <sstream>
#include"Rectangle.h"
#include"Circle.h"
#include"Triangle.h"

#ifndef POLYGON_H_
#define POLYGON_H_

namespace POLY{

class Polygon {
public:

	class Point2D{
	public:
		Point2D();
		Point2D(double , double);
		void set_x(double );
		void set_y(double );
		double get_x()const;
		double get_y()const;

	private:
		double x, y;
	};

	Polygon();
	Polygon(const vector<Point2D>crds);
	Polygon(Rectangle &);
	Polygon(Circle &);
	Polygon(Triangle &);

	Polygon(const Polygon &);
	~Polygon();
	Polygon& operator=(const Polygon &);


	void draw(ofstream &)const;

	void set_ArrSize(int);
	int get_ArrSize()const;
	void set_coords(const Point2D *, int, int);
	void set_coords(const vector<Point2D>crds);
	Point2D* get_coords()const;
	void set_fill(string);
	string get_fill()const;
	const string get_stroke()const;

	const Point2D operator[](int);
	bool operator==(const Polygon &)const;
	bool operator!=(const Polygon &)const;
	friend Polygon operator+(const Polygon &, const Polygon &);
	friend ofstream& operator<<(ofstream &, const Polygon &);


private:
	string fill;
	const string stroke = "stroke='black'";
	Point2D *coords;
	int coordsArrSize;
};

}

#endif
