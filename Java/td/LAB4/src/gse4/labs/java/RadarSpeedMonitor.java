/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class RadarSpeedMonitor {
	private int speed_limit;
	
	public RadarSpeedMonitor(int sl) {
		speed_limit = sl;
	}
	public boolean speedLimitExceeded(Car car) {
		if (car.getSpeed()>speed_limit)
			return true;
		return false;
	}
	/**
	 * @return the speed_limit
	 */
	public int getSpeed_limit() {
		return speed_limit;
	}
	public int getLostPoints(CarDriver driver) {
		int diff_speed = driver.getCar().getSpeed() - speed_limit;
		
		if(diff_speed > 0) {
			if(diff_speed < 11) return 1;
			if(diff_speed < 21) return 2;
			if(diff_speed < 31) return 4;
			if(diff_speed < 41) return 6;
			else return 12;
		}
		return 0;
	}
	public int getSpeedingTicketCost(int ptsLost) {
		switch(ptsLost) {
		case 1: return 50;
		case 2: return 100;
		case 3: return 130;
		case 4: case 5: case 6: return 300;
		case 7: case 8: case 9: return 400;
		case 10: case 11: case 12: return 500;
		default: return 0;
		}
	}
}
