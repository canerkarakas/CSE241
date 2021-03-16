#include<string>
#include<fstream>
#include <iostream>
#include "Circle.h"
using namespace std;

Circle::Circle() {
	radius = 0;
	pos_x = 0;
	pos_y = 0;

}

void Circle::set_radius(int r) {
	if(r>1){
		radius = r;
	}
	else{
		cout<<"circ olusmadi"<<endl;
	}
}

int Circle::get_radius() const {
	return radius;
}

void Circle::set_coords(double p_x, double p_y) {
	if(p_x >= radius && p_y >= radius){
		pos_x = p_x;
		pos_y = p_y;
	}
	else{
		cout<<"circ koordinant hatasi"<<endl;
	}
}

double Circle::get_pos_x() const {
	return pos_x;
}

double Circle::get_pos_y() const {
	return pos_y;
}

const double Circle::area() {
	return (3.1415) * (double)get_radius() * (double)get_radius();
}

const double Circle::lenght() {
	return 2 * (3.1415) * (double)get_radius();
}

const Circle Circle::operator ++() {
	this->pos_x++;
	this->pos_y++;
	this->set_coords(pos_x, pos_y);
	Circle temp;
	temp.set_coords(pos_x, pos_y);
	return temp;
}

const Circle Circle::operator ++(int pre) {
	++this->pos_x;
	++this->pos_y;
	this->set_coords(pos_x, pos_y);
	Circle temp;
	temp.set_coords(pos_x, pos_y);
	return temp;
}

const Circle Circle::operator --() {
	this->pos_x--;
	this->pos_y--;
	this->set_coords(pos_x, pos_y);
	Circle temp;
	temp.set_coords(pos_x, pos_y);
	return temp;
}

const Circle Circle::operator --(int pre) {
	--this->pos_x;
	--this->pos_y;
	this->set_coords(pos_x, pos_y);
	Circle temp;
	temp.set_coords(pos_x, pos_y);
	return temp;
}

const bool Circle::operator ==(Circle& other) {
	return this->area() == other.area();
}

const bool Circle::operator !=(Circle& other) {
	return !(this->area() == other.area());
}

int Circle::get_numOfShape() {
	numOfShape++;
	return numOfShape;
}

double Circle::result_area(Circle& circ) {
	return numOfShape * circ.area();
}

const Circle Circle::operator +(double num) {
	Circle temp;
	temp.set_radius(this->get_radius() + num);
	return temp;
}

const Circle Circle::operator -(double num) {
	Circle temp;
	temp.set_radius(this->get_radius() + num);
	return temp;
}

ofstream& operator <<(ofstream& ofs, const Circle& circ) {
	ofs<<circ.get_idntfy()<<" "<<circ.get_coord_x()<<circ.get_pos_x()<<"' "<<circ.get_coord_y()
			<<circ.get_pos_y()<<"' "<<circ.get_rad()<<circ.get_radius()<<"' "<<circ.get_stroke()
			<<circ.fill<<endl;
	return ofs;
}

string Circle::get_idntfy() const {
	return idntfy;
}

string Circle::get_coord_x() const {
	return coord_x;
}

string Circle::get_coord_y() const {
	return coord_y;
}

string Circle::get_rad() const {
	return rad;
}

string Circle::get_stroke() const {
	return stroke;
}

void Circle::draw(ofstream & ofs) const {
	ofs<<*this;
}

int Circle::reset_numOfShape() {
	numOfShape = 0;
	return numOfShape;
}






