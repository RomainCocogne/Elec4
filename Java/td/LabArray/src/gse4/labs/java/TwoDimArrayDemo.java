/**
 * 
 */
package gse4.labs.java;

import java.util.Random;

/**
 * @author romain
 *
 */
public class TwoDimArrayDemo {

	/**
	* Prints a 2-dimensional array of integers (matrix)
	* on the standard output.
	* Format:
	* [[value00, value01, ..., value0N],
	* [value10, value11, ..., value1N],
	* .....
	* [valueM0, valueM1, ..., valueMN]]
	*
	* @param matrix2D the specified 2-dimensional array of integers
	*
	*/
	public static void printMatrix2D(int[][] matrix2D){
	System.out.print("[");
	for(int i = 0; i < matrix2D.length; ++i) {
		System.out.print("[");
		for(int j = 0; j < matrix2D[i].length; ++j)
			System.out.print(matrix2D[i][j]+", ");
		System.out.println("],");
	}
	System.out.println("]");
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int [][] matrix2D = new int[3][4];
		System.out.println("Width "+matrix2D.length);
		System.out.println("Height "+matrix2D[0].length);
		
		Random randInt = new Random();
		for(int i = 0; i < matrix2D.length; ++i)
			for(int j = 0; j < matrix2D[i].length; ++j)
				matrix2D[i][j] = randInt.nextInt(5);
		printMatrix2D(matrix2D);
	}
}
