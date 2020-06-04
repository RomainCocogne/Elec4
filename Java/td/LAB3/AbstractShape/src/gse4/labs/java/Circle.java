/**
 * 
 */
package gse4.labs.java;

import java.awt.Color;

/**
 * @author romain
 *
 */
public class Circle extends Shape{
	private double radius_;
	
	
	public Circle(double r, Color c) {
		super(c);
		radius_ = r;
	}
	
	public double getRadius() { return radius_; }
	
	@Override
	public double area() {
		return Math.PI * Math.pow(radius_, 2);
	}
	@Override
	public double perimeter() {
		return 2*Math.PI * radius_;
	}
	
	@Override
	public String toString() {
		String s = "Circle:\n";
		s+="\t-color "+ color+"\n";
		s+="\t-radius "+ radius_+"\n";
		s+="\t-perimeter "+ perimeter()+"\n";
		s+="\t-area "+ area()+"\n";
		return s;
	}

}
