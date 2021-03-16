#include<fstream>
#include<string>
#ifndef SHAPE_H_
#define SHAPE_H_
using namespace std;

namespace gtuShape {

class Shape {
public:
	Shape();

	virtual void draw(ofstream &) = 0;
	virtual const int whichShape() const = 0;
	virtual const double area() const = 0;
	virtual const double perimeter() const = 0;
	virtual const Shape& operator ++() = 0;
	virtual	const Shape& operator ++(int) = 0;
	virtual	const Shape& operator --() = 0;
	virtual	const Shape& operator --(int) = 0;
	const bool operator ==(Shape &);
	const bool operator !=(Shape &);
	virtual void set_coords(double,double);
	virtual const double get_pos_x() const {return pos_x;}
	virtual const double get_pos_y() const {return pos_y;}

	/*for the triangle, special situation*/
	void set_points(double, double, double, double, double, double) throw();
	void set_line(double) throw();
	const double get_line() const {return line;}
	double get_point_x(int index) const {return points[index][0];}
	double get_point_y(int index) const {return points[index][1];}

	//virtual ~Shape();

protected:
	double points[3][2];
	double pos_x, pos_y;
	double line;

};

}
#endif
