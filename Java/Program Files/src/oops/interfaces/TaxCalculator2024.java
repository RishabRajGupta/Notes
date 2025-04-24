package oops.interfaces;

public class TaxCalculator2024 implements TaxCalculator {
    private double taxableIncome;

    public TaxCalculator2024(double taxableIncome){
        this.taxableIncome = taxableIncome;
    }
    @Override
    public double calculateTax(){
        return this.taxableIncome * 0.3;
    }
}
