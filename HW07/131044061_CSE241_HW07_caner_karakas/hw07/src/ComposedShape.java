import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;
import javax.swing.JPanel;

public class ComposedShape extends JPanel implements Shape {
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 594073963080847325L;
	private	Rectangle contR, smallR;
	private Circle contC, smallC;
	private Triangle contT, smallT;
	private int which;
	private int sizeShapes;
	private Shape [] shapes;
	private Shape contShape;
	/**
	 * 
	 * @param contRect
	 * @param smallRect
	 * @throws Exception
	 */
	public ComposedShape(Rectangle contRect, Rectangle smallRect) throws Exception {
		contRect_smallRect(contRect, smallRect);
		contR = new Rectangle(contRect);
		contShape = new Rectangle(contR);
		smallR = new Rectangle(smallRect);
		which = 1;
	}
	/**
	 * 
	 * @param contRect
	 * @param smallCirc
	 * @throws Exception
	 */
	public ComposedShape(Rectangle contRect, Circle smallCirc) throws Exception {
		contRect_smallCirc(contRect, smallCirc);
		contR = new Rectangle(contRect);
		contShape = new Rectangle(contR);
		smallC = new Circle(smallCirc);
		which = 2;
	}
	/**
	 * 
	 * @param contRect
	 * @param smallTri
	 * @throws Exception
	 */
	public ComposedShape(Rectangle contRect, Triangle smallTri) throws Exception {
		contRect_smallTri(contRect, smallTri);
		contR = new Rectangle(contRect);
		contShape = new Rectangle(contR);
		smallT = new Triangle(smallTri);
		which = 3;
	}
	/**
	 * 
	 * @param contCirc
	 * @param smallRect
	 * @throws Exception
	 */
	public ComposedShape(Circle contCirc, Rectangle smallRect) throws Exception {
		contCirc_smallRect(contCirc, smallRect);
		contC = new Circle(contCirc);
		contShape = new Circle(contC);
		smallR = new Rectangle(smallRect);
		which = 4;
	}
	/**
	 * 
	 * @param contCirc
	 * @param smallCirc
	 * @throws Exception
	 */
	public ComposedShape(Circle contCirc, Circle smallCirc) throws Exception {
		contCirc_smallCirc(contCirc, smallCirc);
		contC = new Circle(contCirc);
		contShape = new Circle(contC);
		smallC = new Circle(smallCirc);
		which = 5;
	}
	/**
	 * 
	 * @param contCirc
	 * @param smallTri
	 * @throws Exception
	 */
	public ComposedShape(Circle contCirc, Triangle smallTri) throws Exception {
		contCirc_smallTri(contCirc, smallTri);
		contC = new Circle(contCirc);
		contShape = new Circle(contC);
		smallT = new Triangle(smallTri);
		which = 6;
	}
	/**
	 * 
	 * @param contTri
	 * @param smallRect
	 * @throws Exception
	 */
	public ComposedShape(Triangle contTri, Rectangle smallRect) throws Exception {
		contTri_smallRect(contTri, smallRect);
		contT = new Triangle(contTri);
		contShape = new Triangle(contT);
		smallR = new Rectangle(smallRect);
		which = 7;
	}
	/**
	 * 
	 * @param contTri
	 * @param smallCirc
	 * @throws Exception
	 */
	public ComposedShape(Triangle contTri, Circle smallCirc) throws Exception {
		contTri_smallCirc(contTri, smallCirc);
		contT = new Triangle(contTri);
		contShape = new Triangle(contT);
		smallC = new Circle(smallCirc);
		which = 8;
	}
	/**
	 * 
	 * @param contTri
	 * @param smallTri
	 * @throws Exception
	 */
	public ComposedShape(Triangle contTri, Triangle smallTri) throws Exception {
		contTri_smallTri(contTri, smallTri);
		contT = new Triangle(contTri);
		contShape = new Triangle(contT);
		smallT = new Triangle(smallTri);
		which = 9;
	}
	/**
	 * 
	 * @param contRect
	 * @param smallRect
	 */
	public void contRect_smallRect(Rectangle contRect, Rectangle smallRect) {
		int control = 1;
		while(control == 1){
			if(contRect.get_width() < contRect.get_height()){
				if(contRect.get_width() < smallRect.get_width() ||
						contRect.get_width() < smallRect.get_height()){
					System.out.printf("Error!!");
					control = 2;
				}
				else{
					control = 2;
				}
			}
			if(contRect.get_width() > contRect.get_height()){
				if(contRect.get_height() < smallRect.get_width()||
						contRect.get_height() < smallRect.get_height()){
					System.out.printf("Error!!");
					control = 2;
				}
				else{
					control = 2;
				}
			}
			if(contRect.get_width() == contRect.get_height()){
				if(contRect.get_width() < smallRect.get_width() ||
						contRect.get_width() < smallRect.get_height()){
					System.out.printf("Error!!");
					control = 2;
				}
				else{
					control = 2;
				}
			}
		}
	}

