#include<iostream>
#include<cmath>
#include<string>
#include "PolygonDyn.h"

namespace gtuShape {

PolygonDyn::PolygonDyn() {

}

PolygonDyn::PolygonDyn(Rectangle& rectangle) {
	rect = rectangle;
	which = rectangle.whichShape();
	rect.fill = rectangle.fill;
	rect.set_idntfy(rectangle.get_idntfy());
	rect.set_coord_x(rectangle.get_idntfy());
	rect.set_coord_y(rectangle.get_idntfy());
	rect.set_width_word(rectangle.get_idntfy());
	rect.set_height_word(rectangle.get_idntfy());
	rect.set_stroke(rectangle.get_stroke());
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

PolygonDyn::PolygonDyn(Circle& circle) {
	circ = circle;
	which = circle.whichShape();
	circ.set_idntfy(circle.get_idntfy());
	circ.set_coord_x(circle.get_coord_x());
	circ.set_coord_y(circle.get_coord_y());
	circ.set_rad(circle.get_rad());
	circ.set_stroke(circle.get_stroke());
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

PolygonDyn::PolygonDyn(Triangle& triangle) {
	tri = triangle;
	which = triangle.whichShape();
	tri.set_idntfy(triangle.get_idntfy());
	tri.set_stroke(triangle.get_stroke());
	set_ArrSize(3);
	coords = new Point2D[get_ArrSize()];
	int i;
	for(i=0;i<3;++i){
		coords[i].set_x(tri.get_point_x(i));
		coords[i].set_y(tri.get_point_y(i));
	}
}

PolygonDyn::PolygonDyn(const PolygonDyn& other) {
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

PolygonDyn& PolygonDyn::operator =(const PolygonDyn& other) {
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


void PolygonDyn::set_coords(const Point2D* crd, int size, int index) {
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

void PolygonDyn::draw(ofstream& os) {
	os<<"<polygon points='";
	int i;
	for(i=0;i<coordsArrSize;++i){
		os<<" "<<coords[i].get_x()<<" "<<coords[i].get_y()<<" ";
	}
	if(which==1)
		os<<"' "<<rect.get_stroke()<<" "<<rect.fill<<endl;
	if(which==2)
		os<<"' "<<circ.get_stroke()<<" "<<circ.fill<<endl;;
	if(which==3)
		os<<"' "<<tri.get_stroke()<<" "<<tri.fill<<endl;
}

const Polygon::Point2D PolygonDyn::operator [](int index) {
	if(index>=0 && index<this->coordsArrSize)
		return coords[index];
}

const double PolygonDyn::area() const {
	double result;
	switch(which){
	case 1: result = rect.area();break;
	case 2: result = circ.area();break;
	case 3: result = tri.area();break;
	}
	return result;
}

const double PolygonDyn::perimeter() const {
	double result;
	switch(which){
	case 1: result = rect.perimeter();break;
	case 2: result = circ.perimeter();break;
	case 3: result = tri.perimeter();break;
	}
	return result;
}

const Shape& PolygonDyn::operator ++() {
	int i;
	for(i=0;i<coordsArrSize;++i){
		coords[i].set_x(coords[i].get_x() + 1);
		coords[i].set_y(coords[i].get_x() + 1);
	}
	return *this;
}

const Shape& PolygonDyn::operator ++(int ignore) {
	Point2D *temp;
	temp = coords;
	int i;
	for(i=0;i<coordsArrSize;++i){
		coords[i].set_x(coords[i].get_x() + 1);
		coords[i].set_y(coords[i].get_x() + 1);
	}
	return *this;
}

const Shape& PolygonDyn::operator --() {
	int i;
	for(i=0;i<coordsArrSize;++i){
		coords[i].set_x(coords[i].get_x() - 1);
		coords[i].set_y(coords[i].get_x() - 1);
	}
	return *this;
}

const Shape& PolygonDyn::operator --(int ignore) {
	Point2D *temp;
	temp = coords;
	int i;
	for(i=0;i<coordsArrSize;++i){
		coords[i].set_x(coords[i].get_x() - 1);
		coords[i].set_y(coords[i].get_x() - 1);
	}
	return *this;
}

PolygonDyn::~PolygonDyn() {
	if(coordsArrSize!=0){
		coordsArrSize = 0;
		delete [] coords;
	}
}

}
