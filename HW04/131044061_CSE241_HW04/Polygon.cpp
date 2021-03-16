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
#include "Polygon.h"

namespace POLY{

Polygon::Point2D::Point2D(){
	Polygon::Point2D::x = 0;
	Polygon::Point2D::y = 0;
}

Polygon::Point2D::Point2D(double x, double y){
	Polygon::Point2D::set_x(x);
	Polygon::Point2D::set_y(y);
}

void Polygon::Point2D::set_x(double x){
	Polygon::Point2D::x = x;
}

void Polygon::Point2D::set_y(double y){
	Polygon::Point2D::y = y;
}

double Polygon::Point2D::get_x()const{
	return Polygon::Point2D::x;
}

double Polygon::Point2D::get_y()const{
	return Polygon::Point2D::y;
}

Polygon::Polygon() {
}

Polygon::Polygon(const vector<Point2D> crds) {
	set_ArrSize(crds.size());
	set_coords(crds);
}

Polygon::Polygon(Rectangle& rect) {
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

Polygon::Polygon(Circle& circ) {
	set_ArrSize(100);
	coords = new Point2D[get_ArrSize()];
	coords[0].set_x(circ.get_pos_x());
	coords[0].set_y(circ.get_pos_y()-circ.get_radius());
	double cons = 3.6*(3.141593/180.0);//radyan cevirisi * 360/100 (100 nokta);
	int i;
	for(i=1;i<25;++i){
		coords[i].set_x(coords[0].get_x() + circ.get_radius()*(sin(cons*i)));
		coords[i].set_y(coords[0].get_y() + (circ.get_radius() - circ.get_radius()*(cos(cons*i))));
	}
	coords[25].set_x(coords[0].get_x()+circ.get_radius());
	coords[25].set_y(coords[0].get_y()+circ.get_radius());
	for(i=26;i<50;++i){
		coords[i].set_x(coords[25].get_x() -(circ.get_radius() - circ.get_radius()*(cos(cons*(i-25)))));
		coords[i].set_y(coords[25].get_y() + circ.get_radius()*(sin(cons*(i-25))));
	}
	coords[50].set_x(coords[25].get_x()-circ.get_radius());
	coords[50].set_y(coords[25].get_y()+circ.get_radius());
	for(i=51;i<75;++i){
		coords[i].set_x(coords[50].get_x() - circ.get_radius()*(sin(cons*(i-50))));
		coords[i].set_y(coords[50].get_y() - (circ.get_radius() - circ.get_radius()*(cos(cons*(i-50)))));
	}
	coords[75].set_x(coords[50].get_x()-circ.get_radius());
	coords[75].set_y(coords[50].get_y()-circ.get_radius());
	for(i=76;i<100;++i){
		coords[i].set_x(coords[75].get_x() + (circ.get_radius() - circ.get_radius()*(cos(cons*(i-75)))));
		coords[i].set_y(coords[75].get_y() - circ.get_radius()*(sin(cons*(i-75))));
	}
}

Polygon::Polygon(Triangle& tri) {
	set_ArrSize(3);
	coords = new Point2D[get_ArrSize()];
	int i;
	for(i=0;i<3;++i){
		coords[i].set_x(tri.get_point_x(i));
		coords[i].set_y(tri.get_point_y(i));
	}
}

Polygon::Polygon(const Polygon& other) {
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

Polygon::~Polygon() {
	if(coordsArrSize!=0){
		coordsArrSize = 0;
		delete [] coords;
	}
}

Polygon& Polygon::operator =(const Polygon& other) {
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

void Polygon::draw(ofstream& os) const {
	os<<*this;
}

void Polygon::set_ArrSize(int size){
	coordsArrSize = size;
}

int Polygon::get_ArrSize() const {
	return coordsArrSize;
}

void Polygon::set_coords(vector<Point2D>crds){
	int i;
	coords = new Point2D[get_ArrSize()];
	for(i=0;i<get_ArrSize();++i){
		coords[i] = crds[i];
	}
}

void Polygon::set_coords(const Polygon::Point2D *crd, int size, int index){
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

Polygon::Point2D* Polygon::get_coords() const {
	return coords;
}

const Polygon::Point2D Polygon::operator [](int index) {
	return get_coords()[index];
}

bool Polygon::operator ==(const Polygon& other) const {
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

bool Polygon::operator !=(const Polygon& other) const {
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

Polygon operator +(const Polygon& pol1, const Polygon& pol2) {
	Polygon temp;
	temp.set_ArrSize(pol1.get_ArrSize() + pol2.get_ArrSize());
	temp.set_coords(pol1.get_coords(), pol1.get_ArrSize(), 0);
	temp.set_coords(pol2.get_coords(), pol2.get_ArrSize(), pol1.get_ArrSize());
	return temp;
}

void Polygon::set_fill(string str) {
	fill = str;
}

string Polygon::get_fill()const {
	return fill;
}

const string Polygon::get_stroke() const {
	return stroke;
}

ofstream& operator <<(ofstream& os, const Polygon& poly) {
	os<<"<polygon points='";
	int i;
	for(i=0;i<poly.get_ArrSize();++i){
		os<<" "<<poly.get_coords()[i].get_x()<<" "<<poly.get_coords()[i].get_y()<<" ";
	}
	os<<"' "<<poly.get_stroke()<<" "<<"stroke-width='0.05' "<<poly.get_fill()<<"/>"<<endl;
	return os;
}

}
