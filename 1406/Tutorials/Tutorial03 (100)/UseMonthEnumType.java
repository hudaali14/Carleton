	package comp1406t3;

public class UseMonthEnumType{

	public static int days(Month month){
		int days=0;
		switch(month){
			case JANUARY: 
				days=31;
				break;
			case FEBRUARY: 
				days=28;
				break;
			case MARCH: 
				days=31;
				break;
			case APRIL: 
				days=30;
				break;
			case MAY: 
				days=31;
				break;
			case JUNE: 
				days=30;
				break;
			case JULY: 
				days=31;
				break;
			case AUGUST: 
				days=31;
				break;
			case SEPTEMBER: 
				days=30;
				break;
			case OCTOBER: 
				days=31;
				break;
			case NOVEMBER: 
				days=30;
				break;
			case DECEMBER: 
				days=31;
				break;
			default:
				days=0;
		}
		return days;
	}
	public static void main(String[] args){
		// a Month object
		Month current = Month.JANUARY;
		
		// all enum objects have a pre-defined toString() method
		System.out.println("the current month is " + current.toString());
		
		// the values() method returns an array of all constants (objects)
		// in the order that they appear in the enum declaration/definition
		for(Month m : Month.values()){
			System.out.println(m.toString());
		}
	
		// the valueOf(String) method returns the enum object corresponding to the 
		// input string (if it exists)
		current = Month.valueOf("OCTOBER");
		System.out.println("the new current month is " + current.toString());
	
		// try uncommenting this code to see what happens when you compile

		// current = Month.valueOf("September");
		// System.out.println("the new current month is " + current.toString());
	
	}
}