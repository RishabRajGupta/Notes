#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cstring>
using namespace std;

int factorial(int n){

    //base case
    if(n == 0){
        return 1;
    }

    //f(x) = n * f(x-1)
    return n * factorial(n-1);
}

int power(int n, int pow){
    if(pow == 1){
        return n;
    }
    return n * power(n, pow-1);
}

int printing(int n){
    if(n == 0){
        cout << endl;
        return 0;
    }
    cout << n << " ";           //tail recursion
    printing(n-1);
    cout << n << " ";           //head recursion
}

int fib(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }

    return fib(n-1)+fib(n-2);
}

int climb(int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }

    return climb(n-1) + climb(n-2);
}

//general and more efficient solution for above problem
int com(int n, int m){
    return factorial(n+m)/(factorial(n)*factorial(m));
}
int stairs(int n, int step1, int step2){

    //ensure step 1 is minimum
    if(step1 > step2){
        int temp = step1;
        step1 = step2;
        step2 = temp;
    }

    //check max frequency for step 2
    int x = n/step2;
    int count = 0;

    for(int i = 0; i <= x; i++){

        int remaining = (n - (i*step2))/step1;
        
        if((remaining*step1 + i*step2) == n){
            count += com(i,remaining);
        }
    }
    return count;
}


bool isSorted(int *arr, int size){
    if(size == 0 || size == 1){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }
    else{
        isSorted(arr + 1, size-1);
    }
}

int sum(int *arr, int size){
    if(size == 0){
        return 0;
    }
    return arr[0] + sum(arr+1, size-1); 
}

int linearSearch(int *arr, int key, int size, int s2){
    if(size == 0){
        return -1;
    }

    if(arr[0] == key){
        return s2-size;
    }
    else{
        return linearSearch(arr+1, key, size-1,s2);
    }
}

bool binSearch(int *arr, int key, int start, int end){

    if(start > end){
        return false;
    }

    int mid = start + (end - start)/2;

    if(key == arr[mid]){
        return true;
    }
    else if(key < arr[mid]){
        return binSearch(arr, key, start, mid-1);
    }
    else if(key > arr[mid]){
        return binSearch(arr, key, start+mid, end);
    }
}

void reverseString(string &word, int i = 0){
    int j = word.length() - i - 1;
    if(i >= j){
        return;
    }
    swap(word[i], word[j]);

    reverseString(word, ++i);
}

bool checkPalindrome(string word, int i = 0){
    
    int j = word.length() - i - 1;
    if(i > j){
        return 1;
    }
    
    if(word[i] != word[j]){
        return 0;
    }

    return checkPalindrome(word, ++i);
}

int powerFunc(int n, int pow){
    if(pow <= 0){
        return 1;
    }
    if(pow == 1){
        return n;
    }
    
    int ans = powerFunc(n, pow/2);

    if(pow % 2 == 0){
        return ans * ans;
    }
    else{
        return n * ans * ans;
    }

}

void bubbleSort(int *arr, int size){
    int j = size;
    if(j == 0 || j == 1){
        return;
    }
    for(int i = 0; i < j-1; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    bubbleSort(arr, --size);
}

void selectionSort(int *arr, int size){
    if(size == 0){
        return;
    }

    int min = 0;
    for(int i = 1; i < size; i++){
        if(arr[i] < arr[min]){
            min = i;
        }
    }
    swap(arr[0], arr[min]);
    selectionSort(arr+1, size-1);
}

void insertionSort(int *arr, int size, int start = 0){
    if(start == size-1){
        return;
    }

    int temp = arr[start + 1];
    int j = start;
    while(arr[j] > temp && j >= 0){
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = temp;
    insertionSort(arr, size, ++start);
    
}

int main(){

    cout << "factorial : " << factorial(5) << endl;
    cout << "2 ^ 5 : " << power(2,5) << endl;
    printing(5);

    //1.fibbonacci series
    cout << endl << "fibonacci at 7 : " << fib(7) << endl;
    
    //2.Stair climb
    cout << "ways to reach 5th stair : " << climb(5) << endl;
    cout << "No of ways : " << stairs(5,3,2) << endl;

    //check sorted
    int arr[6] = {1, 2, 3, 7, 5, 6};
    cout << "is array sorted : " << isSorted(arr, 6) << endl;

    //array sum
    cout << "array sum : " << sum(arr, 6) << endl;

    //linear search
    int key = 7;
    cout << "Linear Search (index): " << linearSearch(arr, key, 6, 6) << endl;

    //binary search
    int arr2[] = {1, 2, 3, 4, 5, 6};
    cout << "Binary Search : " << binSearch(arr2, 5, 0, 6) << endl;

    //reverse a string
    string word = "hello";
    reverseString(word);
    cout << "reversed : " << word << endl;

    //check palindrome
    string word2 = "racecar";
    cout << "is Palindrome : " << checkPalindrome(word2) << endl;

    //calculate power
    cout << "2 ^ 5 : " << powerFunc(2,10) << endl;
    
    //bubble sort
    int arr3[5] = {4, 3, 5, 1, 2};
    bubbleSort(arr3, 5);
    
    for(int i = 0; i < 5; i++){
        cout << arr3[i] << " ";
    }
    cout << endl;

    //selection sort
    int arr4[] = {5, 4, 3, 2, 1};
    selectionSort(arr4, 5);
    
    for(int i = 0; i < 5; i++){
        cout << arr4[i] << " ";
    }
    cout << endl;

    //insertion sort
    int arr5[5] = {1, 5, 4, 3, 2};
    insertionSort(arr5, 5);
    
    for(int i = 0; i < 5; i++){
        cout << arr5[i] << " ";
    }
    cout << endl;


}