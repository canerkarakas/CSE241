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
#include "Polygon.h"
using namespace std;
using namespace POLY;

ComposedShape::ComposedShape() {
}

ComposedShape::ComposedShape(Rectangle &contRect, Rectangle &smallRect, ofstream &ofs) {
	contRect_smallRect(contRect, smallRect);
}

ComposedShape::ComposedShape(Rectangle &contRect, Circle &smallCirc, ofstream &ofs) {
	contRect_smallCirc(contRect, smallCirc);
}

ComposedShape::ComposedShape(Rectangle &contRect, Triangle &smallTri, ofstream &ofs) {
	contRect_smallTri(contRect, smallTri);
}

ComposedShape::ComposedShape(Circle &contCirc, Rectangle &smallRect, ofstream &ofs) {
	contCirc_smallRect(contCirc, smallRect);
}

ComposedShape::ComposedShape(Circle &contCirc, Circle &smallCirc, ofstream &ofs) {
	contCirc_smallCirc(contCirc, smallCirc);
}

ComposedShape::ComposedShape(Circle &contCirc, Triangle &smallTri, ofstream &ofs) {
	contCirc_smallTri(contCirc, smallTri);
}

ComposedShape::ComposedShape(Triangle &contTri, Rectangle &smallRect, ofstream &ofs) {
	contTri_smallRect(contTri, smallRect);
}

ComposedShape::ComposedShape(Triangle &contTri, Circle &smallCirc, ofstream &ofs) {
	contTri_smallCirc(contTri, smallCirc);
}

ComposedShape::ComposedShape(Triangle &contTri, Triangle &smallTri, ofstream &ofs) {
	contTri_smallTri(contTri, smallTri);
}

void ComposedShape::contRect_smallRect(Rectangle& contRect,
		Rectangle& smallRect) {
	container_rectangle_choice();
	int control = 1;
	while(control == 1){
		small_rectangle_choice();
		if(contWidth < contHeight){
			if(contWidth < smallWidth || contWidth < smallHeight){
				cout<<"Error!!!"<<endl;
			}
			else{
				control = 2;
			}
		}
		if(contWidth > contHeight){
			if(contHeight < smallWidth || contHeight < smallHeight){
				cout<<"Error!!!"<<endl;
			}
			else{
				control = 2;
			}
		}
		if(contWidth == contHeight){
			if(contWidth < smallWidth || contWidth < smallHeight){
				cout<<"Error!!!"<<endl;
			}
			else{
				control = 2;
			}
		}
	}
	setter_contRect_lines(contRect);
	setter_smallRect_lines(smallRect);
}

void ComposedShape::contRect_smallCirc(Rectangle& contRect, Circle& smallCirc) {
	container_rectangle_choice();
	int control = 1;
	while(control == 1){
		small_circle_choice();
		if(contWidth < contHeight){
			if(contWidth < 2*smallRadius){
				cout<<"Error!!!"<<endl;
			}
			else{
				control = 2;
			}
		}
		if(contWidth > contHeight){
			if(contHeight < 2*smallRadius){
				cout<<"Error!!!"<<endl;
			}
			else{
				control = 2;
			}
		}
		if(contWidth == contHeight){
			if(contWidth < 2*smallRadius){
				cout<<"Error!!!"<<endl;
			}
			else{
				control = 2;
			}
		}
	}
	setter_contRect_lines(contRect);
	setter_smallCirc_radius(smallCirc);
}

void ComposedShape::contRect_smallTri(Rectangle& contRect, Triangle& smallTri) {
	container_rectangle_choice();
	int control = 1;
	while(control == 1){
		small_triangle_choice();
		if(contWidth < contHeight){
			if((smallTriEdge * sqrt(3))/2 > contWidth){	//(edge*sqrt(3)) / 2 vertical edge of the triangle
				cout<<"Error!!!"<<endl;
			}
			else{
				control = 2;
			}
		}
		if(contWidth > contHeight){
			if((smallTriEdge * sqrt(3))/2 > contHeight){
				cout<<"Error!!!"<<endl;
			}
			else{
				control = 2;
			}
		}
		if(contWidth == contHeight){
			if((smallTriEdge * sqrt(3))/2 > contWidth){
				cout<<"Error!!!"<<endl;
			}
			else{
				control = 2;
			}
		}
	}
	setter_contRect_lines(contRect);
	setter_smallTri_line(smallTri);

}

void ComposedShape::contCirc_smallRect(Circle& contCirc, Rectangle& smallRect) {
	container_circle_choice();
	int control = 1;
	while(control==1){
		small_rectangle_choice();
		double diagonal = sqrt((smallWidth*smallWidth)+(smallHeight*smallHeight));//find the Rect's diagonal
		if(diagonal>contRadius){	//Rect's diagonal cannot be grater than the radius
			cout<<"Error!!!"<<endl;
		}
		else{
			control = 2;
		}
	}
	setter_contCirc_radius(contCirc);
	setter_smallRect_lines(smallRect);
}

void ComposedShape::contCirc_smallCirc(Circle& contCirc, Circle& smallCirc) {
	container_circle_choice();
	int control = 1;
	while(control==1){
		small_circle_choice();
		if(smallRadius>contRadius){
			cout<<"Error!!!"<<endl;
		}
		else{
			control = 2;
		}
	}
	setter_contCirc_radius(contCirc);
	setter_smallCirc_radius(smallCirc);
}

