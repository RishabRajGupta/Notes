#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool prime(int n){

    if(n <= 0 || n == 1){
        return false;
    }
    else if(n == 2){
        return true;
    }
    else{
        for(int i = 2; i < n/2; i++){
            if(n % i == 0){
                return false;
            }
        }
    }
    return true;
}

int checkPrimes(int a, int n){

    int count = 0;
    vector<int> primes(n+1, true);

    for(int i = 0; i < n; i++){

        //check for a number to be prime
        if(prime(i) && primes[i]){

            if(i >= a){
                count++;
            }

            //remove all multiples
            int multiple = 2*i;
            while(multiple <= n){
                primes[multiple] = false;
                multiple += i;
            }
        }
        else if(!prime(i)){
            primes[i] = false;
        }
    }
    return count;
}

int gcd(int a, int b){

    if(a == 0){
        return b;
    }
    else if(b == 0){
        return a;
    }

    //make both of them = gcd
    //a = 6 and b = 15
    // 15-6 = 9 -> 9-6 = 3(b) -> 6-3 = 3(a)
    //return (any - a or b)
    while(a != b){
        if(a > b){                  
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}

int hcf(int a, int b){
    
    int small = (a>b)? b : a;
    int x = (a>b)? a % b : b % a;
    
    if(x == 0){
        return small;
    }

    return hcf(x,small);
}

int lcm(int a, int b){
    return (a * b)/gcd(a,b);
}

int fastExponentiation(int n, int p){

    int temp = n;
    
    while(p > 1){

        n *= n;
        //>> 1 is faster method of division by 2
        p >>= 1;
    }

    //& with 1 checks for odd faster
    if(p & 1){
        n *= temp;
    }
    
    return n;
}

bool pigeonholePrinciple(vector<int> &arr, int k){
    
    //remiander frequencies
    vector<int> remainders(k, 0);

    for(int i : arr){
        int rem = i % k;

        //to handle negative numbers
        if(rem < 0){
            rem += k;
        }

        //check for two numbers with rem = 0
        if(rem == 0){
            if(remainders[rem] == 1){
                return true;
            }
        }

        //check for complimentary remainders
        else if(remainders[k-rem] > 0){
            return true;
        }

        remainders[rem]++;
    }
    return false;
}

int inclusionExcluison(int n, int a, int b){
    return (n/a)+(n/b)-(n/(a*b));
}

int moduloArithmetic(int n){
    
    int result = 1;
    int m = 1000000007;                     //10^9 + 7

    //mod prevents result from going beyond limit of int
    for(int i = 2; i <= n; i++){

        //1LL temporarily converts result to long long int 
        result = (1LL * result * i) % m;
    }

    return result;
}

int main(){

    //1.Sieve of Eratosthenes
    cout << checkPrimes(10,25) << endl;

    //2.GCD of two numbers
    cout << gcd(15,6) << endl;
    cout << hcf(15,6) << endl;

    //3.LCM of two numbers
    cout << lcm(15,6) << endl;

    //4.Fast Exponentiation
    cout << fastExponentiation(5,3) << endl;

    //5.Pigeonhole Principle
    vector<int> arr = {4,5,6,7,12,13,14};
    cout << pigeonholePrinciple(arr, 7) << endl;

    //6.Inclusion-Exclusion Principle
    cout << inclusionExcluison(1000, 5, 7) << endl;

    //7.Modulo Arithmetic
    cout << moduloArithmetic(212) << endl;

}