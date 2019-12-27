package comp1406t7;

/** A box has a string inside it. */
public abstract class Box implements Comparable<Box>{
  protected String inside;

  public Box(String inside){
	  this.inside = inside; 
	}  

	
	public String getInside(){ return this.inside; }
	
	public void setInside(String newInside){
		this.inside = newInside;
	}
	
	@Override
	public String toString(){
			return "not a very useful version of toString() here";
	}
	
}