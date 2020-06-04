/**
 * 
 */
package gse4.labs.java;

import java.awt.Color;
/**
 * @author romain
 *
 */
public class TestAbsractShape {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// An array of 9 shapes
		Shape[] shapes = new Shape[9];
		for(int i = 0; i < 7; i=i+3){
			shapes[i] = new Circle(4+i, Color.black);
			shapes[i+1] = new Square(2+i, Color.blue);
			shapes[i+2] = new Rectangle(1+i,5+i, Color.green);
		}
		for(int i = 0; i < 9; i++) {
			System.out.println(shapes[i]);
		}
//		Shape shapeObj = new Shape(Color.yellow);
		
	}

}
