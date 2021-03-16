#include <iostream>
#include<fstream>
#include <string>
#include <sstream>
#include "header.h"
using namespace std;

struct RectA{
	string idntfy = "<rect";
	string coord_x = "x='"; int crd_x;
	string coord_y = "y='"; int crd_y;
	string width = "width='";
	string height = "height='";
	string fill = "fill='yellow'/>";
};

struct Circ{
	string idntfy = "<circle";
	string coord_x = "cx='"; int x;
	string coord_y = "cy='"; int y;
	string rad = "r='";
	string fill = "fill='green'/>";
};

struct TriA{
	string idntfy = "<polygon points='";
	int points[3][2];
	string transform = "transform='rotate(";
	int points2[3];
	string fill = "fill='purple'/>";
};

//cont.shape==rectangle and small.shape==rectangle --> draw them and calculate free space.
void recta_to_recta(int &contRectWidth, int &contRectHeight, int &smallRectWidth, int &smallRectHeight, fstream &file){
	RectA rect1, rect2;
	rect2.fill = "fill='red'/>";
	rect2.crd_x = 0; rect2.crd_y = 0;
	string stroke = " stroke='yellow' stroke-width='1' ";
	file<<"<svg>"<<endl<<endl;
	file<<rect1.idntfy<<" "<<rect1.width<<contRectWidth<<"' "<<rect1.height<<contRectHeight<<"' "<<rect1.fill<<endl;

	int countWidth = contRectWidth / smallRectWidth;	//for loop
	int countHeight = contRectHeight / smallRectHeight;	//for loop
	int countForShape = 0;
	int contShapeArea = contRectWidth * contRectHeight;
	int smallShapeArea = smallRectWidth * smallRectHeight;


	while(countHeight>0){
	
		while(countWidth>0){
            //the smaller's other point control
			if(((rect2.crd_x + smallRectWidth) < contRectWidth) || ((rect2.crd_x + smallRectWidth) == contRectWidth)){
				file<<rect2.idntfy<<" "<<rect2.width<<smallRectWidth<<"' "<<rect2.height<<smallRectHeight<<"' "<<rect2.coord_x
				<<rect2.crd_x<<"' "<<rect2.coord_y<<rect2.crd_y<<"' "<<stroke<<rect2.fill<<endl;
				rect2.crd_x = rect2.crd_x + smallRectWidth;
				countForShape = countForShape + 1;
				countWidth = countWidth - 1;
			}

			else{
				countWidth=-1;
			}
		}
		//updates for the next raw
		rect2.crd_y = rect2.crd_y + smallRectHeight;
		rect2.crd_x = 0;
		countWidth = contRectWidth / smallRectWidth;
		countHeight = countHeight - 1;
	}
    //the smaller's rotating control
	if(contRectWidth != (countWidth*smallRectWidth) && (contRectHeight > smallRectWidth || contRectHeight == smallRectWidth)){
		int countForFree = contRectWidth - (countWidth*smallRectWidth);
		rect2.crd_y = 0;

		int tempHeight = smallRectWidth;
		int tempWidth = smallRectHeight;

		int control2 = contRectHeight / smallRectWidth;
		while(control2>0){
		    //free space control and comparing ups situation
			if(countForFree>smallRectHeight || countForFree==smallRectHeight){
				int control = countForFree / smallRectHeight;
				rect2.crd_x = countWidth*smallRectWidth;

				while(control>0){
					if((rect2.crd_x + tempWidth) < contRectWidth || (rect2.crd_x + tempWidth) == contRectWidth){
						file<<rect2.idntfy<<" "<<rect2.width<<tempWidth<<"' "<<rect2.height<<tempHeight<<"' "<<rect2.coord_x
						<<rect2.crd_x<<"' "<<rect2.coord_y<<rect2.crd_y<<"' "<<stroke<<rect2.fill<<endl;
						rect2.crd_x = rect2.crd_x + tempWidth;
						countForShape = countForShape + 1;
						control = control - 1;
					}

					if(!((rect2.crd_x + tempWidth) < contRectWidth || (rect2.crd_x + tempWidth) == contRectWidth)){
						rect2.crd_y = rect2.crd_y + tempHeight;
						control = -1;
					}
				}
			}
			control2 = control2 - 1;
		}
	}
	file<<endl<<"</svg>"<<endl;
	int diffArea = contShapeArea - (countForShape*smallShapeArea);
	cout<<"I can fit at most "<<countForShape<<" small shapes into the main container. The empty area in container is "<<diffArea<<"."<<endl;
}

