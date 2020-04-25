/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class TestRectangle {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println("----- Rectangle with public variables -----");
		RectanglePublic rectp = new RectanglePublic (2.4,7.5);
		rectp.h_ = 8.4;
		System.out.println("width: " + rectp.w_);
		System.out.println("height: " + rectp.h_);
		System.out.println("Area:" + rectp.area());
		System.out.println("Perimeter: " + rectp.perimeter());
		
		System.out.println("----- Rectangle with final keyword -----");
		RectangleWithFinalKW rectf = new RectangleWithFinalKW (2.4,7.5);
//		rectf.h_ = 8.4; // error
		System.out.println("width: " + rectf.w_);
		System.out.println("height: " + rectf.h_);
		System.out.println("Area:" + rectf.area());
		System.out.println("Perimeter: " + rectf.perimeter());
		
		System.out.println("----- Rectangle with private variables -----");
		RectangleWithPrivateKW rectpr = new RectangleWithPrivateKW (2.4,7.5);
		System.out.println("width: " + rectpr.getWidth());
		System.out.println("height: " + rectpr.getHeight());
		System.out.println("Area:" + rectpr.area());
		System.out.println("Perimeter: " + rectpr.perimeter());
		
		System.out.println("----- Rectangle with no keyword -----");
		RectangleWithNoKW rectn = new RectangleWithNoKW (2.4,7.5);
		rectn.h_ = 8.4;
		System.out.println("width: " + rectn.w_);
		System.out.println("height: " + rectn.h_);
		System.out.println("Area:" + rectn.area());
		System.out.println("Perimeter: " + rectn.perimeter());
		
		System.out.println("----- Rectangle with id -----");
		RectangleFull rectf1 = new RectangleFull (2.4, 7.5);
		System.out.println("width 1: " + rectf1.getWidth());
		System.out.println("height 1: " + rectf1.getHeight());
		System.out.println("Area 1:" + rectf1.area());
		System.out.println("Perimeter 1: " + rectf1.perimeter());
		System.out.println("Rect1: cnt=" + RectangleFull.getCnt() + ", uid=" + rectf1.getUid());
		RectangleFull rectf2 = new RectangleFull (3.2, 8);
		System.out.println("Rect2: cnt=" + RectangleFull.getCnt() + ", uid=" + rectf2.getUid());
		System.out.println("Rect1: cnt=" + RectangleFull.getCnt() + ", uid=" + rectf1.getUid());
	}	
}
