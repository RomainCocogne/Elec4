/**
 * 
 */
package gse4.labs.java;


/**
 * @author romain
 *
 */
public class Circle {
	private double radius_;
	
	public static final double PI = 3.141592653589793;
	
	public Circle(double r) {
		radius_ = r;
	}
	
	public double area() {
		return PI * radius_ * radius_;
	}
	
	public double perimeter() {
		return 2*PI * radius_; 
	}
	
	public double getRadius() { return radius_; }

}
