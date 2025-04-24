//pattern questions

#include <iostream>
using namespace std;

int main(){

    //1.Square
    cout << "1.Square (side): ";
    int a;
    cin >> a;
    for(int i = 0; i < a; i++){                         //Filled
        for(int j = 0; j < a; j++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < a; i++){                         //Hollow
        for(int j = 0; j < a; j++){
            if(i == 0 || j == 0 || i == a-1 || j == a-1){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;

    //2.Rectangle
    cout << "2.Rectangle (length): ";
    int b;
    cin >> b;
    cout << "2.Rectangle (breadth): ";
    int c;
    cin >> c;
    for(int i = 0; i < b; i++){                         //Filled
        for(int j = 0; j < c; j++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < b; i++){                         //Hollow
        for(int j = 0; j < c; j++){
            if(i == 0 || j == 0 || i == b-1 || j == c-1){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;

    //3.Pyramid
    cout << "3.Pyramid (Sides): ";
    int d;
    cin >> d;
    for(int i = 0; i < d; i++){                         //Lower Filled
        for(int j = 0; j < d; j++){
            if(j <= i){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < d; i++){                         //Upper Filled
        for(int j = 0; j < d; j++){
            if(j >= i){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;

    //4.Inverted Half Pyramid
    for(int i = 0; i < d; i++){                         //Lower Filled
        for(int j = d-i-1; j > 0; j--){                 //printing spaces
            cout << "  ";
        }
        for(int j = 0; j < i+1; j ++){                  //printing stars
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < d; i++){                         //Upper Filled
        for(int j = d-i; j > 0; j--){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;

    //5.Numeric Half Pyramid
    for(int i = 0; i < d; i++){                         //Lower Filled
        for(int j = 0; j < i+1; j++){
            cout << j + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < d; i++){                         //Upper Filled
        for(int j = 1; j <= d-i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl;

    //5.Full Pyramid
    int e;
    cout << "5.Full Pyramid (height): ";
    cin >> e;
    for(int i = 0; i < e; i++){                             //Regular
        //spaces
        for(int j = e-i-1; j > 0; j--){
            cout << " ";
        }
        //stars
        for(int j = 0; j < i+1; j++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < e; i++){                             //Inverted
        //spaces
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        //stars
        for(int j = e-i; j > 0; j--){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;

    //6.Hollow Pyramid
    for(int i = 0; i < e; i++){                             //Regular
        //spaces
        for(int j = e-i-1; j > 0; j--){
            cout << " ";
        }
        //stars
        for(int j = 0; j < i+1; j++){
            if(j == 0 || j == i){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }

    for(int i = 0; i < e; i++){                             //Inverted
        //spaces
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        //stars
        for(int j = e-i; j > 0; j--){
            if(j == e-i || j == 1){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;

    //7.Hollow Diamond
    int f;
    cout << "7.Hollow Diamond (height): ";
    cin >> f;
    f /= 2;
    //upper part
    for(int i = 0; i < f; i++){
        //stars
        for(int j = 0; j < f-i; j++){
            cout << "*";
        }
        //spaces
        for(int j = 0; j < i+1; j++){
            cout << "  ";
        }
        //stars
        for(int j = 0; j < f-i; j++){
            cout << "*";
        }
        cout << endl;
    }
    //lower part
    for(int i = 0; i < f; i++){
        //stars
        for(int j = 0; j < i+1; j++){
            cout << "*";
        }
        //spaces
        for(int j = 0; j < f-i; j++){
            cout << "  ";
        }
        //stars
        for(int j = 0; j < i+1; j++){
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
    
    //8.Number-star Half Pyramid
    int g;
    cout << "8.Number-star Half Pyramid (height): ";
    cin >> g;
    for(int i = 0; i < g; i++){
        for(int j = 0; j < i+1; j++){
            cout << i+1 << " ";
            if(i != 0 && j != i){
                cout << "* ";
            }
        }
        cout << endl;
    }
    cout << endl;

    //9.Hollow Upper Triangle
    int h;
    cout << "9.Hollow Upper Triangle(height): ";
    cin >> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < h-i; j++){
            if(i == 0){
                cout << "* ";
            }
            else{
                if(j == 0 || j == h-i-1){
                    cout << "* ";
                }
                else{
                    cout << "  ";
                }
            }
        }
        cout << endl;
    }
    cout << endl;

    //10.Number Hollow Triangle
    int k;
    cout << "10.Number Hollow Triangle(height) : ";
    cin >> k;
    for(int i = 0; i < k; i++){
        int count = 1;
        for(int j = 0; j < i+1; j++){
            if(i == k-1){
                cout << count++ << " ";
            }
            else{
                if(j == 0){
                    cout << "1 ";
                }
                else if (j == i){
                    cout << j+1 ;
                }
                else{
                cout << "  ";
                }
            }
        }
        cout << endl;
    }
    cout << endl;

    //11.ABC Triangle
    cout << "ABC Triangle(height): ";
    int l;
    cin >> l;
    for(int i = 0; i < l; i++){
        int char_count=65;
        for(int j = 0; j < i+1; j++){
            cout << static_cast<char>(char_count++) << " ";
        }
        char_count--;
        for(int j = 0; j < i; j++){
            cout << static_cast<char>(--char_count) << " ";
        }
        cout << endl;
    }
    cout << endl;

    //12.Numeric Hollow Inverted Triangle
    cout << "12.Numeric Hollow Inverted Triangle(height): ";
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m-i; j++){
            if(i == 0){
                cout << j+1 << " ";
            }
            else if(i > 0 && j == 0){
                cout << i+1 << " ";
            }
            else if(j == m-i-1){
                cout << m << " ";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;

    //13.Numeric Palindrome Equilateral Pyramid
    int n;
    cout << "13.Numeric Palindrome Equilateral Pyramid(height): ";
    cin >> n;
    for(int i = 0; i < n; i++){
        //spaces
        for(int j = 0; j < n-i; j++){
            cout << "  ";
        }
        //numbers ascending
        int p_counter = 1;
        for(int j = 0; j < i+1; j++){
            cout << p_counter++ << " ";
        }
        //numbers descending
        p_counter--;
        for(int j = 0; j < i; j++){
            cout << --p_counter << " ";
        }
        cout << endl;
    }
    cout << endl; 

    // 14.Star-Number Pyramid
    int o;
    cout << "14.Star-Number Pyramid(height): ";
    cin >> o;
    for(int i = 0; i < o; i++){
        //stars
        for(int j = 0; j < o-i; j++){
            cout << "* ";
        }
        //numbers
        for(int j = 0; j < 2*i+1; j++){
            if(j%2 != 0 && i != 0){
                cout << "* ";
            }
            else{
                cout << i+1 << " ";
            }
        }
        //stars
        for(int j = 0; j < o-i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;

    //15.Floyd's Triangle
    int p;
    cout << "15.Floyd's Triangle(height): ";
    cin >> p;
    for(int i = 0; i < p; i++){
        for(int j = 0; j < i+1; j++){
            cout << (i*(i+1))/2 + j + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;

    //16.Butterfly Pattern
    int q;
    cout << "16.Butterfly Pattern(height): ";
    cin >> q;
    q /= 2;
    //upper part
    for(int i = 0; i < q; i++){
        
        for(int j = 0; j <= i; j++){
            cout << "* ";
        }
        for(int j = 0; j < 2*(q-i-1); j++){
            cout << "  ";
        }
        for(int j = 0; j <= i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    //lower part
    for(int i = 0; i < q; i++){
        for(int j = 0; j < q-i; j++){
            cout << "* ";
        }
        for(int j = 0; j < 2*i; j++){
            cout << "  ";
        }
        for(int j = 0; j < q-i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}