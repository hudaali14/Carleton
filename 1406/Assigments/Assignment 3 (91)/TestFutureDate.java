package comp1406a3;

public class TestFutureDate{

	/** Generate black-box test cases for the futureDate method (in the Date class).
		* @return an array of test cases for the futureDate method (in the Date class).
		*/
	public static FutureDateTestCase[] makeTestCases(){
		FutureDateTestCase[] testCasesArray= new FutureDateTestCase[27];
		Date day = new Date(2019, 1, 1);
		int daysInFuture = 0;
		Date expected = new Date(2019, 1, 1);
		FutureDateTestCase testcase1 = new FutureDateTestCase(day, daysInFuture, expected);
		testCasesArray[0]=testcase1;

		Date day2 = new Date(1735, 8, 25);
		int daysInFuture2 = 1;
		Date expected2 = new Date(1735, 8, 26);
		FutureDateTestCase testcase2 = new FutureDateTestCase(day2, daysInFuture2, expected2);
		testCasesArray[1]=testcase2;

		Date day3 = new Date(2019, 2, 28);
		int daysInFuture3 = 366;
		Date expected3 = new Date(2020, 2, 29);
		FutureDateTestCase testcase3 = new FutureDateTestCase(day3, daysInFuture3, expected3);
		testCasesArray[2]=testcase3;

		Date day4 = new Date(2019, 2, 28);
		int daysInFuture4 = 4;
		Date expected4 = new Date(2019, 3, 4);
		FutureDateTestCase testcase4 = new FutureDateTestCase(day4, daysInFuture4, expected4);
		testCasesArray[3]=testcase4;

		Date day5 = new Date(2020, 12, 31);
		int daysInFuture5 = 1;
		Date expected5 = new Date(2021, 1, 1);
		FutureDateTestCase testcase5 = new FutureDateTestCase(day5, daysInFuture5, expected5);
		testCasesArray[4]=testcase5;

		Date day6 = new Date(2020, 2, 28);
		int daysInFuture6 = 1;
		Date expected6 = new Date(2020, 2, 29);
		FutureDateTestCase testcase6 = new FutureDateTestCase(day6, daysInFuture6, expected6);
		testCasesArray[5]=testcase6;

		Date day7 = new Date(2020, 2, 29);
		int daysInFuture7 = 1461;
		Date expected7 = new Date(2024, 2, 29);
		FutureDateTestCase testcase7 = new FutureDateTestCase(day7, daysInFuture7, expected7);
		testCasesArray[6]=testcase7;

		Date day8 = new Date(2020, 2, 29);
		int daysInFuture8 = 146037;
		Date expected8 = new Date(2420, 2, 29);
		FutureDateTestCase testcase8 = new FutureDateTestCase(day8, daysInFuture8, expected8);
		testCasesArray[7]=testcase8;

		Date day9 = new Date(2020, 2, 29);
		int daysInFuture9 = 29160;
		Date expected9 = new Date(2100, 2, 28);
		FutureDateTestCase testcase9 = new FutureDateTestCase(day9, daysInFuture9, expected9);
		testCasesArray[8]=testcase9;

		Date day10 = new Date(1735, 8, 20);
		int daysInFuture10 = 3;
		Date expected10 = new Date(1735, 8, 23);
		FutureDateTestCase testcase10 = new FutureDateTestCase(day10, daysInFuture10, expected10);
		testCasesArray[9]=testcase10;

		Date day11 = new Date(2019, 1, 1);
		int daysInFuture11 = 30;
		Date expected11 = new Date(2019, 1, 31);
		FutureDateTestCase testcase11 = new FutureDateTestCase(day11, daysInFuture11, expected11);
		testCasesArray[10]=testcase11;

		Date day12 = new Date(2019, 4, 1);
		int daysInFuture12 = 30;
		Date expected12 = new Date(2019, 5, 1);
		FutureDateTestCase testcase12 = new FutureDateTestCase(day12, daysInFuture12, expected12);
		testCasesArray[11]=testcase12;

		Date day13 = new Date(2019, 6, 30);
		int daysInFuture13 = 2;
		Date expected13 = new Date(2019, 7, 2);
		FutureDateTestCase testcase13 = new FutureDateTestCase(day13, daysInFuture13, expected13);
		testCasesArray[12]=testcase13;

		Date day14 = new Date(2019, 7, 30);
		int daysInFuture14 = 2;
		Date expected14 = new Date(2019, 8, 1);
		FutureDateTestCase testcase14 = new FutureDateTestCase(day14, daysInFuture14, expected14);
		testCasesArray[13]=testcase14;

		Date day15 = new Date(2019, 9, 16);
		int daysInFuture15 = 22;
		Date expected15 = new Date(2019, 10, 8);
		FutureDateTestCase testcase15 = new FutureDateTestCase(day15, daysInFuture15, expected15);
		testCasesArray[14]=testcase15;

		Date day16 = new Date(2017, 11, 27);
		int daysInFuture16 = 488;
		Date expected16 = new Date(2019, 3, 30);
		FutureDateTestCase testcase16 = new FutureDateTestCase(day16, daysInFuture16, expected16);
		testCasesArray[15]=testcase16;

		Date day17 = new Date(2019, 12, 21);
		int daysInFuture17 = 387;
		Date expected17 = new Date(2021, 1, 11);
		FutureDateTestCase testcase17 = new FutureDateTestCase(day17, daysInFuture17, expected17);
		testCasesArray[16]=testcase17;

		Date day18 = new Date(2020, 2, 14);
		int daysInFuture18 = 26;
		Date expected18 = new Date(2020, 3, 11);
		FutureDateTestCase testcase18 = new FutureDateTestCase(day18, daysInFuture18, expected18);
		testCasesArray[17]=testcase18;

		Date day19 = new Date(2019, 10, 18);
		int daysInFuture19 = 15;
		Date expected19 = new Date(2019, 11, 2);
		FutureDateTestCase testcase19 = new FutureDateTestCase(day19, daysInFuture19, expected19);
		testCasesArray[18]=testcase19;

		Date day20 = new Date(2019, 11, 6);
		int daysInFuture20 = 29;
		Date expected20 = new Date(2019, 12, 5);
		FutureDateTestCase testcase20 = new FutureDateTestCase(day20, daysInFuture20, expected20);
		testCasesArray[19]=testcase20;

		Date day21 = new Date(2019, 3, 22);
		int daysInFuture21 = 17;
		Date expected21 = new Date(2019, 4, 8);
		FutureDateTestCase testcase21 = new FutureDateTestCase(day21, daysInFuture21, expected21);
		testCasesArray[20]=testcase21;

		Date day22 = new Date(1735, 12, 1);
		int daysInFuture22 = 30;
		Date expected22 = new Date(1735, 12, 31);
		FutureDateTestCase testcase22 = new FutureDateTestCase(day22, daysInFuture22, expected22);
		testCasesArray[21]=testcase22;

		Date day23 = new Date(1800, 1, 15);
		int daysInFuture23 = 23;
		Date expected23 = new Date(1800, 2, 7);
		FutureDateTestCase testcase23 = new FutureDateTestCase(day23, daysInFuture23, expected23);
		testCasesArray[22]=testcase23;

		Date day24 = new Date(2019, 4, 19);
		int daysInFuture24 = 13;
		Date expected24 = new Date(2019, 5, 2);
		FutureDateTestCase testcase24 = new FutureDateTestCase(day24, daysInFuture24, expected24);
		testCasesArray[23]=testcase24;

		Date day25 = new Date(2019, 8, 27);
		int daysInFuture25 = 9;
		Date expected25 = new Date(2019, 9, 5);
		FutureDateTestCase testcase25 = new FutureDateTestCase(day25, daysInFuture25, expected25);
		testCasesArray[24]=testcase25;

		Date day26 = new Date(1967, 8, 30);
		int daysInFuture26 = 2;
		Date expected26 = new Date(1967, 9, 1);
		FutureDateTestCase testcase26 = new FutureDateTestCase(day26, daysInFuture26, expected26);
		testCasesArray[25]=testcase26;

		Date day27 = new Date(1967, 4, 30);
		int daysInFuture27 = 2;
		Date expected27 = new Date(1967, 5, 2);
		FutureDateTestCase testcase27 = new FutureDateTestCase(day27, daysInFuture27, expected27);
		testCasesArray[26]=testcase27;



		return testCasesArray;
	}
}