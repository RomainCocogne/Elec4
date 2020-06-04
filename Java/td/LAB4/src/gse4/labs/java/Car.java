/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class Car {
	private int speed;
	private int reg_year;
	
	public Car(int ry) {
		reg_year = ry;
		speed = 0;
	}

	/**
	 * @return the speed
	 */
	public int getSpeed() {
		return speed;
	}

	/**
	 * @return the reg_year
	 */
	public int getReg_year() {
		return reg_year;
	}

	/**
	 * @param speed the speed to set
	 */
	public void setSpeed(int speed) {
		this.speed = speed;
	}
}
