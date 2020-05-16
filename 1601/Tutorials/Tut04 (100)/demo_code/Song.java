public class Song{
   
   //represents a song
   private String title;  //title of the song
   //private String rating; //"*" ... "*****"
   private String composer;


   //constructor
   public Song(String aSongTitle, String aComposer){
      title = aSongTitle;
      //rating = aRating;
      composer= aComposer;
   }
   //get and set methods
   public String getTitle(){return title;}
   //public String getRating(){return rating;}
   public String getComposer(){return composer;}
   public void setTitle(String aTitle){
      title=aTitle;
   }
   // public void setRating(String aRating){
   //     rating = aRating;
   // }
   public void setComposer(String aComposer){
      composer=aComposer;
   }

   public void print(){
      System.out.println("Song: " + this.getTitle() + " by " + this.getComposer());
   }
}