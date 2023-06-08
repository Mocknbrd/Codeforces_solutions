// Alice and Bob are playing a game on a matrix, consisting of 2 rows and m columns. The cell in the i-th row in the j-th column contains ai,j coins in it.

// Initially, both Alice and Bob are standing in a cell (1,1). They are going to perform a sequence of moves to reach a cell (2,m).

// The possible moves are:

// Move right — from some cell (x,y) to (x,y+1);
// Move down — from some cell (x,y) to (x+1,y).
// First, Alice makes all her moves until she reaches (2,m). She collects the coins in all cells she visit (including the starting cell).

// When Alice finishes, Bob starts his journey. He also performs the moves to reach (2,m) and collects the coins in all cells that he visited, but Alice didn't.

// The score of the game is the total number of coins Bob collects.

// Alice wants to minimize the score. Bob wants to maximize the score. What will the score of the game be if both players play optimally?

// Input
// The first line contains a single integer t (1≤t≤104) — the number of testcases.

// Then the descriptions of t testcases follow.

// The first line of the testcase contains a single integer m (1≤m≤105) — the number of columns of the matrix.

// The i-th of the next 2 lines contain m integers ai,1,ai,2,…,ai,m (1≤ai,j≤104) — the number of coins in the cell in the i-th row in the j-th column of the matrix.

// The sum of m over all testcases doesn't exceed 105.

// Output
// For each testcase print a single integer — the score of the game if both players play optimally.
#include <iostream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <cstring>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define int long long
using namespace std;
int solve(vector<vector<int>>&arr);
int main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int m;
        cin>>m;
        vector<vector<int>>arr(2,vector<int>(m,-1));
        for(int i=0;i<2;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        cout<<solve(arr)<<endl;
    }
    return 0;
}
int solve(vector<vector<int>>&arr){
    int m=arr[0].size();
    if(m<=1){
        return 0;
    } else {
        for(int j=m-2;j>=0;j--){
            arr[0][j]+=arr[0][j+1];
        }
        for(int j=1;j<m;j++){
            arr[1][j]+=arr[1][j-1];
        }
        int ans=min(arr[0][1],arr[1][m-2]);
        for(int j=1;j<m-1;j++){
            ans=min(ans,max(arr[0][j+1],arr[1][j-1]));
        }
        return ans;
    }
}