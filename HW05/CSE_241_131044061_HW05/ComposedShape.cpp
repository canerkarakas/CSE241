#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<vector>
#include"Rectangle.h"
#include"Circle.h"
#include"Triangle.h"
#include "ComposedShape.h"
using namespace std;

namespace gtuShape {

ComposedShape::ComposedShape() {
}
ComposedShape::ComposedShape(Rectangle &contRect, Rectangle &smallRect) {
	contRect_smallRect(contRect, smallRect);
	contR = contRect;
	smallR = smallRect;
	which = 1;
}

ComposedShape::ComposedShape(Rectangle &contRect, Circle &smallCirc) {
	contRect_smallCirc(contRect, smallCirc);
	contR = contRect;
	smallC = smallCirc;
	which = 2;
}

ComposedShape::ComposedShape(Rectangle &contRect, Triangle &smallTri) {
	contRect_smallTri(contRect, smallTri);
	contR = contRect;
	smallT = smallTri;
	which = 3;
}

ComposedShape::ComposedShape(Circle &contCirc, Rectangle &smallRect) {
	contCirc_smallRect(contCirc, smallRect);
	contC = contCirc;
	smallR = smallRect;
	which = 4;
}

ComposedShape::ComposedShape(Circle &contCirc, Circle &smallCirc) {
	contCirc_smallCirc(contCirc, smallCirc);
	contC = contCirc;
	smallC = smallCirc;
	which = 5;
}

ComposedShape::ComposedShape(Circle &contCirc, Triangle &smallTri) {
	contCirc_smallTri(contCirc, smallTri);
	contC = contCirc;
	smallT = smallTri;
	which = 6;
}

ComposedShape::ComposedShape(Triangle &contTri, Rectangle &smallRect) {
	contTri_smallRect(contTri, smallRect);
	contT = contTri;
	smallR = smallRect;
	which = 7;
}

ComposedShape::ComposedShape(Triangle &contTri, Circle &smallCirc) {
	contTri_smallCirc(contTri, smallCirc);
	contT = contTri;
	smallC = smallCirc;
	which = 8;
}

ComposedShape::ComposedShape(Triangle &contTri, Triangle &smallTri) {
	contTri_smallTri(contTri, smallTri);
	contT = contTri;
	smallT = smallTri;
	which = 9;
}


void ComposedShape::contRect_smallRect(Rectangle& contRect, Rectangle& smallRect) {
	int control = 1;
	while(control == 1){
		if(contRect.get_width() < contRect.get_height()){
			if(contRect.get_width() < smallRect.get_width() ||
					contRect.get_width() < smallRect.get_height()){
				cout<<"Error!!!"<<endl;
				control = 2;
			}
			else{
				control = 2;
			}
		}
		if(contRect.get_width() > contRect.get_height()){
			if(contRect.get_height() < smallRect.get_width()||
					contRect.get_height() < smallRect.get_height()){
				cout<<"Error!!!"<<endl;
				control = 2;
			}
			else{
				control = 2;
			}
		}
		if(contRect.get_width() == contRect.get_height()){
			if(contRect.get_width() < smallRect.get_width() ||
					contRect.get_width() < smallRect.get_height()){
				cout<<"Error!!!"<<endl;
				control = 2;
			}
			else{
				control = 2;
			}
		}
	}
}

void ComposedShape::contRect_smallCirc(Rectangle& contRect, Circle& smallCirc) {
	int control = 1;
	while(control == 1){
		if(contRect.get_width() < contRect.get_height()){
			if(contRect.get_width() < 2*smallCirc.get_radius()){
				cout<<"Error!!!"<<endl;
				control = 2;
			}
			else{
				control = 2;
			}
		}
		if(contRect.get_width() > contRect.get_height()){
			if(contRect.get_height() < 2*smallCirc.get_radius()){
				cout<<"Error!!!"<<endl;
				control = 2;
			}
			else{
				control = 2;
			}
		}
		if(contRect.get_width() == contRect.get_height()){
			if(contRect.get_height() < 2*smallCirc.get_radius()){
				cout<<"Error!!!"<<endl;
				control = 2;
			}
			else{
				control = 2;
			}
		}
	}
}

void ComposedShape::contRect_smallTri(Rectangle& contRect, Triangle& smallTri) {
	int control = 1;
	while(control == 1){
		if(contRect.get_width() < contRect.get_height()){
			if((smallTri.get_line() * sqrt(3))/2 > contRect.get_width()){	//(edge*sqrt(3)) / 2 vertical edge of the triangle
				cout<<"Error!!!"<<endl;
				control = 2;
			}
			else{
				control = 2;
			}
		}
		if(contRect.get_width() > contRect.get_height()){
			if((smallTri.get_line() * sqrt(3))/2 > contRect.get_height()){
				cout<<"Error!!!"<<endl;
				control = 2;
			}
			else{
				control = 2;
			}
		}
		if(contRect.get_width() == contRect.get_height()){
			if((smallTri.get_line() * sqrt(3))/2 > contRect.get_width()){
				cout<<"Error!!!"<<endl;
				control = 2;
			}
			else{
				control = 2;
			}
		}
	}
}

void ComposedShape::contCirc_smallRect(Circle& contCirc, Rectangle& smallRect) {
	int control = 1;
	while(control==1){
		double diagonal = sqrt((smallRect.get_width() * smallRect.get_width())+
				(smallRect.get_height() * smallRect.get_height()));//find the Rect's diagonal
		if(diagonal>contCirc.get_radius()){	//Rect's diagonal cannot be grater than the radius
			cout<<"Error!!!"<<endl;
			control = 2;
		}
		else{
			control = 2;
		}
	}
}

void ComposedShape::contCirc_smallCirc(Circle& contCirc, Circle& smallCirc) {
	int control = 1;
	while(control==1){
		if(smallCirc.get_radius() > contCirc.get_radius()){
			cout<<"Error!!!"<<endl;
			control = 2;
		}
		else{
			control = 2;
		}
	}
}

void ComposedShape::contCirc_smallTri(Circle& contCirc, Triangle& smallTri) {
	int control = 1;
	while(control==1){
		if(smallTri.get_line() > (contCirc.get_radius() * sqrt(3))){//the edge cannot be greater than the root three of the radius
			cout<<"Error!!!"<<endl;
			control = 2;
		}
		else{
			control = 2;
		}
	}
}

void ComposedShape::contTri_smallRect(Triangle& contTri, Rectangle& smallRect) {
	int control = 1;
	while(control==1){
		if(smallRect.get_width() < smallRect.get_height()){
			if(smallRect.get_height() > contTri.get_line() ||
					smallRect.get_height() == contTri.get_line()){
				cout<<"1Error!!!"<<endl;
				control = 2;
			}
			else{
				double temp = ((contTri.get_line() - smallRect.get_height())/2) * sqrt(3);
				if(temp < smallRect.get_width()){
					cout<<"2Error!!!"<<endl;
					control = 2;
				}
				else{
					control = 2;
				}
			}
		}
		if(smallRect.get_width() > smallRect.get_height()){
			if(smallRect.get_width() > contTri.get_line() ||
					smallRect.get_width() == contTri.get_line()){
				cout<<"3Error!!!"<<endl;
				control = 2;
			}
			else{
				double temp = ((contTri.get_line() - smallRect.get_width())/2) * sqrt(3);
				if(temp < smallRect.get_height()){
					cout<<"4Error!!!"<<endl;
					control = 2;
				}
				else{
					control = 2;
				}
			}
		}
		if(smallRect.get_width() == smallRect.get_height()){
			if(smallRect.get_width() > contTri.get_line() ||
					smallRect.get_width() == contTri.get_line()){
				cout<<"5Error!!!"<<endl;
				control = 2;
			}
			else{
				double temp = ((contTri.get_line() - smallRect.get_width())/2) * sqrt(3);
				if(temp < smallRect.get_height()){
					cout<<"6Error!!!"<<endl;
					control = 2;
				}
				else{
					control = 2;
				}
			}
		}
	}
}

void ComposedShape::contTri_smallCirc(Triangle& contTri, Circle& smallCirc) {
	int control = 1;
	while(control==1){
		double temp = ((contTri.get_line()/2)*sqrt(3))/3;
		if(smallCirc.get_radius() > temp){
			cout<<"Error!!!!"<<endl;
			control = 2;
		}
		else{
			control = 2;
		}
	}
}

void ComposedShape::contTri_smallTri(Triangle& contTri, Triangle& smallTri) {
	int control = 1;
	while(control==1){
		if(smallTri.get_line() > contTri.get_line()){
			cout<<"Error!!!"<<endl;
			control = 2;
		}
		else{
			control = 2;
		}
	}
}

void ComposedShape::optimalFit(Rectangle contRect, Rectangle smallRect, ofstream &ofs) {
	vector<double>crd_x;
	vector<double>crd_y;
	int x = 0;
	int y = 0;
	crd_x.push_back(0);
	crd_y.push_back(0);
	smallRect.set_coords(crd_x[x], crd_y[y]);
	int index=0;
	int countWidth = contRect.get_width() / smallRect.get_width();
	int countHeight = contRect.get_height() / smallRect.get_height();
	double firstCountForShape, secondCountForShape;
	Rectangle temp;

	while(countHeight>0){
		while(countWidth>0){
	        //the smaller's other point control
			if(((crd_x[x] + smallRect.get_width()) < contRect.get_width()) ||
					((crd_x[x] + smallRect.get_width()) == contRect.get_width())){
				smallRect.set_coords(crd_x[x], crd_y[y]);
				smallRect.fill = "fill='blue' />";
				Shape *shape;
				shape = &smallRect;
				*this += shape;
				shapes[index]->draw(ofs);
				//ofs<<"/>"<<endl;
				++index;
				crd_x.push_back(crd_x[x] + smallRect.get_width());
				firstCountForShape = smallRect.get_numOFShape();
				x++;
				countWidth = countWidth - 1;
			}
			else{
				countWidth--;
			}
		}
		//updates for the next raw
		crd_y.push_back(crd_y[y]+smallRect.get_height());
		y++;
		crd_x.push_back(0);
		x++;
		countWidth = contRect.get_width() / smallRect.get_width();
		countHeight = countHeight - 1;
	}
	//the smaller's rotating control
	if(contRect.get_width() != (countWidth*smallRect.get_width()) &&
			(contRect.get_height() > smallRect.get_width() ||
					contRect.get_height() == smallRect.get_width())){
		int countForFree = contRect.get_width() - (countWidth*smallRect.get_width());
		crd_y.push_back(0);
		y++;
		int tempHeight = smallRect.get_width();
		int tempWidth = smallRect.get_height();
		int control2 = contRect.get_height() / smallRect.get_width();
		while(control2>0){
		    //free space control and comparing ups situation
			if(countForFree>smallRect.get_height()|| countForFree==smallRect.get_height()){
				int control = countForFree / smallRect.get_height();
				crd_x.push_back(countWidth*smallRect.get_width());
				x++;
				while(control>0){
					if((crd_x[x] + tempWidth) < contRect.get_width()
							|| (crd_x[x] + tempWidth) == contRect.get_width()){
						temp.set_lines(tempWidth, tempHeight);
						temp.set_coords(crd_x[x], crd_y[y]);
						temp.fill = "fill='blue' />";
						Shape *s;
						s = &temp;
						*this += s;
						shapes[index]->draw(ofs);
						++index;
						crd_x.push_back(crd_x[x] + tempWidth);
						x++;
						secondCountForShape = temp.get_numOFShape();
						control = control - 1;
					}
					if(!((crd_x[x] + tempWidth) < contRect.get_width() ||
							(crd_x[x] + tempWidth) == contRect.get_width())){
						crd_y.push_back(crd_y[y]+tempHeight);
						y++;
						control = -1;
					}
				}
			}
			control2 = control2 - 1;
		}
	}
	ofs<<endl<<"</svg>"<<endl;
	int diffArea = contRect.area() - ((secondCountForShape+firstCountForShape)*smallRect.area());
	cout<<"I can fit at most "<<secondCountForShape+firstCountForShape<<" small shapes into the main container. The empty area in container is "
			<< diffArea << "." << endl;
}

void ComposedShape::optimalFit(Rectangle contRect, Circle smallCirc,
		ofstream& ofs) {
	vector<double> crd_x;
	vector<double> crd_y;
	int x = 0;
	int y = 0;
	crd_x.push_back(smallCirc.get_radius());
	crd_y.push_back(smallCirc.get_radius());
	int index = 0;
	int jumpControl = smallCirc.get_radius() * 3;
	int jump = smallCirc.get_radius() * 2;
	int countForShape = 0;
	int control1 = contRect.get_height() / (2 * smallCirc.get_radius()); //count for that how many smaller?
	int control2 = 1;
	while (control1 > 0) {
		smallCirc.set_coords(crd_x[x], crd_y[y]);
		smallCirc.fill = "fill='green' />";
		Shape* s;
		s = &smallCirc;
		*this += s;
		shapes[index]->draw(ofs);
		++index;
		countForShape = smallCirc.get_numOfShape();
		while (control2 == 1) {
			//control for next circ's coords.
			if ((crd_x[x] + jumpControl) > contRect.get_width()) {
				control2 = 0;
			} else {
				crd_x.push_back(crd_x[x] + jump);
				x++;
				smallCirc.set_coords(crd_x[x], crd_y[y]);
				smallCirc.fill = "Fill='green' />";
				Shape * s;
				s = &smallCirc;
				*this += s;
				shapes[index]->draw(ofs);
				++index;
				countForShape = smallCirc.get_numOfShape();
			}
		}

		//ups for next raw
		control2 = 1;
		crd_y.push_back(crd_y[y] + jump);
		y++;
		crd_x.push_back(smallCirc.get_radius());
		x++;
		control1 = control1 - 1;
	}

	double diffArea = contRect.area() - smallCirc.result_area(smallCirc);
	cout << "I can fit at most " << countForShape
			<< " small shapes into the main container. The empty area in container is "
			<< diffArea << "." << endl;
	ofs << endl << "</svg>" << endl;
}

void ComposedShape::optimalFit(Rectangle contRect, Triangle smallTri,
		ofstream& ofs) {
	int countForShape;
	int index = 0;
	double height = smallTri.find_height();
	double points[3][2];
	points[0][0] = 0;
	points[0][1] = 0;
	points[1][0] = smallTri.get_line() / 2;
	points[1][1] = height;
	points[2][0] = smallTri.get_line();
	points[2][1] = 0;
	double tempSecPoint[2];
	double tempTrdPoint[2];
	smallTri.set_points(points[0][0], points[0][1], points[1][0], points[1][1],
			points[2][0], points[2][1]);
	int control1 = 0;
	int control2 = 0;
	int raw = 0;
	bool position = true;
	while (control1 == 0) {
		if (points[2][1] > contRect.get_height()
				|| points[0][1] > contRect.get_height()
				|| points[1][1] > contRect.get_height()) {
			control1 = 1;
		} else {
			while (control2 == 0) {
				//control points for overflow
				if (points[2][0] > contRect.get_width()
						|| points[2][1] > contRect.get_height()
						|| points[0][0] > contRect.get_width()
						|| points[0][1] > contRect.get_height()
						|| points[1][0] > contRect.get_width()
						|| points[1][1] > contRect.get_height()) {
					raw = raw + 1;
					if (position == true) {
						points[0][0] = 0;
						points[0][1] = (raw + 1) * height;
						points[1][0] = smallTri.get_line() / 2;
						points[1][1] = raw * height;
						points[2][0] = smallTri.get_line();
						points[2][1] = (raw + 1) * height;
					}
					if (position == false) {
						points[0][0] = 0;
						points[0][1] = raw * height;
						points[1][0] = smallTri.get_line() / 2;
						points[1][1] = (raw + 1) * height;
						points[2][0] = smallTri.get_line();
						points[2][1] = raw * height;
					}
					position = !position;
					control2 = 1;
				} else {
					smallTri.set_points(points[0][0], points[0][1],
							points[1][0], points[1][1], points[2][0],
							points[2][1]);
					smallTri.fill = "fill='purple' />";
					Shape* s;
					s = &smallTri;
					*this += s;
					shapes[index]->draw(ofs);
					++index;
					countForShape = smallTri.get_numOfShape();
					tempSecPoint[0] = points[1][0];
					tempSecPoint[1] = points[1][1];
					tempTrdPoint[0] = points[2][0];
					tempTrdPoint[1] = points[2][1];
					points[0][0] = tempSecPoint[0];
					points[0][1] = tempSecPoint[1];
					points[1][0] = tempTrdPoint[0];
					points[1][1] = tempTrdPoint[1];
					points[2][0] = tempSecPoint[0] + smallTri.get_line();
					points[2][1] = tempSecPoint[1];
				}
			}

			control2 = 0;
		}

	}

	double diffArea = contRect.area() - smallTri.result_area(smallTri);
	cout << "I can fit at most " << countForShape
			<< " small shapes into the main container. The empty area in container is "
			<< diffArea << "." << endl;
	ofs << endl << "</svg>" << endl;
}

void ComposedShape::optimalFit(Circle contCirc, Rectangle smallRect,
		ofstream& ofs) {
	vector<double> crd_x;
	vector<double> crd_y;
	int x = 0;
	int y = 0;
	crd_x.push_back(0);
	crd_y.push_back(0);
	double distance;
	int control = 0;
	int countForShape;
	int index = 0;
	while (crd_y[y] < (2 * contCirc.get_radius()) - smallRect.get_height()) {
		while (crd_x[x] < (contCirc.get_radius() * 2) - smallRect.get_width()) {
			distance = sqrt(
					((contCirc.get_pos_x() - crd_x[x])
							* (contCirc.get_pos_x() - crd_x[x]))
							+ ((contCirc.get_pos_y() - crd_y[y])
									* contCirc.get_pos_y() - crd_y[y]));
			if (distance > contCirc.get_radius()) {
				crd_x.push_back(crd_x[x] + 1);
				x++;
			} else {
				double temp = sqrt(
						((contCirc.get_pos_x()
								- (crd_x[x] + smallRect.get_width()))
								* (contCirc.get_pos_x()
										- (crd_x[x] + smallRect.get_width())))
								+ ((contCirc.get_pos_y() - crd_y[y])
										* (contCirc.get_pos_y() - crd_y[y])));
				if (temp > contCirc.get_radius()) {
					crd_x.push_back(crd_x[x] + 1);
					x++;
				} else {
					double temp2 =
							sqrt(
									((contCirc.get_pos_x() - crd_x[x])
											* (contCirc.get_pos_x() - crd_x[x]))
											+ ((contCirc.get_pos_y()
													- (crd_y[y]
															+ smallRect.get_height()))
													* (contCirc.get_pos_y()
															- (crd_y[y]
																	+ smallRect.get_height())))); //for the other point of rec.
					if (temp2 > contCirc.get_radius()) {
						crd_x.push_back(crd_x[x] + 1);
						x++;
					} else {
						smallRect.set_coords(crd_x[x], crd_y[y]);
						smallRect.fill = "fill='yellow' />";
						Shape* s;
						s = &smallRect;
						*this += s;
						shapes[index]->draw(ofs);
						//ofs<<s;
						++index;
						countForShape = smallRect.get_numOFShape();
						control = 1;
						crd_x.push_back(crd_x[x] + smallRect.get_width());
						x++;
					}
				}

			}

		}

		//for in the previous row has small shape ?
		//true that mean next line
		if (control == 0) {
			crd_x.push_back(0);
			x++;
			control = 0;
			crd_y.push_back(crd_y[y] + 1);
			y++;
		}
		//true that mean next raw
		if (control == 1) {
			control = 0;
			crd_x.push_back(0);
			x++;
			crd_y.push_back(crd_y[y] + smallRect.get_height());
			y++;
		}
	}

	double diffArea = contCirc.area() - smallRect.result_area(smallRect);
	ofs<<endl<<"</svg>"<<endl;
	cout <<"I can fit at most " << countForShape
			<< " small shapes into the main container. The empty area in container is "
			<< diffArea << "." << endl;
}

void ComposedShape::optimalFit(Circle contCirc, Circle smallCirc,
		ofstream& ofs) {
	vector<double> crd_x;
	vector<double> crd_y;
	int x = 0;
	int y = 0;
	int index = 0;
	crd_x.push_back(smallCirc.get_radius());
	crd_y.push_back(smallCirc.get_radius());
	//smallCirc.fill = "fill='blue'/>";
	int count = contCirc.get_radius() - smallCirc.get_radius(); //for the tangent points
	int jump = 2 * smallCirc.get_radius(); //ups
	int control1 = smallCirc.get_radius();
	int control2 = smallCirc.get_radius();
	int smallShapesCount;
	while (control1 < 2 * contCirc.get_radius()) {
		double distance;
		while (control2 < 2 * contCirc.get_radius()) {
			distance = sqrt(
					((contCirc.get_pos_x() - crd_x[x])
							* (contCirc.get_pos_x() - crd_x[x]))
							+ ((contCirc.get_pos_y() - crd_y[y])
									* (contCirc.get_pos_y() - crd_y[y]))); //sqrt((x1-x2)^2+(y1-y2)^2) --> distance between two points
			//is it tangant points?
			if (distance > count) {
				control2++;
				crd_x.push_back(crd_x[x] + 1);
				x++;
			} else {
				//for the overflowing?
				if ((distance + smallCirc.get_radius())
						> contCirc.get_radius()) {
					control2++;
					crd_x.push_back(crd_x[x] + 1);
					x++;
				} else {
					smallCirc.set_coords(crd_x[x], crd_y[y]);
					smallCirc.fill = "fill='blue' />";
					Shape* s;
					s = &smallCirc;
					*this += s;
					shapes[index]->draw(ofs);
					++index;
					smallShapesCount = smallCirc.get_numOfShape();
					control2 = control2 + jump;
					crd_x.push_back(crd_x[x] + jump);
					x++;
				}
			}

		}

		//ups for next raw
		crd_x.push_back(smallCirc.get_radius());
		x++;
		crd_y.push_back(crd_y[y] + jump);
		y++;
		control2 = smallCirc.get_radius();
		control1 = control1 + jump;
	}

	ofs << endl << "</svg>" << endl;
	double diffArea = contCirc.area() - smallCirc.result_area(smallCirc);
	cout << "I can fit at most " << smallShapesCount
			<< " small shapes into the main container. The empty area in container is "
			<< diffArea << "." << endl;
}

void ComposedShape::optimalFit(Circle contCirc, Triangle smallTri,
		ofstream& ofs) {
	double distance;
	bool control2 = false;
	int countForShape;
	int index = 0;
	double point_x = contCirc.get_radius();
	double point_y = 0.00;
	double point2_x, point2_y, point3_x, point3_y;
	point2_x = contCirc.get_radius() - ((double) ((smallTri.get_line())) / 2);
	point2_y = smallTri.find_height();
	point3_x = contCirc.get_radius() + (smallTri.get_line() / 2);
	point3_y = point2_y;
	smallTri.set_points(point_x, point_y, point2_x, point2_y, point3_x,
			point3_y);
	smallTri.fill = "fill='purple' />";
	Shape* s;
	s = &smallTri;
	*this += s;
	shapes[index]->draw(ofs);
	point_x = 0.0;
	point_y = smallTri.find_height();
	while (point_y <= (2 * contCirc.get_radius()) - smallTri.find_height()) {
		while (point_x < (2 * contCirc.get_radius())) {
			distance = sqrt(
					(contCirc.get_pos_x() - point_x)
							* (contCirc.get_pos_x() - point_x)
							+ (contCirc.get_pos_y() - point_y)
									* (contCirc.get_pos_y() - point_y));
			if (distance > contCirc.get_radius()) {
				point_x += 1;
			} else {
				if (control2 == true) {
					point2_x = point_x + smallTri.get_line();
					point2_y = point_y;
					point3_x = point_x + (smallTri.get_line() / 2);
					point3_y = point_y + smallTri.find_height();
				}
				if (control2 == false) {
					point2_x = point_x - (smallTri.get_line() / 2);
					point2_y = point_y + smallTri.find_height();
					point3_x = point2_x + smallTri.get_line();
					point3_y = point2_y;
				}
				control2 = !control2;
				double temp = sqrt(
						(contCirc.get_pos_x() - point_x)
								* (contCirc.get_pos_x() - point_x)
								+ (contCirc.get_pos_y() - point_y)
										* (contCirc.get_pos_y() - point_y));
				double temp2 = sqrt(
						(contCirc.get_pos_x() - point2_x)
								* (contCirc.get_pos_x() - point2_x)
								+ (contCirc.get_pos_y() - point2_y)
										* (contCirc.get_pos_y() - point2_y));
				double temp3 = sqrt(
						(contCirc.get_pos_x() - point3_x)
								* (contCirc.get_pos_x() - point3_x)
								+ (contCirc.get_pos_y() - point3_y)
										* (contCirc.get_pos_y() - point3_y));
				if (temp2 > contCirc.get_radius()
						|| temp3 > contCirc.get_radius()
						|| temp > contCirc.get_radius()) {
					if (control2 == true) {
						point_x += 1;
						control2 = !control2;
					} else {
						point_x += 3 * contCirc.get_radius();
						control2 = !control2;
					}
				} else {
					smallTri.set_points(point_x, point_y, point2_x, point2_y,
							point3_x, point3_y);
					smallTri.fill = "fill='purple'";
					Shape * s;
					s = &smallTri;
					*this += s;
					shapes[index]->draw(ofs);
					++index;
					countForShape = smallTri.get_numOfShape();
					if (control2 == false)
						point_x += smallTri.get_line();
				}
			}

		}

		point_x = 0;
		point_y = point_y + smallTri.find_height();
	}

	ofs << endl << "</svg>" << endl;
	double diffArea = contCirc.area() - smallTri.result_area(smallTri);
	cout << "I can fit at most " << countForShape
			<< " small shapes into the main container. The empty area in container is "
			<< diffArea << "." << endl;
}

void ComposedShape::optimalFit(Triangle contTri, Rectangle smallRect,
		ofstream& ofs) {
	double temp_y = contTri.find_height() - smallRect.get_height();
	double temp_x = smallRect.get_height() / sqrt(3);
	int smallShapesCount;
	int index = 0;
	int control = 1; //for that how many rows have drawn smaller shapes
	int control2 = 0;
	while (temp_y > 0) {
		while (control2 == 0) {
			//for line break or raw break
			double count = contTri.get_line()
					- ((control * smallRect.get_height()) / sqrt(3));
			//there is line break ?
			if (count < temp_x + smallRect.get_width()) {
				control2 = 1;
			} else {
				smallRect.set_coords(temp_x, temp_y);
				smallRect.fill = "fill='yellow' />";
				Shape* s;
				s = &smallRect;
				*this += s;
				shapes[index]->draw(ofs);
				++index;
				smallShapesCount = smallRect.get_numOFShape();
				temp_x = temp_x + smallRect.get_width();
			}
		}

		control++;
		control2 = 0;
		temp_x = (control * smallRect.get_height() / sqrt(3));
		temp_y = temp_y - smallRect.get_height();
	}

	double diffArea = contTri.area() - smallRect.result_area(smallRect);
	cout << "I can fit at most " << smallShapesCount
			<< " small shapes into the main container. The empty area in container is "
			<< diffArea << "." << endl;
	ofs << endl << "</svg>" << endl;
}

void ComposedShape::optimalFit(Triangle contTri, Circle smallCirc,
		ofstream& ofs) {
	vector<double> crd_x;
	vector<double> crd_y;
	int x = 0;
	int y = 0;
	int index = 0;
	crd_x.push_back(smallCirc.get_radius() * sqrt(3));
	crd_y.push_back(contTri.find_height() - smallCirc.get_radius());
	double temp_height = contTri.find_height();
	double base = (double) ((contTri.get_line()));
	int control = 0;
	int control2 = 0;
	int countForShape;
	double decForBase; //to shrink base
	while (crd_y[y] > 0) {
		while (control2 == 0) {
			double count = base - (smallCirc.get_radius() * sqrt(3));
			if (count < crd_x[x]) {
				control2 = 1;
			} else {
				smallCirc.set_coords(crd_x[x], crd_y[y]);
				smallCirc.fill = "fill='green' />";
				Shape* s;
				s = &smallCirc;
				*this += s;
				shapes[index]->draw(ofs);
				++index;
				countForShape = smallCirc.get_numOfShape();
				crd_x.push_back(crd_x[x] + (2 * smallCirc.get_radius()));
				x++;
			}
		}

		control++;
		decForBase = ((smallCirc.get_radius() * 2) / sqrt(3)); //to shrink base
		base = base - decForBase;
		double decForHeight = 2 * smallCirc.get_radius(); //to shrink height
		temp_height = temp_height - decForHeight;
		control2 = 0;
		crd_x.push_back(
				(smallCirc.get_radius() * sqrt(3)) + (decForBase * control));
		x++;
		crd_y.push_back(temp_height - smallCirc.get_radius());
		y++;
	}

	double diffArea = contTri.area() - smallCirc.result_area(smallCirc);
	cout << "I can fit at most " << countForShape
			<< " small shapes into the main container. The empty area in container is "
			<< diffArea << "." << endl;
	ofs << endl << "</svg>" << endl;
}

void ComposedShape::optimalFit(Triangle contTri, Triangle smallTri,
		ofstream& ofs) {
	//smallTri.fill = "fill='blue'/>";
	int countForShape;
	int index = 0;
	double heightForBig = (contTri.get_line() / 2) * sqrt(3);
	double points[3][2];
	double heightForSmall = (smallTri.get_line() / 2) * sqrt(3);
	points[0][0] = 0;
	points[0][1] = heightForBig;
	points[1][0] = smallTri.get_line() / 2;
	points[1][1] = heightForBig - heightForSmall;
	points[2][0] = smallTri.get_line();
	points[2][1] = heightForBig;
	double tempSecPoint[2];
	double tempTrdPoint[2];
	int control1 = 0;
	int control2 = 0;
	int raw = 0;
	double tempForWidth = (double) ((contTri.get_line()));
	while (control1 == 0) {
		if (points[2][1] < 1 || points[0][1] < 1 || points[1][1] < 1) {
			control1 = 1;
		} else {
			while (control2 == 0) {
				if (points[2][0] > tempForWidth || points[2][1] < 1
						|| points[0][0] > tempForWidth || points[0][1] < 1
						|| points[1][0] > tempForWidth || points[1][1] < 1) {
					raw = raw + 1;
					points[0][0] = raw * smallTri.get_line() / 2;
					points[0][1] = heightForBig - (raw * heightForSmall);
					points[1][0] = (raw + 1) * (smallTri.get_line() / 2);
					points[1][1] = heightForBig - ((raw + 1) * heightForSmall);
					points[2][0] = (raw * smallTri.get_line() / 2)
							+ smallTri.get_line();
					points[2][1] = heightForBig - (raw * heightForSmall);
					tempForWidth = tempForWidth - (smallTri.get_line() / 2);
					control2 = 1;
				} else {
					smallTri.set_points(points[0][0], points[0][1],
							points[1][0], points[1][1], points[2][0],
							points[2][1]);
					smallTri.fill = "fill='blue' />";
					Shape* s;
					s = &smallTri;
					*this += s;
					//ofs << shapes[index];
					shapes[index]->draw(ofs);
					++index;
					countForShape = smallTri.get_numOfShape();
					tempSecPoint[0] = points[1][0];
					tempSecPoint[1] = points[1][1];
					tempTrdPoint[0] = points[2][0];
					tempTrdPoint[1] = points[2][1];
					points[0][0] = tempSecPoint[0];
					points[0][1] = tempSecPoint[1];
					points[1][0] = tempTrdPoint[0];
					points[1][1] = tempTrdPoint[1];
					points[2][0] = tempSecPoint[0] + smallTri.get_line();
					points[2][1] = tempSecPoint[1];
				}
			}

			control2 = 0;
		}

	}

	double diffArea = contTri.area() - smallTri.result_area(smallTri);
	cout << "I can fit at most " << countForShape
			<< " small shapes into the main container. The empty area in container is "
			<< diffArea << "." << endl;
	ofs << endl << "</svg>" << endl;
}

void ComposedShape::draw_contRect_smallRect(Rectangle contRect,
		Rectangle smallRect, ofstream& ofs) {
	ofs << "<svg>" << endl << endl;
	double temp = 0;
	contRect.set_coords(temp, temp);
	contRect.fill = "fill='yellow' />";
	Shape* s;
	s = &contRect;
	s->draw(ofs);
	optimalFit(contRect, smallRect, ofs);
}

void ComposedShape::draw_contRect_smallCirc(Rectangle contRect,
		Circle smallCirc, ofstream& ofs) {
	ofs << "<svg>" << endl << endl;
	double temp = 0;
	contRect.set_coords(temp, temp);
	contRect.fill = "fill='yellow' />";
	Shape* s;
	s = &contRect;
	s->draw(ofs);
	optimalFit(contRect, smallCirc, ofs);
}

void ComposedShape::draw_contRect_smallTri(Rectangle contRect,
		Triangle smallTri, ofstream& ofs) {
	ofs << "<svg>" << endl << endl;
	double temp = 0;
	contRect.set_coords(temp, temp);
	contRect.fill = "fill='yellow' />";
	Shape* s;
	s = &contRect;
	s->draw(ofs);
	optimalFit(contRect, smallTri, ofs);
}

void ComposedShape::draw_contCirc_smallRect(Circle contCirc,
		Rectangle smallRect, ofstream& ofs) {
	ofs << "<svg>" << endl << endl;
	ofs << "<rect width='" << 2 * contCirc.get_radius() << "' height='"
			<< 2 * contCirc.get_radius() << "' fill='transparent'/>" << endl;
	double temp = (double) ((contCirc.get_radius()));
	contCirc.set_coords(temp, temp);
	contCirc.fill = "fill='green' />";
	Shape* s;
	s = &contCirc;
	s->draw(ofs);
	optimalFit(contCirc, smallRect, ofs);
}

void ComposedShape::draw_contCirc_smallCirc(Circle contCirc, Circle smallCirc,
		ofstream& ofs) {
	ofs << "<svg>" << endl << endl;
	ofs << "<rect width='" << 2 * contCirc.get_radius() << "' height='"
			<< 2 * contCirc.get_radius() << "' fill='transparent'/>" << endl;
	double temp = (double) ((contCirc.get_radius()));
	contCirc.set_coords(temp, temp);
	contCirc.fill = "fill='green' />";
	Shape* s;
	s = &contCirc;
	s->draw(ofs);
	optimalFit(contCirc, smallCirc, ofs);
}

void ComposedShape::draw_contCirc_smallTri(Circle contCirc, Triangle smallTri,
		ofstream& ofs) {
	ofs << "<svg>" << endl << endl;
	ofs << "<rect width='" << 2 * contCirc.get_radius() << "' height='"
			<< 2 * contCirc.get_radius() << "' fill='transparent'/>" << endl;
	double temp = (double) ((contCirc.get_radius()));
	contCirc.set_coords(temp, temp);
	contCirc.fill = "fill='green' />";
	Shape* s;
	s = &contCirc;
	s->draw(ofs);
	optimalFit(contCirc, smallTri, ofs);
}

void ComposedShape::draw_contTri_smallRect(Triangle contTri,
		Rectangle smallRect, ofstream& ofs) {
	ofs << "<svg>" << endl << endl;
	ofs << "<rect width='" << contTri.get_line() << "' height='"
			<< contTri.find_height() << "' fill='transparent'/>" << endl;
	vector<double> crd_x;
	vector<double> crd_y;
	crd_x.push_back(0);
	crd_x.push_back(contTri.get_line() / 2);
	crd_x.push_back(contTri.get_line());
	crd_y.push_back(contTri.find_height());
	crd_y.push_back(0);
	crd_y.push_back(contTri.find_height());
	contTri.set_points(crd_x[0], crd_y[0], crd_x[1], crd_y[1], crd_x[2],
			crd_y[2]);
	contTri.fill = "fill='purple' />";
	Shape* s;
	s = &contTri;
	s->draw(ofs);
	optimalFit(contTri, smallRect, ofs);
}

void ComposedShape::draw_contTri_smallCirc(Triangle contTri, Circle smallCirc,
		ofstream& ofs) {
	ofs << "<svg>" << endl << endl;
	ofs << "<rect width='" << contTri.get_line() << "' height='"
			<< contTri.find_height() << "' fill='transparent'/>" << endl;
	vector<double> crd_x;
	vector<double> crd_y;
	crd_x.push_back(0);
	crd_x.push_back(contTri.get_line() / 2);
	crd_x.push_back(contTri.get_line());
	crd_y.push_back(contTri.find_height());
	crd_y.push_back(0);
	crd_y.push_back(contTri.find_height());
	contTri.set_points(crd_x[0], crd_y[0], crd_x[1], crd_y[1], crd_x[2],
			crd_y[2]);
	contTri.fill = "fill='purple' />";
	Shape* s;
	s = &contTri;
	s->draw(ofs);
	optimalFit(contTri, smallCirc, ofs);
}

void ComposedShape::draw_contTri_smallTri(Triangle contTri, Triangle smallTri,
		ofstream& ofs) {
	ofs << "<svg>" << endl << endl;
	ofs << "<rect width='" << contTri.get_line() << "' height='"
			<< contTri.find_height() << "' fill='transparent'/>" << endl;
	vector<double> crd_x;
	vector<double> crd_y;
	crd_x.push_back(0);
	crd_x.push_back(contTri.get_line() / 2);
	crd_x.push_back(contTri.get_line());
	crd_y.push_back(contTri.find_height());
	crd_y.push_back(0);
	crd_y.push_back(contTri.find_height());
	contTri.set_points(crd_x[0], crd_y[0], crd_x[1], crd_y[1], crd_x[2],
			crd_y[2]);
	contTri.fill = "fill='purple' />";
	Shape* s;
	s = &contTri;
	s->draw(ofs);
	optimalFit(contTri, smallTri, ofs);
}

void ComposedShape::draw(ofstream& ofs) {
	switch(which){
	case 1: draw_contRect_smallRect(get_cont_rect(), get_small_rect(), ofs);break;
	case 2: draw_contRect_smallCirc(get_cont_rect(), get_small_circ(), ofs);break;
	case 3: draw_contRect_smallTri(get_cont_rect(), get_small_tri(), ofs);break;
	case 4: draw_contCirc_smallRect(get_cont_circ(), get_small_rect(), ofs);break;
	case 5: draw_contCirc_smallCirc(get_cont_circ(), get_small_circ(), ofs);break;
	case 6: draw_contCirc_smallTri(get_cont_circ(), get_small_tri(), ofs);break;
	case 7: draw_contTri_smallRect(get_cont_tri(), get_small_rect(), ofs);break;
	case 8: draw_contTri_smallCirc(get_cont_tri(), get_small_circ(), ofs);break;
	case 9: draw_contTri_smallTri(get_cont_tri(), get_small_tri(), ofs);break;
	}
}

const double ComposedShape::area() const {
	return 1;
}

const double ComposedShape::perimeter() const {
	return 1;
}

const Shape& ComposedShape::operator ++() {
	ComposedShape cmp;
}

const Shape& ComposedShape::operator ++(int ignore) {
	ComposedShape cmp;
}

const Shape& ComposedShape::operator --() {
	ComposedShape cmp;
}

const Shape& ComposedShape::operator --(int ignore) {
	ComposedShape cmp;
}

const ComposedShape& ComposedShape::operator +=(Shape *other) {
	this->shapes.push_back(other);
	return *this;
}



}
