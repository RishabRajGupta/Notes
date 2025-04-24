package Advanced.MultiThreading;
import java.util.*;
import java.io.*;
class thread1 extends Thread{
    public void run(){
        for(int i = 0; i < 1; i++){
            System.out.println("thread");
        }
    }
}
public class Main {
    public static void main(String[] args){
        var th = new thread1();
        th.run();
        for(int i = 0; i < 1; i++){
            System.out.println("main1");
        }
        th.start();
        for(int i = 0; i < 1; i++){
            System.out.println("main2");
        }
        System.out.println("hello");
    }
}
