/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class TestRadarSpeedMonitor {
	
	public static void printSeparateur() {
		System.out.println();
		System.out.println("--------------------------------");
		System.out.println();
	}
	
	public static void ex1() {
		//Create a RadarSpeedMonitor with speed
		//limit set to 130 km/h
		RadarSpeedMonitor radar = new RadarSpeedMonitor(130);
		//Create a car registered in 2001
		Car car = new Car(2001);
		//The car speed reaches 100 km/h
		car.setSpeed(100);
		//Does this car exceed the speed limit?
		if(radar.speedLimitExceeded(car)) {
			System.out.println("Speed limit exceeded!!!");
			car.setSpeed(radar.getSpeed_limit());
		} else {
			System.out.println("Speed Ok");
		}
		System.out.println();
		//The car speed reaches 140 km/h
		car.setSpeed(140);
		//Does this car exceed the speed limit?
		if(radar.speedLimitExceeded(car)) {
			System.out.println("Speed limit exceeded!!!");
			car.setSpeed(radar.getSpeed_limit());
		} else {
			System.out.println("Speed Ok");
		}
	}
	public static void ex2() {
		RadarSpeedMonitor radar = new RadarSpeedMonitor(130);
		CarDriver driver = new CarDriver(new Car(2001), 18, 12);
		driver.getCar().setSpeed(140);
		System.out.println("driver has lost: "+radar.getLostPoints(driver)+" points");
		driver.getCar().setSpeed(150);
		System.out.println("driver has lost: "+radar.getLostPoints(driver)+" points");
		driver.getCar().setSpeed(160);
		System.out.println("driver has lost: "+radar.getLostPoints(driver)+" points");
		driver.getCar().setSpeed(170);
		System.out.println("driver has lost: "+radar.getLostPoints(driver)+" points");
		driver.getCar().setSpeed(180);
		System.out.println("driver has lost: "+radar.getLostPoints(driver)+" points");
		driver.getCar().setSpeed(190);
		System.out.println("driver has lost: "+radar.getLostPoints(driver)+" points");
	}
	public static void ex3() {
		RadarSpeedMonitor radar = new RadarSpeedMonitor(130);
		CarDriver driver2 = new CarDriver(new Car(2001), 18, 12);
		//This driver's car reaches speed = speed limit
		//For loop
		for (int currentSpeed = radar.getSpeed_limit(); currentSpeed < 180; currentSpeed += 10) {
			driver2.getCar().setSpeed(currentSpeed);
			System.out.println("Car speed is "+currentSpeed+" km/h");
			System.out.println("driver has lost "+radar.getLostPoints(driver2)+" points");
			driver2.setPoints(driver2.getPoints()-radar.getLostPoints(driver2));
			System.out.println("driver still has "+driver2.getPoints()+" points");
			if(driver2.getPoints() < 6)
				break;
		}
	}
	public static void ex4() {
		RadarSpeedMonitor radar = new RadarSpeedMonitor(130);
		CarDriver driver3 = new CarDriver(new Car(2002), 6, 12);
		int carSpeed = driver3.getCar().getSpeed();
		System.out.println("Before loop: car speed is "+ carSpeed);
		while (driver3.getCar().getSpeed() < radar.getSpeed_limit()) {
			carSpeed+=1;
			driver3.getCar().setSpeed(carSpeed);
			if(driver3.getNb_month() < 12 && driver3.getCar().getSpeed() >= 0.8*radar.getSpeed_limit())
				break;
			if(driver3.getCar().getSpeed()%2 != 0)
				continue;
			System.out.println("In loop: car speed is "+ driver3.getCar().getSpeed());
		}
		System.out.println("After loop: car speed is "+ driver3.getCar().getSpeed());
	}
	public static void ex5() {
		CarDriver driver4 = new CarDriver(new Car(2002), 6, 12);
		driver4.getCar().setSpeed(140);
		int speed = driver4.getCar().getSpeed();
		System.out.println("Before loop: car speed is "+ speed);
		do {
			speed +=10;
			driver4.getCar().setSpeed(speed);
			System.out.println("car speed is:"+driver4.getCar().getSpeed());
		} while(speed <= 130);
	}
	public static void ex6() {
		RadarSpeedMonitor radar = new RadarSpeedMonitor(130);
		for(int nbPtsLost = 0; nbPtsLost <= 12; ++nbPtsLost) {
			int cost = radar.getSpeedingTicketCost(nbPtsLost);
			System.out.println("Points lost: "+ nbPtsLost+ " Speeding ticket cost: "+cost+"$");
		}
	}
	

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		ex1();
		printSeparateur();
		
		///////////////////////////////////////////////
		
		ex2();
		printSeparateur();
		
		///////////////////////////////////////////////
		
		ex3();		
		printSeparateur();
		
		///////////////////////////////////////////////
		
		ex4();		
		printSeparateur();
		
		///////////////////////////////////////////////

		ex5();		
		printSeparateur();
		
		///////////////////////////////////////////////

		ex6();
		
	}
	
	

}
