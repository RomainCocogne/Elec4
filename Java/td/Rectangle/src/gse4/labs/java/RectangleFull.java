/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class RectangleFull {
	private double h_;
	private double w_;
	
	private static int cnt = 0;
	private int uid_;
	
	public RectangleFull (double h, double w) {
		h_ = h;
		w_ = w;
		++cnt;
		uid_=cnt;
	}
	
	public double area () { return h_*w_; }
	public double perimeter () { return 2*h_+2*w_; }


	public double getHeight() { return h_; }
	public double getWidth() { return w_; }
	public static int getCnt() { return cnt; }
	public int getUid() { return uid_; }

	public void setHeight(double h_) { this.h_ = h_; }
	public void setWidth(double w_) { this.w_ = w_; }
	public void setUid(int uid_) { this.uid_ = uid_; }
}