//cont.shape==rectangle and small.shape==circle --> draw them and calculate free space.
//first of all draw bigger and smaller's coordinates assigned and  it is drawn.
void recta_to_circ(int &contRectWidth, int &contRectHeight, int &smallCircRadius, fstream &file){
	RectA rect;
	Circ circ;
	circ.x = smallCircRadius;
	circ.y = smallCircRadius;
	file<<"<svg>"<<endl<<endl;
	file<<rect.idntfy<<" "<<rect.width<<contRectWidth<<"' "<<rect.height<<contRectHeight<<"' "<<rect.fill<<endl;

	int jumpControl = smallCircRadius * 3;
	int jump = smallCircRadius * 2;
	int countForShape = 0;
	int control1 = contRectHeight / (2*smallCircRadius);//count for that how many smaller?
	int control2 = 1;

	while(control1>0){

		file<<circ.idntfy<<" "<<circ.coord_x<<circ.x<<"' "<<circ.coord_y<<circ.y<<"' "<<circ.rad<<smallCircRadius<<"' "<<circ.fill<<endl;
		countForShape = countForShape + 1;
		while(control2 == 1){
            //control for next circ's coords.
			if((circ.x+jumpControl)>contRectWidth){
				control2 = 0;
			}
			else{
				circ.x = circ.x + jump;
				file<<circ.idntfy<<" "<<circ.coord_x<<circ.x<<"' "<<circ.coord_y<<circ.y<<"' "<<circ.rad
				<<smallCircRadius<<"' "<<circ.fill<<endl;
				countForShape = countForShape + 1;
			}
		}
		//ups for next raw
		control2 = 1;
		circ.y = circ.y + jump;
		circ.x = smallCircRadius;
		control1 = control1 - 1;
	}

	file<<endl<<"</svg>"<<endl;
	double diffArea =(contRectHeight*contRectWidth) - (smallCircRadius*smallCircRadius*3.14*countForShape);
	cout<<"I can fit at most "<<countForShape<<" small shapes into the main container. The empty area in container is "<<diffArea<<"."<<endl;

}

//cont.shape==rectangle and small.shape==triangle --> draw them and calculate free space.
void recta_to_tria(int &contRectWidth, int &contRectHeight, int &smallTriEdge, fstream &file){
	RectA rect;
	TriA tria;
	string stroke = " stroke='black' ";
	int countForShape = 0;

	rect.crd_x = 0;
	rect.crd_y = 0;
	file<<"<svg>"<<endl<<endl;
	file<<rect.idntfy<<" "<<rect.width<<contRectWidth<<"' "<<rect.height<<contRectHeight<<"' "<<rect.fill<<endl;

	double height = (smallTriEdge/2)*find_sqrt(3);
	tria.points[0][0] = 0;
	tria.points[0][1] = 0;
	tria.points[1][0] = smallTriEdge/2;
	tria.points[1][1] = height;
	tria.points[2][0] = smallTriEdge;
	tria.points[2][1] = 0;

	double tempSecPoint[2];
	double tempTrdPoint[2];

	int control1 = 0;
	int control2 = 0;
	int raw = 0;
	bool position = true;
	while(control1==0){
		if(tria.points[2][1]>contRectHeight || tria.points[0][1]>contRectHeight || tria.points[1][1]>contRectHeight){
			control1=1;
		}
		else{
			while(control2==0){
			//control points for overflow
				if(tria.points[2][0]>contRectWidth || tria.points[2][1]>contRectHeight ||
					tria.points[0][0]>contRectWidth || tria.points[0][1]>contRectHeight ||
					tria.points[1][0]>contRectWidth || tria.points[1][1]>contRectHeight){

					raw = raw + 1;

					if(position==true){
						tria.points[0][0] = 0;
						tria.points[0][1] = (raw+1)*height;
						tria.points[1][0] = smallTriEdge/2;
						tria.points[1][1] = raw*height;
						tria.points[2][0] = smallTriEdge;
						tria.points[2][1] = (raw+1)*height;
					}
					if(position==false){
						tria.points[0][0] = 0;
						tria.points[0][1] = raw*height;
						tria.points[1][0] = smallTriEdge/2;
						tria.points[1][1] = (raw+1)*height;
						tria.points[2][0] = smallTriEdge;
						tria.points[2][1] = raw*height;
					}
					position = !position;
					control2=1;
				}
				else{
					file<<tria.idntfy<<tria.points[0][0]<<" "<<tria.points[0][1]<<" "<<tria.points[1][0]<<" "<<tria.points[1][1]<<" "
						<<tria.points[2][0]<<" "<<tria.points[2][1]<<"' "<<stroke<<tria.fill<<endl;
					countForShape++;
					tempSecPoint[0] = tria.points[1][0];
					tempSecPoint[1] = tria.points[1][1];
					tempTrdPoint[0] = tria.points[2][0];
					tempTrdPoint[1] = tria.points[2][1];

					tria.points[0][0] = tempSecPoint[0];
					tria.points[0][1] = tempSecPoint[1];
					tria.points[1][0] = tempTrdPoint[0];
					tria.points[1][1] = tempTrdPoint[1];
					tria.points[2][0] = tempSecPoint[0] + smallTriEdge;
					tria.points[2][1] = tempSecPoint[1];
				}
			}
			control2 = 0;
		}
	}



	file<<endl<<"</svg>"<<endl;



	double smallShapesArea = countForShape * ((smallTriEdge*height)/2);
    double diffArea = (contRectWidth*contRectHeight) - smallShapesArea;
    cout<<"I can fit at most "<<countForShape<<" small shapes into the main container. The empty area in container is "<<diffArea<<"."<<endl;
}

