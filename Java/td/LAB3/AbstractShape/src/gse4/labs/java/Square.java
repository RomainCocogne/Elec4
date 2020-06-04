/**
 * 
 */
package gse4.labs.java;

import java.awt.Color;

/**
 * @author romain
 *
 */
public class Square extends Shape {
	
	private double side_;
	
	public Square(double s, Color c) {
		super(c);
		side_ = s;
	}
	
	public void setSide(double s) { side_ = s; }
	public double getSide() {return side_;}
	
	@Override
	public double area () { return side_*side_; }
	@Override
	public double perimeter () { return 4*side_; }
	
	@Override
	public String toString() {
		String s = "Square:\n";
		s+="\t-color "+ color+"\n";
		s+="\t-side "+ side_+"\n";
		s+="\t-perimeter "+ perimeter()+"\n";
		s+="\t-area "+ area()+"\n";
		return s;
	}

}
