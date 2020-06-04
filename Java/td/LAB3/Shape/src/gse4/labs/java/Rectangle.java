/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class Rectangle {
	protected double h_;
	protected double w_;
	
	protected static int cnt = 0;
	protected int uid_;
	
	public Rectangle (double h, double w) {
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

	protected String computeValues() {
		String s = "";
		s+="\t-id "+ uid_+"\n";
		s+="\t-height "+ w_+"\n";
		s+="\t-width "+ w_+"\n";
		s+="\t-perimeter "+ perimeter()+"\n";
		s+="\t-area "+ area()+"\n";
		return s;
	}
	@Override
	public String toString() {
		String s = "Rectangle:\n";
		s+=computeValues();
		return s;
	}
	
	
}