//cont.shape==circle and small.shape==circle --> draw them and calculate free space.
//first of all drawn bigger and small's coords are assigned
void circ_to_circ(int &contCircRadius, int &smallCircRadius, fstream &file){

    Circ circ1, circ2;
    circ2.fill = "fill='black'/>";
    circ1.x = contCircRadius;
    circ1.y = contCircRadius;

    file<<"<svg>"<<endl<<endl;
    file<<"<rect width='"<<(2*contCircRadius)<<"' "<<"height='"<<(2*contCircRadius)<<"' "<<"fill='transparent'"<<"/>"<<endl;
    file<<circ1.idntfy<<" "<<circ1.coord_x<<circ1.x<<"' "<<circ1.coord_y<<circ1.y<<"' "<<circ1.rad
    <<contCircRadius<<"' "<<circ1.fill<<endl;

    circ2.x = smallCircRadius;
    circ2.y = smallCircRadius;

    int count = contCircRadius - smallCircRadius;//for the tangent points
    int jump = 2*smallCircRadius;//ups
    int control1 = smallCircRadius;
    int control2 =  smallCircRadius;
    int smallShapes = 0;

    while(control1<2*contCircRadius){
        double distance;
        while(control2<2*contCircRadius){
            distance = find_sqrt(((circ1.x-circ2.x)*(circ1.x-circ2.x)) + ((circ1.y-circ2.y)*(circ1.y-circ2.y)));//sqrt((x1-x2)^2+(y1-y2)^2) --> distance between two points
            //is it tangant points?
            if(distance>count){
                control2++;
                circ2.x++;
            }

            else{
                //for the overflowing?
                if((distance+smallCircRadius)>contCircRadius){
                    control2++;
                    circ2.x++;
                }
                else{
                    file<<circ2.idntfy<<" "<<circ2.coord_x<<circ2.x<<"' "<<circ2.coord_y<<circ2.y<<"' "<<circ2.rad
                    <<smallCircRadius<<"' "<<circ2.fill<<endl;
                    smallShapes++;
                    control2 = control2 + jump;
                    circ2.x = circ2.x + jump;
                }
            }
        }
        //ups for next raw
        circ2.x = smallCircRadius;
        circ2.y = circ2.y + jump;
        control2 = smallCircRadius;
        control1 = control1 + jump;
    }
    file<<endl<<"</svg>"<<endl;

    double smallShapesArea = (3.14*smallCircRadius*smallCircRadius) * smallShapes;
    double diffArea = (3.14*contCircRadius*contCircRadius) - smallShapesArea;
    cout<<"I can fit at most "<<smallShapes<<" small shapes into the main container. The empty area in container is "<<diffArea<<"."<<endl;
}

//cont.shape==circle and small.shape==rectangle --> draw them and calculate free space.
//same algorithm the up's func.
void circ_to_recta(int &contCircRadius, int &smallRectWidth, int &smallRectHeight, fstream &file){
	Circ circ;
	RectA rect;
	circ.x = contCircRadius;
	circ.y = contCircRadius;
	string stroke = " stroke='black' ";

	file<<"<svg>"<<endl<<endl;
	file<<"<rect width='"<<(2*contCircRadius)<<"' "<<"height='"<<(2*contCircRadius)<<"' "<<"fill='transparent'"<<"/>"<<endl;
	file<<circ.idntfy<<" "<<circ.coord_x<<circ.x<<"' "<<circ.coord_y<<circ.y<<"' "<<circ.rad<<contCircRadius<<"' "<<circ.fill<<endl;

	rect.crd_x=0;
	rect.crd_y=0;
	double distance;
	int control = 0;
	int shapes=0;

	while(rect.crd_y<contCircRadius*2-smallRectHeight){
		while(rect.crd_x<contCircRadius*2-smallRectWidth){
			distance = find_sqrt(((circ.x-rect.crd_x)*(circ.x-rect.crd_x)) 
			+ ((circ.y-rect.crd_y)*(circ.y-rect.crd_y)));
			if(distance > contCircRadius){
				rect.crd_x++;
			}

			else{
				double temp = find_sqrt(((circ.x-(rect.crd_x+smallRectWidth))*(circ.x-(rect.crd_x+smallRectWidth))) 
				+ ((circ.y-rect.crd_y)*(circ.y-rect.crd_y)));   //for the other point of rec.

				if(temp > contCircRadius){
					rect.crd_x++;
				}

				else{
					double temp2 = find_sqrt(((circ.x-rect.crd_x)*(circ.x-rect.crd_x)) 
					+ ((circ.y-(rect.crd_y + smallRectHeight))*(circ.y-(rect.crd_y + smallRectHeight)))); //for the other point of rec.

					if(temp2 > contCircRadius){
						rect.crd_x++;
					}

					else{
						file<<rect.idntfy<<" "<<rect.width<<smallRectWidth<<"' "<<rect.height
						<<smallRectHeight<<"' "<<rect.coord_x<<rect.crd_x<<"' "<<rect.coord_y<<rect.crd_y<<"' "<<stroke<<rect.fill<<endl;
						shapes++;
						control = 1;
						rect.crd_x = rect.crd_x + smallRectWidth;
					}
				}
			}
		}
		//for in the previous row has small shape ?
		//true that mean next line
		if(control==0){
		    rect.crd_x = 0;
		    control = 0;
		    rect.crd_y++;
		}
		//true that mean next raw
	    if(control==1){
	        control = 0;
	        rect.crd_x = 0;
	        rect.crd_y = rect.crd_y + smallRectHeight;
	    }

	}
    int smallShapesArea = shapes*(smallRectWidth*smallRectHeight);
    double diffArea = (3.14*contCircRadius*contCircRadius) - smallShapesArea;
	file<<endl<<"</svg>"<<endl;
	cout<<"I can fit at most "<<shapes<<" small shapes into the main container. The empty area in container is "<<diffArea<<"."<<endl;

}

