/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class Square extends Rectangle {
	
	
	public Square(double s) {
		super(s, s);
	}
	
	public void setHeight(double h_) {throw new UnsupportedOperationException();}
	public void setWidth(double w_) {throw new UnsupportedOperationException();}
	public void setUid(int uid_) {throw new UnsupportedOperationException();}
	
	public void setSide(double s) {
		super.w_=s;
		super.h_=s;
	}
	public double getSide() {return super.w_;}
	
	@Override
	public String toString() {
		String s = "Square:\n";
		s+=computeValues();
		return s;
	}

}
