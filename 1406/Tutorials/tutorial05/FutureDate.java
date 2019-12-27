package comp1406t5;

/** A class for blackbox testing */
public class FutureDate{

	protected static int[] daysInMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
	protected static String[] months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


/** Creates a new futuredate object that is nDays in the future
	  * from this current futuredate object
		*
		* <p> Example: fd.makeFutureDate(0) will create a new futuredate object that is the same
		*          date as fd.
		* <p> Example: fd.makeFutureDate(1) will create a new futuredate object that is 1 day
    *          after the futuredate fd.
		* <p> Example: fd.makeFutureDate(3) will create a new futuredate object that is 3 days
    *          past the futuredate fd.
		*
		*	@param nDays is a non-negative integer (the number of days from this futuredate that the
    *        new returned futuredate object will be created).
		* @return a new futuredate object that is nDays past this current futuredate.
		*/	public FutureDate makeFutureDate(int nDays){
	  if( this.day + nDays <= daysInMonth[month-1] ){
			return new FutureDate(this.year, this.month, this.day + nDays);
		}
		return new FutureDate(this.year, (this.month+1), this.day + nDays - daysInMonth[this.month-1] );
	}

	@Override
	public String toString(){
		return "{" + months[this.month-1].substring(0,3) + " " +
		         String.format("%02d", this.day) + "," + String.format("%04d", this.year) + "}";
  }

	@Override
	public boolean equals(Object other){
		if( other instanceof FutureDate ){
			FutureDate that = (FutureDate)other;
			return (this.year == that.year && this.month == that.month && this.day == that.day);
		}else{
			return false;
		}
	}


}
