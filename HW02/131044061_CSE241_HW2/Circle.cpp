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

void Circle::set_radius(int &r) {
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

void Circle::set_coords(double &p_x, double &p_y) {
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

/*string Circle::get_fill() const {
	return fill;
}*/

string Circle::get_stroke() const {
	return stroke;
}

void Circle::draw(ofstream & ofs) const {
	ofs<<get_idntfy()<<" "<<get_coord_x()<<get_pos_x()<<"' "<<get_coord_y()<<get_pos_y()<<"' "
			<<get_rad()<<get_radius()<<"' "<<get_stroke()<<fill<<endl;
}


