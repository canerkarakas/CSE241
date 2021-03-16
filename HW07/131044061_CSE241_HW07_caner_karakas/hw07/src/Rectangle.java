

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Component;
import java.awt.Graphics;

public class Rectangle extends JPanel implements Shape {
	
	private static final long serialVersionUID = 1L;
	private static int numOfShape = 0;
	private double width;
	private double height;
	private double pos_x;
	private double pos_y;
	
	Rectangle(){}
	/**
	 * take Rectangle object
	 * @param rect
	 * @throws Exception
	 */
	Rectangle(Rectangle rect) throws Exception{
		this.set_width(rect.get_width());
		this.set_height(rect.get_height());
		this.set_coords(rect.get_pos_x(), rect.get_pos_y());
	}
	/**
	 * take double params
	 * @param w
	 * @param h
	 * @throws Exception
	 */
	Rectangle(double w, double h) throws Exception{
		this.set_width(w);
		this.set_height(h);
	}
	

	@Override
	public int compareTo(Shape other) {
		if(this.area() == other.area())
			return 1;
		return 0;
	}

	@Override
	public double area() {return width * height;}
	

	@Override
	public double perimeter() {return 2 * width * height;}

	@Override
	public Shape increment() {
		this.pos_x++;
		this.pos_y++;
		return this;
	}

	@Override
	public Shape decrement() {
		this.pos_x--;
		this.pos_y--;
		return this;
	}

	@Override
	public void draw(Graphics graph) {
		this.paintComponent(graph);
	}
	
	@Override
	public void paintComponent(Graphics graph){
		super.paintComponent(graph);
		graph.setColor(Color.GREEN);
		graph.drawRect((int)this.get_pos_x(), (int)this.get_pos_y(), (int)this.get_width(), (int)this.get_height());
	}
	/**
	 * set_width
	 * @param w
	 * @throws Exception
	 */
	public void set_width(double w) throws Exception{
		if(w>0){
			width = w;
		}
		else{
			new Exception ();
			/*System.out.printf("Error!!");
			System.exit(0);*/
		}
	}
	/**
	 * set_height
	 * @param h
	 * @throws Exception
	 */
	public void set_height(double h) throws Exception{
		if(h>0){
			height = h;
		}
		else{
			new Exception ();
			/*System.out.printf("Error!!");
			System.exit(0);*/
		}
	}
	
	public double get_width()	{return width;}
	
	public double get_height() {return height;}
	/**
	 * set_pos_x
	 * @param x
	 * @throws Exception
	 */
	public void set_pos_x(double x) throws Exception{
		if(x>=0){
			pos_x = x;
		}
		else{/*
			System.out.printf("Error!!");
			System.exit(0);*/
			new Exception ();
		}
	}
	/**
	 * set_pos_y
	 * @param y
	 * @throws Exception
	 */
	public void set_pos_y(double y) throws Exception{
		if(y>=0){
			pos_y = y;
		}
		else{
			new Exception ();
			/*System.out.printf("Error!!");
			System.exit(0);*/
		}
	}
	
	public double get_pos_x(){return pos_x;}
	
	public double get_pos_y() {return pos_y;}
	
	static int get_numOFShape() {numOfShape++;return numOfShape;}
	
	static int reset_numOfShape(){numOfShape = 0;return numOfShape;}
	
	static double result_area(Rectangle rect){return numOfShape * rect.area();}
	/**
	 * set_coords
	 * @param x
	 * @param y
	 * @throws Exception
	 */
	public void set_coords(double x, double y) throws Exception {
		set_pos_x(x);
		set_pos_y(y);
	}
	/**
	 * set_lines
	 * @param w
	 * @param h
	 * @throws Exception
	 */
	public void set_lines(double w, double h) throws Exception {
		this.set_width(w);
		this.set_height(h);
	}

}
