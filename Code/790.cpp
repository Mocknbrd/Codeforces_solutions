// You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


// Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

// In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.
#include<iostream>
#include<vector>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int numTiles(int n);
int main(){
    ios;
    int n;
    cin>>n;
    cout<<numTiles(n)<<endl;
    return 0;
}
int numTiles(int n){
    if(n<=1){
        return n;
    } else {
        vector<int>dp(n+1,0);
        dp[0]=1,dp[1]=1,dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=2*dp[i-1]+dp[i-3];
        }
        return dp[n];
    }
}