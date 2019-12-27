package comp1406a3;

public class TestFind{

	/** Generate test cases for the (modified) Find class.
		* @return an array of test cases for the (modified) Find class.
		*/
	public static FindTestCase[] makeTestCases(){

		FindTestCase[] testCasesArray= new FindTestCase[10];

		int[] target1= new int[]{0,1,0};
		int[] array1= new int[]{0, 0, 0, 1, 0, 1, 0};
		int[] expectedFindAgain1= new int[]{2, 2, 4};
		FindTestCase testcase1= new FindTestCase(target1 , array1, 4, expectedFindAgain1);
		testCasesArray[0]=testcase1;

		int[] target2= new int[]{0,1,0};
		int[] array2= new int[]{0, 0, 0, 1, 0, 1, 0, 1};
		int[] expectedFindAgain2= new int[]{2, 2, 4};
		FindTestCase testcase2= new FindTestCase(target2 , array2, 4, expectedFindAgain2);
		testCasesArray[1]=testcase2;

		int[] target3= new int[]{0};
		int[] array3= new int[]{0, 0, 0, 0, 1, 0, 0, 0};
		int[] expectedFindAgain3= new int[]{7, 0, 1, 2, 3, 5, 6, 7};
		FindTestCase testcase3= new FindTestCase(target3, array3, 7, expectedFindAgain3);
		testCasesArray[2]=testcase3;

		int[] target4= new int[]{1, 1, 1};
		int[] array4= new int[]{1, 1, 1, 1, 1, 1};
		int[] expectedFindAgain4= new int[]{4, 0, 1, 2, 3};
		FindTestCase testcase4= new FindTestCase(target4 , array4, 3, expectedFindAgain4);
		testCasesArray[3]=testcase4;

		int[] target5= new int[]{0,0,0};
		int[] array5= new int[]{1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1};
		int[] expectedFindAgain5= new int[]{0};
		FindTestCase testcase5= new FindTestCase(target5 , array5, -1, expectedFindAgain5);
		testCasesArray[4]=testcase5;

		int[] target6= new int[]{0};
		int[] array6= new int[]{0};
		int[] expectedFindAgain6= new int[]{1, 0};
		FindTestCase testcase6= new FindTestCase(target6 , array6, 0, expectedFindAgain6);
		testCasesArray[5]=testcase6;

		int[] target7= new int[]{1, 1, 0};
		int[] array7= new int[]{1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0};
		int[] expectedFindAgain7= new int[]{2, 1, 8};
		FindTestCase testcase7= new FindTestCase(target7, array7, 8, expectedFindAgain7);
		testCasesArray[6]=testcase7;

		int[] target8= new int[]{0, 0, 1, 0, 1};
		int[] array8= new int[]{0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
		int[] expectedFindAgain8= new int[]{0};
		FindTestCase testcase8= new FindTestCase(target8, array8, -1, expectedFindAgain8);
		testCasesArray[7]=testcase8;

		int[] target9= new int[]{0, 0, 1, 0, 1};
		int[] array9= new int[]{};
		int[] expectedFindAgain9= new int[]{0};
		FindTestCase testcase9= new FindTestCase(target9, array9, -1, expectedFindAgain9);
		testCasesArray[8]=testcase9;

		int[] target10= new int[]{1, 0, 1};
		int[] array10= new int[]{1, 0, 1};
		int[] expectedFindAgain10= new int[]{1, 0};
		FindTestCase testcase10= new FindTestCase(target10, array10, 0, expectedFindAgain10);
		testCasesArray[9]=testcase10;

		return testCasesArray;
	}

}