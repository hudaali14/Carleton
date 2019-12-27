package comp1406t5;

/** A specific kind of mail */
public class Parcel extends Mail{

	protected Stuff stuff;
	protected double cost;
	protected String comments;

	public Parcel(String description, Stuff stuff, double cost, Date today){
		super(description, today.futureDate(0));
		this.stuff=stuff;
		this.cost=cost;
		this.comments=comments;
		if (cost<10.00){
			today=today.futureDate(7);
		}else if (cost>19.99){
			today=today.futureDate(1);
		}else{
			today=today.futureDate(4);
		}
	}
	@Override
	public String toString(){
		if (delivered==true){
			return this.description + this.expectedDelivery +this.stuff + " This letter has been delivered";
		}else{
			return this.description + this.expectedDelivery +this.stuff + " This letter has not been delivered";
		}
	}

	public void delivered(Date date, String comments){
		super.delivered(date);
		this.comments=comments;
	}

}
