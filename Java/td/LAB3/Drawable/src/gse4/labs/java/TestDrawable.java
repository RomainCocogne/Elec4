/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class TestDrawable {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Drawable drawable1 = new Rectangle(6, 5);
		System.out.println(drawable1.getClass());
		drawable1.drawWithASCII();
		drawable1.drawWithDots();
		Drawable drawable2 = new Cow("Cow", 20);
		System.out.println(drawable2.getClass());
		drawable2.drawWithASCII();
		
//		System.out.println(drawable1.area());
//		System.out.println((Rectangle)drawable1.area());
//		System.out.println((Rectangle)drawable2.area());
		
		if (drawable1 instanceof Rectangle)
			System.out.println(((Rectangle)drawable1).area());
		if (drawable2 instanceof Cow)
			System.out.println(((Cow)drawable2).getName());
	}
}