//cont.shape==circle and small.shape==triangle --> draw them and calculate free space.
void circ_to_tria(int &contCircRadius, int &smallTriEdge, fstream &file){
	Circ circ;
	TriA tria;

	RectA rect;
	rect.crd_x = 0;
	rect.crd_y = 0;
	circ.x = contCircRadius;
	circ.y = contCircRadius;
	string stroke = " stroke='blue' stroke-width='0.05' ";

	file<<"<svg>"<<endl<<endl;
	file<<"<rect width='"<<(2*contCircRadius)<<"' "<<"height='"<<(2*contCircRadius)<<"' "<<"fill='transparent'"<<"/>"<<endl;
	file<<circ.idntfy<<" "<<circ.coord_x<<circ.x<<"' "<<circ.coord_y<<circ.y<<"' "<<circ.rad<<contCircRadius<<"' "<<circ.fill<<endl;

	double distance;
	bool control = true;
	bool control2 = true;
    int countForShape = 0;
    double point_x = 0.00;
    double point_y = 1.00;
    double point2_x, point2_y, point3_x, point3_y;
    double heightForTri = (smallTriEdge/2)*find_sqrt(3);

    while(point_y<(2*contCircRadius)-heightForTri){
    	while(point_x<(2*contCircRadius)){
    		distance = find_sqrt((circ.x-point_x)*(circ.x-point_x) + (circ.y-point_y)*(circ.y-point_y));
    		if(distance>contCircRadius){
    			point_x = point_x + 0.5;
    		}

    		else{
    			if(control2==true){
    				point2_x = point_x - (smallTriEdge/2);
    				point2_y = point_y + heightForTri;
    				point3_x = point_x + (smallTriEdge/2);
    				point3_y = point2_y;
    			}
    			if(control2==false){
    				double temp_x, temp_y;
    				temp_x = point_x;
    				temp_y = point_y;
    				point_x = temp_x - smallTriEdge;
    				point_y = temp_y;
    				point2_x = temp_x - (smallTriEdge/2);
    				point2_y = temp_y + heightForTri;
    				point3_x = temp_x;
    				point3_y = temp_y;
    			}
    			control2 = !control2;
    			double temp = find_sqrt((circ.x-point_x)*(circ.x-point_x) + (circ.y-point_y)*(circ.y-point_y));
    			double temp2 = find_sqrt((circ.x-point2_x)*(circ.x-point2_x) + (circ.y-point2_y)*(circ.y-point2_y));
    			double temp3 = find_sqrt((circ.x-point3_x)*(circ.x-point3_x) + (circ.y-point3_y)*(circ.y-point3_y));
    			if(temp2>contCircRadius || temp3>contCircRadius || temp>contCircRadius){
    				point_x = point_x + 0.5;
    			}
    			else{
    				file<<tria.idntfy<<point_x<<" "<<point_y<<" "<<point2_x<<" "<<point2_y<<" "
    					<<point3_x<<" "<<point3_y<<"' "<<stroke<<tria.fill<<endl;
    				countForShape++;
    				control = false;
    				point_x = point_x + smallTriEdge;
    			}
    		}
    	}
    	if(control==true){
    		point_x = 0.00;
    		control = true;
    		point_y = point_y + 0.5;
    	}
    	if(control==false){
    		point_x = 0.00;
    		point_y = point_y + heightForTri;
    		control = true;
    	}
    }

    file<<endl<<"</svg>"<<endl;
    double smallShapesArea = countForShape * (smallTriEdge*heightForTri/2);
    double diffArea = (contCircRadius*contCircRadius*3.14) - smallShapesArea;
    cout<<"I can fit at most "<<countForShape<<" small shapes into the main container. The empty area in container is "<<diffArea<<"."<<endl;
}