void ComposedShape::contCirc_smallTri(Circle& contCirc, Triangle& smallTri) {
	container_circle_choice();
	int control = 1;
	while(control==1){
		small_triangle_choice();
		if(smallTriEdge>(contRadius*sqrt(3))){//the edge cannot be greater than the root three of the radius
			cout<<"Error!!!"<<endl;
		}
		else{
			control = 2;
		}
	}
	setter_contCirc_radius(contCirc);
	setter_smallTri_line(smallTri);
}

void ComposedShape::contTri_smallRect(Triangle& contTri, Rectangle& smallRect) {
	container_triangle_choice();
	int control = 1;
	while(control==1){
		small_rectangle_choice();
		if(smallWidth<smallHeight){
			if(smallHeight>contTriEdge || smallHeight==contTriEdge){
				cout<<"1Error!!!"<<endl;
			}
			else{
				double temp = ((contTriEdge - smallHeight)/2) * sqrt(3);
				if(temp<smallWidth){
					cout<<"2Error!!!"<<endl;
				}
				else{
					control = 2;
				}
			}
		}
		if(smallWidth>smallHeight){
			if(smallWidth>contTriEdge || smallWidth==contTriEdge){
				cout<<"3Error!!!"<<endl;
			}
			else{
				double temp = ((contTriEdge - smallWidth)/2) * sqrt(3);
				if(temp<smallHeight){
					cout<<"4Error!!!"<<endl;
				}
				else{
					control = 2;
				}
			}
		}
		if(smallWidth==smallHeight){
			if(smallWidth>contTriEdge || smallWidth==contTriEdge){
				cout<<"5Error!!!"<<endl;
			}
			else{
				double temp = ((contTriEdge - smallWidth)/2) * sqrt(3);
				if(temp<smallHeight){
					cout<<"6Error!!!"<<endl;
				}
				else{
					control = 2;
				}
			}
		}
	}
	setter_contTri_line(contTri);
	setter_smallRect_lines(smallRect);
}

void ComposedShape::contTri_smallCirc(Triangle& contTri, Circle& smallCirc) {
	container_triangle_choice();
	int control = 1;
	while(control==1){
		small_circle_choice();
		double temp = ((contTriEdge/2)*sqrt(3))/3;
		if(smallRadius>temp){
			cout<<"Error!!!!"<<endl;
		}
		else{
			control = 2;
		}
	}
	setter_contTri_line(contTri);
	setter_smallCirc_radius(smallCirc);
}

void ComposedShape::contTri_smallTri(Triangle& contTri, Triangle& smallTri) {
	container_triangle_choice();
	int control = 1;
	while(control==1){
		small_triangle_choice();
		if(smallTriEdge>contTriEdge){
			cout<<"Error!!!"<<endl;
		}
		else{
			control = 2;
		}
	}
	setter_contTri_line(contTri);
	setter_smallTri_line(smallTri);
}

