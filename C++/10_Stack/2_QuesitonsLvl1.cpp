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

void input(stack<int> &s, int n){
    int count = 1;
    for(int i = 0; i < n; i++){
        s.push(count++);
    }
}
void print(stack<int> &s){
    if(s.empty()){
        cout << endl;
        return;
    }
    int num = s.top();
    cout << num << " ";
    s.pop();
    print(s);
    s.push(num);
}
void print(stack<char> &s){
    if(s.empty()){
        cout << endl;
        return;
    }
    char num = s.top();
    cout << num << " ";
    s.pop();
    print(s);
    s.push(num);
}

string reverseStr(string word){
    
    stack<char> st;
    string rev = "";

    for(int i = 0; i < word.length(); i++){
        st.push(word[i]);
    }

    while(!st.empty()){
        rev += st.top();
        st.pop();
    }

    return rev;
}

bool match(char ch, char c){
    if(ch == '['){
        return (c == ']');
    }
    else if(ch == '{'){
        return (c == '}');
    }
    else if(ch == '('){
        return (c == ')');
    }
    return false;
}

bool validParenthesis(string par){
    stack<char> s;
    for(int i = 0; i < par.length(); i++){
        char ch = par[i];
        if(ch == '[' || ch == '{' || ch == '('){
            s.push(ch);
        }
        else if(ch == ']' || ch == '}' || ch == ')'){
            if(!s.empty()){
                char c = s.top();
                if(match(c, ch)){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(s.empty()){
        return true;
    }
    return false;
}

void deleteMid(stack<int> &s, int count = 0){
    
    int size = s.size();
    int lastindex = size-1;
    
    if(count == lastindex/2){
        s.pop();
        return;
    }

    int temp = s.top();
    s.pop();
    
    deleteMid(s, ++count);
    
    s.push(temp);
}

void insertAtBottom(stack<int> &s, int n){
    if(s.empty()){
        s.push(n);
        return;
    }

    int num = s.top();
    s.pop();
    insertAtBottom(s, n);
    s.push(num);
}

void stackReverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();
    stackReverse(s);
    insertAtBottom(s,num);

}

void insertSorted(stack<int> &s, int n){
    if((!s.empty() && s.top() < n)|| s.empty()){
        s.push(n);
        return;
    }
    int num = s.top();
    s.pop();
    insertSorted(s, n);
    s.push(num);
}

void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int num = s.top();
    s.pop();
    sortStack(s);
    insertSorted(s, num);
}

bool redundantBrackets(string word){
    stack<char> storage;

    for(int i = 0; i < word.length(); i++){
        char ch = word[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            storage.push(ch);
        }
        else if(ch == ')'){
            char x = storage.top();
            if(x == '+' || x == '-' || x == '*' || x == '/'){
                while(storage.top() != '('){
                    storage.pop();
                }
                storage.pop();
            }
            else{
                return true;
            }
        }
    }
    return false;
}

int minCost(string word){
    int len = word.length();
    
    //odd condition
    if(len%2 != 0){
        return -1;
    }

    //remove valid ones
    stack<char> inv;
    for(int i = 0; i < len; i++){
        char ch = word[i];
        if(ch == '('){
            inv.push(ch);
        }
        else if(ch == ')'){
            if(inv.top() == '(' && !inv.empty()){
                inv.pop();
            }
            else{
                inv.push(ch);
            }
        }
    }

    //correct invalid ones
    int a = 0; int b = 0;
    while(!inv.empty()){
        int x = (inv.top() == '(')? a++ : b++;
        inv.pop();
    }
    return ((a+1)/2 + (b+1)/2);
}

int requiredCost(string word){
    stack<int> s;   int count= 0;
    for(int i = 0; i < word.length(); i++){
        char c = word[i];
        if(c == '('){
            s.push(c);
        }
        else if(c == ')'){
            if(s.empty()){
                count++;
            }
            else{
                s.pop();
            }
        }
    }
    return s.size() + count;
}

int main() {

    //1.Reverse a string
    cout << reverseStr("hello") << endl;

    //2.Delete middle element
    stack<int> s;
    input(s, 5); print(s);
    deleteMid(s); print(s);

    //3.Valid parenthesis
    string par = "[{()}](){[]}";
    cout << validParenthesis(par) << endl;

    //4.Insert at bottom
    stack<int> num;
    input(num,5); print(num);
    insertAtBottom(num,0); print(num);

    //5.Reverse a stack
    print(num);
    stackReverse(num); print(num);

    //6.Sort Stack
    stack<int> num2;
    num2.push(5); num2.push(3); num2.push(1); num2.push(2);
    print(num2);
    sortStack(num2); print(num2);

    //7.Check Redundant Brackets
    string word = "(a+(b+c))";
    cout << redundantBrackets(word) << endl;

    //8.Minimum cost to remove redundant brackets
    word = "((((()((()";
    cout << minCost(word) << endl;
    cout << requiredCost(word) << endl;
    
}