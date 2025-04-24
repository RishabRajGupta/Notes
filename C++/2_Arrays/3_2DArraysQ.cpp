#include <iostream>
using namespace std;

int main(){
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    //1.RowWise Sum
    
    for(int i = 0; i < 3; i++){
        int sum = 0;
        for(int j = 0; j < 3; j++){
            sum += arr[j][i];
        }
        cout << "Sum of Row " << i+1 << " : " << sum << endl;
    }

    //2.Diagonal Sum
    
    int dSum = 0;
    int dSum2 = 0;
    int row = 0;
    while(row < 3){
        dSum += arr[row][row];
        row++;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i+j == 2){
                dSum2 += arr[i][j];
            }
        }
    }
    cout << "Diagonal Sum 1 & 2 : " << dSum << " & " << dSum2 << endl;

    //3.Transform : Rows -> Columns

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            //swap
            int x = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = x;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}