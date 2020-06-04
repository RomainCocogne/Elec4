/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class TestCircle {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		System.out.println("----- Circle with internal PI -----");
		Circle c1 = new Circle (3.0);
		System.out.println("Area:" + c1.area());
		System.out.println("Perimeter: " + c1.perimeter());
		
		System.out.println("----- Circle with Math PI -----");
		CircleWithMath c2 = new CircleWithMath (3.0);
		System.out.println("Area:" + c2.area());
		System.out.println("Perimeter: " + c2.perimeter());

	}

}
