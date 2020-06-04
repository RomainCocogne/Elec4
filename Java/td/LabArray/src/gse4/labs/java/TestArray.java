/**
 * 
 */
package gse4.labs.java;

import java.util.Random;
import java.util.Arrays;

/**
 * @author romain
 *
 */
public class TestArray {
	
	/**
	* Print an array of integers
	* on the standard output.
	* Format: [value0, value1, ..., valueN]
	*
	* @param arrayOfInt the specified array of integers
	*/
	public static void print(int [] arrayOfInt) {
		for(int i = 0; i < arrayOfInt.length; ++i)
			System.out.print(arrayOfInt[i]+", ");
		System.out.println();
	}
	
	/**
	* Returns the maximum value
	* of the specified array of integers
	*
	* @param arrayOfInt the specified array of integers
	*/
	public static int getMaxValue(int[] arrayOfInt) {
		int m = Integer.MIN_VALUE;
		for(int i = 0; i < arrayOfInt.length; ++i)
			if(arrayOfInt[i]>m) m = arrayOfInt[i];
		return m;
	}
	/**
	* Returns the minimum value
	* of the specified array of integers
	*
	* @param arrayOfInt the specified array of integers
	*/
	public static int getMinValue(int[] arrayOfInt) {
		int m = Integer.MAX_VALUE;
		for(int i = 0; i < arrayOfInt.length; ++i)
			if(arrayOfInt[i]<m) m = arrayOfInt[i];
		return m;
	}
	/**
	*
	* Sorts the specified array of objects
	* into ascending order
	*
	* @param arrayOfInt the specified array of integer
	*/
	public static void sortAscending(int[] arrayOfInt){
		boolean sorted = false;
	    int temp;
	    while(!sorted) {
	        sorted = true;
	        for (int i = 0; i < arrayOfInt.length - 1; i++) {
	            if (arrayOfInt[i] > arrayOfInt[i+1]) {
	                temp = arrayOfInt[i];
	                arrayOfInt[i] = arrayOfInt[i+1];
	                arrayOfInt[i+1] = temp;
	                sorted = false;
	            }
	        }
	    }
	}
	/**
	*
	* Sorts the specified array of objects
	* into descending order
	*
	* @param arrayOfInt the specified array of integer
	*/
	public static void sortDescending(int[] arrayOfInt){
		boolean sorted = false;
	    int temp;
	    while(!sorted) {
	        sorted = true;
	        for (int i = 0; i < arrayOfInt.length - 1; i++) {
	            if (arrayOfInt[i] < arrayOfInt[i+1]) {
	                temp = arrayOfInt[i];
	                arrayOfInt[i] = arrayOfInt[i+1];
	                arrayOfInt[i+1] = temp;
	                sorted = false;
	            }
	        }
	    }
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		int [] arrayOfInt = new int[10];
		System.out.println(arrayOfInt.length);
		System.out.println(arrayOfInt);
		System.out.println(arrayOfInt[6]);
		try {
			System.out.println(arrayOfInt[10]);
		} catch(ArrayIndexOutOfBoundsException error) {
			System.out.println("ArrayIndexOutOfBoundsException cached");
			error.printStackTrace();
		}
		
		Random randomInt = new Random();
		for(int i = 0; i < arrayOfInt.length; ++i)
			arrayOfInt[i] = randomInt.nextInt(100);
		print(arrayOfInt);
		
		System.out.println("Max: "+getMaxValue(arrayOfInt));
		System.out.println("Min: "+getMinValue(arrayOfInt));
		System.out.println("Sorted in ascending order:");
		sortAscending(arrayOfInt);
		print(arrayOfInt);
		System.out.println("Sorted in descending order:");
		sortDescending(arrayOfInt);
		print(arrayOfInt);
		System.out.println("...Using java methods...");
		System.out.println("Max: "+Arrays.stream(arrayOfInt).max().getAsInt());
		System.out.println("Min: "+Arrays.stream(arrayOfInt).min().getAsInt());
		System.out.println("Sorted in ascending order:");
		Arrays.sort(arrayOfInt);
		print(arrayOfInt);
		System.out.println("Sorted in descending order:");
		for (int i = 0; i < arrayOfInt.length / 2; i++) {
	        int temp = arrayOfInt[i];
	        arrayOfInt[i] = arrayOfInt[arrayOfInt.length - 1 - i];
	        arrayOfInt[arrayOfInt.length - 1 - i] = temp;
		}
		print(arrayOfInt);
	}
}
