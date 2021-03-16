#include<iostream>
#include "Rectangle.h"
using namespace std;

namespace gtuShape {

Rectangle::Rectangle() {
	width = 0;
	height = 0;
}

Rectangle::Rectangle(double w, double h) {
	set_lines(w, h);
}

void Rectangle::set_lines(double w, double h) throw() {
	try{
		if(w>0 && h>0){
			width = w;
			height = h;
		}
		else{
			throw (w);
			throw (h);
		}
	}
	catch(double num){
		std::cout<<"cannot doing object"<<std::endl;
		std::cout<<"your is width num = "<<num<<endl;
		width = 0;
		height = 0;
	}
}

const Rectangle& Rectangle::operator ++() throw() {
	++pos_x;
	++pos_y;
	return *this;
}

const Rectangle& Rectangle::operator ++(int ignore) {
	Rectangle temp(width, height);
	pos_x++;
	pos_y++;
	return temp;
}

const Rectangle& Rectangle::operator --() {
	--pos_x;
	--pos_y;
	return *this;
}

const Rectangle& Rectangle::operator --(int ignore) {
	Rectangle temp(width, height);
	pos_x--;
	pos_y--;
	return temp;
}


void Rectangle::draw(ofstream& os) {
	os<<this->get_idntfy()<<" "<<this->get_width_word()<<this->get_width()
		<<"' "<<this->get_height_word()<<this->get_height()<<"' "<<this->get_coord_x()
		<<this->get_pos_x()<<"' "<<this->get_coord_y()<<this->get_pos_y()<<"' "
		<<this->get_stroke()<<this->fill<<endl;
}


}
