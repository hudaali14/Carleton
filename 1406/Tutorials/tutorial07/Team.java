package comp1406t7;

public class Team implements Comparable<Team>{
  protected int wins;      // wins
  protected int losses;    // losses
  protected int draws;     // draws (tie game)
  protected String name;   // name of the team

  public Team(String name){
    this(name,0,0,0);
  }
  public Team(String name, int wins, int losses, int draws){
    this.name = name;
    this.wins = wins;
    this.losses = losses;
    this.draws = draws;
  }

  /* getters */
  public int getWins(){ return wins; }
  public int getLosses(){ return losses; }
  public int getdraws(){ return draws; }

  /* setters */
  public Team win(){ wins += 1; return this; }
  public Team lose(){ losses += 1; return this; }
  public Team draw(){ draws += 1; return this; }

  @Override 
  public int compareTo(Team other){
    int point1=(2*this.wins)+this.draws;
    int games1=this.wins+this.losses+this.draws;
    int point2=(2*other.wins)+other.draws;
    int games2=other.wins+this.losses+this.draws;
    if(point1<point2){
      return -1;
    }else if(point1>point2){
      return 1;
    }else{
      if(games1>games2){
        return -1;
      }else if (games1<games2){
        return 1;
      }else{
        if(this.wins<other.wins){
          return -1;
        }else if(this.wins>other.wins){
          return 1;
        }else{
          return 0;
        }
      }
    }
  }

  @Override
  public String toString(){
    return this.name+"["+((2*this.wins)+this.draws)+"]:"+ this.wins+ "/"+ this.losses+"/"+this.draws;
  }

}
