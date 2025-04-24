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

void solve(string input, string output, int index, vector<string> &ans, string map[]){

    if(index >= input.length()){
        ans.push_back(output);
        return;
    }

    int n = input[index] - '0';
    string curr = map[n];

    for(int i = 0; i < curr.length(); i++){
        output += curr[i];
        solve(input, output, index+1, ans, map);
        output.pop_back();
    }

}

vector<string> combinations(string input){
    vector<string> ans;
    string output = "";
    int index = 0;

    string map[10] = {"", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(input, output, index, ans, map);

    return ans;
}

int main(){

    string input = "23";

    vector<string> ans = combinations(input);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;

}