#include<string>
#include<fstream>
#include <iostream>
#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include"Shape.h"

namespace gtuShape {

class Rectangle : public Shape{
public:
	Rectangle();
	Rectangle(double,double);


	const int whichShape() const {return 1;}
	void set_lines(double,double) throw();
	double get_width() const throw() {return width;}
	double get_height() const throw() {return height;}
	const double area() const throw() {return width*height;}
	const double perimeter() const throw() {return 2*width*height;}
	static int get_numOFShape() {numOfShape++;return numOfShape;}
	static int reset_numOfShape(){numOfShape = 0;return numOfShape;}
	static double result_area(Rectangle &rect){return numOfShape * rect.area();}

	const Rectangle& operator ++() throw();
	const Rectangle& operator ++(int);
	const Rectangle& operator --();
	const Rectangle& operator --(int);

	void draw(ofstream &);
	void set_idntfy(string s)  {idntfy = s;}
	void set_coord_x(string s)  {coord_x = s;}
	void set_coord_y(string s)  {coord_y = s;}
	void set_width_word(string s)  {width_word = s;}
	void set_height_word(string s)  {height_word = s;}
	void set_stroke(string s)  {stroke = s;}
	string get_idntfy() const {return idntfy;}
	string get_coord_x() const {return coord_x;}
	string get_coord_y() const {return coord_y;}
	string get_width_word() const {return width_word;}
	string get_height_word() const {return height_word;}
	string get_stroke() const {return stroke;}
	string fill = "fill='yellow'/>";

private:
	static int numOfShape;
	double width, height;
	string idntfy = "<rect ";
	string coord_x = "x='";
	string coord_y = "y='";
	string width_word = "width='";
	string height_word = "height='";
	string stroke = " stroke='black' stroke-width='0.05' ";
};

}
#endif
