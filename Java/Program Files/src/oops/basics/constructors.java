package oops.basics;
public class constructors {
    public int value1;
    public String value2;
    private int value3;

    public constructors(int value1, String value2, int value3){             //constructor method
        this.value1 = value1;
        this.value2 = value2;
        this.value3 = value3;                                               //private values can be set directly
        setValue3(value3);                                                  //or using any other method
    }
    //Polymorphism
    //constructor overloading
    public constructors(int value1){
        this.value1 = value1;
    }
    //method overloading - covered in basics-functions

    public void setValue3(int value3){
        if(value3 >= 0){
            this.value3 = value3;
        }
    }
}
