package comp1406t3;

import java.util.Arrays;
/*
 * A class to model currency (money) as dollars and cents
 */

public class Money{

  /* attributes */
  private int dollars = -1;
  private int cents = -1;

  public Money(){
    dollars = 0;
    cents = 0;
		// create an object with zero dollars and cents.
  }

  public Money(int c){
    dollars=0;
    cents=0;
    cents=c;
    if (c<=99){
      cents=c;
    }else{
      while(cents>99){
        dollars+=1;
        cents-=100;
      }
    }
		// create an object with c cents
		// (adjusting dollars and cents so that 0<=cents<=99)
  }

  public Money(int d, int c){
    dollars=0;
    cents=0;
    cents=c;
    dollars=d;
    while (cents>99){
      dollars+=1;
      cents-=100;
    }
		// create an object with d dollars and c cents
		// (adjusting dollars and cents so that 0<=cents<=99)
  }

  public Money(int[] coins){
    dollars=0;
    cents=0;
    dollars=(coins[0]*2)+(coins[1]);
    cents=(coins[2]*25)+(coins[3]*10)+(coins[4]*5)+(coins[5]*1);
    while(cents>99){
        dollars+=1;
        cents-=100;
      }
	  // input array has 6 elements and corresponds to
		// {#toonies, #loonies, #quarters, #dimes, #nickels, #pennies}
    // {$2, $1, $0.25, $0.10, $0.05, $0.01}		
		// create an object with total money passed in array
		// (adjusting internal dollars and cents so that 0<=cents<=99)
  }


  /**
   * Returns a String representation of the value of the current object.
   *
   * @return The value of the current object is returned as the <code>String</code>"$D.cc"
   * where D is the number of dollars and cc is the cents of the value.  Uses the <code>format()</code>
   * method from the <code>String</code> class to ensure that the cents are displayed properly (2 spaces
   * with leading zeros if needed).
   **/
  public String toString(){
    return "$" + String.format("%01d", dollars) + "." + String.format("%02d", cents);
  }
  public void add(int c){
    if (c+cents>99){
      dollars+=1;
      cents=99-(c+cents);
    }
    return dollars;
    // adds c cents to the current value
    // Again, be sure the internal states
    // does not have cents greater than 99
  }
  public void add(int d, int c){
    dollars=d;
    if (c+cents>99){
      dollars+=1;
      cents=99-(c+cents);
    }
    return dollars;
    // adds d dollars and c cents to the current value
    // Again, be sure the internal states
    // does not have cents greater than 99
  }
  public int remove(int c){
    dollars=dollars*100;
    cents+=dollars;
    if ((cents-c)>0){
      cents-=c;
    }else{
      while(cents<0)
        cents-=c;
    }
    while(cents>99){
      dollars+=1;
      cents-=100;
    }
    return dollars;
  }
    //  

}
