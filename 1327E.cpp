// You wrote down all integers from 0 to 10n−1, padding them with leading zeroes so their lengths are exactly n. For example, if n=3 then you wrote out 000, 001, ..., 998, 999.

// A block in an integer x is a consecutive segment of equal digits that cannot be extended to the left or to the right.

// For example, in the integer 00027734000 there are three blocks of length 1, one block of length 2 and two blocks of length 3.

// For all integers i from 1 to n count the number of blocks of length i among the written down integers.

// Since these integers may be too large, print them modulo 998244353.

// Input
// The only line contains one integer n (1≤n≤2⋅105).

// Output
// In the only line print n integers. The i-th integer is equal to the number of blocks of length i.

// Since these integers may be too large, print them modulo 998244353.
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
#define infinity static_cast<int>(1e18+7);
using namespace std;
int mod=998244353;
int power(int base,int exponent);
int multiply(int a,int b);
signed main(){
    ios;
    int n;
    cin>>n;
    vector<int>ans(n,0);
    for(int i=0;i<n;i++){
        int length=i+1;
        ans[i]=(multiply(180,power(10,n-length-1))+multiply(multiply(810,n-length-1),power(10,n-length-2)))%mod;
    }
    ans.back()=10;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
int power(int base,int exponent){
    int size=(exponent>0)?log2(exponent)+1:1;
    vector<int>dp(size,0);
    dp[0]=base;
    for(int i=1;i<dp.size();i++){
        dp[i]=(dp[i-1]*dp[i-1])%mod;
    }
    int ans=1;
    while(exponent){
        int pos=log2(exponent&(-exponent));
        exponent^=(1<<pos);
        ans*=dp[pos];
        ans%=mod;
    }
    return ans;
}
int multiply(int a,int b){
    int size=(b>0)?log2(b)+1:1;
    vector<int>dp(size,0);
    dp[0]=a;
    for(int i=1;i<dp.size();i++){
        dp[i]=(dp[i-1]+dp[i-1])%mod;
    }
    int ans=0;
    while(b){
        int pos=log2(b&(-b));
        b^=(1<<pos);
        ans+=dp[pos];
        ans%=mod;
    }
    return ans;
}