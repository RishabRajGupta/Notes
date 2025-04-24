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

bool isSafe(int x, int y, int n, vector<vector<int> > visited, vector<vector<int> > m){
    if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y] == 0) && (m[x][y] == 1)){
        return true;
    }
    else{
        return false;
    }
}

void solve(vector<vector<int> > &m, int n, int x, int y, vector<string> &ans, vector<vector<int> > visited, string path){
    
    //Base Case
    if(x >= n-1 && y >= n-1){
        //print visited here
        visited[x][y] = 1;
        cout << "Path : " << endl << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << visited[i][j] << " ";
            }   cout << endl;
        }       cout << endl;

        ans.push_back(path);
        return;
    }

    //change every visited block to 1
    visited[x][y] = 1;

    //down
    int newx = x+1;
    int newy = y;
    if(isSafe(newx, newy, n, visited, m)){
        path.push_back('D');
        solve(m, n, newx, newy, ans, visited, path);
        path.pop_back();
    }

    //left
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, n, visited, m)){
        path.push_back('L');
        solve(m, n, newx, newy, ans, visited, path);
        path.pop_back();
    }

    //right
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, n, visited, m)){
        path.push_back('R');
        solve(m, n, newx, newy, ans, visited, path);
        path.pop_back();
    }

    //up
    newx = x-1;
    newy = y;
    if(isSafe(newx, newy, n, visited, m)){
        path.push_back('U');
        solve(m, n, newx, newy, ans, visited, path);
        path.pop_back();
    }

    //visited[x][y] = 0;
}


vector<string> findPath(vector<vector<int> > &m, int n){

    vector<string> ans;
    int xcor = 0;
    int ycor = 0;

    vector<vector<int> > visited = m;
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m.size(); j++){
            visited[i][j] = 0;
        }
    }   cout << endl;

    string path = "";
    solve(m, n, xcor, ycor, ans, visited, path);
    sort(ans.begin(), ans.end());
    
    return ans;
}

int main(){

    int n = 4;
    vector<vector<int> > m(4,vector<int>(4));
    
    //{1, 0, 0, 0}
    //{1, 1, 0, 1}
    //{1, 1, 0, 0}
    //{0, 1, 1, 1}

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    
    vector<string> ans = findPath(m, n);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    } cout << endl;

}