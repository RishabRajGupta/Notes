package Advanced.Exception_Handling;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException, InsufficientFundException {
        Scanner sc = new Scanner(System.in);

        FileReader reader = null;
        try{
            reader = new FileReader("file.txt");
            reader.read();
        }catch (FileNotFoundException e){                   //handles an exception when needed
            System.out.println("File Not Found");           //user defined message
            System.out.println(e.getMessage());             //inbuilt message
            e.printStackTrace();                            //prints stack of errors with its origins
        } catch (IOException ex){
            System.out.println("Input Output Error");
        } finally {                                         //contains remaining part of the code to execute
            if(reader != null){
                try{
                    reader.close();
                } catch (IOException exp){
                    exp.printStackTrace();
                }
            }
        }

        //this same can also be written by "try-with-resources" method

        try(
                var reader2 = new FileReader("file.txt");           //resources inside try
                var writer2 = new FileWriter("file.txt");
        ){
            var value = reader2.read();
        }catch (FileNotFoundException e){                   //handles an exception when needed
            System.out.println("File Not Found");           //user defined message
            System.out.println(e.getMessage());             //inbuilt message
            e.printStackTrace();                            //prints stack of errors with its origins
        } catch (IOException ex) {
            System.out.println("Input Output Error");
        }
        int n = sc.nextInt();
        is_positive(n);
    }
    public static void is_positive(int n) throws IOException,InsufficientFundException{      //declaration (required if we throw checked exception)
        if(n < 0){
            throw new IOException();                        //throwing exceptions
        }
        else if(n < 100){
            throw new InsufficientFundException();          //user defined exception
        }
        else if(n < 200){
            throw new InsufficientFundException("Low on Funds!"); //user defined exception with message
        }
    }
}

