// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.
#include<iostream>
#include<vector>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int coinChange(vector<int>&coins,int amt);
int solve(vector<int>&coins,vector<int>&mem,int amt);
int main(){
    ios;
    int n;
    cin>>n;
    vector<int>coins(n,0);
    for(int i=0;i<coins.size();i++){
        cin>>coins[i];
    }
    int amt;
    cin>>amt;
    cout<<coinChange(coins,amt)<<endl;
    return 0;
}
int coinChange(vector<int>&coins,int amt){
    vector<int>mem(amt+1,-1);
    return solve(coins,mem,amt);
}
int solve(vector<int>&coins,vector<int>&mem,int amt){
    if(amt==0){
        return 0;
    } else if(mem[amt]!=-1){
        return mem[amt];
    } else {
        int ans=1e9;
        for(int coin:coins){
            if(coin<=amt){
                ans=min(ans,1+solve(coins,mem,amt-coin));
            }
        }
        return mem[amt]=ans;
    }
}