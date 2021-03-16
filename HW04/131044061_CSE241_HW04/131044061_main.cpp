#include <iostream>
#include<fstream>
#include<string>
#include <sstream>
#include<cmath>
#include<cstdlib>
#include<vector>
#include"Rectangle.h"
#include"Circle.h"
#include"Triangle.h"
#include "ComposedShape.h"
#include"Polygon.h"
using namespace std;
using namespace POLY;

int Rectangle::numOfShape = 0;
int Circle::numOfShape = 0;
int Triangle::numOfShape = 0;

int askForContainer();
int askForSmallShape();
void doObject(int, int, ofstream &);
void test(int, int, ofstream &);
void test(ofstream &);

int main() {
	ofstream ofs("output.svg", std::ofstream::out);
	ofstream ofs1("1.svg", std::ofstream::out);
	ofstream ofs2("2.svg", std::ofstream::out);
	ofstream ofs3("3.svg", std::ofstream::out);
	ofstream ofs4("4.svg", std::ofstream::out);
	ofstream ofs5("5.svg", std::ofstream::out);
	ofstream ofs6("6.svg", std::ofstream::out);
	ofstream ofs7("7.svg", std::ofstream::out);
	ofstream ofs8("8.svg", std::ofstream::out);
	ofstream ofs9("9.svg", std::ofstream::out);
	ofstream ofsPoly("poly.svg", std::ofstream::out);

	int choiceCont = askForContainer();
	int choiceSmall = askForSmallShape();
	doObject(choiceCont, choiceSmall, ofs);
	test(0,0,ofs1);
	test(0,1,ofs2);
	test(0,2,ofs3);
	test(1,0,ofs4);
	test(1,1,ofs5);
	test(1,2,ofs6);
	test(2,0,ofs7);
	test(2,1,ofs8);
	test(2,2,ofs9);
	test(ofsPoly);
	ofs.close();
	ofs1.close();
	ofs2.close();
	ofs3.close();
	ofs4.close();
	ofs5.close();
	ofs6.close();
	ofs7.close();
	ofs8.close();
	ofs9.close();
	ofsPoly.close();
	return 0;
}

int askForContainer(){
	int result;
	string count;
	char choice;
	int control = 1;
	cout<<"Please enter the main contain shape (R,C,T)"<<endl;
	while(control==1){
			getline(cin,count);
			choice = count[0];
			if((choice!='R' && choice!='C' && choice!='T') && (choice!='r' && choice!='c' && choice!='t')){
				cout<<"Error!!!"<<endl;
				cout<<"Please enter the main contain shape (R,C,T)"<<endl;
			}
			else{
				control = 0;
			}
		}
		switch(choice){
			case 'R' :
			case 'r' : result = 0; break;
			case 'C' :
			case 'c' : result = 1; break;
			case 'T' :
			case 't' : result = 2; break;
			default: break;
		}
		return result;

}

int askForSmallShape(){
	int result;
	string count;
	char choice;
	int control = 1;
	cout<<"Please enter the main small shape (R,C,T)"<<endl;
	while(control==1){
			getline(cin,count);
			choice = count[0];
			if((choice!='R' && choice!='C' && choice!='T') && (choice!='r' && choice!='c' && choice!='t')){
				cout<<"Error!!!"<<endl;
				cout<<"Please enter the main small shape (R,C,T)"<<endl;
			}
			else{
				control = 0;
			}
		}
		switch(choice){
			case 'R' :
			case 'r' : result = 0; break;
			case 'C' :
			case 'c' : result = 1; break;
			case 'T' :
			case 't' : result = 2; break;
			default: break;
		}
		return result;
}

void doObject(int cont, int small, ofstream &ofs){
	if(cont==0 && small==0){
		Rectangle contRect, smallRect;
		ComposedShape comp(contRect, smallRect, ofs);
		comp.draw_contRect_smallRect(contRect, smallRect, ofs);
	}
	if(cont==0 && small==1){
		Rectangle contRect;
		Circle smallCirc;
		ComposedShape comp(contRect, smallCirc, ofs);
		comp.draw_contRect_smallCirc(contRect, smallCirc, ofs);
	}
	if(cont==0 && small==2){
		Rectangle contRect;
		Triangle smallTri;
		ComposedShape comp(contRect, smallTri, ofs);
		comp.draw_contRect_smallTri(contRect, smallTri, ofs);
	}
	if(cont==1 && small==0){
		Circle contCirc;
		Rectangle smallRect;
		ComposedShape comp(contCirc, smallRect, ofs);
		comp.draw_contCirc_smallRect(contCirc, smallRect, ofs);
	}
	if(cont==1 && small==1){
		Circle contCirc;
		Circle smallCirc;
		ComposedShape comp(contCirc, smallCirc, ofs);
		comp.draw_contCirc_smallCirc(contCirc, smallCirc, ofs);
	}
	if(cont==1 && small==2){
		Circle contCirc;
		Triangle smallTri;
		ComposedShape comp(contCirc, smallTri, ofs);
		comp.draw_contCirc_smallTri(contCirc, smallTri, ofs);
	}
	if(cont==2 && small==0){
		Triangle contTri;
		Rectangle smallRect;
		ComposedShape comp(contTri, smallRect, ofs);
		comp.draw_contTri_smallRect(contTri, smallRect, ofs);
	}
	if(cont==2 && small==1){
		Triangle contTri;
		Circle smallCirc;
		ComposedShape comp(contTri, smallCirc, ofs);
		comp.draw_contTri_smallCirc(contTri, smallCirc, ofs);
	}
	if(cont==2 && small==2){
		Triangle contTri;
		Triangle smallTri;
		ComposedShape comp(contTri, smallTri, ofs);
		comp.draw_contTri_smallTri(contTri, smallTri, ofs);
	}
}

