#include<string>
#include<fstream>
#include <iostream>
#ifndef CIRCLE_H_
#define CIRCLE_H_
using namespace std;

class Circle {
public:
	Circle();

	void set_radius(int &);
	int get_radius() const;
	void set_coords(double &, double &);
	double get_pos_x() const;
	double get_pos_y() const;
	void draw(ofstream &) const;
	string get_idntfy() const;
	string get_coord_x() const;
	string get_coord_y() const;
	string get_rad() const;
	//string get_fill() const;
	string get_stroke() const;
	string fill = "fill='green'/>";

private:
	int radius;
	double pos_x, pos_y;
	string idntfy = "<circle ";
	string coord_x = "cx='";
	string coord_y = "cy='";
	string rad = "r='";
	//string fill = "fill='green'/>";
	string stroke = " stroke='black' stroke-width='0.05' ";
};

#endif

/*struct Circ{
	string idntfy = "<circle";
	string coord_x = "cx='"; int x;
	string coord_y = "cy='"; int y;
	string rad = "r='";
	string fill = "fill='green'/>";
};*/
