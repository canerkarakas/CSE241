import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.PrintStream;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import java.awt.Button;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class test {

	/**
	 * private members for tests
	 */
	private JFrame frame;
	private static Polygon [] poly;
	private static Shape temp1;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					test window = new test();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public test() {
		initialize();
	}
	/**
	 * converAll converts all shapes to Polygons and return a new array with new shapes
	 * @throws Exception 
	 */
	public static Polygon[] convertAll(Shape arr[]) throws Exception {
		poly = new Polygon [arr.length];
		for(int i = 0; i<arr.length; i++) {
			if(arr[i] instanceof Rectangle) {
				Rectangle temp = new Rectangle((Rectangle)arr[i]);
				poly[i] = new PolygonVect(temp);
			}
			else if(arr[i] instanceof Triangle) {
				Triangle temp = new Triangle((Triangle)arr[i]);
				poly[i] = new PolygonVect(temp);
			}
			else if(arr[i] instanceof Circle) {
				Circle temp = new Circle((Circle)arr[i]);
				poly[i] = new PolygonVect(temp);
			}
			else if(arr[i] instanceof PolygonDyn) {
				poly[i] = new PolygonDyn();
				poly[i] = ((PolygonDyn)arr[i]);
			}
			else if(arr[i] instanceof PolygonVect) {
				poly[i] = new PolygonVect();
				poly[i] = ((PolygonVect)arr[i]);
			}
			else
				new Exception();
		}
		return poly;
	}
	
	/**
	 * drawAll
	 * @param arr
	 * @param g
	 */
	public static void drawAll(Shape arr[], Graphics g) {
		for(int i =0;i<arr.length;i++)
			arr[i].draw(g);
	}
	
	/**
	 * sortShapes increasingly sorts them with respect to their areas.
	 * @param arr
	 */
	public static void sortShapes (Shape arr[]) {
		int i = 0;
		int j = 0;
		for(i=0;i<arr.length-1;i++) {
			for(j=0;j<arr.length-i-1;j++) {
				if(arr[j].area() > arr[j+1].area()) {
					temp1 = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp1;
				}
			}
		}
	}

	/**
	 *  Initialize the contents of the frame.
	 */
	private void initialize() {
		//Create a frame to contain all other GUI elements
				frame = new JFrame();
				frame.setBounds(100, 100, 841, 518);
				frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				frame.getContentPane().setLayout(null);
				
				//Create a panel for drawing shapes, you can think this as canvas
				final JPanel panel = new JPanel();
				panel.setBackground(Color.WHITE);
				panel.setBounds(10, 11, 805, 423);
				frame.getContentPane().add(panel);
				
				// A button that will clear our panel (canvas) when clicked
				// This can be done using callback function mouseClicked
				// The GUI engine will execute mouseClicked function when
				// the user clicks our clear button.
				JButton btnClear = new JButton("Clear");
				btnClear.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent e) {
						// Clear panel by filling white :)
						// The Graphics reference is used to draw shapes.
						// When we call panel.getGraphics(), we reach the brush and palette
						// to design our paint that will be painted on the panel(canvas). 
						// After we design our paint,
						// we need to call the paintComponents method, which will
						// ACTUALLY paint the panel with the design that we made.
						Graphics g = panel.getGraphics(); // get brush
						g.setColor(Color.WHITE); // from now on, use white color
						g.fillRect(0, 0, panel.getWidth(), panel.getHeight()); 
						panel.paintComponents(g); // the panel will change when THIS function is executed
					}
				});

				btnClear.setBounds(740, 456, 75, 23);
				frame.getContentPane().add(btnClear); // button reference copied
				
				// A button that will draw our shapes to panel (canvas) when clicked
				// This can be done using callback function mouseClicked (same as above)
				JButton btnDraw = new JButton("9");
				btnDraw.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent arg0) {
						try {
							Triangle t;
							t = new Triangle(500);
							t.set_coords(0, 25, 0, t.get_height(), 50, t.get_height());
							Triangle t1 = new Triangle(10);
							t.set_coords(0, 5, 0, t1.get_height(), 10, t1.get_height());
							ComposedShape comp = new ComposedShape(t,t1);
							comp.optimalFit(t, t1);
							
							Graphics g = panel.getGraphics();
							g.setColor(Color.RED);
							comp.draw(g);
							
							// Now paint component with the graphics
							panel.paintComponents(g);
							System.out.printf("\n");
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				});
				btnDraw.setBounds(619, 456, 75, 23);
				frame.getContentPane().add(btnDraw);
				
				JLabel lblNewLabel = new JLabel("Test");
				lblNewLabel.setBounds(10, 438, 46, 14);
				frame.getContentPane().add(lblNewLabel);
				
				JButton btnNewButton = new JButton("1");
				btnNewButton.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent arg0) {
						try {
							Rectangle r;
							r = new Rectangle(100,100);
							r.set_coords(0, 0);
							Rectangle r1 = new Rectangle(50,50);
							r1.set_coords(0, 0);
							ComposedShape comp = new ComposedShape(r,r1);
							comp.optimalFit(r, r1);
							
							
							Graphics g = panel.getGraphics();
							g.setColor(Color.RED);
							comp.draw(g);
							
							// Now paint component with the graphics
							panel.paintComponents(g);
							System.out.printf("\n");
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				});
				btnNewButton.setBounds(0, 456, 75, 23);
				frame.getContentPane().add(btnNewButton);
				
				JButton btnNewButton_1 = new JButton("2");
				btnNewButton_1.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent arg0) {
						//Rectangle r;
						try {
							Rectangle r;
							r = new Rectangle(200,200);
							r.set_coords(0, 0);
							Circle c = new Circle(10);
							c.set_coords(50, 50);
							ComposedShape comp = new ComposedShape(r,c);
							comp.optimalFit(r, c);
							
							Graphics g = panel.getGraphics();
							g.setColor(Color.RED);
							comp.draw(g);
							
							// Now paint component with the graphics
							panel.paintComponents(g);
							System.out.printf("\n");
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				});
				btnNewButton_1.setBounds(77, 456, 75, 23);
				frame.getContentPane().add(btnNewButton_1);
				
				JButton btnNewButton_2 = new JButton("3");
				btnNewButton_2.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent arg0) {
						try {
							Rectangle r;
							r = new Rectangle(100,100);
							r.set_coords(0, 0);
							Triangle t1 = new Triangle(10);
							t1.set_coords(0, 5, 0, t1.get_height(), 10, t1.get_height());
							ComposedShape comp = new ComposedShape(r,t1);
							comp.optimalFit(r, t1);
							
							
							Graphics g = panel.getGraphics();
							g.setColor(Color.RED);
							comp.draw(g);
							
							// Now paint component with the graphics
							panel.paintComponents(g);
							System.out.printf("\n");
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				});
				btnNewButton_2.setBounds(154, 456, 75, 23);
				frame.getContentPane().add(btnNewButton_2);
				
				JButton btnNewButton_3 = new JButton("4");
				btnNewButton_3.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent arg0) {
						
						try {
							Rectangle r;
							r = new Rectangle(10,10);
							r.set_coords(0, 0);
							Circle c = new Circle();
							c.set_radius(200);
							c.set_coords(200, 200);
							ComposedShape comp = new ComposedShape(c,r);
							comp.optimalFit(c, r);
							
							
							Graphics g = panel.getGraphics();
							g.setColor(Color.RED);
							comp.draw(g);
							
							// Now paint component with the graphics
							panel.paintComponents(g);
							System.out.printf("\n");
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				});
				btnNewButton_3.setBounds(232, 456, 75, 23);
				frame.getContentPane().add(btnNewButton_3);
				
				JButton btnNewButton_4 = new JButton("5");
				btnNewButton_4.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent arg0) {
						
						try {
							Circle c = new Circle();
							c.set_radius(200);
							c.set_coords(200, 200);
							Triangle t1 = new Triangle(10);
							t1.set_coords(0, 5, 0, t1.get_height(), 10, t1.get_height());
							ComposedShape comp = new ComposedShape(c,t1);
							comp.optimalFit(c, t1);
							
							
							Graphics g = panel.getGraphics();
							g.setColor(Color.RED);
							comp.draw(g);
							
							
							// Now paint component with the graphics
							panel.paintComponents(g);
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				});
				btnNewButton_4.setBounds(308, 456, 75, 23);
				frame.getContentPane().add(btnNewButton_4);
				
				JButton btnNewButton_5 = new JButton("6");
				btnNewButton_5.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent arg0) {
						try {
							Triangle t;
							t = new Triangle(500);
							t.set_coords(250, 0, 500, t.get_height(), 0, t.get_height());
							Rectangle r;
							r = new Rectangle(10,10);
							r.set_coords(0, 0);
							ComposedShape comp = new ComposedShape(t,r);
							comp.optimalFit(t, r);
							
							
							Graphics g = panel.getGraphics();
							g.setColor(Color.RED);
							comp.draw(g);
							panel.paintComponents(g);
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
						
					}
				});
				btnNewButton_5.setBounds(385, 456, 75, 23);
				frame.getContentPane().add(btnNewButton_5);
				
				JButton btnNewButton_6 = new JButton("7");
				btnNewButton_6.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent arg0) {
						try {
							Triangle t;
							t = new Triangle(500);
							t.set_coords(250, 0, 500, t.get_height(), 0, t.get_height());
							Circle c = new Circle(10);
							c.set_coords(50, 50);
							ComposedShape comp = new ComposedShape(t,c);
							comp.optimalFit(t, c);
							
							
							Graphics g = panel.getGraphics();
							g.setColor(Color.RED);
							comp.draw(g);
							panel.paintComponents(g);
						} catch (Exception e) {
							e.printStackTrace();
						}
					}
				});
				btnNewButton_6.setBounds(465, 456, 75, 23);
				frame.getContentPane().add(btnNewButton_6);
				
				JButton btnNewButton_7 = new JButton("8");
				btnNewButton_7.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent arg0) {
						try {
							Circle c = new Circle();
							c.set_radius(200);
							c.set_coords(200, 200);
							Circle c1 = new Circle();
							c1.set_radius(10);
							c1.set_coords(10, 10);
							
							ComposedShape comp = new ComposedShape(c,c1);
							comp.optimalFit(c, c1);
							
							Graphics g = panel.getGraphics();
							g.setColor(Color.RED);
							comp.draw(g);
							
							// Now paint component with the graphics
							panel.paintComponents(g);
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				});
				btnNewButton_7.setBounds(541, 456, 75, 23);
				frame.getContentPane().add(btnNewButton_7);
				
				JButton btnNewButton_8 = new JButton("PolyVect");
				btnNewButton_8.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent arg0) {
						try {
							Circle c = new Circle();
							c.set_radius(200);
							c.set_coords(200, 200);
							Triangle t;
							t = new Triangle(500);
							t.set_coords(250, 0, 500, t.get_height(), 0, t.get_height());
							Rectangle r;
							r = new Rectangle(10,10);
							r.set_coords(0, 0);
							PolygonVect pol1 = new PolygonVect(c);
							PolygonVect pol2 = new PolygonVect(t);
							PolygonVect pol3 = new PolygonVect(r);
							
							
							
							Graphics g = panel.getGraphics();
							g.setColor(Color.RED);
							pol1.draw(g);
							pol2.draw(g);
							pol3.draw(g);
							
							// Now paint component with the graphics
							panel.paintComponents(g);
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				});
				btnNewButton_8.setBounds(37, 436, 75, 18);
				frame.getContentPane().add(btnNewButton_8);
				JButton button = new JButton("PolyDyn");
				button.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent arg0) {
						try {
							Triangle t;
							t = new Triangle(500);
							t.set_coords(250, 0, 500, t.get_height(), 0, t.get_height());
							Rectangle r;
							r = new Rectangle(10,10);
							r.set_coords(0, 0);
							PolygonDyn pol2 = new PolygonDyn(t);
							PolygonDyn pol3 = new PolygonDyn(r);
							
							
							Graphics g = panel.getGraphics();
							g.setColor(Color.RED);
							pol2.draw(g);
							pol3.draw(g);
							
							// Now paint component with the graphics
							panel.paintComponents(g);
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				});
				button.setBounds(120, 436, 75, 18);
				frame.getContentPane().add(button);
				
				JButton button_1 = new JButton("drawAll");
				button_1.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent arg0) {
						try {
							Triangle t;
							t = new Triangle(500);
							t.set_coords(250, 0, 500, t.get_height(), 0, t.get_height());
							Rectangle r;
							r = new Rectangle(10,10);
							r.set_coords(0, 0);
							Circle c = new Circle();
							c.set_radius(200);
							c.set_coords(200, 200);
							Shape [] shapes = new Shape[3];
							shapes[0] = r;
							shapes[1] = c;
							shapes[2] = t;
							
							
							Graphics g = panel.getGraphics();
							g.setColor(Color.RED);
							drawAll(shapes, g);
							
							// Now paint component with the graphics
							panel.paintComponents(g);
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				});
				button_1.setBounds(205, 436, 75, 18);
				frame.getContentPane().add(button_1);
				
				JButton button_2 = new JButton("convertAll");
				button_2.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent arg0) {
						try {
							Rectangle r;
							r = new Rectangle(200,200);
							r.set_coords(0, 0);
							Circle c = new Circle(10);
							c.set_coords(50, 50);
							Shape [] shapes = new Shape [2];
							shapes[0] = r;
							shapes[1] = c;
							
							Graphics g = panel.getGraphics();
							g.setColor(Color.RED);
							Polygon [] pol = new Polygon[2];
							pol = convertAll(shapes);
							pol[0].draw(g);
							pol[1].draw(g);
							
							// Now paint component with the graphics
							panel.paintComponents(g);
							System.out.printf("\n");
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				});
				button_2.setBounds(281, 436, 75, 18);
				frame.getContentPane().add(button_2);
				
				JButton button_3 = new JButton("sortShapes");
				button_3.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent arg0) {
						try {
							Triangle t;
							t = new Triangle(500);
							t.set_coords(250, 0, 500, t.get_height(), 0, t.get_height());
							Rectangle r;
							r = new Rectangle(10,10);
							r.set_coords(0, 0);
							Circle c = new Circle(10);
							c.set_coords(50, 50);
							Shape [] shapes = new Shape[3];
							shapes[0] = t;
							shapes[1] = r;
							shapes[2] = c;
							
							for(int i=0;i<3;i++)
								System.out.printf("%s ==> area = %.2f\n", shapes[i].getClass().getName(), shapes[i].area());
							
							sortShapes(shapes);
							System.out.printf("\nsortShapes sonrasi\n\n");
							for(int i=0;i<3;i++)
								System.out.printf("%s ==> area = %.2f\n", shapes[i].getClass().getName(), shapes[i].area());
							
							
							
							Graphics g = panel.getGraphics();
							g.setColor(Color.RED);
							drawAll(shapes,g);
							
							// Now paint component with the graphics
							panel.paintComponents(g);
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				});
				button_3.setBounds(362, 434, 75, 18);
				frame.getContentPane().add(button_3);
	}
}
