#include <iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include <sstream>
#include"Rectangle.h"
#include"Circle.h"
#include"Triangle.h"
#include "Polyline.h"

namespace {

Polyline::Point2D::Point2D(){
	Polyline::Point2D::x = 0;
	Polyline::Point2D::y = 0;
}

Polyline::Point2D::Point2D(double x, double y){
	Polyline::Point2D::set_x(x);
	Polyline::Point2D::set_y(y);
}

void Polyline::Point2D::set_x(double x){
	Polyline::Point2D::x = x;
}

void Polyline::Point2D::set_y(double y){
	Polyline::Point2D::y = y;
}

double Polyline::Point2D::get_x()const{
	return Polyline::Point2D::x;
}

double Polyline::Point2D::get_y()const{
	return Polyline::Point2D::y;
}

Polyline::Polyline() {
}

Polyline::Polyline(const vector<Point2D> crds) {
	set_ArrSize(crds.size());
	set_coords(crds);
}

Polyline::Polyline(Rectangle& rect) {
	set_ArrSize(4);
	coords = new Point2D[get_ArrSize()];
	coords[0].set_x(rect.get_pos_x());
	coords[0].set_y(rect.get_pos_y());
	coords[1].set_x(rect.get_pos_x() + rect.get_width());
	coords[1].set_y(rect.get_pos_y());
	coords[2].set_x(rect.get_pos_x() + rect.get_width());
	coords[2].set_y(rect.get_pos_y() + rect.get_height());
	coords[3].set_x(rect.get_pos_x());
	coords[3].set_y(rect.get_pos_y() + rect.get_height());
}

Polyline::Polyline(Circle& circ) {
	set_ArrSize(100);
	coords = new Point2D[get_ArrSize()];
	coords[0].set_x(circ.get_pos_x()-circ.get_radius());
	coords[0].set_y(circ.get_pos_y());
	int i;
	for(i=1;i<25;++i){
		coords[i].set_x(coords[i-1].get_x() + coords[i-1].get_y() * sin(3.6));
		coords[i].set_y(coords[i-1].get_y() - coords[i-1].get_x() * sin(3.6));
	}
	for(i=25;i<50;++i){
		coords[i].set_x(coords[i-1].get_x() + coords[i-1].get_y() * sin(3.6));
		coords[i].set_y(coords[i-1].get_y() + coords[i-1].get_x() * sin(3.6));
	}
	for(i=50;i<75;++i){
		coords[i].set_x(coords[i-1].get_x() - coords[i-1].get_y() * sin(3.6));
		coords[i].set_y(coords[i-1].get_y() + coords[i-1].get_x() * sin(3.6));
	}
	for(i=50;i<100;++i){
		coords[i].set_x(coords[i-1].get_x() - coords[i-1].get_y() * sin(3.6));
		coords[i].set_y(coords[i-1].get_y() + coords[i-1].get_x() * sin(3.6));
	}
}

Polyline::Polyline(Triangle& tri) {
	set_ArrSize(3);
	coords = new Point2D[get_ArrSize()];
	int i;
	for(i=0;i<3;++i){
		coords[i].set_x(tri.get_point_x(i));
		coords[i].set_y(tri.get_point_y(i));
	}
}

Polyline::Polyline(const Polyline& other) {
	if(other.get_ArrSize()>0){
		coordsArrSize = other.get_ArrSize();
		coords = new Point2D[get_ArrSize()];
		int i;
		for(i=0;i<other.get_ArrSize();++i){
			coords[i] = other.get_coords()[i];
		}
	}
	else{
		coordsArrSize = 0;
		coords = NULL;
	}
}

Polyline::~Polyline() {
	if(coordsArrSize!=0){
		coordsArrSize = 0;
		delete [] coords;
	}
}

Polyline& Polyline::operator =(const Polyline& other) {
	if(other.get_ArrSize()>0){
		coordsArrSize = other.get_ArrSize();
		delete [] coords;
		coords = new Point2D[get_ArrSize()];
		int i;
		for(i=0;i<other.get_ArrSize();++i){
			coords[i] = other.get_coords()[i];
		}
	}
	else{
		coordsArrSize = 0;
		if(coords)
			delete [] coords;
		coords = NULL;
	}
	return *this;
}

void Polyline::draw(ofstream& os) const {
	os<<*this;
}

void Polyline::set_ArrSize(int size){
	coordsArrSize = size;
}

int Polyline::get_ArrSize() const {
	return coordsArrSize;
}

void Polyline::set_coords(vector<Point2D>crds){
	int i;
	coords = new Point2D[get_ArrSize()];
	for(i=0;i<get_ArrSize();++i){
		coords[i] = crds[i];
	}
}

void Polyline::set_coords(const Polyline::Point2D *crd, int size, int index){
	if(index>this->get_ArrSize()){
		cout<<"Error!!"<<endl;
	}
	else{
		int i;
		for(i=0;i<size;++i){
			if(index<this->get_ArrSize()){
				this->coords[index] = crd[i];
				++index;
			}
			else{
				i = size + 1;
			}
		}
	}
}

Polyline::Point2D* Polyline::get_coords() const {
	return coords;
}

const Polyline::Point2D Polyline::operator [](int index) {
	return get_coords()[index];
}

bool Polyline::operator ==(const Polyline& other) const {
	bool result;
	if(other.get_ArrSize() == this->get_ArrSize()){
		int i;
		for(i=0;i<other.get_ArrSize();++i){
			if(other.get_coords()[i].get_x() == this->get_coords()[i].get_x() &&
					other.get_coords()[i].get_y() == this->get_coords()[i].get_y()){
				result = true;
			}
			else{
				result = false;
				i = other.get_ArrSize() + 1;
			}
		}
	}
	else{
		result = false;
	}
	return result;
}

bool Polyline::operator !=(const Polyline& other) const {
	bool result;
	if(other.get_ArrSize() != this->get_ArrSize()){
		int i;
		for(i=0;i<other.get_ArrSize();++i){
			if(other.get_coords()[i].get_x() != this->get_coords()[i].get_x() &&
					other.get_coords()[i].get_y() != this->get_coords()[i].get_y()){
				result = true;
			}
			else{
				result = false;
				i = other.get_ArrSize() + 1;
			}
		}
	}
	else{
		result = false;
	}
	return result;
}

Polyline operator +(const Polyline& pol1, const Polyline& pol2) {
	Polyline temp;
	temp.set_ArrSize(pol1.get_ArrSize() + pol2.get_ArrSize());
	temp.set_coords(pol1.get_coords(), pol1.get_ArrSize(), 0);
	temp.set_coords(pol2.get_coords(), pol2.get_ArrSize(), pol1.get_ArrSize());
	return temp;
}

void Polyline::set_fill(string str) {
	fill = str;
}

string Polyline::get_fill()const {
	return fill;
}

const string Polyline::get_stroke() const {
	return stroke;
}

ofstream& operator <<(ofstream& os, const Polyline& poly) {
	os<<"<polyline points='";
	int i;
	for(i=0;i<poly.get_ArrSize();++i){
		os<<" "<<poly.get_coords()[i].get_x()<<" "<<poly.get_coords()[i].get_y()<<" ";
	}
	os<<"' "<<poly.get_stroke()<<" "<<"stroke-width='0.05' "<<poly.get_fill()<<"/>"<<endl;
	return os;
}

}


