package Advanced.LambdaExpressions;

public class main {

    //making a function to use class of a functional interface
    public static void greet(printer printer){
        printer.print("Hello World");
    }

    //another function that passes the class to previous one
    public static void display(){
        greet(new TerminalPrinter());
    }

    //using anonymous inner class
    public static void display2(){
        greet(new printer() {
            @Override
            public void print(String message) {
                System.out.println(message);
            }
        });
    }

    //using lambda expressions
    public static void display3() {
        greet((String message) -> {System.out.println(message);});
        greet(System.out::println);                 //method referencing
    }

    public static void main(String args[]){
        display();
        display2();
        display3();

        //lambda expression inside main block
        printer pin = (String message) -> {System.out.println(message);};
        printer pin2 = System.out::println;
        pin.print("Lambda");


    }
}
