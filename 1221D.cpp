// You have a fence consisting of n vertical boards. The width of each board is 1. The height of the i-th board is ai. You think that the fence is great if there is no pair of adjacent boards having the same height. More formally, the fence is great if and only if for all indices from 2 to n, the condition ai−1≠ai holds.

// Unfortunately, it is possible that now your fence is not great. But you can change it! You can increase the length of the i-th board by 1, but you have to pay bi rubles for it. The length of each board can be increased any number of times (possibly, zero).

// Calculate the minimum number of rubles you have to spend to make the fence great again!

// You have to answer q independent queries.

// Input
// The first line contains one integer q (1≤q≤3⋅105) — the number of queries.

// The first line of each query contains one integers n (1≤n≤3⋅105) — the number of boards in the fence.

// The following n lines of each query contain the descriptions of the boards. The i-th line contains two integers ai and bi (1≤ai,bi≤109) — the length of the i-th board and the price for increasing it by 1, respectively.

// It is guaranteed that sum of all n over all queries not exceed 3⋅105.

// It is guaranteed that answer to each query will not exceed 1018.

// Output
// For each query print one integer — the minimum number of rubles you have to spend to make the fence great.
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
signed main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
        }
        vector<vector<int>>dp(n,vector<int>(3,infinity));
        for(int i=0;i<3;i++){
            dp[0][i]=i*b[i];
        }
        for(int i=1;i<n;i++){
            for(int curr=0;curr<3;curr++){
                for(int prev=0;prev<3;prev++){
                    if(a[i]+curr!=a[i-1]+prev){
                        dp[i][curr]=min(dp[i][curr],curr*b[i]+dp[i-1][prev]);
                    }
                }
            }
        }
        cout<<min({dp.back()[0],dp.back()[1],dp.back()[2]})<<endl;
    }
    return 0;
}