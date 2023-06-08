// The student council is preparing for the relay race at the sports festival.

// The council consists of n members. They will run one after the other in the race, the speed of member i is si. The discrepancy di of the i-th stage is the difference between the maximum and the minimum running speed among the first i members who ran. Formally, if ai denotes the speed of the i-th member who participated in the race, then di=max(a1,a2,…,ai)−min(a1,a2,…,ai).

// You want to minimize the sum of the discrepancies d1+d2+⋯+dn. To do this, you are allowed to change the order in which the members run. What is the minimum possible sum that can be achieved?

// Input
// The first line contains a single integer n (1≤n≤2000)  — the number of members of the student council.

// The second line contains n integers s1,s2,…,sn (1≤si≤109)  – the running speeds of the members.

// Output
// Print a single integer  — the minimum possible value of d1+d2+⋯+dn after choosing the order of the members.
#include <bits/stdc++.h>
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define YY cout<<"YES"<<endl
#define NN cout<<"NO"<<endl
#define yy cout<<"Yes"<<endl
#define nn cout<<"No"<<endl
#define endl "\n"
#define int long long
#define infinity static_cast<int>(1e18+7);
using namespace std;
vector<vector<int>>mem;
int solve(vector<int>&arr,int l,int r);
signed main(){
    ios;
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mem=vector<vector<int>>(n,vector<int>(n,-1));
    sort(arr.begin(),arr.end());
    cout<<solve(arr,0,n-1)<<endl;
    return 0;
}
int solve(vector<int>&arr,int l,int r){
    if(l>=r){
        return 0;
    } else if(mem[l][r]!=-1){
        return mem[l][r];
    } else {
        return mem[l][r]=arr[r]-arr[l]+min(solve(arr,l+1,r),solve(arr,l,r-1));
    }
}