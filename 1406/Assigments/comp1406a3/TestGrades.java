package comp1406a3;

public class TestGrades{
	/** Generate test cases for the Grades class.
		* @return an array of test cases for the Grades class
		*/
	public static GradesTestCase[] makeTestCases(){
		GradesTestCase[] testCasesArray= new GradesTestCase[20];

		double[] a1 = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
		double[] m1 = {0.0, 0.0, 0.0};
		double[] t1 = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
		double f1 = 0.0;
		GradesTestCase testcase1 = new GradesTestCase(a1, m1, t1, f1, "F", false);
		testCasesArray[0]=testcase1;

		double[] a2 = {98.0, 91.0, 92.0, 96.0, 100.0, 92.0, 95.0, 93.0, 98.0};
		double[] m2 = {92.0, 94.0, 98.0};
		double[] t2 = {92.0, 99.0, 98.0, 97.0, 97.0, 100.0, 90.0, 95.0, 100.0, 92.0};
		double f2 = 61.0;
		GradesTestCase testcase2 = new GradesTestCase(a2, m2, t2, f2, "A", true);
		testCasesArray[1]=testcase2;

		double[] a3 = {72.0, 76.0, 65.0, 65.0, 75.0, 68.0, 72.0, 65.0, 74.0};
		double[] m3 = {72.0, 71.0, 69.0};
		double[] t3 = {69.0, 73.0, 72.0, 78.0, 72.0, 79.0, 68.0, 72.0, 71.0, 72.0};
		double f3 = 50.0;
		GradesTestCase testcase3 = new GradesTestCase(a3, m3, t3, f3, "C", true);
		testCasesArray[2]=testcase3;

		double[] a4 = {50.0, 46.0, 27.0, 40.0, 36.0, 27.0, 35.0, 19.0, 37.0};
		double[] m4 = {15.0, 28.0, 39.0};
		double[] t4 = {59.0, 17.0, 43.0, 17.0, 59.0, 49.0, 24.0, 29.0, 19.0, 38.0};
		double f4 = 100.0;
		GradesTestCase testcase4 = new GradesTestCase(a4, m4, t4, f4, "D", false);
		testCasesArray[3]=testcase4;

		double[] a5 = {100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0};
		double[] m5 = {100.0, 100.0, 100.0};
		double[] t5 = {100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0};
		double f5 = 0.0;
		GradesTestCase testcase5 = new GradesTestCase(a5, m5, t5, f5, "B-", true);
		testCasesArray[4]=testcase5;

		double[] a6 = {67.0, 66.0, 71.0, 68.0, 76.0, 74.0, 69.0, 71.0, 65.0};
		double[] m6 = {78.0, 73.0, 71.0};
		double[] t6 = {75.0, 73.0, 66.0, 75.0, 73.0, 67.0, 71.0, 73.0, 67.0, 78.0};
		double f6 = 30.0;
		GradesTestCase testcase6 = new GradesTestCase(a6, m6, t6, f6, "C-", true);
		testCasesArray[5]=testcase6;
 
		double[] a7 = {100.0, 0.0, 0.0, 100.0, 100.0, 0.0, 0.0, 100.0, 100.0};
		double[] m7 = {100.0, 0.0, 0.0};
		double[] t7 = {100.0, 100.0, 100.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
		double f7 = 40.0;
		GradesTestCase testcase7 = new GradesTestCase(a7, m7, t7, f7, "F", false);
		testCasesArray[6]=testcase7;

		double[] a8 = {100,100,100,100,100,100,100,100,100};
		double[] m8 = {90,90,0};
		double[] t8 = {100,100,100,100,100,100,100,100,100,100};
		double f8 = 0.0;
		GradesTestCase testcase8 = new GradesTestCase(a8, m8, t8, f8, "F", true);
		testCasesArray[7]=testcase8;

		double[] a9 = {90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0};
		double[] m9 = {90.0, 90.0, 90.0};
		double[] t9 = {90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0, 90.0};
		double f9 = 90.0;
		GradesTestCase testcase9 = new GradesTestCase(a9, m9, t9, f9, "A+", true);
		testCasesArray[8]=testcase9;

		double[] a10 = {85.0, 85.0, 85.0, 85.0, 85.0, 85.0, 85.0, 85.0, 0.0};
		double[] m10 = {85.0, 85.0, 0.0};
		double[] t10 = {85.0, 85.0, 85.0, 85.0, 85.0, 85.0, 85.0, 85.0, 0.0, 0.0};
		double f10 = 85.0;
		GradesTestCase testcase10 = new GradesTestCase(a10, m10, t10, f10, "A", true);
		testCasesArray[9]=testcase10;

		double[] a11 = {80.0, 80.0, 80.0, 80.0, 80.0, 80.0, 80.0, 80.0, 0.0};
		double[] m11 = {80.0, 80.0, 0.0};
		double[] t11 = {80.0, 80.0, 80.0, 80.0, 80.0, 80.0, 80.0, 80.0, 0.0, 0.0};
		double f11 = 80.0;
		GradesTestCase testcase11 = new GradesTestCase(a11, m11, t11, f11, "A-", true);
		testCasesArray[10]=testcase11;

		double[] a12 = {77.0, 77.0, 77.0, 77.0, 77.0, 77.0, 77.0, 77.0, 0.0};
		double[] m12 = {77.0, 77.0, 0.0};
		double[] t12 = {77.0, 77.0, 77.0, 77.0, 77.0, 77.0, 77.0, 77.0, 77.0, 77.0};
		double f12 = 77.0;
		GradesTestCase testcase12 = new GradesTestCase(a12, m12, t12, f12, "B+", true);
		testCasesArray[11]=testcase12;

		double[] a13 = {57.0, 57.0, 57.0, 57.0, 57.0, 57.0, 0.0, 57.0, 57.0};
		double[] m13 = {57.0, 57.0, 0.0};
		double[] t13 = {57.0, 57.0, 57.0, 57.0, 57.0, 57.0, 57.0, 57.0, 0.0, 0.0};
		double f13 = 57.0;
		GradesTestCase testcase13 = new GradesTestCase(a13, m13, t13, f13, "D+", false);
		testCasesArray[12]=testcase13;

		double[] a14 = {50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 0.0, 50.0, 50.0};
		double[] m14 = {50.0, 50.0, 0.0};
		double[] t14 = {50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 50.0, 0.0, 0.0};
		double f14 = 50.0;
		GradesTestCase testcase14 = new GradesTestCase(a14, m14, t14, f14, "D-", false);
		testCasesArray[13]=testcase14;

		double[] a15 = {100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 0.0};
		double[] m15 = {30.0, 30.0, 0.0};
		double[] t15 = {100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 0.0, 0.0};
		double f15 = 30.0;
		GradesTestCase testcase15 = new GradesTestCase(a15, m15, t15, f15, "F", true);
		testCasesArray[14]=testcase15;

		double[] a16 = {100, 100, 100, 100, 100, 100, 100, 100, 100};
		double[] m16 = {100, 100, 100};
		double[] t16 = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
		double f16 = 100.0;
		GradesTestCase testcase16 = new GradesTestCase(a16, m16, t16, f16, "F", true);
		testCasesArray[15]=testcase16;

		double[] a17 = {49.9, 49.9, 49.9, 49.9, 49.9, 49.9, 49.9, 49.9, 0.0};
		double[] m17 = {49.9, 49.9, 0.0};
		double[] t17 = {49.9, 49.9, 49.9, 49.9, 49.9, 49.9, 49.9, 49.9, 0.0, 0.0};
		double f17 = 49.9;
		GradesTestCase testcase17 = new GradesTestCase(a17, m17, t17, f17, "A+", true);
		testCasesArray[16]=testcase17;

		double[] a18 = {69.99999999, 69.99999999, 69.99999999, 69.99999999, 69.99999999, 69.99999999, 69.99999999, 69.99999999, 0.0};
		double[] m18 = {69.99999999, 69.99999999, 0.0};
		double[] t18 = {69.99999999, 69.99999999, 69.99999999, 69.99999999, 69.99999999, 69.99999999, 69.99999999, 69.99999999, 0.0, 0.0};
		double f18 = 69.99999999;
		GradesTestCase testcase18 = new GradesTestCase(a18, m18, t18, f18, "C+", true);
		testCasesArray[17]=testcase18;

		double[] a19 = {0.000000001, 0.000000001, 0.000000001, 0.000000001, 0.000000001, 0.000000001, 0.000000001, 0.000000001, 0.0};
		double[] m19 = {99.99999999, 99.99999999, 0.0};
		double[] t19 = {0.000000001, 0.000000001, 0.000000001, 0.000000001, 0.000000001, 0.000000001, 0.000000001, 0.000000001, 0.0, 0.0};
		double f19 = 99.99999999;
		GradesTestCase testcase19 = new GradesTestCase(a19, m19, t19, f19, "C-", true);
		testCasesArray[18]=testcase19;

		double[] a20 = {89.9999999, 89.9999999, 89.9999999, 89.9999999, 89.9999999, 89.9999999, 89.9999999, 89.9999999, 89.9999999};
		double[] m20 = {14.9999999, 14.9999999, 0.0};
		double[] t20 = {89.9999999, 89.9999999, 89.9999999, 89.9999999, 89.9999999, 89.9999999, 89.9999999, 89.9999999, 0.0, 0.0};
		double f20 = 29.9999999;
		GradesTestCase testcase20 = new GradesTestCase(a20, m20, t20, f20, "F", true);
		testCasesArray[19]=testcase20;

		return testCasesArray;
	}
}