#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

vector<int> makeBeautiful(vector<int> arr) {
    // code here
    stack<int> temp;
    for(int i = 0; i < arr.size(); i++){
        
        if(temp.empty()){
            temp.push(arr[i]);
        }
        
        else if((temp.top() >= 0 && arr[i] < 0) || (temp.top() < 0 && arr[i] >= 0)){
            temp.pop();
            continue;
        }
        
        else {
            temp.push(arr[i]);
        }
    }
    
    vector<int> arr2;
    while(!temp.empty()){
        arr2.push_back(temp.top());
        temp.pop();
    }

    reverse(arr2.begin(), arr2.end());
    return arr2;
}

bool backspaceCompare(string s, string t) {
    stack<char> a;  stack<char> b;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '#'){
            if(!a.empty()){
                a.pop();
            }
            continue;
        }
        else{
            a.push(s[i]);
        }
    }
    for(int i = 0; i < t.length(); i++){
        if(t[i] == '#'){
            if(!b.empty()){
                b.pop();
            }  
            continue;
        }
        else{
            b.push(t[i]);
        }
    }

    if(a.size() != b.size()){
        return false;
    }
    while(!a.empty() && !b.empty()){
        if(a.top() != b.top()){
            return false;
        }
        a.pop(); b.pop();
    }

    return true;
}

vector<int> bracketNumber(string s){
   
    vector<int> number;
    stack<int> st;  int count = 0;
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        if(ch == '('){
            count++;
            number.push_back(count);
            st.push(count);
        }
        else if(ch == ')'){
            number.push_back(st.top());
            st.pop();
        }
    }
    return number;
}

stack<int> minAtPop(vector<int> arr, int n){
    stack<int> s;
    
    s.push(arr[0]);
    for(int i = 1; i < n; i++){
        s.push(min(arr[i], s.top()));
    }
    
    return s;
}

vector<int> nextMaximum(vector<int> arr){
    vector<int> result(arr.size(), -1);
    stack<int> st;
    for(int i = 0; i < arr.size(); i++){
        while(!st.empty() && arr[i] > arr[st.top()]){
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> result(n, -1);
    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            result[st.top()] = arr[i];
            st.pop();
        }

        st.push(i);
    }
    return result;
}

vector<int> leftSmaller(int n, int a[]){
    // code here
    vector<int> result(n, -1);
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && a[i] < a[st.top()]){
            result[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}

vector<int> nextLargerElement(vector<int> &arr) {
    // code here
    vector<int> result(arr.size(), -1);
    stack<int> st;
    for(int i = 0; i < (2*arr.size())-1; i++){
        int j = i % arr.size();
        while(!st.empty() && (arr[st.top()] < arr[j])){
            result[st.top()] = arr[j];
            st.pop();
        }
        st.push(j);
    }
    return result;
}

vector<int> calculateSpan(vector<int>& arr) {

    vector<int> ans(arr.size(), 1);
    stack<int> st;
    for(int i = arr.size()-1; i >= 0; i--){
        while(!st.empty() && arr[i] > arr[st.top()]){
            ans[st.top()] = st.top()-i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        ans[st.top()] = st.top() + 1;
        st.pop();
    }
    return ans;
}

int main(){

    // 1. Make Beautiful
    
    vector<int> arr(5);
    arr.push_back(1);   arr.push_back(2);
    arr.push_back(3);   arr.push_back(-4);
    arr.push_back(5);   arr = makeBeautiful(arr);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }   cout << endl;

    // 2. Background string compare
    
    cout << backspaceCompare("ab#c", "ad#c") << endl;

    // 3. Print Bracket Number

    vector<int> number = bracketNumber("(aa(bdc))p(dee)");
    for(int i = 0; i < number.size(); i++){
        cout << number[i] << " ";
    }   cout << endl;

    // 4. Get Minimum at POP
    vector<int> arr2;
    arr2.push_back(2); arr2.push_back(1);
    arr2.push_back(3); arr2.push_back(5);
    arr2.push_back(0); arr2.push_back(6);
    stack<int> st1 = minAtPop(arr2, 6);
    while(!st1.empty()){
        cout << st1.top() << " ";
        st1.pop();
    }   cout << endl;

    // 5. Next Greater Element
    vector<int> arr3 = {6, 8, 0, 1, 3};
    vector<int> result = nextMaximum(arr3);
    for(int i : result){
        cout << i << " ";
    }   cout << endl;

    // 6. Next Smaller Element
    vector<int> arr4 = {2, 1, 4, 3};
    vector<int> result2 = nextSmallerElement(arr4, 4);
    for(int i : result2){
        cout << i << " ";
    }   cout << endl;

    // 7. Next Smaller on Left
    int arr5[] = {1, 5, 0, 3, 4, 5};
    vector<int> result3 = leftSmaller(6, arr5);
    for(int i : result3){
        cout << i << " ";
    }   cout << endl;

    // 8. Next Greater element in a circular array
    vector<int> arr6 = {0, 2, 3, 1, 1};
    vector<int> result4 = nextLargerElement(arr6);
    for(int i : result4){
        cout << i << " ";
    }   cout << endl;

    // 9. Stock span problem
    vector<int> arr7 = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result5 = calculateSpan(arr7);
    for(int i : result5){
        cout << i << " ";
    }   cout << endl;

}