void ComposedShape::optimalFit(Rectangle& contRect, Rectangle& smallRect, ofstream &ofs) {
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
				Polygon poly(smallRect);
				*this += poly;
				polygons[index].set_fill("fill='blue'");
				ofs<<polygons[index];
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
			if(countForFree>smallHeight || countForFree==smallHeight){
				int control = countForFree / smallHeight;
				crd_x.push_back(countWidth*smallWidth);
				x++;
				while(control>0){
					if((crd_x[x] + tempWidth) < contRect.get_width()
							|| (crd_x[x] + tempWidth) == contRect.get_width()){
						temp.set_lines(tempWidth, tempHeight);
						temp.set_coords(crd_x[x], crd_y[y]);
						Polygon poly(smallRect);
						*this += poly;
						polygons[index].set_fill("fill='blue'");
						ofs<<polygons[index];
						++index;
						crd_x.push_back(crd_x[x] + tempWidth);
						x++;
						secondCountForShape = temp.get_numOFShape();
						control = control - 1;
					}
					if(!((crd_x[x] + tempWidth) < contRect.get_width() ||
							(crd_x[x] + tempWidth) == contWidth)){
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
	cout<<"I can fit at most "<<secondCountForShape+firstCountForShape<<" small shapes into the main container. "
			"The empty area in container is "<<diffArea<<"."<<endl;

}

void ComposedShape::optimalFit(Rectangle& contRect, Circle& smallCirc, ofstream &ofs) {
	vector<double>crd_x;
	vector<double>crd_y;
	int x = 0;
	int y = 0;
	crd_x.push_back(smallCirc.get_radius());
	crd_y.push_back(smallCirc.get_radius());

	int index=0;

	int jumpControl = smallCirc.get_radius() * 3;
	int jump = smallCirc.get_radius() * 2;
	int countForShape = 0;
	int control1 = contRect.get_height() / (2*smallCirc.get_radius());//count for that how many smaller?
	int control2 = 1;
	while(control1>0){
		smallCirc.set_coords(crd_x[x], crd_y[y]);
		Polygon poly(smallCirc);
		*this += poly;
		polygons[index].set_fill("fill='green'");
		ofs<<polygons[index];
		++index;
		countForShape = smallCirc.get_numOfShape();
		while(control2 == 1){
            //control for next circ's coords.
			if((crd_x[x]+jumpControl) > contRect.get_width()){
				control2 = 0;
			}
			else{
				crd_x.push_back(crd_x[x]+jump);
				x++;
				smallCirc.set_coords(crd_x[x], crd_y[y]);
				Polygon poly(smallCirc);
				*this += poly;
				polygons[index].set_fill("fill='green'");
				ofs<<polygons[index];
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
	double diffArea =contRect.area()-smallCirc.result_area(smallCirc);
	cout<<"I can fit at most "<<countForShape<<" small shapes into the main container. "
			"The empty area in container is "<<diffArea<<"."<<endl;

	ofs<<endl<<"</svg>"<<endl;
}

void ComposedShape::optimalFit(Rectangle& contRect, Triangle& smallTri, ofstream &ofs) {
	int countForShape;
	int index = 0;

	double height = smallTri.find_height();
	double points[3][2];
	points[0][0] = 0;
	points[0][1] = 0;
	points[1][0] = smallTri.get_line()/2;
	points[1][1] = height;
	points[2][0] = smallTri.get_line();
	points[2][1] = 0;
	double tempSecPoint[2];
	double tempTrdPoint[2];
	smallTri.set_points(points[0][0],points[0][1],points[1][0],points[1][1],points[2][0],points[2][1]);

	int control1 = 0;
	int control2 = 0;
	int raw = 0;
	bool position = true;
	while(control1==0){
		if(points[2][1]>contRect.get_height() || points[0][1]>contRect.get_height() ||
				points[1][1]>contRect.get_height()){
			control1=1;
		}
		else{
			while(control2==0){
			//control points for overflow
				if(points[2][0]>contRect.get_width() || points[2][1]>contRect.get_height() ||
					points[0][0]>contRect.get_width() || points[0][1]>contRect.get_height() ||
					points[1][0]>contRect.get_width() || points[1][1]>contRect.get_height()){
					raw = raw + 1;
					if(position==true){
						points[0][0] = 0;
						points[0][1] = (raw+1)*height;
						points[1][0] = smallTri.get_line()/2;
						points[1][1] = raw*height;
						points[2][0] = smallTri.get_line();
						points[2][1] = (raw+1)*height;
					}
					if(position==false){
						points[0][0] = 0;
						points[0][1] = raw*height;
						points[1][0] = smallTri.get_line()/2;
						points[1][1] = (raw+1)*height;
						points[2][0] = smallTri.get_line();
						points[2][1] = raw*height;
					}
					position = !position;
					control2=1;
				}
				else{
					smallTri.set_points(points[0][0],points[0][1],points[1][0],points[1][1],
							points[2][0],points[2][1]);
					Polygon poly(smallTri);
					*this += poly;
					polygons[index].set_fill("fill='purple'");
					ofs<<polygons[index];
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
    cout<<"I can fit at most "<<countForShape<<" small shapes into the main container. "
    		"The empty area in container is "<<diffArea<<"."<<endl;
	ofs<<endl<<"</svg>"<<endl;
}

void ComposedShape::optimalFit(Circle& contCirc, Rectangle& smallRect, ofstream &ofs) {
	vector<double>crd_x;
	vector<double>crd_y;
	int x = 0;
	int y = 0;
	crd_x.push_back(0);
	crd_y.push_back(0);
	double distance;
	int control = 0;
	int countForShape;
	int index = 0;
	while(crd_y[y]<(2*contCirc.get_radius())-smallRect.get_height()){
		while(crd_x[x]<(contCirc.get_radius()*2)-smallRect.get_width()){
			distance = sqrt(((contCirc.get_pos_x()-crd_x[x])*(contCirc.get_pos_x()-crd_x[x]))
			+ ((contCirc.get_pos_y()-crd_y[y])*contCirc.get_pos_y()-crd_y[y]));
			if(distance > contCirc.get_radius()){
				crd_x.push_back(crd_x[x] + 1);
				x++;
			}
			else{
				double temp = sqrt(((contCirc.get_pos_x()-(crd_x[x]+smallRect.get_width()))
						*(contCirc.get_pos_x()-(crd_x[x]+smallRect.get_width())))
						+((contCirc.get_pos_y()-crd_y[y])*(contCirc.get_pos_y()-crd_y[y])));
				if(temp > contCirc.get_radius()){
					crd_x.push_back(crd_x[x] + 1);
					x++;
				}
				else{
					double temp2 = sqrt(((contCirc.get_pos_x()-crd_x[x])*(contCirc.get_pos_x()-crd_x[x]))
					+ ((contCirc.get_pos_y()-(crd_y[y] + smallRect.get_height()))*(contCirc.get_pos_y()
							-(crd_y[y] + smallRect.get_height())))); //for the other point of rec.
					if(temp2 > contCirc.get_radius()){
						crd_x.push_back(crd_x[x] + 1);
						x++;
					}
					else{
						smallRect.set_coords(crd_x[x], crd_y[y]);
						Polygon poly(smallRect);
						*this += poly;
						polygons[index].set_fill("fill='yellow'");
						ofs<<polygons[index];
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
		if(control==0){
			crd_x.push_back(0);
			x++;
		    control = 0;
		    crd_y.push_back(crd_y[y] + 1);
		    y++;
		}
		//true that mean next raw
	    if(control==1){
	        control = 0;
	        crd_x.push_back(0);
	        x++;
	        crd_y.push_back(crd_y[y] + smallRect.get_height());
	        y++;
	    }
	}
	double diffArea = contCirc.area() - smallRect.result_area(smallRect);
    ofs<<endl<<"</svg>"<<endl;
	cout<<"I can fit at most "<<countForShape<<" small shapes into the main container. The empty area"
		" in container is "<<diffArea<<"."<<endl;

}

void ComposedShape::optimalFit(Circle& contCirc, Circle& smallCirc, ofstream &ofs) {
	vector<double>crd_x;
	vector<double>crd_y;
	int x = 0;
	int y = 0;
	int index = 0;
	crd_x.push_back(smallCirc.get_radius());
	crd_y.push_back(smallCirc.get_radius());
	//smallCirc.fill = "fill='blue'/>";
	int count = contCirc.get_radius() - smallCirc.get_radius();//for the tangent points
    int jump = 2*smallCirc.get_radius();//ups
    int control1 = smallCirc.get_radius();
    int control2 =  smallCirc.get_radius();
    int smallShapesCount;
    while(control1<2*contCirc.get_radius()){
        double distance;
        while(control2<2*contCirc.get_radius()){
            distance = sqrt(((contCirc.get_pos_x()-crd_x[x])*(contCirc.get_pos_x()-crd_x[x])) +
            		((contCirc.get_pos_y()-crd_y[y])*(contCirc.get_pos_y()-crd_y[y])));//sqrt((x1-x2)^2+(y1-y2)^2) --> distance between two points
            //is it tangant points?
            if(distance>count){
                control2++;
                crd_x.push_back(crd_x[x] + 1);
                x++;
            }
            else{
                //for the overflowing?
                if((distance+smallCirc.get_radius())>contCirc.get_radius()){
                    control2++;
                    crd_x.push_back(crd_x[x] + 1);
                    x++;
                }
                else{
                	smallCirc.set_coords(crd_x[x], crd_y[y]);
                	Polygon poly(smallCirc);
                	*this += poly;
                	polygons[index].set_fill("fill='blue'");
                	ofs<<polygons[index];
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
    ofs<<endl<<"</svg>"<<endl;
    double diffArea = contCirc.area() - smallCirc.result_area(smallCirc);
    cout<<"I can fit at most "<<smallShapesCount<<" small shapes into the main container."
    	" The empty area in container is "<<diffArea<<"."<<endl;

}

void ComposedShape::optimalFit(Circle& contCirc, Triangle& smallTri, ofstream &ofs) {
	double distance;
	bool control2 = false;
    int countForShape;
    int index = 0;
    double point_x = contCirc.get_radius();
    double point_y = 0.00;
    double point2_x, point2_y, point3_x, point3_y;
    point2_x = contCirc.get_radius() - ((double)smallTri.get_line()/2);
    point2_y = smallTri.find_height();
    point3_x = contCirc.get_radius() + (smallTri.get_line()/2);
    point3_y = point2_y;
    smallTri.set_points(point_x, point_y, point2_x, point2_y, point3_x, point3_y);
    Polygon poly(smallTri);
    *this += poly;
    polygons[index].set_fill("fill='purple'");
    ofs<<polygons[index];
    point_x = 0.0;
    point_y = smallTri.find_height();
    while(point_y<=(2*contCirc.get_radius())-smallTri.find_height()){
    	while(point_x<(2*contCirc.get_radius())){
    		distance = sqrt((contCirc.get_pos_x()-point_x)*(contCirc.get_pos_x()-point_x)
    				+ (contCirc.get_pos_y()-point_y)*(contCirc.get_pos_y()-point_y));
    		if(distance>contCirc.get_radius()){
    			point_x += 1;
    		}
    		else{
    			if(control2==true){
    				point2_x = point_x + smallTri.get_line();
    				point2_y = point_y;
    				point3_x = point_x + (smallTri.get_line()/2);
    				point3_y = point_y + smallTri.find_height();
    			}
    			if(control2==false){
    				point2_x = point_x - (smallTri.get_line()/2);
    				point2_y = point_y + smallTri.find_height();
    				point3_x = point2_x + smallTri.get_line();
    				point3_y = point2_y;
    			}
    			control2 = !control2;
    			double temp = sqrt((contCirc.get_pos_x()-point_x)*(contCirc.get_pos_x()-point_x)
    					+ (contCirc.get_pos_y()-point_y)*(contCirc.get_pos_y()-point_y));
    			double temp2 = sqrt((contCirc.get_pos_x()-point2_x)*(contCirc.get_pos_x()-point2_x)
    					+ (contCirc.get_pos_y()-point2_y)*(contCirc.get_pos_y()-point2_y));
    			double temp3 = sqrt((contCirc.get_pos_x()-point3_x)*(contCirc.get_pos_x()-point3_x)
    					+ (contCirc.get_pos_y()-point3_y)*(contCirc.get_pos_y()-point3_y));
    			if(temp2>contCirc.get_radius() || temp3>contCirc.get_radius() || temp>contCirc.get_radius()){
    				if(control2==true){
    				    point_x += 1;
    				    control2 = !control2;
    				}
    				else{
    					point_x += 3*contCirc.get_radius();
    					control2 = !control2;
    				}
    			}
    			else{
    				smallTri.set_points(point_x, point_y, point2_x, point2_y, point3_x, point3_y);
    				Polygon poly(smallTri);
    				*this += poly;
    				polygons[index].set_fill("fill='purple'");
    				ofs<<polygons[index];
    				++index;
    				countForShape = smallTri.get_numOfShape();
    				if(control2==false)
    					point_x += smallTri.get_line();
    			}
    		}
    	}
    	point_x = 0;
    	point_y = point_y + smallTri.find_height();
    }
    ofs<<endl<<"</svg>"<<endl;
    double diffArea = contCirc.area() - smallTri.result_area(smallTri);
    cout<<"I can fit at most "<<countForShape<<" small shapes into the main container."
    	" The empty area in container is "<<diffArea<<"."<<endl;
}

void ComposedShape::optimalFit(Triangle& contTri, Rectangle& smallRect, ofstream &ofs) {
	double temp_y = contTri.find_height() - smallRect.get_height();
	double temp_x = smallRect.get_height()/sqrt(3);
	int smallShapesCount;
	int index = 0;
    int control = 1;//for that how many rows have drawn smaller shapes
    int control2 = 0;
    while(temp_y>0){
    	while(control2==0){
    		//for line break or raw break
    		double count = contTriEdge - ((control*smallRect.get_height())/sqrt(3));
    		//there is line break ?
    		if(count < temp_x+smallRect.get_width()){
    			control2 = 1;
    		}
    		else{
    			smallRect.set_coords(temp_x, temp_y);
    			Polygon poly(smallRect);
    			*this += poly;
    			polygons[index].set_fill("fill='yellow'");
    			ofs<<polygons[index];
    			++index;
    			smallShapesCount = smallRect.get_numOFShape();
    			temp_x = temp_x + smallRect.get_width();
    		}
    	}
    	control++;
    	control2 = 0;
    	temp_x = (control*smallRect.get_height()/sqrt(3));
    	temp_y = temp_y - smallRect.get_height();
    }
    double diffArea = contTri.area()-smallRect.result_area(smallRect);
    cout<<"I can fit at most "<<smallShapesCount<<" small shapes into the main container."
    		" The empty area in container is "<<diffArea<<"."<<endl;
	ofs<<endl<<"</svg>"<<endl;
}

void ComposedShape::optimalFit(Triangle& contTri, Circle& smallCirc, ofstream &ofs) {
	vector<double>crd_x;
	vector<double>crd_y;
	int x = 0;
	int y = 0;
	int index = 0;
	crd_x.push_back(smallCirc.get_radius() * sqrt(3));
	crd_y.push_back(contTri.find_height() - smallCirc.get_radius());
	double temp_height = contTri.find_height();
	double base = (double)contTri.get_line();

	int control = 0;
    int control2 = 0;
	int countForShape;
	double decForBase;//to shrink base
	while(crd_y[y]>0){
		while(control2==0){
			double count = base-(smallCirc.get_radius()*sqrt(3));
			if(count<crd_x[x]){
				control2 = 1;
			}
			else{
				smallCirc.set_coords(crd_x[x], crd_y[y]);
				Polygon poly(smallCirc);
				*this += poly;
				polygons[index].set_fill("fill='green'");
				ofs<<polygons[index];
				++index;
				countForShape = smallCirc.get_numOfShape();
				crd_x.push_back(crd_x[x] + (2*smallCirc.get_radius()));
				x++;
			}
		}
		control++;
		decForBase = ((smallCirc.get_radius()*2)/sqrt(3));//to shrink base
		base = base - decForBase;
		double decForHeight = 2*smallCirc.get_radius();//to shrink height
		temp_height = temp_height - decForHeight;
		control2 = 0;
		crd_x.push_back((smallCirc.get_radius()*sqrt(3)) + (decForBase*control));
		x++;
		crd_y.push_back(temp_height - smallCirc.get_radius());
		y++;
	}
    double diffArea = contTri.area()-smallCirc.result_area(smallCirc);
    cout<<"I can fit at most "<<countForShape<<" small shapes into the main container."
    		" The empty area in container is "<<diffArea<<"."<<endl;
	ofs<<endl<<"</svg>"<<endl;
}

void ComposedShape::optimalFit(Triangle& contTri, Triangle& smallTri, ofstream &ofs) {
	//smallTri.fill = "fill='blue'/>";
    int countForShape;
    int index = 0;
    double heightForBig = (contTri.get_line()/2) * sqrt(3);
    double points[3][2];
    double heightForSmall = (smallTri.get_line()/2) * sqrt(3);
    points[0][0] = 0;
    points[0][1] = heightForBig;
    points[1][0] = smallTri.get_line()/2;
    points[1][1] = heightForBig - heightForSmall;
    points[2][0] = smallTri.get_line();
    points[2][1] = heightForBig;

    double tempSecPoint[2];
    double tempTrdPoint[2];

    int control1=0;
    int control2=0;
    int raw = 0;

    double tempForWidth = (double)contTri.get_line();

    while(control1==0){
    	if(points[2][1]<1 || points[0][1]<1 || points[1][1]<1){
    		control1=1;
    	}
    	else{
    		while(control2==0){
    			if(points[2][0]>tempForWidth || points[2][1]<1 ||
    				points[0][0]>tempForWidth || points[0][1]<1 ||
    				points[1][0]>tempForWidth || points[1][1]<1){

    				raw = raw + 1;
    				points[0][0] = raw * smallTri.get_line() / 2;
    				points[0][1] = heightForBig - (raw*heightForSmall);
    				points[1][0] = (raw+1)* (smallTri.get_line()/2);
    				points[1][1] = heightForBig - ((raw+1)*heightForSmall);
    				points[2][0] = (raw*smallTri.get_line()/2) + smallTri.get_line();
    				points[2][1] = heightForBig - (raw*heightForSmall);

    				tempForWidth = tempForWidth - (smallTri.get_line()/2);

    				control2=1;
    			}
    			else{
    				smallTri.set_points(points[0][0], points[0][1],
    						points[1][0], points[1][1],points[2][0], points[2][1]);
    				Polygon poly(smallTri);
    				*this += poly;
    				polygons[index].set_fill("fill='blue'");
    				ofs<<polygons[index];
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
     cout<<"I can fit at most "<<countForShape<<" small shapes into the main container."
     		" The empty area in container is "<<diffArea<<"."<<endl;


 	ofs<<endl<<"</svg>"<<endl;
}

void ComposedShape::draw_contRect_smallRect(Rectangle &contRect, Rectangle &smallRect, ofstream &ofs){
	ofs<<"<svg>"<<endl<<endl;
	double temp = 0;
	contRect.set_coords(temp, temp);
	Polygon poly(contRect);
	poly.set_fill("fill='yellow'");
	ofs<<poly;
	//contRect.draw(ofs);
	optimalFit(contRect, smallRect, ofs);
}
void ComposedShape::draw_contRect_smallCirc(Rectangle &contRect, Circle &smallCirc, ofstream &ofs){
	ofs<<"<svg>"<<endl<<endl;
	double temp = 0;
	contRect.set_coords(temp, temp);
	Polygon poly(contRect);
	poly.set_fill("fill='yellow'");
	ofs<<poly;
	//contRect.draw(ofs);
	optimalFit(contRect, smallCirc, ofs);
}
void ComposedShape::draw_contRect_smallTri(Rectangle &contRect, Triangle &smallTri, ofstream &ofs){
	ofs<<"<svg>"<<endl<<endl;
	double temp = 0;
	contRect.set_coords(temp, temp);
	Polygon poly(contRect);
	poly.set_fill("fill='yellow'");
	ofs<<poly;
	//contRect.draw(ofs);
	optimalFit(contRect, smallTri, ofs);
}
void ComposedShape::draw_contCirc_smallRect(Circle &contCirc, Rectangle &smallRect, ofstream &ofs){
	ofs<<"<svg>"<<endl<<endl;
	ofs<<"<rect width='"<<2*contCirc.get_radius()<<"' height='"<<2*contCirc.get_radius()
			<<"' fill='transparent'/>"<<endl;

	double temp = (double)contRadius;
	contCirc.set_coords(temp, temp);
	Polygon poly(contCirc);
	poly.set_fill("fill='green'");
	ofs<<poly;
	contCirc.draw(ofs);
	optimalFit(contCirc, smallRect, ofs);

}
void ComposedShape::draw_contCirc_smallCirc(Circle &contCirc, Circle &smallCirc, ofstream &ofs){
	ofs<<"<svg>"<<endl<<endl;
	ofs<<"<rect width='"<<2*contCirc.get_radius()<<"' height='"<<2*contCirc.get_radius()
			<<"' fill='transparent'/>"<<endl;

	double temp = (double)contRadius;
	contCirc.set_coords(temp, temp);
	Polygon poly(contCirc);
	poly.set_fill("fill='green'");
	ofs<<poly;
	//contCirc.draw(ofs);
	optimalFit(contCirc, smallCirc, ofs);
}
void ComposedShape::draw_contCirc_smallTri(Circle &contCirc, Triangle &smallTri, ofstream &ofs){
	ofs<<"<svg>"<<endl<<endl;
	ofs<<"<rect width='"<<2*contCirc.get_radius()<<"' height='"<<2*contCirc.get_radius()
			<<"' fill='transparent'/>"<<endl;

	double temp = (double)contRadius;
	contCirc.set_coords(temp, temp);
	Polygon poly(contCirc);
	poly.set_fill("fill='green'");
	ofs<<poly;
	//contCirc.draw(ofs);
	optimalFit(contCirc, smallTri, ofs);
}
void ComposedShape::draw_contTri_smallRect(Triangle &contTri, Rectangle &smallRect, ofstream &ofs){
	ofs<<"<svg>"<<endl<<endl;
	ofs<<"<rect width='"<<contTri.get_line()<<"' height='"<<contTri.find_height()
			<<"' fill='transparent'/>"<<endl;
	vector<double>crd_x;
	vector<double>crd_y;
	crd_x.push_back(0);
	crd_x.push_back(contTri.get_line() / 2);
	crd_x.push_back(contTri.get_line());
	crd_y.push_back(contTri.find_height());
	crd_y.push_back(0);
	crd_y.push_back(contTri.find_height());
	contTri.set_points(crd_x[0], crd_y[0], crd_x[1], crd_y[1], crd_x[2], crd_y[2]);
	Polygon poly(contTri);
	poly.set_fill("fill='purple'");
	ofs<<poly;
	//contTri.draw(ofs);
	optimalFit(contTri, smallRect, ofs);
}
void ComposedShape::draw_contTri_smallCirc(Triangle &contTri, Circle &smallCirc, ofstream &ofs){
	ofs<<"<svg>"<<endl<<endl;
	ofs<<"<rect width='"<<contTri.get_line()<<"' height='"<<contTri.find_height()
			<<"' fill='transparent'/>"<<endl;
	vector<double>crd_x;
	vector<double>crd_y;
	crd_x.push_back(0);
	crd_x.push_back(contTri.get_line() / 2);
	crd_x.push_back(contTri.get_line());
	crd_y.push_back(contTri.find_height());
	crd_y.push_back(0);
	crd_y.push_back(contTri.find_height());
	contTri.set_points(crd_x[0], crd_y[0], crd_x[1], crd_y[1], crd_x[2], crd_y[2]);
	Polygon poly(contTri);
	poly.set_fill("fill='purple'");
	ofs<<poly;
	//contTri.draw(ofs);
	optimalFit(contTri, smallCirc, ofs);
}
void ComposedShape::draw_contTri_smallTri(Triangle &contTri, Triangle &smallTri, ofstream &ofs){
	ofs<<"<svg>"<<endl<<endl;
	ofs<<"<rect width='"<<contTri.get_line()<<"' height='"<<contTri.find_height()
			<<"' fill='transparent'/>"<<endl;
	vector<double>crd_x;
	vector<double>crd_y;
	crd_x.push_back(0);
	crd_x.push_back(contTri.get_line() / 2);
	crd_x.push_back(contTri.get_line());
	crd_y.push_back(contTri.find_height());
	crd_y.push_back(0);
	crd_y.push_back(contTri.find_height());
	contTri.set_points(crd_x[0], crd_y[0], crd_x[1], crd_y[1], crd_x[2], crd_y[2]);
	Polygon poly(contTri);
	poly.set_fill("fill='purple'");
	ofs<<poly;
	//contTri.draw(ofs);
	optimalFit(contTri, smallTri, ofs);
}


void ComposedShape::container_rectangle_choice(){
	int control = 1;
	string count;
	cout<<"Please enter the container rectangle's width"<<endl;
	while(control==1){
		getline(cin, count);
		stringstream(count)>>contWidth;
		if(contWidth==0){
			cout<<"Error!!!"<<endl
			<<"Please enter the container rectangle's width"<<endl;
		}
		else{
			control = 0;
		}
	}
	control = 1;
	cout<<"Please enter the container rectangle's height"<<endl;
	while(control == 1){
		getline(cin,count);
		stringstream(count)>>contHeight;
		if(contHeight==0){
			cout<<"Error!!!"<<endl
			<<"Please enter the container rectangle's height"<<endl;
		}
		else{
			control = 0;
		}
	}
}


void ComposedShape::setter_contRect_lines(Rectangle& contRect) {
	//container_rectangle_choice();
	contRect.set_lines(contWidth, contHeight);
}

int ComposedShape::getter_contRect_width(Rectangle& contRect) const {
	return contRect.get_width();
}

int ComposedShape::getter_contRect_height(Rectangle &contRect) const{
	return contRect.get_height();
}

void ComposedShape::small_rectangle_choice() {
	int control = 1;
	string count;
	cout<<"Please enter the small rectangle's width"<<endl;
	while(control==1){
		getline(cin, count);
		stringstream(count)>>smallWidth;
		if(smallWidth==0){
			cout<<"Error!!!"<<endl
			<<"Please enter the small rectangle's width"<<endl;
		}
		else{
			control = 0;
		}
	}
	control = 1;
	cout<<"Please enter the small rectangle's height"<<endl;
	while(control == 1){
		getline(cin,count);
		stringstream(count)>>smallHeight;
		if(smallHeight==0){
			cout<<"Error!!!"<<endl
			<<"Please enter the small rectangle's height"<<endl;
		}
		else{
			control = 0;
		}
	}
}

void ComposedShape::setter_smallRect_lines(Rectangle& smallRect) {
	//small_rectangle_choice();
	smallRect.set_lines(smallWidth, smallHeight);
}

int ComposedShape::getter_smallRect_width(Rectangle& smallRect) const {
	return smallRect.get_width();
}

int ComposedShape::getter_smallRect_height(Rectangle& smallRect) const {
	return smallRect.get_height();
}

void ComposedShape::setter_smallRect_coords(Rectangle& smallRect, double &x, double &y) {
	smallRect.set_coords(x,y);
}

double ComposedShape::getter_smallRect_coord_x(Rectangle& smallRect) const {
	return smallRect.get_pos_x();
}

double ComposedShape::getter_smallRect_coord_y(Rectangle& smallRect) const {
	return smallRect.get_pos_y();
}

void ComposedShape::container_circle_choice(){
	int control = 1;
	string count;
	cout<<"Please enter the container circle's radius"<<endl;
	while(control==1){
		getline(cin, count);
		stringstream(count)>>contRadius;
		if(contRadius==0){
			cout<<"Error!!!"<<endl
			<<"Please enter the container circle's radius"<<endl;
		}
		else{
			control = 0;
		}
	}
}

void ComposedShape::setter_contCirc_radius(Circle& contCirc) {
	//container_circle_choice();
	contCirc.set_radius(contRadius);
}

int ComposedShape::getter_contCirc_radius(Circle& contCirc) const {
	return contCirc.get_radius();
}

void ComposedShape::setter_contCirc_coords(Circle& contCirc, double &x, double &y) {
	contCirc.set_coords(x, y);
}

double ComposedShape::getter_contCirc_coord_x(Circle& contCirc) const {
	return contCirc.get_pos_x();
}

double ComposedShape::getter_contCirc_coord_y(Circle& contCirc) const {
	return contCirc.get_pos_y();
}

void ComposedShape::small_circle_choice(){
	int control = 1;
	string count;
	cout<<"Please enter the small circle's radius"<<endl;
	while(control==1){
		getline(cin, count);
		stringstream(count)>>smallRadius;
		if(smallRadius==0){
			cout<<"Error!!!"<<endl
			<<"Please enter the small circle's radius"<<endl;
		}
		else{
			control = 0;
		}
	}
}

void ComposedShape::setter_smallCirc_radius(Circle& smallCirc) {
	//small_circle_choice();
	smallCirc.set_radius(smallRadius);
}

int ComposedShape::getter_smallCirc_radius(Circle& smallCirc) const {
	return smallCirc.get_radius();
}

void ComposedShape::setter_smallCirc_coords(Circle& smallCirc, double &x, double &y) {
	smallCirc.set_coords(x,y);
}

double ComposedShape::getter_smallCirc_coord_x(Circle& smallCirc) const {
	return smallCirc.get_pos_x();
}

double ComposedShape::getter_smallCirc_coord_y(Circle& smallCirc) const {
	return smallCirc.get_pos_y();
}

void ComposedShape::container_triangle_choice() {
	string count;
	cout<<"Please enter the container triangle's edge"<<endl;
	int control = 1;
	while(control == 1){
		getline(cin,count);
		stringstream(count)>>contTriEdge;
		if(contTriEdge==0){
			cout<<"Error!!!"<<endl
			<<"Please enter the container triangle's edge"<<endl;
		}
		else{
			control = 0;
		}
	}
}

void ComposedShape::setter_contTri_line(Triangle& contTri) {
	//container_triangle_choice();
	contTri.set_line(contTriEdge);
}

int ComposedShape::getter_contTri_line(Triangle& contTri) const {
	return contTri.get_line();
}

void ComposedShape::setter_contTri_points(Triangle& contTri, double& x1, double& y1, double& x2,
											double& y2, double& x3, double& y3) {
	contTri.set_points(x1,y1,x2,y2,x3,y3);
}

double ComposedShape::getter_contTri_point_x(Triangle &contTri, int index) const {
	return contTri.get_point_x(index);
}

double ComposedShape::getter_contTri_point_y(Triangle &contTri, int index) const {
	return contTri.get_point_y(index);
}

void ComposedShape::small_triangle_choice() {
	string count;
	cout<<"Please enter the small triangle's edge"<<endl;
	int control = 1;
	while(control == 1){
		getline(cin,count);
		stringstream(count)>>smallTriEdge;
		if(smallTriEdge==0){
			cout<<"Error!!!"<<endl
			<<"Please enter the small triangle' s radius"<<endl;
		}
		else{
			control = 0;
		}
	}
}

void ComposedShape::setter_smallTri_line(Triangle& smallTri) {
	//small_triangle_choice();
	smallTri.set_line(smallTriEdge);
}

int ComposedShape::getter_smallTri_line(Triangle& smallTri) const {
	return smallTri.get_line();
}

void ComposedShape::setter_smallTri_points(Triangle& smallTri,double& x1, double& y1, double& x2,
											double& y2, double& x3, double& y3) {
	smallTri.set_points(x1,y1,x2,y2,x3,y3);
}

double ComposedShape::getter_smallTri_point_x(Triangle &smallTri, int index) const {
	return smallTri.get_point_x(index);
}

double ComposedShape::getter_smallTri_point_y(Triangle& smallTri, int index) const {
	return smallTri.get_point_y(index);
}

Polygon* ComposedShape::get_polygons() const {
	Polygon *poly;
	poly = new Polygon[this->polygons.size()];
	int i;
	for(i=0;i<this->polygons.size();++i)
		poly[i] = polygons[i];
	return poly;
}

const Polygon ComposedShape::operator [](int index) const {
	return this->get_polygons()[index];
}

const ComposedShape& ComposedShape::operator +=(Polygon& other) {
	this->polygons.push_back(other);
	return *this;
}

Rectangle* ComposedShape::get_smallRects() const {
	Rectangle *rect;
	rect = new Rectangle[this->smallRects.size()];
	int i;
	for(i=0;i<this->smallRects.size();++i)
		rect[i] = smallRects[i];
	return rect;
}

const ComposedShape& ComposedShape::operator +=(Rectangle& other) {
	this->smallRects.push_back(other);
	return *this;
}

Circle* ComposedShape::get_smallCircs() const {
	Circle *circ;
	circ = new Circle[this->smallCircs.size()];
	int i;
	for(i=0;i<this->smallCircs.size();++i)
		circ[i] = smallCircs[i];
	return circ;
}

const ComposedShape& ComposedShape::operator +=(Circle& other) {
	this->smallCircs.push_back(other);
	return *this;
}

Triangle* ComposedShape::get_smallTries() const {
	Triangle *tri;
	tri = new Triangle[this->smallTries.size()];
	int i;
	for(i=0;i<this->smallTries.size();++i)
		tri[i] = smallTries[i];
	return tri;
}

const ComposedShape& ComposedShape::operator +=(Triangle& other) {
	this->smallTries.push_back(other);
	return *this;
}








