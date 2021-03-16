#include<string>
#include<cstdlib>
#include <iostream>
#include<fstream>
#ifndef TRIANGLE_H_
#define TRIANGLE_H_
using namespace std;

class Triangle {
public:
	Triangle();

	void set_line(int&);
	int get_line() const;
	double find_height();
	void set_points(double&, double&, double&, double&, double&, double&);
	double get_point_x(int) const;
	double get_point_y(int) const;
	void draw(ofstream &) const;
	string get_idntfy() const;
	//string get_fill() const;
	string get_stroke() const;
	string fill = "fill='purple'/>";

private:
	int line;
	double height;
	double points[3][2];
	string idntfy = "<polygon points='";
	//string fill = "fill='purple'/>";
	string stroke = " stroke='black' stroke-width='0.05' ";
};

#endif
/*struct TriA{
	string idntfy = "<polygon points='";
	double points[3][2];
	string fill = "fill='purple'/>";
};*/
