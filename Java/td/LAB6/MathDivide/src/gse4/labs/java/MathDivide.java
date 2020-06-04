/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class MathDivide {
	public MathDivide() {}
	public int divideNormal(int n, int d) {
		return n/d;
	}
	
	public int divide(int n, int d) {
		if(d == 0) throw new IllegalArgumentException("Can't divide by zero");
		return n/d;
	}
	
	public int divideCatchError(int n, int d) {
		int res = -1;
		try {
			res = n/d;
		} catch (ArithmeticException e) {
			System.out.println("error: / by zero");
		}
		return res;
	}
}
