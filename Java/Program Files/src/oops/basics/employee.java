package oops.basics;
//encapsulation
public class employee {
    private Integer baseSalary;                              //wrapper class - takes more memory coz it's an object
    public int hourlyWage;                                   //primitive class - less memory coz it's a variable
    private boolean activeEmployee = false;                  //abstraction OR hiding unnecessary details from main class
                                                             //this also reduces coupling
    public int calculateWage(int extraHours){
        return baseSalary + (extraHours * hourlyWage);
    }

    //setters
    public void setBaseSalary(int baseSalary) {
        if(baseSalary >= 0) {
            this.baseSalary = baseSalary;
            activeEmployee = true;
        }
    }
    //getters
    protected int getBaseSalary(){
        return this.baseSalary;
    }
}
