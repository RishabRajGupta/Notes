package Basics;

import java.util.*;
public class UsefulPrograms {
    public static int DecimalToBinary(int bin){
        int dec = 0;
        int power = 0;
        while(bin > 0){
            int lastDigit = (int)bin - (int)(bin/10)*10;
            dec += Math.pow(2,power) * lastDigit;
            power++;
            bin /= 10;
        }
        return dec;
    }
    public static int BinaryToDecimal(int dec){
            int bin = 0;
            int multiplier = 1;
            while(dec > 0){
                bin += multiplier * (dec % 2);
                dec /= 2;
                multiplier *= 10;
            }
            return bin;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println(DecimalToBinary(101));           //converts Decimal to Binary
        System.out.println(BinaryToDecimal(5));             //converts Binary to Decimal
    }
}
