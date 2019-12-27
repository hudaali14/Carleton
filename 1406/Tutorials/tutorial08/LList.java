package comp1406t8;

/** A linked list implementation for the list ADT that stores _strings
 *
 * Represents a list S0, S1, S2, ..., Sn-1 of Strings
 */
public class LList extends LinkedList{

	/** Creates an empty linked list */
	public LList(){super();}

	/** Creates a linked list with a single item (S0)
	  *
		* @param s is string S0 in the created list of size 1.
		*/
	public LList(String s ){
		super(s);
	}

	@Override
	public int find(String s){
		for (int i = 0; i < this.getSize(); i++) {
			if(this.get(i).equals(s)){
				return i;
			}
		}
		return -1;
	}

	@Override 
	public boolean set(int k, String s){
		Node temp= head;
		for (int i = 1; i < this.getSize(); i++){
			if(i==k){
				temp.setData(s);
				return true;
			}
			temp=temp.next;
		}
		return false;
	}

	@Override 
	public String removeFront(){
		if(head==null){
			return null;
		}
		Node temp=head;
		this.head=temp.next;
		this.size--;
		return temp.getData();
	}

	@Override
	public String remove(int k){
		Node temp= head;
		for (int i = 1; i < this.getSize(); i++){
			if(i==k-1){
				temp.next=temp.next.next;
			}
			temp=temp.next;
		}
		size--;
		return temp.next.getData();

	}


}
