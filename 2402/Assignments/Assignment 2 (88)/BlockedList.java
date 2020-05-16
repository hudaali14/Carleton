package comp2402a2;

import java.util.AbstractList;
import java.util.Collection;

/**
 * @author morin
 *
 * @param <T> the type of objects stored in the List
 */
public class BlockedList<T> extends AbstractList<T> {
	/**
	 * keeps track of the class of objects we store
	 */
	Factory<T> f;

	/**
	 * The number of elements stored
	 */
	int n;

	/**
	 * The block size
	 */
	int b;

	T[] a;
	int j;


	/**
	 * Constructor
	 * @param t the type of objects that are stored in this list
	 * @param b the block size
	 */
	public BlockedList(Class<T> t, int b) {
		f = new Factory<T>(t);
		a = f.newArray(b);
		n = 0;
		j = 0;
		// TODO: Implement this
	}

	public int size() {
		return n;
	}

	void resize() {
		T[] c = f.newArray(Math.max(2*n,1));
		for (int k = 0; k < n; k++){ 
			c[k] = a[(j+k) % a.length];
		}
		a = c;
		j = 0;
	}

	public T get(int i) {
		// TODO: Implement this
		if (i < 0 || i > n - 1) throw new IndexOutOfBoundsException();
		return a[(j+i) % a.length];
	}

	public T set(int i, T x) {
		// TODO: Implement this
		if (i < 0 || i > n - 1) throw new IndexOutOfBoundsException();
		T y= a[(j+i) % a.length];
		a[(j+i) % a.length] = x;
		return y;
	}


	public void add(int i, T x) {
		// TODO: Implement this
		if (i < 0 || i > n) throw new IndexOutOfBoundsException();
		if (n+1 > a.length){
			resize();
		}
		if (i < n/2) {	
			j = (j == 0) ? a.length - 1 : j - 1; 
			for (int k = 0; k <= i-1; k++){
				a[(j+k)%a.length] = a[(j+k+1)%a.length];
			}
		}else{	    
			for (int k = n; k > i; k--){
				a[(j+k)%a.length] = a[(j+k-1)%a.length];
			}
		}
		a[(j+i)%a.length] = x;
		n++;
	}

	public T remove(int i) {
		// TODO: Implement this
		if (i < 0 || i > n - 1) throw new IndexOutOfBoundsException();
		T x = a[(j+i)%a.length];
		if (i < n/2) {  
			for (int k = i; k > 0; k--){
				a[(j+k)%a.length] = a[(j+k-1)%a.length];
			}
			j = (j + 1) % a.length;
		}else{        
			for (int k = i; k < n-1; k++){
				a[(j+k)%a.length] = a[(j+k+1)%a.length];
			}
		}
		n--;
		if (3*n < a.length){
			resize();
		}
 		return x;
	}

	// public static void main(String args[]){
	// 	BlockedList<Integer> array= new BlockedList<Integer>(Integer.class, 10);
	// 	array.add(0, 8);
	// 	array.set(0, 7);
	// 	array.add(1, 6);
	// 	array.add(2, 1);
	// 	array.add(3, 9);
	// 	array.add(4, 2);
	// 	array.add(5, 8);
	// 	array.add(3, 10);
	// 	System.out.println(array.toString());
	// 	array.add(1, 9);
	// 	System.out.println(array.toString());
	// 	array.add(5, 13);
	// 	System.out.println(array.toString());
	// 	array.remove(2);
	// 	System.out.println(array.toString());
	// 	array.remove(4);
	// 	System.out.println(array.toString());
	// 	array.remove(6);
	// 	System.out.println(array.toString());
		// System.out.println(array.get(2));
		// System.out.println(array.get(4));
		// System.out.println(array.get(5));
		// System.out.println(array.toString());
		// System.out.println(array.get(6));
	// }
}
