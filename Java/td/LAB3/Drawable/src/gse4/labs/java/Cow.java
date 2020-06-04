/**
 * 
 */
package gse4.labs.java;

/**
 * @author romain
 *
 */
public class Cow implements Drawable {
	
	private String nalme_;
	private int weight_;
	
	public Cow(String str, int weight) {
		nalme_ = str;
		weight_ = weight;
	}

	
	@Override
	public void drawWithASCII() {
		String fat = "";
		for(int w = 0; w < weight_/2; ++w) {
			fat+="     \\";
			for (int f = 0; f < weight_; ++f)
				fat+=" ";
			fat+="   )\n";
		}
		
		String line2 =" (oo)\\";
		String line3=" (__)\\";
		String line4="     ||";
		String line5 ="     ||";
		for(int w = 0; w < weight_; ++w) {
			line2+="_";
			line3+=" ";
			line4+="-";
			line5+=" ";
		}
		line2+="___\n";
		line3+="   )\\\\/\\\\\n";
		line4+="w |\n";
		line5+=" ||\n";
		System.out.println(" ^__^\n" +
				           line2+
				           line3 +
				           fat+
				           line4 +
						   line5);
	}

	@Override
	public void drawWithDots() {
		// TODO Auto-generated method stub

	}
	/**
	 * @return the str_
	 */
	public String getName() {
		return nalme_;
	}
	/**
	 * @return the weight_
	 */
	public int getWeight() {
		return weight_;
	}
	/**
	 * @param str_ the str_ to set
	 */
	public void setName(String str_) {
		this.nalme_ = str_;
	}
	/**
	 * @param weight_ the weight_ to set
	 */
	public void setWeight(int weight_) {
		this.weight_ = weight_;
	}
}
