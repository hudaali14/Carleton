package comp1406t7;

import java.util.*;

public final class TestTeam{
  private static String[] names = {
      "Kittens", "Cats", "Dogs", "Bats", "Cows", "Oxen", "Ravens", "Ohs"};

  public static void play(Team[] teams, int numGames){
    for(int loop=0; loop<numGames; loop+=1){
      for(int i=0; i<names.length; i+=1){
        for(int j=i+1; j<names.length; j+=1){
          if(Math.random() < 0.1){
            teams[i].draw();
            teams[j].draw();
          }else if(Math.random() < 0.5){
            teams[i].win();
            teams[j].lose();
          }else{
            teams[i].lose();
            teams[j].win();
          }
        }// for j
      }// for i
    }// for loop

  }
// if(this.getRank() == Card.RANKS[0]) {
        //     rank1=0;
        // }else if(this.getRank() == Card.RANKS[11]) {
        //     rank1=11;
        // }else if(this.getRank() == Card.RANKS[12]) {
        //     rank1=12;
        // }else if(this.getRank() == Card.RANKS[13]) {
        //     rank1=13;
        // }else if(this.getRank() == Card.RANKS[14]) {
        //     rank1=14;
        // }else if(other.getRank() == Card.RANKS[0]) {
        //     rank2=0;
        // }else if(other.getRank() == Card.RANKS[11]) {
        //     rank2=11;
        // }else if(other.getRank() == Card.RANKS[12]) {
        //     rank2=12;
        // }else if(other.getRank() == Card.RANKS[13]) {
        //     rank1=13;
        // }else if(other.getRank() == Card.RANKS[14]) {
        //     rank2=14;
        // }else{
        //     if(this.getRank() == Card.RANKS[1]) {
        //         rank1=15;
        //     }else if(other.getRank() ==Card.RANKS[1]){
        //         rank2=15;
        //     }else{
        //         rank1=Integer.parseInt(this.getRank());
        //         rank2=Integer.parseInt(other.getRank());
        //     }
        // }
  public static void main(String[] args){
    Team[] teams = new Team[ names.length ];
    for(int i=0; i<names.length; i+=1){
      teams[i] = new Team(names[i]);
    }
    play(teams, 1);

    System.out.println("before sorting ------------------------");
    System.out.println( Arrays.toString(teams) );
    Arrays.sort(teams);
    System.out.println("after sorting -------------------------");
    System.out.println( Arrays.toString(teams) );

    Comparator<Team> cmp = new Comparator<Team>(){
      @Override
      public int compare(Team t1, Team t2){
        if(t1.name.length()<t2.name.length()){
          return -1;
        }else if(t1.name.length()>t2.name.length()){
          return 1;
        }else{
          if(t1.wins<t2.wins){
            return -1;
          }else if(t1.wins>t2.wins){
            return 1;
          }else{
            return 0;
          }
        }
      }
    };
    java.util.Arrays.sort(teams, cmp);
    System.out.println( Arrays.toString(teams) );
  }
}
