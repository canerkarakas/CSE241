#include<string>
#include<fstream>
#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle() {
	width = 0;
	height = 0;
	pos_x = 0;
	pos_y = 0;
}

void Rectangle::set_lines(int &w, int &h) {
	if(w>1 && h>1){
		width = w;
		height = h;
	}
	else{
		cout<<"rect set etmedi"<<endl;
	}
}

int Rectangle::get_width() const {
	return width;
}

int Rectangle::get_height() const {
	return height;
}

void Rectangle::set_coords(double &p_x, double &p_y) {
	if(p_x>=0.0 && p_y>=0.0){
		pos_x = p_x;
		pos_y = p_y;
	}
	else{
		cout<<"rect koordinantlar set olmadi"<< endl;
	}
}

double Rectangle::get_pos_x() const {
	return pos_x;
}

double Rectangle::get_pos_y() const {
	return pos_y;
}

string Rectangle::get_idntfy() const {
	return idntfy;
}

string Rectangle::get_coord_x() const {
	return coord_x;
}

string Rectangle::get_coord_y() const {
	return coord_y;
}

/*string Rectangle::get_fill() const {
	return fill;
}*/

string Rectangle::get_width_word() const {
	return width_word;
}

string Rectangle::get_height_word() const {
	return height_word;
}

string Rectangle::get_stroke() const {
	return stroke;
}

void Rectangle::draw(ofstream & ofs) const {
	ofs<<get_idntfy()<<" "<<get_width_word()<<get_width()<<"' "<<get_height_word()<<get_height()<<"' "
			<<get_coord_x()<<get_pos_x()<<"' "<<get_coord_y()<<get_pos_y()<<"' "<<get_stroke()
			<<fill<<endl;
}



