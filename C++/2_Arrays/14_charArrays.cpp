#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int length(char string[]){
    int count = 0;
    for(int i = 0; string[i] != '\0'; i++){
        count++;
    }
    return count;
}

void Reverse(char arr[]){
    int len = length(arr);
    for(int i = 0; i < len/2; i++){
        swap(arr[i], arr[len-i-1]);
    }
}

bool Palindrome(char arr[]){
    int end = length(arr)-1;
    int start = 0;
    while(start <= end){
        if(arr[start++] != arr[end--]){
            return false;
        }
    }
    return true;
}

char toLower(char x){
    if(x >= 'a' && x <= 'z'){
        return x;
    }
    return x - 'A' + 'a';
}

char toUpper(char x){
    if(x >= 'A' && x <= 'Z'){
        return x;
    }
    return x - 'a' + 'A';
}

void removeSpl(char arr[]){
    string x;
    for(int i = 0; i < length(arr); i++){
        char a = arr[i];
        if((a >='0' && a <='9')||(a >='A' && a <='Z')||(a >='a' && a <='z')){
            x += a;
        }
    }
    
    for(int i = 0; i < length(arr); i++){
        arr[i] = x[i];
    }
}

bool truePalindrome(char arr[]){
    
    //removing special characters & white spaces
    removeSpl(arr);

    //comparision in lowercase
    int s = 0;
    int e = length(arr)-1;
    while(s <= e){
        if(toLower(arr[s++]) != toLower(arr[e--])){
            return false;
        }
    }
    return true;
}

void ReverseWords(char arr[]){
    int n = length(arr);
    vector<string> vrr;

    //storing elements as a vector
    string temp = "";
    for(int i = 0; i < n; i++){
        if(arr[i] != ' '){
            temp += arr[i];
        }
        else{
            vrr.push_back(temp);
            temp = "";
        }
    }

    //append last word
    if(!temp.empty()){
        vrr.push_back(temp);
    }

    //reversing vector
    reverse(vrr.begin(),vrr.end());

    //restoring words
    int j = 0;
    for(int i = 0; i < vrr.size(); i++){
        for(int k = 0; k < vrr[i].length(); k++){
            arr[j++] = vrr[i][k];
        }
        arr[j++] = ' ';
    }

    //null value at end -- important
    arr[j] = '\0';
}

char maxOccuring(char arr[]){
    int n = length(arr);

    //vector to store occurence of each element
    vector<int> vrr(26, 0);

    //checking the occurence of each element
    for(int i = 0; i < n; i++){
        int z = toLower(arr[i]) - 'a';
        vrr[z]++;
    }

    //finding maximum
    int max = 0;
    int index = 0;
    for(int i = 0; i < vrr.size(); i++){
        if(vrr[i] > max){
            max = vrr[i];
            index = i;
        }
    }

    return 'a'+index;
}

string replaceBy(string s, string ins){
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            s.erase(i,1);
            s.insert(i,ins);
        }
    }
    return s;
}

string removeSubstring(string s, string sub){
    for(int i = 0; i < s.length(); i++){

        //check for first character
        if(s[i] == sub[0]){

            //take out substring
            string temp = "";
            for(int j = 0; j < sub.length(); j++){
                temp += s[i+j];
            }
            
            //compare substring
            bool same = true;
            for(int j = 0; j < sub.length(); j++){
                if(temp[j] != sub[j]){
                    same = false;
                }
            }

            //remove if same
            if(same){
                s.erase(i, sub.length());
            }
        }
    }
    return s;
}

bool compareArrays(vector<int> arr, vector<int> vrr){
    
    for(int i = 0; i < 26; i++){
        if(arr[i] != vrr[i]){
            return false;
        }
    }
    return true;
}

bool permutationInString(string s1, string s2){

    //s1 - smaller string 
    //s2 - larger string
    
    //character count array
    vector<int> arr(26,0);
    for(int i = 0; i < s1.length(); i++){
        int x = s1[i] - 'a';
        arr[x]++;
    }

    int x = 0;
    int i = x;
    int windowSize = s1.length();

    
    while(x+windowSize <= s2.length()){

        i = x;
        int size = i;
        vector<int> vrr(26,0);

        //storing windows
        while(i < windowSize+size){
            int x = s2[i++] - 'a';
            vrr[x]++;
        }
        
        //compairing windows
        if(compareArrays(arr,vrr)){
            return true;
        }
        x++;
    }
    return false;
}

string removeAdjacentDuplicates(string s){
    
    for(int i = 1; i < s.length(); i++){

        if(s[i] == s[i-1]){
            s.erase(--i,2);
            i--;
        }
    }
    return s;
}

string stringCompression(string s){

    for(int i = 1; i < s.length(); i++){
        int count = 1;

        while(s[i] == s[i-1]){
            count++;
            s.erase(i,1);
        }

        if(count > 1){
            string x = to_string(count);
            s.insert(i,x);
            i++;
        }

    }
    return s;
}

int main(){

    char arr[10];
    string s = "Racecar";
    strcpy(arr,s.c_str());
    cout << arr << endl;

    //1.Length of a string
    cout << length(arr) << endl;
    cout << strlen(arr) << endl;

    //2.Reverse a String
    Reverse(arr);
    cout << arr << endl;

    //3.Check Palindrome
    char arr2[10] = {'a','b','@',' ','c','b','#','a'};
    cout << Palindrome(arr2) << endl;
    cout << truePalindrome(arr2) << endl;
    
    //4.Reverse Words
    string x = "Hello World Output";
    char arr3[50];
    strcpy(arr3, x.c_str());
    ReverseWords(arr3);
    cout << arr3 << endl;

    //5.Max Occuring Character
    cout << maxOccuring(arr3) << endl;

    //6.Replace Spaces with '@*$'
    s = "This is Output";
    cout << replaceBy(s,"@*$") << endl;

    //7.Remove all occurences of a substring
    s = "abcaadcaabckjabbcabc";
    cout << removeSubstring(s,"abc") << endl;

    //8.Permutation in String
    string s1 = "ab";
    string s2 = "aidbaoo";
    cout << permutationInString(s1,s2) << endl;

    //9.Remove Adjacent Duplicates
    s = "azxxzy";
    cout << removeAdjacentDuplicates(s) << endl;

    //10.String Compression
    s = "aaabbccccccccccccd";
    cout << stringCompression(s) << endl;

}