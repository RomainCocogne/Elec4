/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class TestSmartPhone {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Smartphone mytel = new Smartphone();
		mytel.sendSMS("0687374202", "I have a new phone !");
		mytel.voiceCall("BFF");
		mytel.captureVideo();
		mytel.displayPicture("landscape");
		mytel.playSong("wrecking ball");
	}

}
