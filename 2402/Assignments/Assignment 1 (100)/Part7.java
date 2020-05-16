package comp2402a1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;

public class Part7 {
	
	/**
	 * Your code goes here - see Part0 for an example
	 * @param r the reader to read from
	 * @param w the writer to write to
	 * @throws IOException
	 */
	public static void doIt(BufferedReader r, PrintWriter w) throws IOException {
		PriorityQueue<String> listmax= new PriorityQueue<String>();
		PriorityQueue<String> listmin= new PriorityQueue<String>(Collections.reverseOrder());
		int counter=0;
		for (String line = r.readLine(); line != null; line = r.readLine()) {
			if(counter<2000){
				if(counter<1000){
					listmin.add(line);
					counter++;
				}else{
					listmin.add(line);
					listmax.add(listmin.poll());
					counter++;
				}
			}else{
				if(line.compareTo(listmin.peek())>0 && line.compareTo(listmax.peek())<0){
					w.println(line);
				}else if(line.compareTo(listmin.peek())<0){
					listmin.poll();
					listmin.add(line);
				}else if(line.compareTo(listmax.peek())>0){
					listmax.poll();
					listmax.add(line);
				}else{
					continue;
				}
			}	
		}
	}

	/**
	 * The driver.  Open a BufferedReader and a PrintWriter, either from System.in
	 * and System.out or from filenames specified on the command line, then call doIt.
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BufferedReader r;
			PrintWriter w;
			if (args.length == 0) {
				r = new BufferedReader(new InputStreamReader(System.in));
				w = new PrintWriter(System.out);
			} else if (args.length == 1) {
				r = new BufferedReader(new FileReader(args[0]));
				w = new PrintWriter(System.out);				
			} else {
				r = new BufferedReader(new FileReader(args[0]));
				w = new PrintWriter(new FileWriter(args[1]));
			}
			long start = System.nanoTime();
			doIt(r, w);
			w.flush();
			long stop = System.nanoTime();
			System.out.println("Execution time: " + 10e-9 * (stop-start));
		} catch (IOException e) {
			System.err.println(e);
			System.exit(-1);
		}
	}
}
