/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class Smartphone extends Phone implements Camera, MediaPlayer {

	public Smartphone() { super(); }

	@Override
	public void playMovie(String name) {
		System.out.println("playing movie \""+name+"\"...");
	}

	@Override
	public void playSong(String name) {
		System.out.println("playing music \""+name+"\"...");
	}

	@Override
	public void displayPicture(String name) {
		System.out.println("displaying picture \""+name+"\"...");
	}

	@Override
	public void captureImage() {
		System.out.println("taking a picture...");
	}

	@Override
	public void captureVideo() {
		System.out.println("taking a video...");
	}

}
