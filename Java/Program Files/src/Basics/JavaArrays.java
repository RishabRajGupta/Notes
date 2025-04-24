package Basics;

import java.util.*;
public class JavaArrays {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        //declarations
        int[] arr1 = new int[5];                             //integer array
        int[] arr2 = {1, 2, 3, 4, 5};
        int[] arr3 = new int[]{6, 7, 8, 9, 0};
        String[] names = {"Hello", "Java", "phone"};        //string array

        //methods
        int len = arr1.length;                              //length of an array
        Arrays.sort(arr2);                                  //sorting
        Arrays.fill(arr1, 5);                            //fills the array with 5
        boolean a = Arrays.equals(arr3, arr2);               //checks equality and returns true or false
        String b = Arrays.toString(arr2);                   //Array --> String
        int[] array = Arrays.copyOf(arr1, 5);     //copies arr1 --> array till 5th element(fills 0 if no element is found)
        int[] array2 = Arrays.copyOfRange(arr2, 2, 4);//copies arr2 --> array from index 2 to 4

        //filling
        for (int i = 0; i < arr1.length; i++) {
            arr1[i] = sc.nextInt();
        }
        //printing
        for (int value : arr1) {
            System.out.println(value + " ");
        }

        //Binary Search
        int target = 4;                                     //finding 4 in arr2
        int start = 0;
        int end = arr2.length - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr2[mid] == target) {
                System.out.format("%d found at %d", target, mid);
                break;
            } else if (arr2[mid] > target) {
                end = mid - 1;
            } else if (arr2[mid] < target) {
                start = mid + 1;
            } else {
                System.out.println("Not Found");
            }
        }

        //Max SubArray Sum
        //Brute Force
        int maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < arr2.length; i++) {
            for (int j = i; j < arr2.length - 1; j++) {
                int currSum = 0;
                for (int k = i; k <= j; k++) {
                    currSum += arr2[k];
                }
                if (maxSum < currSum) {
                    maxSum = currSum;
                }
            }
        }
        //Prefix Sum
        int[] prefix = new int[arr2.length];
        prefix[0] = arr2[0];
        for (int i = 1; i < arr2.length; i++) {
            prefix[i] = prefix[i - 1] + arr2[i];
        }
         for (int i = 0; i < arr2.length; i++) {
             start = i;
             for (int j = i; j < arr2.length - 1; j++) {
                int currSum = start == 0 ? prefix[j] : prefix[j] - prefix[start - 1];
                 if (maxSum < currSum) {
                     maxSum = currSum;
                 }
            }
        }
        //Kadane's Algorithm
        maxSum = Integer.MIN_VALUE;
        int currSum = 0;
        for (int value : arr2) {
            currSum += value;
            if (currSum < 0) {
                currSum = 0;
            }
            maxSum = Math.max(currSum, maxSum);
        }

        //Sorting
        int[] Array = {1,5,3,4,2};
        //Bubble Sort
        for(int i = 0; i < Array.length -1; i++){
            for(int j = 0; j < Array.length -1-i; j++){
                if(Array[j]>Array[j+1]){
                    //swap
                    int x = Array[j];
                    Array[j] = Array[j+1];
                    Array[j+1] = x;
                }
            }
        }
        //Selection Sort
        for(int i = 0; i < Array.length-1; i++){
            int min = i;
            for(int j = i+1; j < Array.length; j++){
                if(Array[j]  < Array[min]){
                    min = j;
                }
            }
            //swap - less no. of swapping
            int y = Array[i];
            Array[i] = Array[min];
            Array[min] = y;
        }
        //Insertion Sort
        for(int i = 1; i < Array.length; i++){
            int curr = Array[i];
            int prev = i-1;
            //shifting(OR finding position for curr element)
            while(prev >= 0 && Array[prev] > curr){
                Array[prev+1] = Array[prev];
                prev--;
            }
            //insertion
            Array[prev+1] = curr;
        }
        //Counting Sort
        int[] Array2 = {1,4,1,3,2,4,3,7};
        //size of count array
        int largestElement = Integer.MIN_VALUE;
        for (int value : Array2) {
            largestElement = Math.max(largestElement, value);
        }
        int[] count = new int[largestElement+1];
        //counting
        for (int value : Array2) {
            count[value]++;
        }
        //sorting
        int j = 0;
        for(int i = 0; i < Array2.length; i++){
            while (count[i] > 0){
                Array2[j] = i;
                j++;
                count[i]--;
            }
        }
        //for(i in Array2) - Python alternative code
        for (int i : Array2) {
            System.out.print(i + " ");
        }

        //Multi-dimensional Arrays
        int rows = 4;
        int columns = 4;
        int[][] matrix = new int[rows][columns];
        int[][] numbers = {{1, 2, 3, 4},
                {5, 6, 7, 8},
                {9, 10, 11, 12},
                {13, 14, 15, 16}};
        //print spiral - numbers
        int startRow = 0;
        int startColumn = 0;
        int endRow = numbers.length - 1;
        int endColumn = numbers[0].length - 1;
        while (startRow <= endRow && startColumn <= endColumn) {
            //top
            for (int i = startColumn; i <= endColumn; i++) {
                System.out.print(numbers[startRow][i] + " ");
            }
            //right
            for (int i = startRow + 1; i <= endRow; i++) {
                System.out.print(numbers[i][endColumn] + " ");
            }
            //bottom
            for (int i = endColumn - 1; i >= startColumn; i--) {
                if (startRow == endRow) {
                    break;
                }
                System.out.print(numbers[endRow][i] + " ");
            }
            //left
            for (int i = endRow - 1; i >= startRow + 1; i--) {
                if (startColumn == endColumn) {
                    break;
                }
                System.out.print(numbers[i][startColumn] + " ");
            }
            startRow++;
            startColumn++;
            endRow--;
            endColumn--;
        }
        //Diagonal Sum
        int diagonalSum = 0;
        for(int i = 0; i < numbers.length; i++){
            for(int k = 0; k < numbers[0].length; k++){
                if(i == k){                                     //primary diagonal
                    diagonalSum += numbers[i][k];
                }
                else if(i+k == numbers.length-1){               //secondary diagonal
                    diagonalSum += numbers[i][k];
                }
            }
        }
        //Staircase Search
        int[][] number = {{10, 20, 30, 40},
                          {15, 25, 35, 45},
                          {27, 29, 37, 48},
                          {32, 33, 39, 50}};
        int key = 33;
        int i = 1;
        int z = number[0].length-1;
        while(i < number.length && z >= 0){
            if(number[i][z] == key){
                System.out.println("Found at : "+String.format("row:%d and column:%d",i,z));
                break;
            }
            else if(number[i][z] < key){
                i++;
            }
            else if(number[i][z] > key){
                z--;
            }

        }
    }
}