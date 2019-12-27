/* Tutorial #1             */
/* COMP 1406 - Winter 2019 */

package comp1406a0;

import java.util.Arrays;  // helper functions for arrays
import java.util.Scanner; // for keyboard input

public class PrintQs{

 /* the main method is the "program"              */
 /* this is what is executed when we run the code */
 public static void main(String[] args){
  
  Scanner keyboard = new Scanner(System.in);
  String input = null;
  int size = 0;

  System.out.print("enter a number (integer) : ");
  if( keyboard.hasNextInt() == true){
    size = keyboard.nextInt();
  }else{
    input = keyboard.next();
    System.out.println("you entered  \"" + input + "\", which is not an integer");
    return;
  }
  System.out.println("you entered the number " + size + " (yea!)");
  
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
        System.out.print("Q");
      }
    System.out.println();
    }

    for(int i=0; i<size; i++){
      String j="1";
      int k= Integer.parseInt(j);
      System.out.print(k);
      
    }
  //
  // proceed to draw the images as requested in the tutorial now...
  //
  
  
  
 }
 
}