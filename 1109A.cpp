// Sasha likes programming. Once, during a very long contest, Sasha decided that he was a bit tired and needed to relax. So he did. But since Sasha isn't an ordinary guy, he prefers to relax unusually. During leisure time Sasha likes to upsolve unsolved problems because upsolving is very useful.

// Therefore, Sasha decided to upsolve the following problem:

// You have an array a with n integers. You need to count the number of funny pairs (l,r) (l≤r). To check if a pair (l,r) is a funny pair, take mid=l+r−12, then if r−l+1 is an even number and al⊕al+1⊕…⊕amid=amid+1⊕amid+2⊕…⊕ar, then the pair is funny. In other words, ⊕ of elements of the left half of the subarray from l to r should be equal to ⊕ of elements of the right half. Note that ⊕ denotes the bitwise XOR operation.

// It is time to continue solving the contest, so Sasha asked you to solve this task.

// Input
// The first line contains one integer n (2≤n≤3⋅105) — the size of the array.

// The second line contains n integers a1,a2,…,an (0≤ai<220) — array itself.

// Output
// Print one integer — the number of funny pairs. You should consider only pairs where r−l+1 is even number.
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
using namespace std;
int sz=(1<<20)+7;
signed main(){
    ios;
    int n;
    cin>>n;
    vector<int>arr(n,0);
    vector<vector<int>>dp(sz,vector<int>(2,0));
    dp[0][1]=1;
    int ans=0,_xor=0;
    for(int i=0;i>n;i++){
        cin>>arr[i];
        _xor^=arr[i];
        ans+=dp[_xor][i%2]++;
    }
    cout<<ans<<endl;
    return 0;
}