void test(int cont, int small, ofstream &ofs){
	if(cont==0 && small==0){
		Rectangle contRect, smallRect;
		int temp = smallRect.reset_numOfShape();
		ComposedShape comp(contRect, smallRect, ofs);
		comp.draw_contRect_smallRect(contRect, smallRect, ofs);
	}
	if(cont==0 && small==1){
		Rectangle contRect;
		Circle smallCirc;
		int temp = smallCirc.reset_numOfShape();
		ComposedShape comp(contRect, smallCirc, ofs);
		comp.draw_contRect_smallCirc(contRect, smallCirc, ofs);
	}
	if(cont==0 && small==2){
		Rectangle contRect;
		Triangle smallTri;
		int temp = smallTri.reset_numOfShape();
		ComposedShape comp(contRect, smallTri, ofs);
		comp.draw_contRect_smallTri(contRect, smallTri, ofs);
	}
		if(cont==1 && small==0){
		Circle contCirc;
		Rectangle smallRect;
		int temp = smallRect.reset_numOfShape();
		ComposedShape comp(contCirc, smallRect, ofs);
		comp.draw_contCirc_smallRect(contCirc, smallRect, ofs);
	}
	if(cont==1 && small==1){
		Circle contCirc;
		Circle smallCirc;
		int temp = smallCirc.reset_numOfShape();
		ComposedShape comp(contCirc, smallCirc, ofs);
		comp.draw_contCirc_smallCirc(contCirc, smallCirc, ofs);
	}
	if(cont==1 && small==2){
		Circle contCirc;
		Triangle smallTri;
		int temp = smallTri.reset_numOfShape();
		ComposedShape comp(contCirc, smallTri, ofs);
		comp.draw_contCirc_smallTri(contCirc, smallTri, ofs);
	}
	if(cont==2 && small==0){
		Triangle contTri;
		Rectangle smallRect;
		int temp = smallRect.reset_numOfShape();
		ComposedShape comp(contTri, smallRect, ofs);
		comp.draw_contTri_smallRect(contTri, smallRect, ofs);
	}
	if(cont==2 && small==1){
		Triangle contTri;
		Circle smallCirc;
		int temp = smallCirc.reset_numOfShape();
		ComposedShape comp(contTri, smallCirc, ofs);
		comp.draw_contTri_smallCirc(contTri, smallCirc, ofs);
	}
	if(cont==2 && small==2){
		Triangle contTri;
		Triangle smallTri;
		int temp = smallTri.reset_numOfShape();
		ComposedShape comp(contTri, smallTri, ofs);
		comp.draw_contTri_smallTri(contTri, smallTri, ofs);
	}


}

void test(ofstream &ofs){
	Polygon *polS;
	Rectangle rect , smallRect;
	Circle circ , smallCirc;
	Triangle tri;
	polS = new Polygon[5];

	ofs<<"<svg>"<<endl<<endl;

	rect.set_lines(150,200);
	rect.set_coords(0 , 0);
	Polygon temp(rect);
	polS[0] = temp;
	polS[0].set_fill("fill='yellow'");
	ofs<<polS[0];

	smallRect.set_lines(10,25);
	smallRect.set_coords(0 , 0);
	Polygon temp1(smallRect);
	polS[1] = temp1;
	polS[1].set_fill("fill='blue'");
	ofs<<polS[1];

	circ.set_radius(50);
	circ.set_coords(60,(double)circ.get_radius());
	Polygon temp2(circ);
	polS[2] = temp2;
	polS[2].set_fill("fill='green'");
	ofs<<polS[2];

	smallCirc.set_radius(10);
	smallCirc.set_coords(circ.get_pos_x(), circ.get_pos_y());
	Polygon temp3(smallCirc);
	polS[3] = temp3;
	polS[3].set_fill("fill='blue'");
	ofs<<polS[3];

	tri.set_line(50);
	tri.set_points(85,120,80-((double)tri.get_line()/2),120+tri.find_height(),110,120+tri.find_height());
	Polygon temp4(tri);
	polS[4] = temp4;
	polS[4].set_fill("fill='purple'");
	ofs<<polS[4];

	ofs<<"</svg>"<<endl;

}
