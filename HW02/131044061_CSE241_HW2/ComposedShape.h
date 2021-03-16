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
using namespace std;

#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_


class ComposedShape {
public:
	ComposedShape();
	ComposedShape(Rectangle &, Rectangle &, ofstream &);//++
	ComposedShape(Rectangle &, Circle &, ofstream &);//++
	ComposedShape(Rectangle &, Triangle &, ofstream &);//++
	ComposedShape(Circle &, Rectangle &, ofstream &);//++
	ComposedShape(Circle &, Circle &, ofstream &);//++
	ComposedShape(Circle &, Triangle &, ofstream &);//++
	ComposedShape(Triangle &, Rectangle &, ofstream &);//++
	ComposedShape(Triangle &, Circle &, ofstream &);//++
	ComposedShape(Triangle &, Triangle &, ofstream &);//++

	void contRect_smallRect(Rectangle &, Rectangle &);//++
	void contRect_smallCirc(Rectangle &, Circle &);//++
	void contRect_smallTri(Rectangle &, Triangle &);//++
	void contCirc_smallRect(Circle &, Rectangle &);//++
	void contCirc_smallCirc(Circle &, Circle &);//++
	void contCirc_smallTri(Circle &, Triangle &);//++
	void contTri_smallRect(Triangle &, Rectangle &);//++
	void contTri_smallCirc(Triangle &, Circle &);//++
	void contTri_smallTri(Triangle &, Triangle &);//++

	void draw_contRect_smallRect(Rectangle &, Rectangle &, ofstream &);//++
	void draw_contRect_smallCirc(Rectangle &, Circle &, ofstream &);//++
	void draw_contRect_smallTri(Rectangle &, Triangle &, ofstream &);//++
	void draw_contCirc_smallRect(Circle &, Rectangle &, ofstream &);//++
	void draw_contCirc_smallCirc(Circle &, Circle &, ofstream &);//++
	void draw_contCirc_smallTri(Circle &, Triangle &, ofstream &);//++
	void draw_contTri_smallRect(Triangle &, Rectangle &, ofstream &);//++
	void draw_contTri_smallCirc(Triangle &, Circle &, ofstream &);//++
	void draw_contTri_smallTri(Triangle &, Triangle &, ofstream &);//++

	void optimalFit(Rectangle &, Rectangle &, ofstream &);//++
	void optimalFit(Rectangle &, Circle &, ofstream &);//++
	void optimalFit(Rectangle &, Triangle &, ofstream &);//++
	void optimalFit(Circle &, Rectangle &, ofstream &);//++
	void optimalFit(Circle &, Circle &, ofstream &);//++
	void optimalFit(Circle &, Triangle &, ofstream &);//++
	void optimalFit(Triangle &, Rectangle &, ofstream &);
	void optimalFit(Triangle &, Circle &, ofstream &);
	void optimalFit(Triangle &, Triangle &, ofstream &);

	void container_rectangle_choice();//++
	void setter_contRect_lines(Rectangle &);//++
	int getter_contRect_width(Rectangle &) const;//++
	int getter_contRect_height(Rectangle &) const;//++

	void small_rectangle_choice();//++
	void setter_smallRect_lines(Rectangle &);//++
	int getter_smallRect_width(Rectangle &) const;//++
	int getter_smallRect_height(Rectangle &) const;//++
	void setter_smallRect_coords(Rectangle &, double &, double &);//++
	double getter_smallRect_coord_x(Rectangle &) const;//++
	double getter_smallRect_coord_y(Rectangle &) const;//++

	void container_circle_choice();//++
	void setter_contCirc_radius(Circle &);//++
	int getter_contCirc_radius(Circle &) const;//++
	void setter_contCirc_coords(Circle &, double &, double &);//++
	double getter_contCirc_coord_x(Circle &) const;//++
	double getter_contCirc_coord_y(Circle &) const;//++

	void small_circle_choice();//++
	void setter_smallCirc_radius(Circle &);//++
	int getter_smallCirc_radius(Circle &) const;//++
	void setter_smallCirc_coords(Circle &, double &, double &);//++
	double getter_smallCirc_coord_x(Circle &) const;//++
	double getter_smallCirc_coord_y(Circle &) const;//++

	void container_triangle_choice();//++
	void setter_contTri_line(Triangle &);//++
	int getter_contTri_line(Triangle &) const;//++
	void setter_contTri_points(Triangle &, double&, double&, double&, double&, double&, double&);//++
	double getter_contTri_point_x(Triangle &, int) const;//++
	double getter_contTri_point_y(Triangle &, int) const;//++

	void small_triangle_choice();//++
	void setter_smallTri_line(Triangle &);//++
	int getter_smallTri_line(Triangle &) const;//++
	void setter_smallTri_points(Triangle &, double&, double&, double&, double&, double&, double&);//++
	double getter_smallTri_point_x(Triangle &, int) const;//++
	double getter_smallTri_point_y(Triangle &, int) const;//++






private:
	int contWidth, contHeight, contRadius, contTriEdge;
	int smallWidth, smallHeight, smallRadius, smallTriEdge;

	/*vector<double>smallRectCoords_x;
	vector<double>smallCircCoords_x;
	vector<double>smallTriCoords_x;
	vector<double>smallRectCoords_y;
	vector<double>smallCircCoords_y;
	vector<double>smallTriCoords_y;*/




};

#endif /* COMPOSEDSHAPE_H_ */
