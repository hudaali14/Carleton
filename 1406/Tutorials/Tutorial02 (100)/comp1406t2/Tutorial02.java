package comp1406t2;

import java.util.Random;
import java.util.Scanner;
import java.util.Arrays;

public class Tutorial02{

	// an array of strings to use
	public static String[] words = {"cat", "dog", "eel", "owl", "fox", "kitten", "puppy", "elver", "owlet", "kit"};

	public static void strings(){
		int total=0;
        int longest=0;
        String string="";
        String long_word="";
        char upper='a';
        for (int i = 0; i < words.length; i++){
            total+=words[i].length();
            upper=Character.toUpperCase(words[i].charAt(0));
            string= upper+words[i].substring(1);
            if (words[i].length()>longest){
                longest=words[i].length();
                long_word= string.toUpperCase();
            }
            System.out.println(string+ ", is "+ string.length()+ " letters long.");
        }
        System.out.println("The longest word is "+ long_word+ ".");
        System.out.println("There were "+ total+ " characters total.");
    }
	
	public static void rollRandomDice(long seed){
		Random die1= new Random();
		Random die2= new Random();
		die1.setSeed(seed);
		die2.setSeed(seed+1);
		int[] array=new int[11];
		int roll1=0;
		int roll2=0;
		int sum=0;
		for (int i=0; i<10000; i+=1){
			roll1= die1.nextInt(6)+1;
			roll2= die2.nextInt(6)+1;
			sum=roll1+roll2;
			if (sum==2){
				array[0]+=1;
			}else if (sum==3){
				array[1]+=1;
			}else if (sum==4){
				array[2]+=1;
			}else if (sum==5){
				array[3]+=1;
			}else if (sum==6){
				array[4]+=1;
			}else if (sum==7){
				array[5]+=1;
			}else if (sum==8){
				array[6]+=1;
			}else if (sum==9){
				array[7]+=1;
			}else if (sum==10){
				array[8]+=1;
			}else if (sum==11){
				array[9]+=1;
			}else{
				array[10]+=1;
			}
		}
		System.out.println(Arrays.toString(array));

	}
	
	
	public static void testPoint2D(){
		Point2D test1=new Point2D();
        test1.x=1.2;
        test1.y=2.6;
        System.out.println(test1.magnitude());
		System.out.println(test1.toString());
        
        Point2D test2=new Point2D();
        test2.x=1.4;
        test2.y=2.7;
		System.out.println(test2.magnitude());
		System.out.println(test2.toString());
        System.out.println(test2.distance(test1));
	}
	
	public static void main(String[] args){
		strings();
		rollRandomDice(17);
		testPoint2D();
	
	}
	
}