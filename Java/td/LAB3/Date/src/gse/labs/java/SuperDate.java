/**
 * 
 */
package gse.labs.java;

/**
 * @author romain
 *
 */
public class SuperDate {
	private int day;
	private int month;
	private int year;
	
	public SuperDate(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}

	@Override
	public String toString() {
		return month+"/"+day+"/"+year;
	}
	

}
