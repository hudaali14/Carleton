package comp1406t6;

public class Owl extends Animal{

    protected boolean wise;
    protected String noise;

    public boolean getWise(){
        return wise;
    }

    public Owl(String name, int year, boolean wise){
        super(name, year);
        this.wise=wise;
    }

    @Override
    public String noise(){
        this.noise="hoot";
        return this.noise;
    }

    @Override
    public String toString(){
        if (wise==true){
            return super.toString() + "This owl is wise"; 
        }else{
            return super.toString() + "This owl is not wise";
        }
    }
}