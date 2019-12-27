package comp1406a4;

public class SeniorTaxes extends Taxes{

    protected double income;
    protected double health_costs;

    public SeniorTaxes(String name, int sin, double income, double health_costs){
        super(name, sin);
        this.income=income;
        this.health_costs=health_costs;
    }

    @Override
    public long taxesOwed(){
        // this.income=(long) this.income;
        // this.health_costs= (long) this.health_costs;
        if (this.income < 20000){
            return (long) Math.round((this.income * 0.0)-(this.health_costs * 1.0));
        }else if(this.income >= 20000 && this.income < 50000){
            return (long) Math.round((this.income * 0.1) - (this.health_costs * 0.75));
        }else{
            return (long) Math.round((this.income * 0.4) - (this.health_costs * 0.5));
        }
    }

}