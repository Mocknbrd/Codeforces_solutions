// There are n slimes in a row. Each slime has an integer value (possibly negative or zero) associated with it.

// Any slime can eat its adjacent slime (the closest slime to its left or to its right, assuming that this slime exists).

// When a slime with a value x eats a slime with a value y, the eaten slime disappears, and the value of the remaining slime changes to x−y.

// The slimes will eat each other until there is only one slime left.

// Find the maximum possible value of the last slime.

// Input
// The first line of the input contains an integer n (1≤n≤500000) denoting the number of slimes.

// The next line contains n integers ai (−109≤ai≤109), where ai is the value of i-th slime.

// Output
// Print an only integer — the maximum possible value of the last slime.
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
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
constexpr int infinity=1e18+7;
using namespace std;
vector<vector<vector<int>>>mem;
int solve(vector<int>&arr,int index,bool pos,bool neg);
signed main(){
    ios;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mem=vector<vector<vector<int>>>(n,vector<vector<int>>(2,vector<int>(2,-1)));
    cout<<solve(arr,0,false,false)<<endl;
    return 0;
}
int solve(vector<int>&arr,int index,bool pos,bool neg){
    if(index==arr.size()){
        (!pos or !neg)*(-infinity);
    } else if(mem[index][pos][neg]!=-1){
        return mem[index][pos][neg];
    } else {
        int ans1=arr[index]+solve(arr,index+1,true,neg);
        int ans2=(-arr[index])+solve(arr,index+1,pos,true);
        return mem[index][pos][neg]=max(ans1,ans2);
    }
}