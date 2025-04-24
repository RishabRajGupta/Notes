package oops.basics;

public class main {
    public static void main(String[] args){
        //new object formation
        textbox textbox1 = new textbox();                       //general method
        var textbox2 = new textbox();                           //var keyword automatically detects the type of variable

        textbox1.setText("Text 1");                             //using other class methods
        System.out.println(textbox1.text);                      //using other class data

        textbox2.setText("TEXT 2");                             //new object from other class
        System.out.println(textbox2.text);

        textbox1.clear();
        System.out.println(textbox1.text);

        //memory allocation
        var textbox3 = textbox1;                                //new variable created from already existing variable
        textbox3.setText("Hello");                              //any change in new variable is also reflected in older variables of same object
        System.out.println(textbox1.text);

        //encapsulation
        var emp1 = new employee();
        emp1.setBaseSalary(30_000);                               //'_' is only used to separate digits(doesn't affect the values)
        emp1.hourlyWage = 200;
        System.out.println(emp1.calculateWage(10));
        System.out.println(emp1.getBaseSalary());

        //constructors
        var const1 = new constructors(15,"String",10);
        var const2 = new constructors(15);                  //overloaded constructor

    }
}
