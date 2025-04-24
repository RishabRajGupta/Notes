package oops.interfaces;

public class Main {
    public static void main(String args[]) {
        var calculator = new TaxCalculator2024(1_00_000);
        var report = new TaxReport(calculator);             //injected calculator - constructor injection
        report.show();
        report.setCalculator(new TaxCalculator2023());      //injected calculator - setter injection
        report.show();
        report.show(new TaxCalculator2024(5_00_000));
    }
}
