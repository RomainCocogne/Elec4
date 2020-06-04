/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class RectanglePublic {
	public double h_;
	public double w_;
	
	/**
	 * 
	 * @param h set the height of rectangle
	 * @param w set the width of rectangle
	 */
	public RectanglePublic (double h, double w) {
		h_ = h;
		w_ = w;
	}
	
	/**
	 * 
	 * @return area of rectangle
	 */
	public double area () {
		return h_*w_;
	}
	/**
	 * 
	 * @return perimeter of rectangle
	 */
	public double perimeter () {
		return 2*h_+2*w_;
	}
}
