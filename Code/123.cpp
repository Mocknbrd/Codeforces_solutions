// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
#include<iostream>
#include<vector>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int maxProfit(vector<int>&prices);
int main(){
    ios;
    int n;
    cin>>n;
    vector<int>prices(n,0);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    cout<<maxProfit(prices)<<endl;
    return 0;
}
int maxProfit(vector<int>&prices){
    int n=prices.size();
    vector<int>left(n,0),right(n,0);
    int leftmin=prices[0],rightmax=prices.back();
    for(int i=1,j=n-2;i<n;i++,j--){
        leftmin=min(leftmin,prices[i]);
        left[i]=max(left[i-1],prices[i]-leftmin);
        rightmax=max(rightmax,prices[j]);
        right[j]=max(right[j+1],rightmax-prices[j]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,left[i]+right[i]);
    }
    return ans;
}