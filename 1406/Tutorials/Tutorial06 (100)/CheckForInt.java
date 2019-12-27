package comp1406t6;
public class CheckForInt{
	public static boolean isInt(String s){
		try{
			int number = Integer.parseInt(s);
		}catch(java.lang.NumberFormatException e){
			// oh no! it was not a string representation of an integer
			// just return false
			return false;
		}catch(Exception e){
			// hmmm, some else bad happened... don't really care what it is though
			// still terminate with a false answer
		}
		// if we got this far then everything worked out and we return true
		return true;
	}
}