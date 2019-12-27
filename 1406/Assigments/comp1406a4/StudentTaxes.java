package comp1406a4;

public class StudentTaxes extends Taxes{

    protected double income;
    protected double tuition;

    public StudentTaxes(String name, int sin, double income, double tuition){
        super(name, sin);
        this.income=income;
        this.tuition=tuition;
    }

    @Override
    public long taxesOwed(){
        // this.income=(long) this.income;
        // this.tuition= (long) this.tuition;
        if(this.income < 10000){
            return Math.round((this.income * 0.1) - (this.tuition * 1.0));
        }else if(this.income >= 10000 && this.income < 30000){
            return Math.round((this.income * 0.3) - (this.tuition * 0.5));
        }else{
            return Math.round((this.income * 0.5) - (this.tuition * 0.25));
        }
    }

    // public static void main(String[] args){
    //     StudentTaxes s1= new StudentTaxes("Huda", 1, 29999, 10000);
    //     System.out.println(s1.taxesOwed());
    // }

}