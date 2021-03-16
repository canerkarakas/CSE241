#include<string>
#include<fstream>
#include <iostream>
#ifndef RECTANGLE_H_
#define RECTANGLE_H_
using namespace std;

class Rectangle {
public:
	Rectangle();

	void set_lines(int, int);
	int get_width() const;
	int get_height() const;
	void set_coords(double, double);
	double get_pos_x() const;
	double get_pos_y() const;
	void draw(ofstream &) const;
	const double area();
	const double lenght();
	const Rectangle operator +(double);
	const Rectangle operator -(double);
	const Rectangle operator ++();
	const Rectangle operator ++(int);
	const Rectangle operator --();
	const Rectangle operator --(int);
	const bool operator ==(Rectangle &);
	const bool operator !=(Rectangle &);
	static int get_numOFShape();
	static int reset_numOfShape();
	static double result_area(Rectangle &);
	string get_idntfy() const;
	string get_coord_x() const;
	string get_coord_y() const;
	string get_width_word() const;
	string get_height_word() const;
	string get_stroke() const;
	string fill = "fill='yellow'/>";

friend ofstream& operator <<(ofstream &, const Rectangle &);

private:
	static int numOfShape;
	int width, height;
	double pos_x, pos_y;
	string idntfy = "<rect ";
	string coord_x = "x='";
	string coord_y = "y='";
	string width_word = "width='";
	string height_word = "height='";
	string stroke = " stroke='black' stroke-width='0.05' ";
};

#endif
