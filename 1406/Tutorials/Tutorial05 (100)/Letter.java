package comp1406t5;

/** A specific kind of mail */
public class Letter extends Mail{
	
	protected String text;

	public Letter(String description, String text, Date today){
		super(description,today.futureDate(7));
		this.text=text;
	}
	@Override
	public String toString(){
		if (delivered==true){
			return this.description + " This letter has been delivered";
		}else{
			return this.description + " This letter has not been delivered";
		}
	}

}
