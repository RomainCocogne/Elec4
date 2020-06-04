/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class CarDriver {
	private Car car;
	private int nb_month;
	private int points;

	public CarDriver(Car c, int nm, int p) {
		car = c;
		nb_month = nm;
		points = p;
	}
	/**
	 * @return the nb_month
	 */
	public int getNb_month() {
		return nb_month;
	}
	/**
	 * @return the points
	 */
	public int getPoints() {
		return points;
	}
	/**
	 * @return the car
	 */
	public Car getCar() {
		return car;
	}
	/**
	 * @param points the points to set
	 */
	public void setPoints(int points) {
		this.points = points;
	}
}
