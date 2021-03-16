#include<string>
#include <iostream>
#include<cmath>
#include<cstdlib>
#include<fstream>
#include "Triangle.h"

namespace gtuShape {

Triangle::Triangle() {
	line = 0;
}

Triangle::Triangle(double l) {
	set_line(l);
}


const Triangle& Triangle::operator ++() {
	int i,j;
	for(i=0;i<3;++i)
		for(j=0;j<2;++j)
			++points[i][j];
	return *this;
}

const Triangle& Triangle::operator ++(int ignore) {
	Triangle temp(line);
	int i,j;
	for(i=0;i<3;++i)
		for(j=0;j<2;++j)
			++points[i][j];
	return temp;
}

const Triangle& Triangle::operator --() {
	int i,j;
	for(i=0;i<3;++i)
		for(j=0;j<2;++j)
			--points[i][j];
	return *this;
}

const Triangle& Triangle::operator --(int ignore) {
	Triangle temp(line);
	int i,j;
	for(i=0;i<3;++i)
		for(j=0;j<2;++j)
			--points[i][j];
	return temp;
}
const double Triangle::find_height() const {
	return sqrt(3) * (line/2);
}

void Triangle::draw(ofstream &os) {
	os<<this->get_idntfy()<<this->get_point_x(0)<<" "<<this->get_point_y(0)
			<<" "<<this->get_point_x(1)<<" "<<this->get_point_y(1)<<" "<<this->get_point_x(2)
			<<" "<<this->get_point_y(2)<<"' "<<this->get_stroke()<<this->fill<<endl;
}

}
