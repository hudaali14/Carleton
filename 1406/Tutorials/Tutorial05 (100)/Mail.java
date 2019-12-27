package comp1406t5;

/** A class to represent all kinds of mail */
public class Mail{
	protected String  description;
	protected Date    expectedDelivery;
	protected Date    deliveredDate = null;
	protected boolean delivered = false;

	/** Creates a mail object with a description and expected delivery date */
	public Mail(String description, Date expectedDelivery){
		this.description = description;
		this.expectedDelivery = expectedDelivery;
	}

	public String getDescription(){ return this.description; }
	public Date   getExpectedDelivery(){ return this.expectedDelivery; }
	public boolean isDelivered(){ return this.delivered; }

	/** Sets the mail object as been delivered */
	public void delivered(Date date){
		this.deliveredDate = date;
		this.delivered = true;
	}

	@Override
	public String toString(){
		return this.description;
	}
}
