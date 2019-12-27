package comp1406t5;

/** A tester for the FutureDate class */
public class TestFutureDate{

/** Run a test case on the makeFutureDate method.
  * @param start is a futuredate
  * @param daysLater is a non-negative integer
  * @param expected is a futuredate that is daysLater after start
	* @return true if and only if start.makeFutureDate(daysLater).equals(expected)
	*/
public static boolean test(FutureDate start, int daysLater, FutureDate expected){
	//
	// change futureDate(daysLater) to futureDate2(daysLater), futureDate3(daysLater), etc
	//
	FutureDate actual = start.futureDate(daysLater);


	System.out.print(start + " + " + String.format("%03d", daysLater) + " days: " + expected + "  " + actual + " -- ");
	System.out.println( expected.equals(actual)?"success":"fail");
	return expected.equals(actual);
}

public static void main(String[] args){
	System.out.println("< start date>             <  expected >  <   actual  >    result");
	System.out.println("-----------------------------------------------------------------");
	
	test( new FutureDate(2019, 01, 01), 2, new FutureDate(2019, 01, 03) );    
	test( new FutureDate(2019, 01, 31), 1, new FutureDate(2019, 02, 01) );    
	test( new FutureDate(2019, 03, 31), 31, new FutureDate(2019, 05, 01) );    


}
}