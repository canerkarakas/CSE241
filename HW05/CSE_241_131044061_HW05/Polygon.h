
#ifndef POLYGON_H_
#define POLYGON_H_

#include "Shape.h"

namespace gtuShape {

class Polygon: public Shape {
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

	void set_fill(string s){fill = s;};
	string get_fill()const {return fill;}
	const string get_stroke(){return stroke;}

	//virtual ~Polygon();
protected:
	string fill;
	const string stroke = "stroke='black'";
};

}
#endif
