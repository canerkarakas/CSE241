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

void Rectangle::set_lines(int w, int h) {
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

void Rectangle::set_coords(double p_x, double p_y) {
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

const double Rectangle::area() {
	return (double)get_width() * (double)get_height();
}

const double Rectangle::lenght() {
	return 2*((double)get_width() + (double)get_height());
}


const Rectangle Rectangle::operator ++() {
	this->pos_x++;
	this->pos_y++;
	this->set_coords(pos_x, pos_y);
	Rectangle temp;
	temp.set_coords(pos_x, pos_y);
	return temp;
}

const Rectangle Rectangle::operator ++(int pre) {
	++this->pos_x;
	++this->pos_y;
	this->set_coords(pos_x, pos_y);
	Rectangle temp;
	temp.set_coords(pos_x, pos_y);
	return temp;
}

const Rectangle Rectangle::operator --() {
	this->pos_x--;
	this->pos_y--;
	this->set_coords(pos_x, pos_y);
	Rectangle temp;
	temp.set_coords(pos_x, pos_y);
	return temp;
}

const Rectangle Rectangle::operator --(int pre) {
	--this->pos_x;
	--this->pos_y;
	this->set_coords(pos_x, pos_y);
	Rectangle temp;
	temp.set_coords(pos_x, pos_y);
	return temp;
}

const bool Rectangle::operator ==(Rectangle& other) {
	return this->area() == other.area();
}

const bool Rectangle::operator !=(Rectangle& other) {
	return !(this->area() == other.area());
}

ofstream& operator <<(ofstream& ofs, const Rectangle& rect) {
	ofs<<rect.get_idntfy()<<" "<<rect.get_width_word()<<rect.get_width()
			<<"' "<<rect.get_height_word()<<rect.get_height()<<"' "<<rect.get_coord_x()
			<<rect.get_pos_x()<<"' "<<rect.get_coord_y()<<rect.get_pos_y()<<"' "
			<<rect.get_stroke()<<rect.fill<<endl;
	return ofs;
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
	ofs<<*this;
}

const Rectangle Rectangle::operator +(double num) {
	Rectangle temp;
	temp.set_lines((this->get_width()+num), (this->get_height()+num));
	return temp;
}

const Rectangle Rectangle::operator -(double num) {
	Rectangle temp;
	temp.set_lines((this->get_width()-num), (this->get_height()-num));
	return temp;
}

int Rectangle::get_numOFShape() {
	numOfShape++;
	return numOfShape;
}

double Rectangle::result_area(Rectangle & rect) {
	return numOfShape * rect.area();
}







