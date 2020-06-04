/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class Phone {
	
	public Phone() {
		System.out.println("Manufacturing your phone...");
	}
	public void voiceCall(String contact) {
		System.out.println("Calling "+contact+"...");
	}
	public void sendSMS(String contact, String message) {
		System.out.println("Sending \""+message+"\" to "+contact+"...");
	}
}
