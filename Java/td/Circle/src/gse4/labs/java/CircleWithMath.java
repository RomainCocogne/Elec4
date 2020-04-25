/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class CircleWithMath {
	private double radius_;
	
	
	public CircleWithMath(double r) {
		radius_ = r;
	}
	
	public double area() {
		return Math.PI * Math.pow(radius_, 2);
	}
	
	public double perimeter() {
		return 2*Math.PI * radius_;
	}
	
	public double getRadius() { return radius_; }
}
