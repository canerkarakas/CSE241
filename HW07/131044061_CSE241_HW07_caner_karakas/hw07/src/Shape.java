
import java.awt.Graphics;
import java.awt.Graphics2D;



public interface Shape extends Comparable<Shape> {
	
	public abstract double area();
	public abstract double perimeter();
	public abstract Shape increment();
	public abstract Shape decrement();
	public abstract void draw(Graphics graph);
}
