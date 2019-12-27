package comp1406t2;

import java.util.Arrays;

public class TestTutorial02{

	public static void testRemoveLessThan(){
		int[] input1 = {9,8,7,6,5,4,3,2,1};
		int[] expected1 = {1,2,3,4,5};
		boolean check1 = true;
		int[] actual1 = Tutorial02.removeLessThan(6, input1);
		System.out.println("expected output : " + Arrays.toString(expected1));
		System.out.println("actual output   : " + Arrays.toString(actual1));
		Arrays.sort(expected1);
		Arrays.sort(actual1);
		if( expected1.length == actual1.length ){
			for(int i=0; i<expected1.length; i+=1){
				if( expected1[i] != actual1[i] ){
					check1 = false;
					break;
				}
			}
		}else{
			check1 = false;
		}
		String out1 = "passed";
		if( check1 == false ){
			out1 = "failed";
		}
		System.out.println("test case " + out1 + "  (after sorting each array)");
	}

	public static void testCoinFlip(){
		System.out.print("coin flip resulted in ");
		boolean heads = Tutorial02.coinFlip(0.75);
		if(heads){
			System.out.println("heads");
		}else{
			System.out.println("tails");
		}
	}
	
	public static void main(String[] args){
		testRemoveLessThan();
		testCoinFlip();
	}


}