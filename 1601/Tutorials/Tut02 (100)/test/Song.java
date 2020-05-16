public class Song{

    //represents a song
    private String title; //title of the song
    private String rating; //"*"..."*****"
    public String composer; //artist

    //constructor
    public Song(String aSongTitle, String aRating){
        title= aSongTitle;
        rating= aRating;
    }

    public Song(String aSongTitle, String aRating, String artist){
        title= aSongTitle;
        rating= aRating;
        composer= artist;
    }

    //get and set methods
    public String getTitle(){
        return title;
    }

    public String getRating(){
        return rating;
    }

    public String getComposer(){
        return composer;
    }

    public void setTitle(String aTitle){
        title= aTitle;
    }

    public void setRating(String aRating){
        rating = aRating;
    }

    public void setComposer(String aComposer){
        composer=aComposer;
    }
}