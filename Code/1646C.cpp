// A number is called powerful if it is a power of two or a factorial. In other words, the number m is powerful if there exists a non-negative integer d such that m=2d or m=d!, where d!=1⋅2⋅…⋅d (in particular, 0!=1). For example 1, 4, and 6 are powerful numbers, because 1=1!, 4=22, and 6=3! but 7, 10, or 18 are not.

// You are given a positive integer n. Find the minimum number k such that n can be represented as the sum of k distinct powerful numbers, or say that there is no such k.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). Description of the test cases follows.

// A test case consists of only one line, containing one integer n (1≤n≤1012).

// Output
// For each test case print the answer on a separate line.

// If n can not be represented as the sum of distinct powerful numbers, print −1.

// Otherwise, print a single positive integer  — the minimum possible value of k.
#include<bits/stdc++.h>
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define int long long
using namespace std;
int findSum(int mask,vector<int>&f);
signed main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>f(15,1);
        for(int i=1;i<15;i++){
            f[i]=i*f[i-1];
        }
        int ans=1e9;
        for(int mask=0;mask<(1<<15);mask++){
            int sum=findSum(mask,f);
            int used=__builtin_popcountll(mask)+__builtin_popcountll(n-sum);
            ans=min(ans,used);
        }
        cout<<ans<<endl;
    }
    return 0;
}
int findSum(int mask,vector<int>&f){
    int ans=0;
    while(mask){
        int pos=log2(mask&(-mask));
        mask^=(1<<pos);
        ans+=f[pos];
    }
    return ans;
}