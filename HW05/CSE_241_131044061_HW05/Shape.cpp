#include<iostream>
#include<cmath>
#include "Shape.h"

namespace gtuShape {

Shape::Shape() {
}

const bool Shape::operator ==(Shape& other) {
	return this->area() == other.area();
}

const bool Shape::operator !=(Shape& other) {
	return !(this->area() == other.area());
}

void Shape::set_coords(double x, double y) {
	if(x>=0 && y>=0){
		pos_x = x;
		pos_y = y;
	}
	else{
		std::cout<<"shape olusmadi"<<std::endl;
	}
}

void Shape::set_points(double p1_x, double p1_y, double p2_x,
		double p2_y, double p3_x, double p3_y) throw() {
	try{
		double line1 = sqrt(((p1_x-p2_x)*(p1_x-p2_x)) + ((p1_y-p2_y)*(p1_y-p2_y)));
		double line2 = sqrt(((p1_x-p3_x)*(p1_x-p3_x)) + ((p1_y-p3_y)*(p1_y-p3_y)));
		double line3 = sqrt(((p3_x-p2_x)*(p3_x-p2_x)) + ((p3_y-p2_y)*(p3_y-p2_y)));
		if(line1<=line || line2<=line || line3<=line){
			points[0][0] = p1_x;
			points[0][1] = p1_y;
			points[1][0] = p2_x;
			points[1][1] = p2_y;
			points[2][0] = p3_x;
			points[2][1] = p3_y;
		}
		else{
			throw(p1_x);
			throw(p1_y);
			throw(p2_x);
			throw(p2_y);
			throw(p3_x);
			throw(p3_y);
		}
	}
	catch(double n){
		std::cout<<"cannot doing object"<<std::endl;
		line = 0;
	}
}

void Shape::set_line(double l) throw() {
	try{
		if(l>0){
			line = l;
		}
		else{
			throw(l);
		}
	}
	catch(double n){
		cout<<"triangle olusmadi"<<endl;
		line = 0;
	}
}
/*
Shape::~Shape() {
}*/

}
