// There are n armchairs, numbered from 1 to n from left to right. Some armchairs are occupied by people (at most one person per armchair), others are not. The number of occupied armchairs is not greater than n2.

// For some reason, you would like to tell people to move from their armchairs to some other ones. If the i-th armchair is occupied by someone and the j-th armchair is not, you can tell the person sitting in the i-th armchair to move to the j-th armchair. The time it takes a person to move from the i-th armchair to the j-th one is |i−j| minutes. You may perform this operation any number of times, but these operations must be done sequentially, i. e. you cannot tell a person to move until the person you asked to move in the last operation has finished moving to their destination armchair.

// You want to achieve the following situation: every seat that was initially occupied must be free. What is the minimum time you need to do it?

// Input
// The first line contains one integer n (2≤n≤5000) — the number of armchairs.

// The second line contains n integers a1,a2,…,an (0≤ai≤1). ai=1 means that the i-th armchair is initially occupied, ai=0 means that it is initially free. The number of occupied armchairs is at most n2.

// Output
// Print one integer — the minimum number of minutes you have to spend to achieve the following situation: every seat that was initially occupied must be free.
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
int mem[5001][5001];
int solve(vector<int>&occupied,vector<int>&unoccupied,int i,int j);
signed main(){
    ios;
    int n;
    cin>>n;
    vector<int>occupied,unoccupied,arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        switch(arr[i]){
            case 0: unoccupied.push_back(i);
            break;
            default: occupied.push_back(i);
            break;
        }
    }
    memset(mem,-1,sizeof(mem));
    cout<<solve(occupied,unoccupied,0,0)<<endl;
    return 0;
}
int solve(vector<int>&occupied,vector<int>&unoccupied,int i,int j){
    if(i==occupied.size()){
        return 0;
    } else if(j==unoccupied.size()){
        return infinity;
    } else if(mem[i][j]!=-1){
        return mem[i][j];
    } else {
        int ans1=solve(occupied,unoccupied,i,j+1);
        int ans2=abs(occupied[i]-unoccupied[j])+solve(occupied,unoccupied,i+1,j+1);
        return mem[i][j]=min(ans1,ans2);
    }
}