//cont.shape==triangle and small.shape==rectangle --> draw them and calculate free space.
void tria_to_recta(int &contTriEdge, int &smallRectWidth, int &smallRectHeight, fstream &file){

    TriA tri;
    RectA rect;
    double height = (contTriEdge/2) * find_sqrt(3);
    cout<<"height = "<<height<<endl;

    tri.points[0][0] = 0;
    tri.points[0][1] = height;
    tri.points[1][0] = contTriEdge/2;
    tri.points[1][1] = 0;
    tri.points[2][0] = contTriEdge;
    tri.points[2][1] = height;

    double temp_y = height - smallRectHeight;
    double temp_x = smallRectHeight/find_sqrt(3);
    string stroke = " stroke='blue' ";



    file<<"<svg>"<<endl<<endl;
    file<<"<rect width='"<<contTriEdge<<"' "<<"height='"<<height<<"' "<<rect.coord_x<<"0' "<<rect.coord_y<<"0' "<<"fill='transparent'"<<"/>"<<endl;
    file<<tri.idntfy<<tri.points[0][0]<<" "<<tri.points[0][1]<<" "<<tri.points[1][0]<<" "<<tri.points[1][1]<<" "
    		<<tri.points[2][0]<<" "<<tri.points[2][1]<<"' "<<tri.fill<<endl;

    int smallShapes = 0;
    int control = 1;//for that how many rows have drawn smaller shapes
    int control2 = 0;
    while(temp_y>0){
    	while(control2==0){
    		double count = contTriEdge - ((control*smallRectHeight)/find_sqrt(3));//for line break or raw break
    		//there is line break ?
    		if(count< temp_x+smallRectWidth){
    			control2 = 1;
    		}
    		else{
    			file<<rect.idntfy<<" "<<rect.width<<smallRectWidth<<"' "<<rect.height
    			    <<smallRectHeight<<"' "<<rect.coord_x<<temp_x<<"' "<<rect.coord_y<<temp_y<<"' "<<stroke<<rect.fill<<endl;
    			smallShapes++;
    			temp_x = temp_x + smallRectWidth;
    		}
    	}
    	control++;
    	control2 = 0;
    	temp_x = (control*smallRectHeight/find_sqrt(3));
    	temp_y = temp_y - smallRectHeight;
    }
    file<<"</svg>"<<endl;
    double areaForSmallShapes = smallShapes*smallRectHeight*smallRectWidth;
    double diffArea = ((contTriEdge*height)/2)-areaForSmallShapes;
    cout<<"I can fit at most "<<smallShapes<<" small shapes into the main container. The empty area in container is "<<diffArea<<"."<<endl;
}
//cont.shape==triangle and small.shape==circ --> draw them and calculate free space.
void tria_to_circ(int &contTriEdge, int &smallCircRadius, fstream &file){
    TriA tri;
    Circ circ;
    RectA rect;
    double height1 = (contTriEdge/2) * find_sqrt(3);
    double height = height1;
    double base = (double)contTriEdge;

    tri.points[0][0] = 0;
    tri.points[0][1] = height;
    tri.points[1][0] = contTriEdge/2;
    tri.points[1][1] = 0;
    tri.points[2][0] = contTriEdge;
    tri.points[2][1] = height;

    double temp_y = height - smallCircRadius;//for circ's y's coordinate
    double temp_x = smallCircRadius*find_sqrt(3);//for circ's x's coordinate

    file<<"<svg>"<<endl<<endl;
    file<<"<rect width='"<<contTriEdge<<"' "<<"height='"<<height<<"' "<<rect.coord_x<<"0' "<<rect.coord_y<<"0' "<<"fill='transparent'"<<"/>"<<endl;
    file<<tri.idntfy<<tri.points[0][0]<<" "<<tri.points[0][1]<<" "<<tri.points[1][0]<<" "<<tri.points[1][1]<<" "
        <<tri.points[2][0]<<" "<<tri.points[2][1]<<"' "<<tri.fill<<endl;

    int control = 0;
    int control2 = 0;
	int countForShape = 0;
	double decForBase;//to shrink base

	while(temp_y>0){
		while(control2==0){
			double count = base-(smallCircRadius*find_sqrt(3));
			if(count<temp_x){
				control2 = 1;
			}
			else{
				file<<circ.idntfy<<" "<<circ.coord_x<<temp_x<<"' "<<circ.coord_y<<temp_y<<"' "
					<<circ.rad<<smallCircRadius<<"' "<<circ.fill<<endl;
				countForShape++;
				temp_x = temp_x + (2*smallCircRadius);
			}
		}
		control++;
		decForBase = ((smallCircRadius*2)/find_sqrt(3));//to shrink base
		base = base - decForBase;
		double decForHeight = 2*smallCircRadius;//to shrink height
		height = height - decForHeight;
		control2 = 0;
		temp_x = (smallCircRadius*find_sqrt(3)) + (decForBase*control);//new x's coord.
		temp_y = height - smallCircRadius;//new y's coord.
		//cout<<"base = "<<base<<" height = "<<height<<" temp_x= "<<temp_x<<" temp_y= "<<temp_y<<endl;
	}
	file<<"</svg>"<<endl;
	double areaForSmallShapes= countForShape*(3.14*smallCircRadius*smallCircRadius);
    double diffArea = ((contTriEdge*height1)/2)-areaForSmallShapes;
    cout<<"I can fit at most "<<countForShape<<" small shapes into the main container. The empty area in container is "<<diffArea<<"."<<endl;
}

