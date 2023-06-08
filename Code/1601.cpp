// We have n buildings numbered from 0 to n - 1. Each building has a number of employees. It's transfer season, and some employees want to change the building they reside in.

// You are given an array requests where requests[i] = [fromi, toi] represents an employee's request to transfer from building fromi to building toi.

// All buildings are full, so a list of requests is achievable only if for each building, the net change in employee transfers is zero. This means the number of employees leaving is equal to the number of employees moving in. For example if n = 3 and two employees are leaving building 0, one is leaving building 1, and one is leaving building 2, there should be two employees moving to building 0, one employee moving to building 1, and one employee moving to building 2.

// Return the maximum number of achievable requests.
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
#include<map>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
vector<int>seen;
vector<vector<int>>mem;
int solve(vector<vector<int>>&req,int index,int mask);
int maxRequests(vector<vector<int>>&req,int n);
int main(){
    ios;
    int n,r;
    cin>>n>>r;
    vector<vector<int>>req(r,vector<int>(2,0));
    for(int i=0;i<req.size();i++){
        cin>>req[i][0]>>req[i][1];
    }
    seen=vector<int>(n,0);
    mem=vector<vector<int>>(r,vector<int>(1<<r,-1));
    cout<<maxRequests(req,n)<<endl;
    return 0;
}
int maxRequests(vector<vector<int>>&req,int n){
    return solve(req,0,0);
}
int solve(vector<vector<int>>&req,int index,int mask){
    if(index==req.size()){
        for(int i=0;i<seen.size();i++){
            if(seen[i]){
                return -1e9;
            }
        }
        return 0;
    } else if(mem[index][mask]!=-1){
        return mem[index][mask];
    } else {
        int ans1=solve(req,index+1,mask);
        int start=req[index][0],end=req[index][1];
        seen[start]--;
        seen[end]++;
        int ans2=1+solve(req,index+1,mask^(1<<index));
        seen[start]++;
        seen[end]--;
        return mem[index][mask]=max(ans1,ans2);
    }
}