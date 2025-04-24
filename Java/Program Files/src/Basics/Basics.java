package Basics;

import java.util.*;                                 //java utility library
public class Basics {                               //file name is the main class

    public static void printHello(){                //function definition
        System.out.println("Hello");
    }  //user defined printHello function
    public static int sum(int a, int b){                   //here a and b are parameters
        return a + b;
    }             //user defined sum function
    public static double sum(double a, double b){return a + b;}       //function overloading using different data types
    public static int sum(int a, int b, int c){                   //here a and b are parameters
        return a + b + c;
    }  //function overloading using multiple parameters

    public static void main(String[] args) {        //main function should be public & static both

        Scanner sc = new Scanner(System.in);        //scanner class

        //variables
        int a = 10;                                 //variable declaration - <datatype><variable_name>
        float b = 10.5f;
        double c = 10.5;
        char d = '@';
        String e = "Hello World";
        int castNum = (int)c;                       //Type casting OR Explicit Conversion

        //input
        int num = sc.nextInt();                     //integer input
        String g = sc.next();                       //single word string input
        String h = sc.nextLine();                   //single line string input
        float fnum = sc.nextFloat();                   //float input

        //printing
        System.out.print("Hello World!");           //printing hello world
        System.out.println("Hello " + num + " World!"); //printing hello num world line
        System.out.format("Hello %d %f %s",num,fnum,h); //formatted string

        // operators
        a = ++a;                                    //pre-increment : +1 then use (a = 11)
        a = a++;                                    //post-increment : use then +1 (a = 1)

        //ternary operator - condition ? expression True: expression False
        String result = (num % 2 == 0)?"even":"odd";    //even when true and odd when false

        //conditional statements
        //if
        if(num % 2 == 0 && num >= 0){
            System.out.println("Even and positive");
        }
        else if(num % 2 == 0 && num < 0){
            System.out.println("Even and negative");
        }
        else{
            System.out.println("Odd");
        }
        //switch
        switch(num){
            case 1:
                System.out.println("ONE");              //executes when num == 1
                break;                                  //breaks out of switch if executed
            case 2:
                System.out.println("TWO");              //executes when num == 2
            default:
                System.out.println("Other Number");     //executes when num != all of the above cases
        }

        //loops
        //while loop
        while(num > 0){                                 //while(condition)
            a = a + 1;                                  //statement
            num--;
        }
        //for loop
        for(int i = 0; i < num; i++){                   //for(initialisation; condition; increment/decrement)
            System.out.println("ABCD");                 //statement
        }
        //do while loop
        do{
            System.out.println("Hello");                //do statement
            num--;
        }while(num > 0);                                //condition
        //labels
        label1:                                         //label for first for loop
        for(int i = 0; i < a; i++){
            label2:
            for(int j = 0; j < num; j++){
                if(i + j == 5){
                    break label1;                       //control statement for label1
                }
                else if (i + j == 10) {
                    break label2;
                }
            }
        }

        //functions
        printHello();                                   //function call
        int functionSum = sum(a,d);               //here 3 and 4 are arguments - call by value

    }
}