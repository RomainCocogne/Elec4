/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class Rectangle implements Drawable{
	private int h_;
	private int w_;

	
	public Rectangle (int h, int w) {
		h_ = h;
		w_ = w;
	}
	
	public int getHeight() { return h_; }
	public int getWidth() { return w_; }

	public void setHeight(int h_) { this.h_ = h_; }
	public void setWidth(int w_) { this.w_ = w_; }

	public int area () { return h_*w_; }
	public int perimeter () { return 2*h_+2*w_; }
	
	@Override
	public String toString() {
		String s = "Rectangle:\n";
		s+="\t-height "+ w_+"\n";
		s+="\t-width "+ w_+"\n";
		s+="\t-perimeter "+ perimeter()+"\n";
		s+="\t-area "+ area()+"\n";
		return s;
	}

	@Override
	public void drawWithASCII() {
		System.out.print(" ");
		for(int first_line = 0; first_line < w_; ++first_line)
			System.out.print("__");
		System.out.println("");
		for(int i = 0; i < h_-1; ++i) {
			System.out.print("|");
			for(int j = 0; j < w_; ++j)
				System.out.print("  ");
			System.out.println("|");
		}
		System.out.print("|");
		for(int last_line = 0; last_line < w_; ++last_line)
			System.out.print("__");
		System.out.println("|");
	}

	@Override
	public void drawWithDots() {
		for(int i = 0; i < h_; ++i) {
			for(int j = 0; j < w_; ++j)
				System.out.print(".");
			System.out.println("");
		}
	}	
}
