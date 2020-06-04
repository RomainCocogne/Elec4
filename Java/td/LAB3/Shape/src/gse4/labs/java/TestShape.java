/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class TestShape {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Square sq1 = new Square(7.0);
		double height = sq1.getHeight();
		System.out.println("height: "+height);
		double width = sq1.getWidth();
		System.out.println("width: "+width);
		double area = sq1.area();
		System.out.println("area: "+area);
		
		Rectangle rect1 = new Rectangle(4.0, 6.0);
		System.out.println("rect1 = "+ rect1);

		Rectangle rect2 = new Square(4);
		System.out.println("rect2 = "+rect2);
//		Square sq2 = new Rectangle(4,4);
//		System.out.println(sq2);
		
		Square sq = new Square(2.0);
		System.out.println("sq1 = "+sq);
		sq.setWidth(3.0);
		

	}

}
