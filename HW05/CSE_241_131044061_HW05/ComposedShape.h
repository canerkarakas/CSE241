#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include <sstream>
#include"Rectangle.h"
#include"Circle.h"
#include"Triangle.h"
using namespace std;

#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
#include"Shape.h"
namespace gtuShape {

class ComposedShape : public Shape{
public:

	ComposedShape();
	ComposedShape(Rectangle &, Rectangle &);
	ComposedShape(Rectangle &, Circle &);
	ComposedShape(Rectangle &, Triangle &);
	ComposedShape(Circle &, Rectangle &);
	ComposedShape(Circle &, Circle &);
	ComposedShape(Circle &, Triangle &);
	ComposedShape(Triangle &, Rectangle &);
	ComposedShape(Triangle &, Circle &);
	ComposedShape(Triangle &, Triangle &);

	void contRect_smallRect(Rectangle &, Rectangle &);
	void contRect_smallCirc(Rectangle &, Circle &);
	void contRect_smallTri(Rectangle &, Triangle &);
	void contCirc_smallRect(Circle &, Rectangle &);
	void contCirc_smallCirc(Circle &, Circle &);
	void contCirc_smallTri(Circle &, Triangle &);
	void contTri_smallRect(Triangle &, Rectangle &);
	void contTri_smallCirc(Triangle &, Circle &);
	void contTri_smallTri(Triangle &, Triangle &);

	void draw_contRect_smallRect(Rectangle , Rectangle , ofstream &);
	void draw_contRect_smallCirc(Rectangle , Circle , ofstream &);
	void draw_contRect_smallTri(Rectangle , Triangle , ofstream &);
	void draw_contCirc_smallRect(Circle , Rectangle , ofstream &);
	void draw_contCirc_smallCirc(Circle , Circle , ofstream &);
	void draw_contCirc_smallTri(Circle , Triangle , ofstream &);
	void draw_contTri_smallRect(Triangle , Rectangle , ofstream &);
	void draw_contTri_smallCirc(Triangle , Circle , ofstream &);
	void draw_contTri_smallTri(Triangle , Triangle , ofstream &);

	void optimalFit(Rectangle , Rectangle , ofstream &);
	void optimalFit(Rectangle , Circle , ofstream &);
	void optimalFit(Rectangle , Triangle , ofstream &);
	void optimalFit(Circle , Rectangle , ofstream &);
	void optimalFit(Circle , Circle , ofstream &);
	void optimalFit(Circle , Triangle , ofstream &);
	void optimalFit(Triangle , Rectangle , ofstream &);
	void optimalFit(Triangle , Circle , ofstream &);
	void optimalFit(Triangle , Triangle , ofstream &);

	Rectangle get_cont_rect() const {return contR;}
	Rectangle get_small_rect() const {return smallR;}
	Circle get_cont_circ() const {return contC;}
	Circle get_small_circ() const {return smallC;}
	Triangle get_cont_tri() const {return contT;}
	Triangle get_small_tri() const {return smallT;}

	const int whichShape() const{return 0;}
	void draw(ofstream &);

	const double area() const;
	const double perimeter() const;

	const Shape& operator ++();
	const Shape& operator ++(int);
	const Shape& operator --();
	const Shape& operator --(int);

	const ComposedShape& operator+=(Shape *);
	const Shape* get_shapes_element(int index) const{return shapes[index];}


private:
	Rectangle contR, smallR;
	Circle contC, smallC;
	Triangle contT, smallT;
	int which;
	vector<Shape*>shapes;
};
}
#endif
