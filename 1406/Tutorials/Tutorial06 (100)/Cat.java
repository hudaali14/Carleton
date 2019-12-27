package comp1406t6;
import java.util.Random;

public class Cat extends Dog{

    protected String noise;

    public String getNoise(){
        String[] noises= {"meow", "prrr"};
        Random random=new Random();
        int index= random.nextInt(noises.length);
        this.noise= noises[index];
        return this.noise;
    }

    public Cat(String name, int year){
        super(name, year); 
    }

    @Override
    public String noise(){
        return getNoise();
    }

   
}