import java.awt.Color;
import java.awt.Graphics;
import java.lang.*;

import javax.swing.JPanel;

public class Circle extends JPanel implements Shape {
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 6168523935497005135L;
	private double radius;
	private static int numOfShape = 0;
	private double pos_x, pos_y;
	/**
	 * empty constructor
	 */
	public Circle() {}
	/**
	 * takeCircleObject
	 * @param c
	 * @throws Exception
	 */
	public Circle(Circle c) throws Exception {
		this.set_radius(c.get_radius());
		this.set_coords(c.get_pos_x(), c.get_pos_y());
	}
	/**
	 * take radius
	 * @param r
	 * @throws Exception
	 */
	public Circle(double r) throws Exception {
		set_radius(r);
	}

	@Override
	public int compareTo(Shape other) {
		if(this.area() == other.area())
			return 1;
		return 0;
	}
	public void set_radius(double r) throws Exception {
		if(r>0)
			radius = r;
		else {
			new Exception ();
		}
	}
	@Override
	public double area() {return (Math.PI) * radius * radius;}

	@Override
	public double perimeter() {return 2 * (Math.PI) * radius;}

	@Override
	public Shape increment() {
		++pos_x;
		++pos_y;
		return null;
	}
	/**
	 * set_coords
	 * @param x
	 * @param y
	 * @throws Exception
	 */
	void set_coords(double x, double y) throws Exception{
		if(x >= radius && y >= radius){
			set_pos_x(x);
			set_pos_y(y);
		}
		else{
			/*System.out.printf("Error!!");
			System.exit(0);*/
			new Exception ();
		}
	}
	
	@Override
	public void paintComponent(Graphics graph){
		super.paintComponent(graph);
		graph.setColor(Color.GREEN);
		graph.drawOval((int)this.get_pos_x()-(int)this.get_radius(), (int)this.get_pos_y()-(int)this.get_radius(), (int)this.get_radius()*2, (int)this.get_radius()*2);
	}

	@Override
	public Shape decrement() {
		--pos_x;
		--pos_y;
		return this;
	}

	@Override
	public void draw(Graphics graph) {
		this.paintComponent(graph);
	}
	
	public double get_radius() {return radius;}
	
	static int get_numOfShape(){numOfShape++;return numOfShape;}
	
	static int reset_numOfShape(){numOfShape = 0;return numOfShape;}
	
	static double result_area(Circle circ){return numOfShape * circ.area();}

	public double get_pos_x() {return pos_x;}

	public void set_pos_x(double x) {this.pos_x = x;}

	public double get_pos_y() {return pos_y;}

	public void set_pos_y(double y) {this.pos_y = y;}

}
