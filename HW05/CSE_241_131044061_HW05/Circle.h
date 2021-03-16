#include<string>
#include<fstream>
#include <iostream>
#ifndef CIRCLE_H_
#define CIRCLE_H_
#include"Shape.h"

namespace gtuShape {

class Circle : public Shape {
public:
	Circle();
	Circle(double);

	const int whichShape() const {return 2;}
	void set_radius(double) throw();
	double get_radius() const {return radius;}
	void set_coords(double , double ) throw();
	const double area() const {return (3.1415) * radius * radius;}
	const double perimeter() const {return 2 * (3.1415) * radius;}
	static int get_numOfShape(){numOfShape++;return numOfShape;}
	static int reset_numOfShape(){numOfShape = 0;return numOfShape;}
	static double result_area(Circle &circ){return numOfShape * circ.area();}

	const Circle& operator ++();
	const Circle& operator ++(int);
	const Circle& operator --();
	const Circle& operator --(int);

	void draw(ofstream &);
	void set_idntfy(string s) {idntfy = s;}
	void set_coord_x(string s)  {coord_x = s;}
	void set_coord_y(string s) {coord_y = s;}
	void set_rad(string s) {rad = s;}
	void set_stroke(string s) {stroke = s;}
	string get_idntfy() const {return idntfy;}
	string get_coord_x() const {return coord_x;}
	string get_coord_y() const {return coord_y;}
	string get_rad() const {return rad;}
	string get_stroke() const {return stroke;}
	string fill = "fill='green'/>";

private:
	double radius;
	static int numOfShape;
	string idntfy = "<circle ";
	string coord_x = "cx='";
	string coord_y = "cy='";
	string rad = "r='";
	string stroke = " stroke='black' stroke-width='0.05' ";
};

}
#endif
