package comp1406t6;
import java.util.Random;

public class Dog extends Animal{

    protected String noise;

    public String getNoise(){
        String[] noises= {"woof", "grrrr"};
        Random random=new Random();
        int index= random.nextInt(noises.length);
        this.noise=noises[index];
        return this.noise;
    }

    public Dog(String name, int year){
        super(name, year);
    }

    @Override
    public String noise(){
        return getNoise();
    } 
}