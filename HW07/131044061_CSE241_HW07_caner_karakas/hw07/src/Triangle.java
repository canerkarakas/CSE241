import java.awt.Color;
import java.awt.Graphics;
import java.awt.Polygon;
import javax.swing.JPanel;
import java.lang.*;


public class Triangle extends JPanel implements Shape {

	private static final long serialVersionUID = 1L;
	private static int numOfShape = 0;
	private double line;
	private double height;
	private int [][] points = new int[6][6];
	
	/**
	 * default constructor
	 */
	public Triangle() {
	}
	/**
	 * take Triangle object constructor
	 * @param l
	 * @throws Exception
	 */
	public Triangle(Triangle l) throws Exception {
		this.set_line(l.get_line());
		this.set_coords(l.get_point_x(0), l.get_point_y(0), l.get_point_x(1), l.get_point_y(1), l.get_point_x(2), l.get_point_y(2));
	}
	/**
	 * take double line
	 * @param l
	 * @throws Exception
	 */
	public Triangle(double l) throws Exception {
		this.set_line(l);
	}
	
	@Override
	public int compareTo(Shape other) {
		if(this.area() == other.area())
			return 1;
		return 0;
	}

	@Override
	public double area() {return height * line / 2;}

	@Override
	public double perimeter() {return line * 3;}

	@Override
	public Shape increment() {
		for(int i = 0; i<6; i++){
			for(int j=0; j<6; j++)
				points[i][j]++;
		}
		return this;
	}

	@Override
	public Shape decrement() {
		for(int i = 0; i<6; i++){
			for(int j=0; j<6; j++)
				points[i][j]--;
		}
		return this;
	}

	@Override
	public void draw(Graphics graph) {
		this.paintComponent(graph);
	}
	
	@Override
	public void paintComponent(Graphics graph){
		super.paintComponent(graph);
		int [] xPoints = new int [3];
		int [] yPoints = new int [3];
		for(int i = 0; i<3; i++) {
			xPoints[i] = points[i][0];
		}
		for(int i = 0; i<3; i++) {
			yPoints[i] = points[i][1];
		}
		graph.setColor(Color.RED);
		graph.drawPolygon(xPoints, yPoints, 3);
	}
	
	/**
	 * set_line
	 * @param l
	 * @throws Exception
	 */
	public void set_line(double l) throws Exception{
		if(l>0){
			line = l;
			height = (line/2) * Math.sqrt(3);
		}
		else{/*
			System.out.printf("Error111!!");
			System.exit(0);*/
			new Exception();
		}
	}
	
	public double get_line(){return line;}
	
	public double get_height(){return height;}
	
	/**
	 * set_coords
	 * @param p1_x
	 * @param p1_y
	 * @param p2_x
	 * @param p2_y
	 * @param p3_x
	 * @param p3_y
	 * @throws Exception
	 */
	public void set_coords(double p1_x, double p1_y, double p2_x,
		double p2_y, double p3_x, double p3_y) throws Exception{
		double line1 = Math.sqrt(((p1_x-p2_x)*(p1_x-p2_x)) + ((p1_y-p2_y)*(p1_y-p2_y)));
		double line2 = Math.sqrt(((p1_x-p3_x)*(p1_x-p3_x)) + ((p1_y-p3_y)*(p1_y-p3_y)));
		double line3 = Math.sqrt(((p3_x-p2_x)*(p3_x-p2_x)) + ((p3_y-p2_y)*(p3_y-p2_y)));
		if(line1<=line || line2<=line || line3<=line){
			points[0][0] = (int) p1_x;
			points[0][1] = (int) p1_y;
			points[1][0] = (int) p2_x;
			points[1][1] = (int) p2_y;
			points[2][0] = (int) p3_x;
			points[2][1] = (int) p3_y;
		}
		else{/*
			System.out.printf("Error!!");
			System.exit(0);*/
			new Exception();
		}
	}
	
	public double get_point_x(int index) {return points[index][0];}
	
	public double get_point_y(int index) {return points[index][1];}
	
	static double result_area(Triangle tri){return numOfShape * tri.area();}
	
	static int get_numOfShape(){numOfShape++;return numOfShape;}
	
	static int reset_numOfShape(){numOfShape = 0;return numOfShape;}

}
