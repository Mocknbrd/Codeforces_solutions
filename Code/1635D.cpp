// You are given an array a consisting of n distinct positive integers.

// Let's consider an infinite integer set S which contains all integers x that satisfy at least one of the following conditions:

// x=ai for some 1≤i≤n.
// x=2y+1 and y is in S.
// x=4y and y is in S.
// For example, if a=[1,2] then the 10 smallest elements in S will be {1,2,3,4,5,7,8,9,11,12}.

// Find the number of elements in S that are strictly smaller than 2p. Since this number may be too large, print it modulo 109+7.

// Input
// The first line contains two integers n and p (1≤n,p≤2⋅105).

// The second line contains n integers a1,a2,…,an (1≤ai≤109).

// It is guaranteed that all the numbers in a are distinct.

// Output
// Print a single integer, the number of elements in S that are strictly smaller than 2p. Remember to print it modulo 109+7.
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
#define ld long double
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
constexpr int mod=1e9+7;
using namespace std;
bool present(set<int>&seen,int x);
int length(int x);
signed main(){
    ios;
    int n,p;
    cin>>n>>p;
    vector<int>arr(n);
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<int>dp(p+1);
    dp[0]=dp[1]=1;
    for(int i=2;i<dp.size();i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    for(int i=1;i<dp.size();i++){
        dp[i]+=dp[i-1];
    }
    set<int>seen;
    int ans=0;
    for(int i=0;i<arr.size();i++){
        if(!present(seen,arr[i])){
            seen.insert(arr[i]);
            int size=length(arr[i]);
            if(size<=p){
                ans+=dp[p-size];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
bool present(set<int>&seen,int x){
    while(x){
        if(seen.count(x)){
            return true;
        } else if(x&1){
            x>>=1;
        } else if(x%4==0){
            x>>=2;
        } else {
            break;
        }
    }
    return false;
}
int length(int x){
    int ans=0;
    while(x){
        x>>=1;
        ans++;
    }
    return ans;
}