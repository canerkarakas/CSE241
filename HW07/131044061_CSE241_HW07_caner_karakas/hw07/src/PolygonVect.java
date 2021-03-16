import java.awt.Color;
import java.awt.Graphics;
import java.util.*;

public class PolygonVect extends Polygon {

	/**
	 * 
	 */
	private static final long serialVersionUID = 7453971179933937248L;
	
	ArrayList<Point2D>coords = new ArrayList<Point2D>();
	private int which;
	private int nPoints;
	private Rectangle rect;
	private Circle circ;
	private Triangle tri;

	public PolygonVect() {
		// TODO Auto-generated constructor stub
	}
	/**
	 * take Rectangle object
	 * @param rectangle
	 * @throws Exception
	 */
	PolygonVect(Rectangle rectangle) throws Exception {
		rect = new Rectangle();
		rect = rectangle;
		which = 1;
		Point2D temp = new Point2D();
		coords.add(temp);
		coords.get(0).set_x(rect.get_pos_x());
		coords.get(0).set_y(rect.get_pos_y());
		temp = new Point2D();
		coords.add(temp);
		coords.get(1).set_x(rect.get_pos_x() + rect.get_width());
		coords.get(1).set_y(rect.get_pos_y());
		temp = new Point2D();
		coords.add(temp);
		coords.get(2).set_x(rect.get_pos_x() + rect.get_width());
		coords.get(2).set_y(rect.get_pos_y() + rect.get_height());
		temp = new Point2D();
		coords.add(temp);
		coords.get(3).set_x(rect.get_pos_x());
		coords.get(3).set_y(rect.get_pos_y() + rect.get_height());
		nPoints = 4;
	}
	/**
	 * take Circle
	 * @param circle
	 * @throws Exception
	 */
	PolygonVect(Circle circle) throws Exception {
		circ = circle;
		which = 2;
		Point2D temp = new Point2D();
		temp.set_x(circ.get_pos_x());
		temp.set_y(circ.get_pos_y()-circ.get_radius());
		coords.add(temp);
		double cons = 3.6*(3.141593/180.0);//radyan cevirisi * 360/100 (100 nokta);
		int i;
		for(i=1;i<25;++i){
			temp = new Point2D();
			temp.set_x(coords.get(0).get_x() + circ.get_radius()*(Math.sin(cons*i)));
			temp.set_y(coords.get(0).get_y() + (circ.get_radius() - circ.get_radius()*(Math.cos(cons*i))));
			coords.add(temp);
		}
		temp = new Point2D();
		temp.set_x(coords.get(0).get_x()+circ.get_radius());
		temp.set_y(coords.get(0).get_y()+circ.get_radius());
		coords.add(temp);
		for(i=26;i<50;++i){
			temp = new Point2D();
			temp.set_x(coords.get(25).get_x() -(circ.get_radius() - circ.get_radius()*(Math.cos(cons*(i-25)))));
			temp.set_y(coords.get(25).get_y() + circ.get_radius()*(Math.sin(cons*(i-25))));
			coords.add(temp);
		}
		temp = new Point2D();
		temp.set_x(coords.get(25).get_x()-circ.get_radius());
		temp.set_y(coords.get(25).get_y()+circ.get_radius());
		coords.add(temp);
		for(i=51;i<75;++i){
			temp = new Point2D();
			temp.set_x(coords.get(50).get_x() - circ.get_radius()*(Math.sin(cons*(i-50))));
			temp.set_y(coords.get(50).get_y() - (circ.get_radius() - circ.get_radius()*(Math.cos(cons*(i-50)))));
			coords.add(temp);
		}
		temp = new Point2D();
		temp.set_x(coords.get(50).get_x()-circ.get_radius());
		temp.set_y(coords.get(50).get_y()-circ.get_radius());
		coords.add(temp);
		for(i=76;i<100;++i){
			temp = new Point2D();
			temp.set_x(coords.get(75).get_x() + (circ.get_radius() - circ.get_radius()*(Math.cos(cons*(i-75)))));
			temp.set_y(coords.get(75).get_y() - circ.get_radius()*(Math.sin(cons*(i-75))));
			coords.add(temp);
		}
		nPoints = 100;
	}
	/**
	 * take Triangle
	 * @param triangle
	 * @throws Exception
	 */
	PolygonVect(Triangle triangle) throws Exception {
		tri = triangle;
		which = 3;
		Point2D temp = new Point2D();
		int i;
		for(i=0;i<3;++i){
			temp = new Point2D();
			coords.add(temp);
			coords.get(i).set_x(tri.get_point_x(i));
			coords.get(i).set_y(tri.get_point_y(i));
		}
		nPoints = 3;
	}

	@Override
	public double area() {
		double result = 0;
		switch(which){
		case 1: result = rect.area();break;
		case 2: result = circ.area();break;
		case 3: result = tri.area();break;
		}
		return result;
	}

	@Override
	public double perimeter() {
		double result = 0;
		switch(which){
		case 1: result = rect.perimeter();break;
		case 2: result = circ.perimeter();break;
		case 3: result = tri.perimeter();break;
		}
		return result;
	}

	@Override
	public Shape increment() {
		int i;
		for(i=0;i<coords.size();++i){
			try {
				coords.get(i).set_x(coords.get(i).get_x() + 1);
				coords.get(i).set_y(coords.get(i).get_x() + 1);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return this;
	}

	@Override
	public Shape decrement() {
		int i;
		for(i=0;i<coords.size();++i){
			try {
				coords.get(i).set_x(coords.get(i).get_x() - 1);
				coords.get(i).set_y(coords.get(i).get_x() - 1);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
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
		graph.setColor(Color.RED);
		int [] xPoints = new int [nPoints];
		int [] yPoints = new int [nPoints];
		
		for(int i=0; i<nPoints; i++) {
			xPoints[i] = (int)coords.get(i).get_x();
			//System.out.println(xPoints[i]);
			yPoints[i] = (int)coords.get(i).get_y();
			//System.out.println(yPoints[i]);
		}
		graph.drawPolygon(xPoints, yPoints, nPoints);
	}

	@Override
	public int compareTo(Shape other) {
		if(this.area() == other.area())
			return 1;
		return 0;
	}

}
