/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class MainMathDivide {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		MathDivide div = new MathDivide();
		System.out.println(div.divideNormal(4, 2));
//		System.out.println(div.divide(4, 0));
		System.out.println(div.divideCatchError(4, 0));

	}

}
