#include<string>
#include<cstdlib>
#include <iostream>
#include<fstream>
#ifndef TRIANGLE_H_
#define TRIANGLE_H_
using namespace std;

class Triangle {
public:
	Triangle();

	void set_line(int);
	int get_line() const;
	double find_height();
	void set_points(double, double, double, double, double, double);
	double get_point_x(int) const;
	double get_point_y(int) const;
	void draw(ofstream &) const;
	const double area();
	const double lenght();
	const Triangle operator +(double);
	const Triangle operator -(double);
	const bool operator ==(Triangle &);
	const bool operator !=(Triangle &);
	static int get_numOfShape();
	static int reset_numOfShape();
	static double result_area(Triangle &);
	string get_idntfy() const;
	string get_stroke() const;
	string fill = "fill='purple'/>";

friend ofstream& operator <<(ofstream &, const Triangle&);

private:
	int line;
	static int numOfShape;
	double height;
	double points[3][2];
	string idntfy = "<polygon points='";
	string stroke = " stroke='black' stroke-width='0.05' ";
};

#endif