//cont.shape==triangle and small.shape==triangle --> draw them and calculate free space.
//this func is same recta_to_tria
void tria_to_tria(int &contTriEdge, int &smallTriEdge, fstream &file){
	TriA tria1, tria2;
	RectA rect;
	tria2.fill = "fill='blue'/>";
	string stroke = " stroke='pink' stroke-width='0.05' ";
	rect.crd_x = 0;
	rect.crd_y = 0;

    int countForShape = 0;
    double heightForBig = (contTriEdge/2) * find_sqrt(3);
    tria1.points[0][0] = contTriEdge/2;
    tria1.points[0][1] = 0;
    tria1.points[1][0] = 0;
    tria1.points[1][1] = heightForBig;
    tria1.points[2][0] = contTriEdge;
    tria1.points[2][1] = heightForBig;

    file<<"<svg>"<<endl<<endl;
    file<<"<rect width='"<<contTriEdge<<"' "<<"height='"<<heightForBig<<"' "<<rect.coord_x<<"0' "<<rect.coord_y<<"0' "<<"fill='transparent'"<<"/>"<<endl;
    file<<tria1.idntfy<<tria1.points[0][0]<<" "<<tria1.points[0][1]<<" "<<tria1.points[1][0]<<" "<<tria1.points[1][1]<<" "
    		<<tria1.points[2][0]<<" "<<tria1.points[2][1]<<"' "<<tria1.fill<<endl;

    double heightForSmall = (smallTriEdge/2) * find_sqrt(3);
    tria2.points[0][0] = 0;
    tria2.points[0][1] = heightForBig;
    tria2.points[1][0] = smallTriEdge/2;
    tria2.points[1][1] = heightForBig - heightForSmall;
    tria2.points[2][0] = smallTriEdge;
    tria2.points[2][1] = heightForBig;

    double tempSecPoint[2];
    double tempTrdPoint[2];

    int control1=0;
    int control2=0;
    int raw = 0;

    double tempForWidth = (double)contTriEdge;

    while(control1==0){
    	if(tria2.points[2][1]<1 || tria2.points[0][1]<1 || tria2.points[1][1]<1){
    		control1=1;
    	}
    	else{
    		while(control2==0){
    			if(tria2.points[2][0]>tempForWidth || tria2.points[2][1]<1 ||
    				tria2.points[0][0]>tempForWidth || tria2.points[0][1]<1 ||
    				tria2.points[1][0]>tempForWidth || tria2.points[1][1]<1){

    				raw = raw + 1;
    				tria2.points[0][0] = raw * smallTriEdge / 2;
    				tria2.points[0][1] = heightForBig - (raw*heightForSmall);
    				tria2.points[1][0] = (raw+1)* (smallTriEdge/2);
    				tria2.points[1][1] = heightForBig - ((raw+1)*heightForSmall);
    				tria2.points[2][0] = (raw*smallTriEdge/2) + smallTriEdge;
    				tria2.points[2][1] = heightForBig - (raw*heightForSmall);

    				tempForWidth = tempForWidth - (smallTriEdge/2);

    				control2=1;
    			}
    			else{
    				file<<tria2.idntfy<<tria2.points[0][0]<<" "<<tria2.points[0][1]<<" "<<tria2.points[1][0]<<" "<<tria2.points[1][1]<<" "
    					<<tria2.points[2][0]<<" "<<tria2.points[2][1]<<"' "<<stroke<<tria2.fill<<endl;
    				countForShape++;
    				tempSecPoint[0] = tria2.points[1][0];
    				tempSecPoint[1] = tria2.points[1][1];
    				tempTrdPoint[0] = tria2.points[2][0];
    				tempTrdPoint[1] = tria2.points[2][1];

    				tria2.points[0][0] = tempSecPoint[0];
    				tria2.points[0][1] = tempSecPoint[1];
    				tria2.points[1][0] = tempTrdPoint[0];
    				tria2.points[1][1] = tempTrdPoint[1];
    				tria2.points[2][0] = tempSecPoint[0] + smallTriEdge;
    				tria2.points[2][1] = tempSecPoint[1];
    			}
    		}
    		control2 = 0;
    	}
    }

    file<<"</svg>"<<endl<<endl;
    double smallShapesArea = countForShape * (smallTriEdge * heightForSmall / 2);
    double diffArea = (contTriEdge * heightForBig / 2) - smallShapesArea;
    cout<<"I can fit at most "<<countForShape<<" small shapes into the main container. The empty area in container is "<<diffArea<<"."<<endl;
}

//draw shapes and informs the user
void draw(int &contRectWidth, int &contRectHeight, int &contCircRadius, int &contTriEdge,
          int &smallRectWidth, int &smallRectHeight, int &smallCircRadius, int &smallTriEdge,
          Shapes &containerShape, Shapes &smallShape){
    
    fstream file;
    file.open("output.svg", ios::out|ios::in|ios::app);
    
    if(containerShape==rectangle && smallShape==rectangle){
        recta_to_recta(contRectWidth, contRectHeight, smallRectWidth, smallRectHeight, file);
        file.close();
        
    }
    if(containerShape==rectangle && smallShape==circle){
        recta_to_circ(contRectWidth, contRectHeight, smallCircRadius, file);
        file.close();
    }
    if(containerShape==rectangle && smallShape==triangle){
        recta_to_tria(contRectWidth, contRectHeight, smallTriEdge, file);
        file.close();
    }
    if(containerShape==circle && smallShape==rectangle){
        circ_to_recta(contCircRadius, smallRectWidth, smallRectHeight, file);
        file.close();
    }
    if(containerShape==circle && smallShape==circle){
        circ_to_circ(contCircRadius, smallCircRadius, file);
        file.close();
    }
    if(containerShape==circle && smallShape==triangle){
        circ_to_tria(contCircRadius, smallTriEdge, file);
        file.close();
    }
    if(containerShape==triangle && smallShape==rectangle){
        tria_to_recta(contTriEdge, smallRectWidth, smallRectHeight, file);
        file.close();
    }
    if(containerShape==triangle && smallShape==circle){
        tria_to_circ(contTriEdge, smallCircRadius, file);
        file.close();
    }
    if(containerShape==triangle && smallShape==triangle){
        tria_to_tria(contTriEdge, smallTriEdge, file);
        file.close();
    }
}

