/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class RectangleWithPrivateKW {
	private double h_;
	private double w_;
	
	public RectangleWithPrivateKW (double h, double w) {
		h_ = h;
		w_ = w;
	}
	
	public double area () {
		return h_*w_;
	}
	public double perimeter () {
		return 2*h_+2*w_;
	}

	public double getHeight() { return h_; }

	public double getWidth() { return w_; }

	public void setHeight(double h_) { this.h_ = h_; }

	public void setWidth(double w_) { this.w_ = w_; }
	
}
