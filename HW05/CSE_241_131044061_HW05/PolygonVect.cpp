#include<iostream>
#include<cmath>
#include<string>
#include "PolygonVect.h"
using namespace std;
namespace gtuShape {

PolygonVect::PolygonVect() {
}

PolygonVect::PolygonVect(Rectangle& rectangle) {
	rect = rectangle;
	which = rectangle.whichShape();
	rect.fill = rectangle.fill;
	rect.set_idntfy(rectangle.get_idntfy());
	rect.set_coord_x(rectangle.get_idntfy());
	rect.set_coord_y(rectangle.get_idntfy());
	rect.set_width_word(rectangle.get_idntfy());
	rect.set_height_word(rectangle.get_idntfy());
	rect.set_stroke(rectangle.get_stroke());
	Point2D temp;
	coords.push_back(temp);
	coords[0].set_x(rect.get_pos_x());
	coords[0].set_y(rect.get_pos_y());
	coords.push_back(temp);
	coords[1].set_x(rect.get_pos_x() + rect.get_width());
	coords[1].set_y(rect.get_pos_y());
	coords.push_back(temp);
	coords[2].set_x(rect.get_pos_x() + rect.get_width());
	coords[2].set_y(rect.get_pos_y() + rect.get_height());
	coords.push_back(temp);
	coords[3].set_x(rect.get_pos_x());
	coords[3].set_y(rect.get_pos_y() + rect.get_height());
}

PolygonVect::PolygonVect(Circle& circle) {
	circ = circle;
	which = circle.whichShape();
	circ.set_idntfy(circle.get_idntfy());
	circ.set_coord_x(circle.get_coord_x());
	circ.set_coord_y(circle.get_coord_y());
	circ.set_rad(circle.get_rad());
	circ.set_stroke(circle.get_stroke());
	Point2D temp;
	temp.set_x(circ.get_pos_x());
	temp.set_y(circ.get_pos_y()-circ.get_radius());
	coords.push_back(temp);
	double cons = 3.6*(3.141593/180.0);//radyan cevirisi * 360/100 (100 nokta);
	int i;
	for(i=1;i<25;++i){
		temp.set_x(coords[0].get_x() + circ.get_radius()*(sin(cons*i)));
		temp.set_y(coords[0].get_y() + (circ.get_radius() - circ.get_radius()*(cos(cons*i))));
		coords.push_back(temp);
	}
	temp.set_x(coords[0].get_x()+circ.get_radius());
	temp.set_y(coords[0].get_y()+circ.get_radius());
	coords.push_back(temp);
	for(i=26;i<50;++i){
		temp.set_x(coords[25].get_x() -(circ.get_radius() - circ.get_radius()*(cos(cons*(i-25)))));
		temp.set_y(coords[25].get_y() + circ.get_radius()*(sin(cons*(i-25))));
		coords.push_back(temp);
	}
	temp.set_x(coords[25].get_x()-circ.get_radius());
	temp.set_y(coords[25].get_y()+circ.get_radius());
	coords.push_back(temp);
	for(i=51;i<75;++i){
		temp.set_x(coords[50].get_x() - circ.get_radius()*(sin(cons*(i-50))));
		temp.set_y(coords[50].get_y() - (circ.get_radius() - circ.get_radius()*(cos(cons*(i-50)))));
		coords.push_back(temp);
	}
	temp.set_x(coords[50].get_x()-circ.get_radius());
	temp.set_y(coords[50].get_y()-circ.get_radius());
	coords.push_back(temp);
	for(i=76;i<100;++i){
		temp.set_x(coords[75].get_x() + (circ.get_radius() - circ.get_radius()*(cos(cons*(i-75)))));
		temp.set_y(coords[75].get_y() - circ.get_radius()*(sin(cons*(i-75))));
		coords.push_back(temp);
	}
}

PolygonVect::PolygonVect(Triangle& triangle) {
	tri = triangle;
	which = triangle.whichShape();
	tri.set_idntfy(triangle.get_idntfy());
	tri.set_stroke(triangle.get_stroke());
	Point2D temp;
	int i;
	for(i=0;i<3;++i){
		coords.push_back(temp);
		coords[i].set_x(tri.get_point_x(i));
		coords[i].set_y(tri.get_point_y(i));
	}
}


const Polygon::Point2D PolygonVect::operator [](int index) {
	if(index>=0 && index<this->coords.size())
		return coords[index];
}

void PolygonVect::draw(ofstream& os) {
	os<<"<polygon points='";
	int i;
	for(i=0;i<coords.size();++i){
		os<<" "<<coords[i].get_x()<<" "<<coords[i].get_y()<<" ";
	}
	if(which==1)
		os<<"' "<<rect.get_stroke()<<" "<<rect.fill<<endl;
	if(which==2)
		os<<"' "<<circ.get_stroke()<<" "<<circ.fill<<endl;;
	if(which==3)
		os<<"' "<<tri.get_stroke()<<" "<<tri.fill<<endl;
}


const double PolygonVect::area() const {
	double result;
	switch(which){
	case 1: result = rect.area();break;
	case 2: result = circ.area();break;
	case 3: result = tri.area();break;
	}
	return result;
}

const double PolygonVect::perimeter() const {
	double result;
	switch(which){
	case 1: result = rect.perimeter();break;
	case 2: result = circ.perimeter();break;
	case 3: result = tri.perimeter();break;
	}
	return result;
}

const Shape& PolygonVect::operator ++() {
	int i;
	for(i=0;i<coords.size();++i){
		coords[i].set_x(coords[i].get_x() + 1);
		coords[i].set_y(coords[i].get_x() + 1);
	}
	return *this;
}

const Shape& PolygonVect::operator ++(int ignore) {
	vector<Point2D>temp;
	temp = coords;
	int i;
	for(i=0;i<coords.size();++i){
		coords[i].set_x(coords[i].get_x() + 1);
		coords[i].set_y(coords[i].get_x() + 1);
	}
	return *this;
}

const Shape& PolygonVect::operator --() {
	int i;
	for(i=0;i<coords.size();++i){
		coords[i].set_x(coords[i].get_x() - 1);
		coords[i].set_y(coords[i].get_x() - 1);
	}
	return *this;
}
const Shape& PolygonVect::operator --(int ignore) {
	vector<Point2D>temp;
	temp = coords;
	int i;
	for(i=0;i<coords.size();++i){
		coords[i].set_x(coords[i].get_x() - 1);
		coords[i].set_y(coords[i].get_x() - 1);
	}
	return *this;
}

}
