/**
 * 
 */
package gse.labs.java;

import java.lang.reflect.Constructor;

/**
 * @author romain
 *
 */
public class TestDate {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Date date1 = new Date(5, 2, 2016);
		System.out.println("getClass date1 -> "+date1.getClass());
		
		Constructor<?> c[] = date1.getClass().getConstructors();
		for(int i = 0; i < c.length; i++) {
			System.out.println(c[i]);
		}

		Date date2 = new Date (5, 2, 2016);
		System.out.println("date2 -> "+date2);
		System.out.println(date2.getClass());
		
		SuperDate date3 = new SuperDate (5, 2, 2016);
		System.out.println("date3 -> "+date3);
		System.out.println(date3.getClass());
		
		SuperDate date4 = new SuperDate (5, 2, 2016);
		SuperDate date5 = new SuperDate (5, 2, 2016);
		if(date4.equals(date5))
			System.out.println(date4+" is equal to "+date5);
		else
			System.out.println(date4+" is not equal to "+date5);
		
		GreatDate date6 = new GreatDate (5, 2, 2013);
		GreatDate date7 = new GreatDate (5, 2, 2013);
		if(date6.equals(date7))
			System.out.println(date7+" is equal to "+date6);
		else
			System.out.println(date7+" is not equal to "+date6);

		System.out.println(date6.equals(date7));
		System.out.println(date6.equals(0));
		
		
	}

}
