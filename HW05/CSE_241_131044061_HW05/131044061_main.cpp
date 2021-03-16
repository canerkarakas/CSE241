#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include<vector>
#include"Rectangle.h"
#include"Circle.h"
#include"Triangle.h"
#include"ComposedShape.h"
#include "Polygon.h"
#include "PolygonVect.h"
#include "PolygonDyn.h"
using namespace gtuShape;
using namespace std;

int Rectangle::numOfShape = 0;
int Circle::numOfShape = 0;
int Triangle::numOfShape = 0;

ofstream& operator<<(ofstream &, Shape *);
void printAll(vector<Shape*>, ofstream &);
void printPoly(vector<Shape*>, ofstream &);
void sortShapes(vector<Shape*>&);


int main(){
	Circle c(15);
	Rectangle r(5,5);
	Triangle t(5);
	t.set_points(0, 5*sqrt(3)/2, 2.5, 0, 5, 5*sqrt(3)/2);
	c.set_coords(15,15);
	r.set_coords(0,0);

	PolygonVect pv(c);
	PolygonDyn pd(r);

	ComposedShape cmp(c,r);

	vector<Shape*> shapes;
	vector<Shape*> shapes2;
	Shape* shapes3;

	shapes.push_back(&c);
	shapes.push_back(&r);
	shapes.push_back(&t);
	shapes.push_back(&r);
	shapes.push_back(&r);
	shapes2.push_back(&pv);
	shapes2.push_back(&pd);

	shapes3 = &cmp;
	ofstream ofs("composedShape.svg", std::ofstream::out);
	ofs<<shapes3;
	ofs.close();

	ofstream ofs1("printAll_1.svg", std::ofstream::out);
	ofstream ofs2("printPoly_1.svg", std::ofstream::out);
	printPoly(shapes, ofs1);
	printPoly(shapes2, ofs2);
	printAll(shapes, ofs1);
	printAll(shapes2, ofs2);
	ofs1.close();
	ofs2.close();

	sortShapes(shapes);
	sortShapes(shapes2);

	ofstream ofs3("printAll_2.svg", std::ofstream::out);
	ofstream ofs4("printPoly_2.svg", std::ofstream::out);
	printPoly(shapes, ofs3);
	printPoly(shapes2, ofs4);
	printAll(shapes, ofs3);
	printAll(shapes2, ofs4);
	ofs3.close();
	ofs4.close();

	return 0;
}

ofstream& operator<<(ofstream &os, Shape *shape){
	shape->draw(os);
	return os;
}

void printAll(vector<Shape*> shapes, ofstream &ofs){
	ofs<<"<svg>"<<endl<<"<rect width='100' height='100' fill='transparent'/>"<<endl<<endl;

	int i;
	for(i=0;i<shapes.size();++i)
		ofs<<shapes[i];

	ofs<<endl<<endl<<"</svg>"<<endl<<endl;
	ofs.close();
}

void printPoly(vector<Shape*> shapes, ofstream &ofs){
	ofs<<"<svg>"<<endl<<"<rect width='100' height='100' fill='transparent'/>"<<endl<<endl;

	int i;
	for(i=0;i<shapes.size();++i)
		ofs<<shapes[i];

	ofs<<endl<<endl<<"</svg>"<<endl<<endl;
	ofs.close();
}

void sortShapes(vector<Shape*>&shapes){
	Shape *temp;
	int i;
	for(i=1;i<shapes.size();++i){
		if(shapes[i]->area()<shapes[i-1]->area()){
			temp = shapes[i];
			shapes[i] = shapes[i-1];
			shapes[i-1] = temp;
			i = 0;
		}
	}
}




