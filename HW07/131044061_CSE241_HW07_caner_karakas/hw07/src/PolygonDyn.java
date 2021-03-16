import java.awt.Color;
import java.awt.Graphics;
import java.lang.*;

public class PolygonDyn extends Polygon {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private Point2D [] coords;
	private int coordsArrSize;
	private Rectangle rect;
	private Circle circ;
	private Triangle tri;
	private int which;
	private int nPoints;

	public PolygonDyn() {
		// TODO Auto-generated constructor stub
	}
	/**
	 * take Rectangle obj
	 * @param rectangle
	 * @throws Exception
	 */
	public PolygonDyn(Rectangle rectangle) throws Exception {
		rect = new Rectangle(rectangle);
		which = 1;
		this.set_ArrSize(4);
		nPoints = 4;
		System.out.printf("%.2f", rect.get_width());
		coords = new Point2D[this.get_ArrSize()];
		Point2D temp = new Point2D(rect.get_pos_x(), rect.get_pos_y());
		coords[0] = temp;
		temp = new Point2D(rect.get_pos_x() + rect.get_width(), rect.get_pos_y());
		coords[1] = temp;
		temp = new Point2D(rect.get_pos_x() + rect.get_width(), rect.get_pos_y() + rect.get_height());
		coords[2] = temp;
		temp = new Point2D(rect.get_pos_x(), rect.get_pos_y() + rect.get_height());
		coords[3] = temp;
	}
	/**
	 * take Circle obj
	 * @param circle
	 * @throws Exception
	 */
	public PolygonDyn(Circle circle) throws Exception {
		circ = new Circle();
		circ = circle;
		which = 2;
		nPoints = 100;
		this.set_ArrSize(100);
		coords = new Point2D[this.get_ArrSize()];
		Point2D temp = new Point2D(circ.get_pos_x(),circ.get_pos_y()-circ.get_radius());
		coords[0] = temp;
		double cons = 3.6*(Math.PI/180.0);//radyan cevirisi * 360/100 (100 nokta);
		int i;
		for(i=1;i<25;++i){
			temp = new Point2D(coords[0].get_x() + circ.get_radius()*(Math.sin(cons*i)), coords[0].get_y() + (circ.get_radius() - circ.get_radius()*(Math.cos(cons*i))));
			coords[i] = temp;
		}
		temp = new Point2D(coords[0].get_x()+circ.get_radius(), coords[0].get_y()+circ.get_radius());
		coords[25] = temp;
		for(i=26;i<50;++i){
			temp = new Point2D(coords[25].get_x() -(circ.get_radius() - circ.get_radius()*(Math.cos(cons*(i-25)))), coords[25].get_y() + circ.get_radius()*(Math.sin(cons*(i-25))));
			coords[i] = temp;
		}
		temp = new Point2D(coords[25].get_x()-circ.get_radius(), coords[25].get_y() + coords[25].get_y()+circ.get_radius());
		coords[50] = temp;
		for(i=51;i<75;++i){
			temp = new Point2D(coords[50].get_x() - circ.get_radius()*(Math.sin(cons*(i-50))), coords[50].get_y() - (circ.get_radius() - circ.get_radius()*(Math.cos(cons*(i-50)))));
			coords[i] = temp;
		}
		temp = new Point2D(coords[50].get_x()-circ.get_radius(), coords[50].get_y()-circ.get_radius());
		coords[75] = temp;
		for(i=76;i<100;++i){
			temp = new Point2D(coords[75].get_x() + (circ.get_radius() - circ.get_radius()*(Math.cos(cons*(i-75)))), coords[75].get_y() - circ.get_radius()*(Math.sin(cons*(i-75))));
			coords[i] = temp;
		}
	}
	/**
	 * take Triangle obj
	 * @param triangle
	 * @throws Exception
	 */
	public PolygonDyn(Triangle triangle) throws Exception {
		tri = new Triangle();
		tri = triangle;
		which = 3;
		set_ArrSize(3);
		nPoints = 3;
		coords = new Point2D[get_ArrSize()];
		Point2D temp = new Point2D();
		int i;
		for(i=0;i<3;++i){
			temp = new Point2D(tri.get_point_x(i),tri.get_point_y(i));
			coords[i] = temp;
		}
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
		for(i=0;i<coordsArrSize;++i){
			try {
				coords[i].set_x(coords[i].get_x() + 1);
				coords[i].set_y(coords[i].get_x() + 1);
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
		for(i=0;i<coordsArrSize;++i){
			try {
				coords[i].set_x(coords[i].get_x() - 1);
				coords[i].set_y(coords[i].get_x() - 1);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return this;
	}
	
	@Override
	public void paintComponent(Graphics graph){
		super.paintComponent(graph);
		graph.setColor(Color.BLACK);
		int [] xPoints = new int [nPoints];
		int [] yPoints = new int [nPoints];
		
		for(int i=0; i<nPoints; i++)
			xPoints[i] = (int) coords[i].get_x();
		for(int i=0; i<nPoints; i++)
			yPoints[i] = (int) coords[i].get_y();
		
		graph.drawPolygon(xPoints, yPoints, nPoints);
	}

	@Override
	public void draw(Graphics graph) {
		this.paintComponent(graph);
	}

	@Override
	public int compareTo(Shape other) {
		if(this.area() == other.area())
			return 1;
		return 0;
	}
	
	public void set_coords(Point2D crd[], int size, int index) throws Exception {
		if(index>this.get_ArrSize()){
			//System.out.printf("Error!!");
			new Exception();
		}
		else{
			int i;
			for(i=0;i<size;++i){
				if(index<this.get_ArrSize()){
					this.coords[index] = crd[i];
					++index;
				}
				else{
					i = size + 1;
				}
			}
		}
	}
	
	Point2D[] get_coords() {return coords;}

	public int get_ArrSize()  {return coordsArrSize;}

	public void set_ArrSize(int size) {coordsArrSize = size;}

}
