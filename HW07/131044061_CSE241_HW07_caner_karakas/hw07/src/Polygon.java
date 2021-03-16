
import javax.swing.JPanel;

public abstract class Polygon extends JPanel implements Shape {

	private static final long serialVersionUID = 1L;
	/**
	 * empty const.
	 */
	public Polygon() {
	}
	
	public class Point2D {
		
		private double x, y;
		/**
		 * inner Point2D constructor
		 */
		public Point2D() {}
		/**
		 * take double params
		 * @param x
		 * @param y
		 * @throws Exception
		 */
		Point2D(double x, double y) throws Exception{
			set_x(x);
			set_y(y);
		}


		public double get_y() {
			return y;
		}
		/**
		 * set_y
		 * @param y
		 * @throws Exception
		 */
		public void set_y(double y) throws Exception {
			if(y>=0)
				this.y = y;
			else
				new Exception();
		}

		public double get_x() {
			return x;
		}
		/**
		 * set_x
		 * @param x1
		 * @throws Exception
		 */
		public void set_x(double x1) throws Exception{
			if(x>=0)
				this.x = x1;
			else
				new Exception();
		}
	}
	

}
