// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
#include<cstring>
#include<map>
#include<algorithm>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
vector<int>solve(vector<int>&arr);
int main(){
    ios;
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans=solve(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
vector<int>solve(vector<int>&arr){
    sort(arr.begin(),arr.end());
    vector<int>dp(arr.size(),1),pre(arr.size(),-1);
    int max=0,index=-1;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<i;j++){
            if(arr[i]%arr[j]==0 and dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                pre[i]=j;
            }
        }
        if(dp[i]>max){
            max=dp[i];
            index=i;
        }
    }
    vector<int>ans;
    while(index!=-1){
        ans.push_back(arr[index]);
        index=pre[index];
    }
    return ans;
}