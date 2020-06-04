package gse4.labs.java;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.Test;

class MathDivideTest {

	@Test
	void testDivison() {
		MathDivide test = new MathDivide();
		assertEquals(2, test.divide(4,2), "4/2 must be 2");
	}
	
	@Test(expected = IllegalArgumentException.class)
	void testDivideException() {
		MathDivide test = new MathDivide();
		test.divide(4, 0);
	}

}