	public void contRect_smallCirc(Rectangle contRect, Circle smallCirc) {
		int control = 1;
		while(control == 1){
			if(contRect.get_width() < contRect.get_height()){
				if(contRect.get_width() < 2*smallCirc.get_radius()){
					System.out.printf("Error!!");
					control = 2;
				}
				else{
					control = 2;
				}
			}
			if(contRect.get_width() > contRect.get_height()){
				if(contRect.get_height() < 2*smallCirc.get_radius()){
					System.out.printf("Error!!");
					control = 2;
				}
				else{
					control = 2;
				}
			}
			if(contRect.get_width() == contRect.get_height()){
				if(contRect.get_height() < 2*smallCirc.get_radius()){
					System.out.printf("Error!!");
					control = 2;
				}
				else{
					control = 2;
				}
			}
		}
	}

	public void contRect_smallTri(Rectangle contRect, Triangle smallTri) {
		int control = 1;
		while(control == 1){
			if(contRect.get_width() < contRect.get_height()){
				if((smallTri.get_line() * Math.sqrt(3))/2 > contRect.get_width()){	//(edge*sqrt(3)) / 2 vertical edge of the triangle
					System.out.printf("Error!!");
					control = 2;
				}
				else{
					control = 2;
				}
			}
			if(contRect.get_width() > contRect.get_height()){
				if((smallTri.get_line() * Math.sqrt(3))/2 > contRect.get_height()){
					System.out.printf("Error!!");
					control = 2;
				}
				else{
					control = 2;
				}
			}
			if(contRect.get_width() == contRect.get_height()){
				if((smallTri.get_line() * Math.sqrt(3))/2 > contRect.get_width()){
					System.out.printf("Error!!");
					control = 2;
				}
				else{
					control = 2;
				}
			}
		}
	}

	public void contCirc_smallRect(Circle contCirc, Rectangle smallRect) {
		int control = 1;
		while(control==1){
			double diagonal = Math.sqrt((smallRect.get_width() * smallRect.get_width())+
					(smallRect.get_height() * smallRect.get_height()));//find the Rect's diagonal
			if(diagonal>contCirc.get_radius()){	//Rect's diagonal cannot be grater than the radius
				System.out.printf("Error!!");
				control = 2;
			}
			else{
				control = 2;
			}
		}
	}

	public void contCirc_smallCirc(Circle contCirc, Circle smallCirc) {
		int control = 1;
		while(control==1){
			if(smallCirc.get_radius() > contCirc.get_radius()){
				System.out.printf("Error!!");
				control = 2;
			}
			else{
				control = 2;
			}
		}
	}

	public void contCirc_smallTri(Circle contCirc, Triangle smallTri) {
		int control = 1;
		while(control==1){
			if(smallTri.get_line() > (contCirc.get_radius() * Math.sqrt(3))){//the edge cannot be greater than the root three of the radius
				System.out.printf("Error!!");
				control = 2;
			}
			else{
				control = 2;
			}
		}
	}

