package comp1406t8;

import java.util.HashSet;
import java.util.ArrayList;

public class SetORList{

	public static void main(String[] args){
		ArrayList<Integer> list = new ArrayList<Integer>();
		HashSet<Integer> set = new HashSet<Integer>();

		int size = 25000;

		System.out.print("making collections... ");
		for(int i=0; i<size; i+=1){
			list.add(i);
			set.add(i);
		}
		System.out.println("done!");

		long start_time = System.nanoTime();
		for(int i=0; i<2*size; i+=1){
			set.contains(i);
		}
		long set_time = System.nanoTime()-start_time;
		System.out.println("set time  (" + size + " searches)= " + (set_time*1e-9));

		start_time = System.nanoTime();
		for(int i=0; i<2*size; i+=1){
			list.contains(i);
		}
		long list_time = System.nanoTime()-start_time;

		System.out.println("list time (" + size + " searches)= " + (list_time*1e-9));

		HashSet<Integer> s = new HashSet<Integer>();
		for(int i=0; i<10; i+=1){
			s.add(i);
		}

		//System.out.println(s);
		//java.util.Collections.sort(s);
		//System.out.println(s);


	}


}
