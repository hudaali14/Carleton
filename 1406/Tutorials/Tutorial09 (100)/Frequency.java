package comp1406t9;
import java.io.*;
import java.util.*;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.io.StringReader;

public class Frequency{

    public static void main(String[] args){
        Map<String, Integer> dictionary = new HashMap<String, Integer>();
        BufferedReader fileIn = null;
        try {
            fileIn = new BufferedReader(new FileReader("testfile2.txt"));
            String thisLine = null;
            while ((thisLine = fileIn.readLine()) != null) {
                String[] words = thisLine.split("\\s+");
                for (String word : words) {
                    Integer value = dictionary.get(word);
                    if (value == null) {
                        dictionary.put(word, 1);
                    } else {
                        dictionary.put(word, value+1);
                    }
                }
            }       
        } catch(Exception e) {
            e.printStackTrace();
        }

        dictionary.forEach((key, value) -> System.out.println(key + " : " + value));

    }


}