	public void contTri_smallRect(Triangle contTri, Rectangle smallRect) {
		int control = 1;
		while(control==1){
			if(smallRect.get_width() < smallRect.get_height()){
				if(smallRect.get_height() > contTri.get_line() ||
						smallRect.get_height() == contTri.get_line()){
					System.out.printf("Error!!");
					control = 2;
				}
				else{
					double temp = ((contTri.get_line() - smallRect.get_height())/2) * Math.sqrt(3);
					if(temp < smallRect.get_width()){
						System.out.printf("Error!!");
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
					System.out.printf("Error!!");
					control = 2;
				}
				else{
					double temp = ((contTri.get_line() - smallRect.get_width())/2) * Math.sqrt(3);
					if(temp < smallRect.get_height()){
						System.out.printf("Error!!");
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
					System.out.printf("Error!!");
					control = 2;
				}
				else{
					double temp = ((contTri.get_line() - smallRect.get_width())/2) * Math.sqrt(3);
					if(temp < smallRect.get_height()){
						System.out.printf("Error!!");
						control = 2;
					}
					else{
						control = 2;
					}
				}
			}
		}
	}

	public void contTri_smallCirc(Triangle contTri, Circle smallCirc) {
		int control = 1;
		while(control==1){
			double temp = ((contTri.get_line()/2)*Math.sqrt(3))/3;
			if(smallCirc.get_radius() > temp){
				System.out.printf("Error!!");
				control = 2;
			}
			else{
				control = 2;
			}
		}
	}

	public void contTri_smallTri(Triangle contTri, Triangle smallTri) {
		int control = 1;
		while(control==1){
			if(smallTri.get_line() > contTri.get_line()){
				System.out.printf("Error!!");
				control = 2;
			}
			else{
				control = 2;
			}
		}
	}
	/**
	 * optimalFit
	 * @param contRect
	 * @param smallRect
	 * @throws Exception
	 */
	public void optimalFit(Rectangle contRect, Rectangle smallRect) throws Exception {
		ArrayList<Double>crd_x = new ArrayList<Double>();
		ArrayList<Double>crd_y = new ArrayList<Double>();
		Shape [] temp1 = new Shape[9000];
		int x = 0;
		int y = 0;
		crd_x.add(0.0);
		crd_y.add(0.0);
		smallRect.set_coords(crd_x.get(x), crd_y.get(y));
		int index=0;
		int countWidth = (int) (contRect.get_width() / smallRect.get_width());
		int countHeight = (int) (contRect.get_height() / smallRect.get_height());
		double firstCountForShape = 0, secondCountForShape = 0;
		Rectangle temp = new Rectangle();
	
		while(countHeight>0){
			while(countWidth>0){
		        //the smaller's other point control
				if(((crd_x.get(x) + smallRect.get_width()) < contRect.get_width()) ||
						((crd_x.get(x) + smallRect.get_width()) == contRect.get_width())){
					smallRect.set_coords(crd_x.get(x), crd_y.get(y));
					Rectangle r = new Rectangle(smallRect);
					//r = smallRect;
					temp1[index] = r;
					++index;
					crd_x.add(crd_x.get(x) + smallRect.get_width());
					//firstCountForShape = smallRect.get_numOFShape();
					firstCountForShape = Rectangle.get_numOFShape();
					x++;
					countWidth = countWidth - 1;
				}
				else{
					countWidth--;
				}
			}
			//updates for the next raw
			crd_y.add(crd_y.get(y)+smallRect.get_height());
			y++;
			crd_x.add(0.0);
			x++;
			countWidth = (int) (contRect.get_width() / smallRect.get_width());
			countHeight = countHeight - 1;
		}
		//the smaller's rotating control
		if(contRect.get_width() != (countWidth*smallRect.get_width()) &&
				(contRect.get_height() > smallRect.get_width() ||
						contRect.get_height() == smallRect.get_width())){
			int countForFree = (int) (contRect.get_width() - (countWidth*smallRect.get_width()));
			crd_y.add((double) 0);
			y++;
			int tempHeight = (int) smallRect.get_width();
			int tempWidth = (int) smallRect.get_height();
			int control2 = (int) (contRect.get_height() / smallRect.get_width());
			while(control2>0){
			    //free space control and comparing ups situation
				if(countForFree>smallRect.get_height()|| countForFree==smallRect.get_height()){
					int control = (int) (countForFree / smallRect.get_height());
					crd_x.add(countWidth*smallRect.get_width());
					x++;
					while(control>0){
						if((crd_x.get(x) + tempWidth) < contRect.get_width()
								|| (crd_x.get(x) + tempWidth) == contRect.get_width()){
							temp.set_lines(tempWidth, tempHeight);
							Rectangle r = new Rectangle(temp);
							//r = temp;
							temp1[index] = r;
							++index;
							crd_x.add(crd_x.get(x) + tempWidth);
							x++;
							//secondCountForShape = temp.get_numOFShape();
							secondCountForShape = Rectangle.get_numOFShape();
							control = control - 1;
						}
						if(!((crd_x.get(x) + tempWidth) < contRect.get_width() ||
								(crd_x.get(x) + tempWidth) == contRect.get_width())){
							crd_y.add(crd_y.get(y)+tempHeight);
							y++;
							control = -1;
						}
					}
				}
				control2 = control2 - 1;
			}
		}
		int diffArea = (int) (contRect.area() - ((secondCountForShape+firstCountForShape)*smallRect.area()));
		shapes = new Shape[index];
		sizeShapes = index;
		for(int i = 0; i<index; i++)
			shapes[i] = temp1[i];
		System.out.printf("I can fit at most %.2f small shapes into the main container."
				+ " The empty area in container is %d.", secondCountForShape+firstCountForShape, diffArea);
		Rectangle.reset_numOfShape();
	}
	/**
	 * optimalFit
	 * @param contRect
	 * @param smallCirc
	 * @throws Exception
	 */
	public void optimalFit(Rectangle contRect, Circle smallCirc) throws Exception {
		ArrayList<Double>crd_x = new ArrayList<Double>();
		ArrayList<Double>crd_y = new ArrayList<Double>();
		Shape [] temp1 = new Shape[9000];
		int x = 0;
		int y = 0;
		crd_x.add(smallCirc.get_radius());
		crd_y.add(smallCirc.get_radius());
		int index = 0;
		int jumpControl = (int) (smallCirc.get_radius() * 3);
		int jump = (int) (smallCirc.get_radius() * 2);
		int countForShape = 0;
		int control1 = (int) (contRect.get_height() / (2 * smallCirc.get_radius())); //count for that how many smaller?
		int control2 = 1;
		while (control1 > 0) {
			smallCirc.set_coords(crd_x.get(x), crd_y.get(y));
			//Shape s = new Shape();
			Circle c = new Circle(smallCirc);
			//c = smallCirc;
			temp1[index] = c;
			++index;
			//countForShape = smallCirc.get_numOfShape();
			countForShape = Circle.get_numOfShape();
			while (control2 == 1) {
				//control for next circ's coords.
				if ((crd_x.get(x) + jumpControl) > contRect.get_width()) {
					control2 = 0;
				} else {
					crd_x.add(crd_x.get(x)+ jump);
					x++;
					smallCirc.set_coords(crd_x.get(x), crd_y.get(y));
					Circle c1 = new Circle(smallCirc);
					//c1 = smallCirc;
					temp1[index] = c1;
					++index;
					//countForShape = smallCirc.get_numOfShape();
					countForShape = Circle.get_numOfShape();
				}
			}
	
			//ups for next raw
			control2 = 1;
			crd_y.add(crd_y.get(y) + jump);
			y++;
			crd_x.add(smallCirc.get_radius());
			x++;
			control1 = control1 - 1;
		}
	
		double diffArea = contRect.area() - Circle.result_area(smallCirc);
		shapes = new Shape[index];
		sizeShapes = index;
		for(int i = 0; i<index; i++)
			shapes[i] = temp1[i];
		System.out.printf("I can fit at most %d small shapes into the main container."
				+ " The empty area in container is %.2f.", countForShape, diffArea);
		Circle.reset_numOfShape();
	}
	/**
	 * optimalFit
	 * @param contRect
	 * @param smallTri
	 * @throws Exception
	 */
	public void optimalFit(Rectangle contRect, Triangle smallTri) throws Exception {
		Shape [] temp1 = new Shape[9000];
		int countForShape = 0;
		int index = 0;
		double height = smallTri.get_height();
		double [][] points = new double [3][2];
		points[0][0] = 0;
		points[0][1] = 0;
		points[1][0] = smallTri.get_line() / 2;
		points[1][1] = height;
		points[2][0] = smallTri.get_line();
		points[2][1] = 0;
		double [] tempSecPoint = new double [2];
		double [] tempTrdPoint = new double [2];
		smallTri.set_coords(points[0][0], points[0][1], points[1][0], points[1][1],
				points[2][0], points[2][1]);
		int control1 = 0;
		int control2 = 0;
		int raw = 0;
		boolean position = true;
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
						smallTri.set_coords(points[0][0], points[0][1],
								points[1][0], points[1][1], points[2][0],
								points[2][1]);
						Triangle t = new Triangle(smallTri);
						//t = smallTri;
						temp1[index] = t;
						++index;
						countForShape = Triangle.get_numOfShape();
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
	
		double diffArea = contRect.area() - Triangle.result_area(smallTri);
		shapes = new Shape[index];
		sizeShapes = index;
		for(int i = 0; i<index; i++)
			shapes[i] = temp1[i];
		System.out.printf("I can fit at most %d small shapes into the main container."
				+ " The empty area in container is %.2f.", countForShape, diffArea);
		Triangle.reset_numOfShape();
	}
	/**
	 * optimalFit
	 * @param contCirc
	 * @param smallRect
	 * @throws Exception
	 */
	public void optimalFit(Circle contCirc, Rectangle smallRect) throws Exception {
		ArrayList<Double>crd_x = new ArrayList<Double>();
		ArrayList<Double>crd_y = new ArrayList<Double>();
		Shape [] temp1 = new Shape[9000];
		int x = 0;
		int y = 0;
		crd_x.add(0.0);
		crd_y.add(0.0);
		double distance;
		int control = 0;
		int countForShape = 0;
		int index = 0;
		while (crd_y.get(y) < (2 * contCirc.get_radius()) - smallRect.get_height()) {
			while (crd_x.get(x) < (contCirc.get_radius() * 2) - smallRect.get_width()) {
				distance = Math.sqrt(
						((contCirc.get_pos_x() - crd_x.get(x))
								* (contCirc.get_pos_x() - crd_x.get(x)))
								+ ((contCirc.get_pos_y() - crd_y.get(y))
										* contCirc.get_pos_y() - crd_y.get(y)));
				if (distance > contCirc.get_radius()) {
					crd_x.add(crd_x.get(x) + 1);
					x++;
				} else {
					double temp = Math.sqrt(
							((contCirc.get_pos_x()
									- (crd_x.get(x) + smallRect.get_width()))
									* (contCirc.get_pos_x()
											- (crd_x.get(x) + smallRect.get_width())))
									+ ((contCirc.get_pos_y() - crd_y.get(y))
											* (contCirc.get_pos_y() - crd_y.get(y))));
					if (temp > contCirc.get_radius()) {
						crd_x.add(crd_x.get(x) + 1);
						x++;
					} else {
						double temp2 =
								Math.sqrt(
										((contCirc.get_pos_x() - crd_x.get(x))
												* (contCirc.get_pos_x() - crd_x.get(x)))
												+ ((contCirc.get_pos_y()
														- (crd_y.get(y)
																+ smallRect.get_height()))
														* (contCirc.get_pos_y()
																- (crd_y.get(y)
																		+ smallRect.get_height())))); //for the other point of rec.
						if (temp2 > contCirc.get_radius()) {
							crd_x.add(crd_x.get(x) + 1);
							x++;
						} else {
							smallRect.set_coords(crd_x.get(x), crd_y.get(y));
							Rectangle r = new Rectangle(smallRect);
							//r = smallRect;
							temp1[index] = r;
							++index;
							countForShape = Rectangle.get_numOFShape();
							control = 1;
							crd_x.add(crd_x.get(x) + smallRect.get_width());
							x++;
						}
					}
	
				}
	
			}
	
			//for in the previous row has small shape ?
			//true that mean next line
			if (control == 0) {
				crd_x.add(0.0);
				x++;
				control = 0;
				crd_y.add(crd_y.get(y) + 1);
				y++;
			}
			//true that mean next raw
			if (control == 1) {
				control = 0;
				crd_x.add(0.0);
				x++;
				crd_y.add(crd_y.get(y) + smallRect.get_height());
				y++;
			}
		}
	
		double diffArea = contCirc.area() - Rectangle.result_area(smallRect);
		shapes = new Shape[index];
		sizeShapes = index;
		for(int i = 0; i<index; i++)
			shapes[i] = temp1[i];
		System.out.printf("I can fit at most %d small shapes into the main container."
				+ " The empty area in container is %.2f.", countForShape, diffArea);
		Rectangle.reset_numOfShape();
	}
	/**
	 * optimalFit
	 * @param contCirc
	 * @param smallCirc
	 * @throws Exception
	 */
	public void optimalFit(Circle contCirc, Circle smallCirc) throws Exception {
		ArrayList<Double>crd_x = new ArrayList<Double>();
		ArrayList<Double>crd_y = new ArrayList<Double>();
		Shape [] temp1 = new Shape[9000];
		int x = 0;
		int y = 0;
		int index = 0;
		crd_x.add(smallCirc.get_radius());
		crd_y.add(smallCirc.get_radius());
		//smallCirc.fill = "fill='blue'/>";
		int count = (int) (contCirc.get_radius() - smallCirc.get_radius()); //for the tangent points
		int jump = (int) (2 * smallCirc.get_radius()); //ups
		int control1 = (int) smallCirc.get_radius();
		int control2 = (int) smallCirc.get_radius();
		int smallShapesCount = 0;
		while (control1 < 2 * contCirc.get_radius()) {
			double distance;
			while (control2 < 2 * contCirc.get_radius()) {
				distance = Math.sqrt(
						((contCirc.get_pos_x() - crd_x.get(x))
								* (contCirc.get_pos_x() - crd_x.get(x)))
								+ ((contCirc.get_pos_y() - crd_y.get(y))
										* (contCirc.get_pos_y() - crd_y.get(y)))); //sqrt((x1-x2)^2+(y1-y2)^2) --> distance between two points
				//is it tangant points?
				if (distance > count) {
					control2++;
					crd_x.add(crd_x.get(x) + 1);
					x++;
				} else {
					//for the overflowing?
					if ((distance + smallCirc.get_radius())
							> contCirc.get_radius()) {
						control2++;
						crd_x.add(crd_x.get(x) + 1);
						x++;
					} else {
						smallCirc.set_coords(crd_x.get(x), crd_y.get(y));
						Circle c = new Circle(smallCirc);
						//c = smallCirc;
						temp1[index] = c;
						++index;
						smallShapesCount = Circle.get_numOfShape();
						control2 = control2 + jump;
						crd_x.add(crd_x.get(x) + jump);
						x++;
					}
				}
	
			}
	
			//ups for next raw
			crd_x.add(smallCirc.get_radius());
			x++;
			crd_y.add(crd_y.get(y) + jump);
			y++;
			control2 = (int) smallCirc.get_radius();
			control1 = control1 + jump;
		}
	
		double diffArea = contCirc.area() - Circle.result_area(smallCirc);
		shapes = new Shape[index];
		sizeShapes = index;
		for(int i = 0; i<index; i++)
			shapes[i] = temp1[i];
		System.out.printf("I can fit at most %d small shapes into the main container."
				+ " The empty area in container is %.2f.", smallShapesCount, diffArea);
		Circle.reset_numOfShape();
	}
	/**
	 * optimalFit
	 * @param contCirc
	 * @param smallTri
	 * @throws Exception
	 */
	public void optimalFit(Circle contCirc, Triangle smallTri) throws Exception {
		double distance;
		boolean control2 = false;
		int countForShape = 0;
		Shape [] temp1 = new Shape[9000];
		int index = 0;
		double point_x = contCirc.get_radius();
		double point_y = 0.00;
		double point2_x, point2_y, point3_x, point3_y;
		point2_x = contCirc.get_radius() - ((double) ((smallTri.get_line())) / 2);
		point2_y = smallTri.get_height();
		point3_x = contCirc.get_radius() + (smallTri.get_line() / 2);
		point3_y = point2_y;
		smallTri.set_coords(point_x, point_y, point2_x, point2_y, point3_x,
				point3_y);
		Triangle t = new Triangle(smallTri);
		//t = smallTri;
		temp1[index] = t;
		point_x = 0.0;
		point_y = smallTri.get_height();
		while (point_y <= (2 * contCirc.get_radius()) - smallTri.get_height()) {
			while (point_x < (2 * contCirc.get_radius())) {
				distance = Math.sqrt(
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
						point3_y = point_y + smallTri.get_height();
					}
					if (control2 == false) {
						point2_x = point_x - (smallTri.get_line() / 2);
						point2_y = point_y + smallTri.get_height();
						point3_x = point2_x + smallTri.get_line();
						point3_y = point2_y;
					}
					control2 = !control2;
					double temp = Math.sqrt(
							(contCirc.get_pos_x() - point_x)
									* (contCirc.get_pos_x() - point_x)
									+ (contCirc.get_pos_y() - point_y)
											* (contCirc.get_pos_y() - point_y));
					double temp2 = Math.sqrt(
							(contCirc.get_pos_x() - point2_x)
									* (contCirc.get_pos_x() - point2_x)
									+ (contCirc.get_pos_y() - point2_y)
											* (contCirc.get_pos_y() - point2_y));
					double temp3 = Math.sqrt(
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
						smallTri.set_coords(point_x, point_y, point2_x, point2_y,
								point3_x, point3_y);
						Triangle t1 = new Triangle(smallTri);
						//t1 = smallTri;
						temp1[index] = t1;
						++index;
						countForShape = Triangle.get_numOfShape();
						if (control2 == false)
							point_x += smallTri.get_line();
					}
				}
	
			}
	
			point_x = 0;
			point_y = point_y + smallTri.get_height();
		}
	
		double diffArea = contCirc.area() - Triangle.result_area(smallTri);
		shapes = new Shape[index];
		sizeShapes = index;
		for(int i = 0; i<index; i++)
			shapes[i] = temp1[i];
		System.out.printf("I can fit at most %d small shapes into the main container."
				+ " The empty area in container is %.2f.", countForShape, diffArea);
		Triangle.reset_numOfShape();
	}
	/**
	 * optimalFit
	 * @param contTri
	 * @param smallRect
	 * @throws Exception
	 */
	public void optimalFit(Triangle contTri, Rectangle smallRect) throws Exception {
		double temp_y = contTri.get_height() - smallRect.get_height();
		double temp_x = smallRect.get_height() / Math.sqrt(3);
		Shape [] temp1 = new Shape[9000];
		int smallShapesCount = 0;
		int index = 0;
		int control = 1; //for that how many rows have drawn smaller shapes
		int control2 = 0;
		while (temp_y > 0) {
			while (control2 == 0) {
				//for line break or raw break
				double count = contTri.get_line()
						- ((control * smallRect.get_height()) / Math.sqrt(3));
				//there is line break ?
				if (count < temp_x + smallRect.get_width()) {
					control2 = 1;
				} else {
					smallRect.set_coords(temp_x, temp_y);
					Rectangle r = new Rectangle(smallRect);
					//r = smallRect;
					temp1[index] = r;
					++index;
					smallShapesCount = Rectangle.get_numOFShape();
					temp_x = temp_x + smallRect.get_width();
				}
			}
	
			control++;
			control2 = 0;
			temp_x = (control * smallRect.get_height() / Math.sqrt(3));
			temp_y = temp_y - smallRect.get_height();
		}
	
		double diffArea = contTri.area() - Rectangle.result_area(smallRect);
		shapes = new Shape[index];
		sizeShapes = index;
		for(int i = 0; i<index; i++)
			shapes[i] = temp1[i];
		System.out.printf("I can fit at most %d small shapes into the main container."
				+ " The empty area in container is %.2f.", smallShapesCount, diffArea);
		Rectangle.reset_numOfShape();
	}
	/**
	 * optimalFit
	 * @param contTri
	 * @param smallCirc
	 * @throws Exception
	 */
	public void optimalFit(Triangle contTri, Circle smallCirc) throws Exception {
		ArrayList<Double>crd_x = new ArrayList<Double>();
		ArrayList<Double>crd_y = new ArrayList<Double>();
		Shape [] temp1 = new Shape[9000];
		int x = 0;
		int y = 0;
		int index = 0;
		crd_x.add(smallCirc.get_radius() * Math.sqrt(3));
		crd_y.add(contTri.get_height() - smallCirc.get_radius());
		double temp_height = contTri.get_height();
		double base = (double) ((contTri.get_line()));
		int control = 0;
		int control2 = 0;
		int countForShape = 0;
		double decForBase; //to shrink base
		while (crd_y.get(y) > 0) {
			while (control2 == 0) {
				double count = base - (smallCirc.get_radius() * Math.sqrt(3));
				if (count < crd_x.get(x)) {
					control2 = 1;
				} else {
					smallCirc.set_coords(crd_x.get(x), crd_y.get(y));
					Circle c = new Circle(smallCirc);
					//c = smallCirc;
					temp1[index] = c;
					++index;
					countForShape = Circle.get_numOfShape();
					crd_x.add(crd_x.get(x) + (2 * smallCirc.get_radius()));
					x++;
				}
			}
	
			control++;
			decForBase = ((smallCirc.get_radius() * 2) / Math.sqrt(3)); //to shrink base
			base = base - decForBase;
			double decForHeight = 2 * smallCirc.get_radius(); //to shrink height
			temp_height = temp_height - decForHeight;
			control2 = 0;
			crd_x.add(
					(smallCirc.get_radius() * Math.sqrt(3)) + (decForBase * control));
			x++;
			crd_y.add(temp_height - smallCirc.get_radius());
			y++;
		}
	
		double diffArea = contTri.area() - Circle.result_area(smallCirc);
		shapes = new Shape[index];
		sizeShapes = index;
		for(int i = 0; i<index; i++)
			shapes[i] = temp1[i];
		System.out.printf("I can fit at most %d small shapes into the main container."
				+ " The empty area in container is %.2f.", countForShape, diffArea);
		Circle.reset_numOfShape();
	}
	/**
	 * optimalFit
	 * @param contTri
	 * @param smallTri
	 * @throws Exception
	 */
	public void optimalFit(Triangle contTri, Triangle smallTri) throws Exception {
		int countForShape = 0;
		Shape [] temp1 = new Shape[9000];
		int index = 0;
		double heightForBig = (contTri.get_line() / 2) * Math.sqrt(3);
		double [][] points = new double [3][2];
		double heightForSmall = (smallTri.get_line() / 2) * Math.sqrt(3);
		points[0][0] = 0;
		points[0][1] = heightForBig;
		points[1][0] = smallTri.get_line() / 2;
		points[1][1] = heightForBig - heightForSmall;
		points[2][0] = smallTri.get_line();
		points[2][1] = heightForBig;
		double [] tempSecPoint = new double [2];
		double [] tempTrdPoint = new double [2];
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
						smallTri.set_coords(points[0][0], points[0][1],
								points[1][0], points[1][1], points[2][0],
								points[2][1]);
						Triangle t = new Triangle(smallTri);
						temp1[index] = t;
						++index;
						countForShape = Triangle.get_numOfShape();
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
	
		double diffArea = contTri.area() - Triangle.result_area(smallTri);
		shapes = new Shape[index];
		sizeShapes = index;
		for(int i = 0; i<index; i++)
			shapes[i] = temp1[i];
		System.out.printf("I can fit at most %d small shapes into the main container."
				+ " The empty area in container is %.2f.", countForShape, diffArea);
		Triangle.reset_numOfShape();
	}
	
	
	public Rectangle get_cont_rect() {return contR;}
	
	public int get_sizeShapes() {return sizeShapes;}
	
	public Rectangle get_small_rect() {return smallR;}
	
	public Circle get_cont_circ() {return contC;}
	
	public Circle get_small_circ() {return smallC;}
	
	public Triangle get_cont_tri() {return contT;}
	
	public Triangle get_small_tri()  {return smallT;}
	
	public int whichShape() {return 0;}
	
	public Shape get_shapes_element(int index) {return shapes[index];}
	
	public ComposedShape() {}

	@Override
	public int compareTo(Shape other) {
		if(this.area() == other.area())
			return 1;
		return 0;
	}

	@Override
	public double area() {
		int i = 0;
		double result = 0;
		while(shapes[i] != null) {
			result += shapes[i].area();
		}
		return result;
	}

	@Override
	public double perimeter() {
		int i = 0;
		double result = 0;
		while(shapes[i] != null) {
			result += shapes[i].perimeter();
		}
		return result;
	}

	@Override
	public Shape increment() {
		int i = 0;
		while(shapes[i] != null) 
			shapes[i].increment();
		return this;
	}

	@Override
	public Shape decrement() {
		int i = 0;
		while(shapes[i] != null) 
			shapes[i].decrement();
		return this;
	}

	@Override
	public void draw(Graphics graph) {
		this.paintComponent(graph);
	}
	
	@Override
	public void paintComponent(Graphics graph){
		super.paintComponent(graph);
		graph.setColor(Color.BLACK);
		contShape.draw(graph);

		graph.setColor(Color.GREEN);
		for(int i = 0; i<sizeShapes; i++)
			shapes[i].draw(graph);
	}

}
