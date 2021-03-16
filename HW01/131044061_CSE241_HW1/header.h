#include <iostream>
#include<fstream>
#include <string>
#include <sstream>

#ifndef _HEADER_H_
#define _HEADER_H_

enum Shapes{rectangle, circle, triangle};

Shapes user_container_shape_choice(void);

void container_rectangle_choice(int &, int &);

void container_circle_choice(int &);

void container_triangle_choice(int &);

Shapes user_small_shape_choice(void);

void small_shape_rectangle_choice(int &, int &);

void small_shape_circle_choice(int &);

void small_shape_triangle_choice(int &);

void inputs_control_for_return_result(int&, int&, int&, int&,
                                      int&, int&, int&, int&,
                                      Shapes&, Shapes&);

void recta_to_recta(int&, int&, int&, int&, std::fstream&);

void recta_to_circ(int&, int&, int&, std::fstream&);

void recta_to_tria(int&, int&, int&, std::fstream&);

void circ_to_circ(int&, int&, std::fstream&);

void circ_to_recta(int&, int&, int&, std::fstream&);

void circ_to_tria(int&, int&, std::fstream&);

void tria_to_recta(int&, int&, int&, std::fstream&);

void tria_to_circ(int&, int&, std::fstream&);

void tria_to_tria(int&, int&, std::fstream&);

void draw(int&, int&, int&, int&,
          int&, int&, int&, int&,
          Shapes&, Shapes&);

double find_sqrt(int);




#endif
