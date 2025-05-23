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

void solve(string str, string output, int index, vector<string>& ans){

    if(index >= str.length()){
        ans.push_back(output);
        return;
    }

    //exclude
    solve(str, output, index+1, ans);

    //include
    char el = str[index];
    output += el;
    solve(str, output, index+1, ans);

}

vector<string> subsequences(string str){
    
    vector<string> ans;
    string output = "";
    int index = 0;

    solve(str, output, index, ans);

    return ans;
}



int main(){

    string str = "abc";
    vector<string> ans = subsequences(str);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }

    return 0;

}