/**
 * 
 */
package gse.labs.java;

/**
 * @author romain
 *
 */
public class GreatDate {
	private int day;
	private int month;
	private int year;
	
	public GreatDate(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}

	@Override
	public String toString() {
		return month+"/"+day+"/"+year;
	}

	@Override
	public boolean equals(Object obj) {
		if (getClass() == obj.getClass()) {
			GreatDate d = (GreatDate)obj;
			if(day != d.day || month != d.month || year != d.year)
				return false;
			return true;
		}
		return false;
	}
}
