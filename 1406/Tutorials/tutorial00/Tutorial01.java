package comp1406a0;

import java.util.Arrays;  // helper functions for arrays

public class Tutorial01{ 
  	// create and return a new array
	// the new array contains all the even integers
	// found in the input numbers
	//
	// example: if numbers is the array [2,3,4,5,6,2] then
	//          the output should be the array [2,4,6,2] 
	//          (with the numbers in any order)
	public static int[] evens(int[] numbers){
		int size=0;
		for(int i=0; i<numbers.length; i++){
			if (numbers[i]%2==0){
				size+=1;
			}
		}
		int size2=0;
		int[] arr= new int[size];
		for(int i=0; i<numbers.length; i++){
			if (numbers[i]%2==0){
				arr[size2]=numbers[i];
				size2+=1;
			}
		}
		return arr;
	}


	
	/* the main method is the "program"              */
	/* this is what is executed when we run the code */
	public static void main(String[] args){
		
		// array of integers (declaration and initialization)
		int[] nums = {1,2,3,4,5,6,7,8,9,10,11};
		System.out.println("nums = " + Arrays.toString(nums) );
		
		// array to hold 5 integers
		int[] first = new int[5];
		System.out.println("first (before) = " + Arrays.toString(first) );
		
		for(int i=0; i<5; i+=1){
			first[i]=nums[i];
		}
		// add code to copy the first 5 elements of nums into first 
	
		System.out.println("first (after)  = " + Arrays.toString(first) );
		
		// add code to the evens() function so that when you pass
		// nums as input it returns the correct array
		
		int[] second = evens(nums);
		System.out.println("second = " + Arrays.toString(second) );
		
		

		
	}
}