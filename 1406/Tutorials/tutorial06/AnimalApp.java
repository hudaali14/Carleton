package comp1406t6;

import java.util.Random;
import java.util.Calendar;

/** Tutorial #6 
    <p>
		Testing program for the Animal, Cat and Dog classes.
        
	  @version 1.1
	 */

public class AnimalApp{
	/** number of animals in collection */
	public static int SIZE = 7;

	/** a collection of names for generating random animals */
	public static String[] names = {"Fluffy", "Tiger", "Spot", 
	    "Bubbles", "Dodger", "Ace", "Flower", "Tiny", "Pip", 
			"Chyanne", "Darla", "Maggie", "Cookie", "Booboo"};
	
	
	public static void main(String[] args){
		if( args.length == 1                     // check for single command line argument 
		    && CheckForInt.isInt(args[0])        // that is an integer
				&& Integer.parseInt(args[0]) > 0     // that is at least 1
	    )  
		{
			SIZE = Integer.parseInt(args[0]);
		}
		System.out.println("SIZE = " + SIZE + " for this execution");
		
		Random rnd = new Random();
		
		/* get the current year based on computer's clock */
	  Calendar now = Calendar.getInstance();   
		int year = now.get(Calendar.YEAR);  
		System.out.println("The year is " + year);
		
		/* some animals */
		Animal[] animal_list = new Animal[SIZE];

		/* randomly pick a cat or dog */
		for(int i=0; i<SIZE; i+=1){
			if(Math.random() < 0.5){
				animal_list[i] = new Cat( names[rnd.nextInt(names.length)],2000 + rnd.nextInt(18));
			}else{
				animal_list[i] = new Dog( names[rnd.nextInt(names.length)],2000 + rnd.nextInt(18));
			}
		}
	
		for(Animal animal: animal_list){
			System.out.print(animal + " ... ");
			System.out.println(animal.noise());
		}

		String[] owlnames= {"John", "Happy", "April", "Cassidy", "Jace"};
		int yearsowl= 1999;
		Animal[] owls= new Animal[5];
		for (int i=0; i<owls.length; i++){
			if (i%2==0){
				owls[i]= new Owl(owlnames[i], i+1990, true);
				System.out.println(owls[i]);
				System.out.println(owls[i].noise());
			}else{
				owls[i]= new Owl(owlnames[i], i+1985, false);
				System.out.println(owls[i]);
				System.out.println(owls[i].noise());
			}
		}
	}


}