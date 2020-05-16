import java.util.ArrayList;

public class MyApp {
   public static void main(String[] args){
      // System.out.println("Hello World");

      // Song song1 = new Song("Girl From Ipanema", "Antonio Carlos Jobim", "***");
      // Song song2 = new Song("Hotel California", "Don Henley Glenn Frey Don Felder", "****");
      // song1.print();
      // song2.print();

      // ArrayList<Song> songs = new ArrayList<Song>();

      // songs.add(new Song("Girl From Ipanema", "Antonio Carlos Jobim", "*****"));
      // songs.add(new Song("Hotel California", "Don Henley Glenn Frey Don Felder", "****"));

      // System.out.println("Songs:");
      // for(Song s : songs) {
      //   s.print();
      // }

      //ArrayList<RecordedSong> songs = new ArrayList<RecordedSong>();
      ArrayList<Song> songs = new ArrayList<Song>();

      songs.add(new RecordedSong("Girl From Ipanema", "Antonio Carlos Jobim", "Stan Getz", "file1.mp3",  "*****"));
      songs.add(new RecordedSong("Hotel California", "Don Henley Glenn Frey Don Felder", "Eagles", "hotel_california.mp3", "****"));

      System.out.println("Songs:");
      for(Song s : songs) {
        s.print();
      }
   }
}