void inputs_control_for_return_result(int &contRectWidth, int &contRectHeight, int &contCircRadius, int &contTriEdge,
                                      int &smallRectWidth, int &smallRectHeight, int &smallCircRadius, int &smallTriEdge,
                                      Shapes &containerShape, Shapes &smallShape){
                    
	containerShape = user_container_shape_choice();

	if(containerShape == rectangle){
		container_rectangle_choice(contRectWidth, contRectHeight);
		smallShape = user_small_shape_choice();

		int control = 1;
		while(control == 1){
			if(smallShape == rectangle){
				small_shape_rectangle_choice(smallRectWidth, smallRectHeight);

				if(contRectWidth < contRectHeight){

					if(contRectWidth < smallRectWidth || contRectWidth < smallRectHeight){
						cout<<"Error!!!"<<endl;
					}

					else{
						control = 2;
					}
				}

				if(contRectWidth > contRectHeight){

					if(contRectHeight < smallRectWidth || contRectHeight < smallRectHeight){
						cout<<"Error!!!"<<endl;
					}
					else{
						control = 2;
					}
				}

				if(contRectWidth == contRectHeight){

					if(contRectWidth < smallRectWidth || contRectWidth < smallRectHeight){
						cout<<"Error!!!"<<endl;
					}
					else{
						control = 2;
					}
				}
			}

			if(smallShape == circle){
				small_shape_circle_choice(smallCircRadius);

				if(contRectWidth < contRectHeight){

					if(contRectWidth < 2*smallCircRadius){
						cout<<"Error!!!"<<endl;
					}
					else{
						control = 2;
					}
				}

				if(contRectWidth > contRectHeight){

					if(contRectHeight < 2*smallCircRadius){
						cout<<"Error!!!"<<endl;
					}
					else{
						control = 2;
					}
				}

				if(contRectWidth == contRectHeight){
					if(contRectWidth < 2*smallCircRadius){
						cout<<"Error!!!"<<endl;
					}
					else{
						control = 2;
					}
				}
			}

			if(smallShape == triangle){
				small_shape_triangle_choice(smallTriEdge);

				if(contRectWidth < contRectHeight){

					if((smallTriEdge * find_sqrt(3))/2 > contRectWidth){	//(edge*sqrt(3)) / 2 vertical edge of the triangle
						cout<<"Error!!!"<<endl;
					}
					else{
						control = 2;
					}
				}

				if(contRectWidth > contRectHeight){

					if((smallTriEdge * find_sqrt(3))/2 > contRectHeight){
						cout<<"Error!!!"<<endl;
					}
					else{
						control = 2;
					}
				}

				if(contRectWidth == contRectHeight){
					if((smallTriEdge * find_sqrt(3))/2 > contRectWidth){
						cout<<"Error!!!"<<endl;
					}
					else{
						control = 2;
					}
				}
			}
		}
	}
	if(containerShape == circle){
		int control = 1;
		container_circle_choice(contCircRadius);
		smallShape = user_small_shape_choice();

		while(control==1){
			if(smallShape == rectangle){
				small_shape_rectangle_choice(smallRectWidth, smallRectHeight);
				double diagonal = find_sqrt((smallRectWidth*smallRectWidth)+(smallRectHeight*smallRectHeight));//find the Rect's diagonal
				if(diagonal>contCircRadius){					//Rect's diagonal cannot be grater than the radius
					cout<<"Error!!!"<<endl;
				}
				else{
					control = 2;
				}
			}

			if(smallShape == circle){
				small_shape_circle_choice(smallCircRadius);
				if(smallCircRadius>contCircRadius){
					cout<<"Error!!!"<<endl;
				}
				else{
					control = 2;
				}
			}

			if(smallShape == triangle){
				small_shape_triangle_choice(smallTriEdge);
				if(smallTriEdge>(contCircRadius*find_sqrt(3))){//the edge cannot be greater than the root three of the radius
					cout<<"Error!!!"<<endl;
				}
				else{
					control = 2;
				}
			}
		}

	}
	if(containerShape == triangle){
		container_triangle_choice(contTriEdge);
		smallShape = user_small_shape_choice();
		int control = 1;

		while(control==1){

			if(smallShape == rectangle){
				small_shape_rectangle_choice(smallRectWidth, smallRectHeight);

				if(smallRectWidth<smallRectHeight){

					if(smallRectHeight>contTriEdge || smallRectHeight==contTriEdge){
						cout<<"Error!!!"<<endl;
					}
					else{
						double temp = ((contTriEdge - smallRectHeight)/2) * find_sqrt(3);

						if(temp>smallRectWidth){
							cout<<"Error!!!"<<endl;
						}
						else{
							control = 2;
						}
					}
				}
				if(smallRectWidth>smallRectHeight){

					if(smallRectWidth>contTriEdge || smallRectWidth==contTriEdge){
						cout<<"Error!!!"<<endl;
					}
					else{
						double temp = ((contTriEdge - smallRectWidth)/2) * find_sqrt(3);

						if(temp>smallRectHeight){
							cout<<"Error!!!"<<endl;
						}
						else{
							control = 2;
						}
					}
				}
				if(smallRectWidth==smallRectHeight){

					if(smallRectWidth>contTriEdge || smallRectWidth==contTriEdge){
						cout<<"Error!!!"<<endl;
					}
					else{
						double temp = ((contTriEdge - smallRectWidth)/2) * find_sqrt(3);

						if(temp>smallRectHeight){
							cout<<"Error!!!"<<endl;
						}
						else{
							control = 2;
						}
					}
				}

			}

			if(smallShape == circle){
				small_shape_circle_choice(smallCircRadius);
				double temp = ((contTriEdge/2)*find_sqrt(3))/3;

				if(smallCircRadius>temp){
					cout<<"Error!!!!"<<endl;
				}
				else{
					control = 2;
				}

			}

			if(smallShape == triangle){
				small_shape_triangle_choice(smallTriEdge);

				if(smallTriEdge>contTriEdge){
					cout<<"Error!!!"<<endl;
				}
				else{
					control = 2;
				}
			}

		}

	}



}

