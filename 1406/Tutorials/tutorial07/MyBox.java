package comp1406t7;

public class MyBox extends Box{

    public MyBox(String inside){
        super(inside);
    }

    @Override 
    public String toString(){
        return ""+this.inside;
    }

    @Override
    public int compareTo(Box other){
        if(this.inside.length()<other.inside.length()){
            return -1;
        }else if(this.inside.length()>other.inside.length()){
            return 1;
        }else{
            if(this.inside.compareTo(other.inside)==1){
                return 1;
            }else if(this.inside.compareTo(other.inside)==-1){
                return -1;
            }else{
                return 0;
            }
        }
    }
}