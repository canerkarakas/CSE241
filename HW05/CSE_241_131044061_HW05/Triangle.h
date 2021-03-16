#include<string>
#include<fstream>
#include <iostream>
#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include"Shape.h"

namespace gtuShape {

class Triangle : public Shape{
public:
	Triangle();
	Triangle(double);

	const int whichShape() const {return 3;}
	const double area() const {return (this->get_line()*this->find_height())/2;}
	const double perimeter() const {return 3*line;}
	const double find_height() const;
	static int get_numOfShape(){numOfShape++;return numOfShape;}
	static int reset_numOfShape(){numOfShape = 0;return numOfShape;}
	static double result_area(Triangle &tri){return numOfShape * tri.area();}

	const Triangle& operator ++();
	const Triangle& operator ++(int);
	const Triangle& operator --();
	const Triangle& operator --(int);

	void draw(ofstream &);
	void set_idntfy(string s) {idntfy = s;}
	void set_stroke(string s) {stroke = s;}
	string get_idntfy() const {return idntfy;}
	string get_stroke() const {return stroke;}
	string fill = "fill='purple'/>";


private:
	static int numOfShape;
	string idntfy = "<polygon points='";
	string stroke = " stroke='black' stroke-width='0.05' ";
};

}
#endif
