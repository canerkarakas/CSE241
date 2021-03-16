
#include "Polygon.h"

namespace gtuShape {

Polygon::Polygon() {


}

gtuShape::Polygon::Point2D::Point2D() {
	Polygon::Point2D::x = 0;
	Polygon::Point2D::y = 0;
}

Polygon::Point2D::Point2D(double x, double y){
	Polygon::Point2D::set_x(x);
	Polygon::Point2D::set_y(y);
}

void Polygon::Point2D::set_x(double x){
	if(x>0)
		Polygon::Point2D::x = x;
}

void Polygon::Point2D::set_y(double y){
	if(y>0)
		Polygon::Point2D::y = y;
}

double Polygon::Point2D::get_x()const{
	return Polygon::Point2D::x;
}

double Polygon::Point2D::get_y()const{
	return Polygon::Point2D::y;
}


/*
Polygon::~Polygon() {

}*/

}
