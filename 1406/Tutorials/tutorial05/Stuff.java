package comp1406t5;

/** The stuff that gets put into a Parcel */
public class Stuff{
	protected String description;

	/** Creates a stuff object with given description */
	public Stuff(String description){
		this.description = description;
	}

	/** A string representation of stuff */
	@Override
	public String toString(){
		return "[" + this.description + "]";
	}
}
