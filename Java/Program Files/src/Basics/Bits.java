package Basics;

public class Bits {
    public static void main(String[] args){
        int a = 5;
        int b = 4;
        System.out.println(a & b);                          //4
        System.out.println(a | b);                          //5
        System.out.println(a ^ b);                          //1
        System.out.println(~a);                             //-6
        System.out.println(5<<2);                           //20
        System.out.println(5>>2);                           //1

        //check even
        if((a&1) == 0){
            System.out.println("Even");
        }
        else{
            System.out.println("Odd");
        }

        //get ith bit (here i = 2)
        int x = 1<<2;                                     // 2 -- > i
        if((a & x) == 0){
            System.out.println("0");
        }
        else{
            System.out.println("1");
        }

        //set ith bit (here i = 2 i.e. x used)
        System.out.println(a | x);

        //clear ith bit (here i = 2 i.e. x used)
        System.out.println(a & ~(x));

        //clear last i bits (here i = 2)
        int y = (~0) << 2;
        System.out.println(a & y);

        //clear range of bits (here from 2 to 5)
        int num = 214;
        x = (~0)<<(5+1);
        y = ~((~0)<<2)-1;
        System.out.println(num & (x|y));

        //if num is power of 2
        int p = 8;
        if ((p & (p-1)) == 0){
            System.out.println("Power of 2");
        }
        else{
            System.out.println("Not a power of 2");
        }
        //count set bits(1) in a number
        int count = 0;
        while(p > 0){
            if((p & 1)!=0){
               count++;
            }
            p = p >> 1;
        }
        System.out.println(count);
        //fast Exponentiation (calculate 3^5)
        int base = 3;
        int power = 5;

        int iteration = 0;
        int ans = 1;
        while(power > 0){
            if((power & 1) != 0){                           //bit == 1
                ans *= base;
            }
            base *= base;                                   //doubling base at each iteration
            power >>= 1;                                    //proceeding to next digit in binary of power
            iteration++;                                    //counting iterations
        }
        System.out.println(ans + " " + iteration);
    }
}
