/**
 * 
 */
package gse4.labs.java;

import java.awt.Color;

/**
 * @author romain
 *
 */
public abstract class Shape {
	protected Color color;
	
	public Shape(Color c) {
		color = c;
	}
	
	public Color getColor() { return color; }
	
	// calculate and compute the area of the shape
	public abstract double area();
	// calculate and compute the perimeter of the shape
	public abstract double perimeter();

}
