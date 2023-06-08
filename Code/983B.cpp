// For an array b of length m we define the function f as

// f(b)={b[1]f(b[1]⊕b[2],b[2]⊕b[3],…,b[m−1]⊕b[m])if m=1otherwise,
// where ⊕ is bitwise exclusive OR.

// For example, f(1,2,4,8)=f(1⊕2,2⊕4,4⊕8)=f(3,6,12)=f(3⊕6,6⊕12)=f(5,10)=f(5⊕10)=f(15)=15
// You are given an array a and a few queries. Each query is represented as two integers l and r. The answer is the maximum value of f on all continuous subsegments of the array al,al+1,…,ar.

// Input
// The first line contains a single integer n (1≤n≤5000) — the length of a.

// The second line contains n integers a1,a2,…,an (0≤ai≤230−1) — the elements of the array.

// The third line contains a single integer q (1≤q≤100000) — the number of queries.

// Each of the next q lines contains a query represented as two integers l, r (1≤l≤r≤n).

// Output
// Print q lines — the answers for the queries.
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
#define ll long long
#define ld long double
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
constexpr int infinity=1e9+7;
constexpr ll linf=1e18+7;
using namespace std;
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
int main(){
    ios;
    int n;
    cin>>n;
    vector<int>arr(n);
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[0][i]=arr[i];
    }
    for(int level=0;level<n;level++){
        for(int pos=1;pos<n-level;pos++){
            dp[level+1][pos-1]=dp[level][pos-1]^dp[level][pos];
        }
    }
    for(int level=0;level<n;level++){
        for(int pos=1;pos<n-level;pos++){
            dp[level+1][pos-1]=max({dp[level+1][pos-1],dp[level][pos],dp[level][pos-1]});
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<dp[r-l][l-1]<<endl;
    }
    return 0;
}