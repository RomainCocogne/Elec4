/**
 * 
 */
package gse4.labs.java;

import java.awt.Color;

/**
 * @author romain
 *
 */
public class Rectangle extends Shape{
	private double h_;
	private double w_;

	
	public Rectangle (double h, double w, Color c) {
		super(c);
		h_ = h;
		w_ = w;
	}
	
	public double getHeight() { return h_; }
	public double getWidth() { return w_; }

	public void setHeight(double h_) { this.h_ = h_; }
	public void setWidth(double w_) { this.w_ = w_; }

	@Override
	public double area () { return h_*w_; }
	@Override
	public double perimeter () { return 2*h_+2*w_; }
	
	@Override
	public String toString() {
		String s = "Rectangle:\n";
		s+="\t-color "+ color+"\n";
		s+="\t-height "+ w_+"\n";
		s+="\t-width "+ w_+"\n";
		s+="\t-perimeter "+ perimeter()+"\n";
		s+="\t-area "+ area()+"\n";
		return s;
	}
}
