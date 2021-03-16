#include<string>
#include <iostream>
#include "Triangle.h"
#include<cmath>
#include<cstdlib>
#include<fstream>
using namespace std;

Triangle::Triangle() {
	line = 0;
}

void Triangle::set_line(int l) {
	if(l>0){
		line = l;
	}
	else{
		cout<<"triangle olusmadi"<<endl;
	}
}

int Triangle::get_line() const {
	return line;
}

double Triangle::find_height() {
	height = sqrt(3)* (line/2);
	return height;
}

void Triangle::set_points(double p1_x, double p1_y, double p2_x,
		double p2_y, double p3_x, double p3_y) {
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
		cout<<"triangle koordinantlar hatali"<<endl;
	}
}


double Triangle::get_point_x(int index) const {
	return points[index][0];
}

double Triangle::get_point_y(int index) const {
	return points[index][1];
}

const double Triangle::area() {
	return (double)get_line() * find_height() / 2;
}

const double Triangle::lenght() {
	return (double)get_line() * 3;
}

const bool Triangle::operator ==(Triangle& other) {
	return this->area() == other.area();
}

const bool Triangle::operator !=(Triangle& other) {
	return !(this->area() == other.area());
}

const Triangle Triangle::operator +(double num) {
	Triangle temp;
	temp.set_line(this->get_line() + num);
	return temp;
}

const Triangle Triangle::operator -(double num) {
	Triangle temp;
	temp.set_line(this->get_line() + num);
	return temp;
}

int Triangle::get_numOfShape() {
	numOfShape++;
	return numOfShape;
}

double Triangle::result_area(Triangle &tri) {
	return numOfShape * tri.area();
}

ofstream& operator <<(ofstream& ofs, const Triangle& tri) {
	ofs<<tri.get_idntfy()<<tri.get_point_x(0)<<" "<<tri.get_point_y(0)<<" "<<tri.get_point_x(1)
			<<" "<<tri.get_point_y(1)
			<<" "<<tri.get_point_x(2)<<" "<<tri.get_point_y(2)<<"' "<<tri.get_stroke()<<tri.fill<<endl;
	return ofs;
}

string Triangle::get_idntfy() const {
	return idntfy;
}

string Triangle::get_stroke() const {
	return stroke;
}

void Triangle::draw(ofstream & ofs) const {
	ofs<<*this;
}

int Triangle::reset_numOfShape() {
	numOfShape = 0;
	return numOfShape;
}






