/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class RectangleWithNoKW {
	double h_;
	double w_;
	
	public RectangleWithNoKW (double h, double w) {
		h_ = h;
		w_ = w;
	}
	
	public double area () {
		return h_*w_;
	}
	public double perimeter () {
		return 2*h_+2*w_;
	}
}
