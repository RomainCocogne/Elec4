/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class RectangleWithFinalKW {
	public final double h_;
	public final double w_;
	
	public RectangleWithFinalKW (double h, double w) {
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