Shapes user_container_shape_choice(){
	string count;
	char choice;
	int control = 1;
	Shapes result;
	cout<<"Please enter the main contain shape (R,C,T)"<<endl;
	while(control==1){
		getline(cin,count);
		choice = count[0];
		if(choice!='R' && choice!='C' && choice!='T'){
			cout<<"Error!!!"<<endl;
			cout<<"Please enter the main contain shape (R,C,T)"<<endl;
		}
		else{
			control = 0;
		}
	}
	switch(choice){
		case 'R' : result = rectangle; break;
		case 'C' : result = circle; break;
		case 'T' : result = triangle; break;
		default: break;
	}
	return result;
}


void container_rectangle_choice(int &contRectWidth, int &contRectHeight){
	int control = 1;
	string count;
	cout<<"Please enter the container rectangle's width"<<endl;
	while(control==1){
		getline(cin, count);
		stringstream(count)>>contRectWidth;
		if(contRectWidth==0){
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
		stringstream(count)>>contRectHeight;
		if(contRectHeight==0){
			cout<<"Error!!!"<<endl
			<<"Please enter the container rectangle's height"<<endl;
		}
		else{
			control = 0;
		}
	}
}

void container_circle_choice(int &contCircRadius){
	int control = 1;
	string count;
	cout<<"Please enter the container circle's radius"<<endl;
	while(control==1){
		getline(cin, count);
		stringstream(count)>>contCircRadius;
		if(contCircRadius==0){
			cout<<"Error!!!"<<endl
			<<"Please enter the container circle's radius"<<endl;
		}
		else{
			control = 0;
		}
	}
}

void container_triangle_choice(int &contTriEdge){
	string count;
	cout<<"Please enter the container triangle's edge"<<endl;
	int control = 1;
	while(control == 1){
		getline(cin,count);
		stringstream(count)>>contTriEdge;
		if(contTriEdge==0){
			cout<<"Error!!!"<<endl
			<<"Please enter the container radius"<<endl;
		}
		else{
			control = 0;
		}
	}
}

Shapes user_small_shape_choice(void){
	string count;
	char choice;
	int control = 1;
	Shapes result;
	cout<<"Please enter the small shape (R,C,T)"<<endl;
	while(control==1){
		getline(cin,count);
		choice = count[0];
		if(choice!='R' && choice!='C' && choice!='T'){
			cout<<"Error!!!"<<endl;
			cout<<"Please enter the small shape (R,C,T)"<<endl;
		}
		else{
			control = 0;
		}

	}
	switch(choice){
		case 'R' : result = rectangle; break;
		case 'C' : result = circle; break;
		case 'T' : result = triangle; break;
		default: break;
	}
	return result;
}

void small_shape_rectangle_choice(int &smallRectWidth, int &smallRectHeight){
	int control = 1;
	string count;
	cout<<"Please enter the small rectangle's width"<<endl;
	while(control==1){
		getline(cin, count);
		stringstream(count)>>smallRectWidth;
		if(smallRectWidth==0){
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
		stringstream(count)>>smallRectHeight;
		if(smallRectHeight==0){
			cout<<"Error!!!"<<endl
			<<"Please enter the small rectangle's height"<<endl;
		}
		else{
			control = 0;
		}
	}
}

void small_shape_circle_choice(int &smallCircRadius){
	int control = 1;
	string count;
	cout<<"Please enter the small circle's radius"<<endl;
	while(control==1){
		getline(cin, count);
		stringstream(count)>>smallCircRadius;
		if(smallCircRadius==0){
			cout<<"Error!!!"<<endl
			<<"Please enter the small circle's radius"<<endl;
		}
		else{
			control = 0;
		}
	}
}

void small_shape_triangle_choice(int &smallTriEdge){
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

double find_sqrt(int number){
	double first_target = static_cast<double>(number);
	double second_target = 0.0;
	double temp = 0.0;

	int count = 9999999;
	while(count != 0){
		temp = (first_target + second_target)/2;
		if(temp*temp==number){
			return temp;
		}
		else if(temp*temp>number){
			first_target = temp;
		}
		else{
			second_target = temp;
		}
		count = count - 1;
	}
	return temp;

}
