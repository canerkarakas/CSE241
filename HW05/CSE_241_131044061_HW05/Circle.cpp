#include<iostream>
#include "Circle.h"

namespace gtuShape {

Circle::Circle() {
	radius = 0;

}
Circle::Circle(double r) {
	set_radius(r);
}

void Circle::draw(ofstream& os) {
	os<<this->get_idntfy()<<" "<<this->get_coord_x()<<this->get_pos_x()<<"' "<<this->get_coord_y()
				<<this->get_pos_y()<<"' "<<this->get_rad()<<this->get_radius()<<"' "<<this->get_stroke()
				<<this->fill<<endl;
}

void Circle::set_radius(double r) throw() {
	try{
		if(r>0)
			radius = r;
		else
			throw(r);
	}
	catch(double num){
		std::cout<<"cannot doing object"<<std::endl;
		r = 0;
	}
}

const Circle& Circle::operator ++() {
	++pos_x;
	++pos_y;
	return *this;
}

const Circle& Circle::operator ++(int ignore) {
	Circle temp(radius);
	pos_x++;
	pos_y++;
	return temp;
}

const Circle& Circle::operator --() {
	--pos_x;
	--pos_y;
	return *this;
}

const Circle& Circle::operator --(int ignore) {
	Circle temp(radius);
	pos_x--;
	pos_y--;
	return temp;
}

void Circle::set_coords(double x, double y) throw() {
	try{
		if(x >= radius && y >= radius){
			pos_x = x;
			pos_y = y;
		}
		else{
			throw(x);
			throw(y);
		}
	}
	catch(double n){
		std::cout<<"cannot doing object"<<std::endl;
		radius = 0;
		pos_x = 0;
		pos_y = 0;
	}
}


}

