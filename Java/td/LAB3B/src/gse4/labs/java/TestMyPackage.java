/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class TestMyPackage {
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Drawable drawable2 = new Cow("Cow", 20);
		System.out.println(drawable2.getClass());
		drawable2.drawWithASCII();
	}
}
