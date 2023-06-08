// Vasya is preparing a contest, and now he has written a statement for an easy problem. The statement is a string of length n consisting of lowercase Latin latters. Vasya thinks that the statement can be considered hard if it contains a subsequence hard; otherwise the statement is easy. For example, hard, hzazrzd, haaaaard can be considered hard statements, while har, hart and drah are easy statements.

// Vasya doesn't want the statement to be hard. He may remove some characters from the statement in order to make it easy. But, of course, some parts of the statement can be crucial to understanding. Initially the ambiguity of the statement is 0, and removing i-th character increases the ambiguity by ai (the index of each character is considered as it was in the original statement, so, for example, if you delete character r from hard, and then character d, the index of d is still 4 even though you delete it from the string had).

// Vasya wants to calculate the minimum ambiguity of the statement, if he removes some characters (possibly zero) so that the statement is easy. Help him to do it!

// Recall that subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.

// Input
// The first line contains one integer n (1≤n≤105) — the length of the statement.

// The second line contains one string s of length n, consisting of lowercase Latin letters — the statement written by Vasya.

// The third line contains n integers a1,a2,…,an (1≤ai≤998244353).

// Output
// Print minimum possible ambiguity of the statement after Vasya deletes some (possibly zero) characters so the resulting statement is easy.
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    string hard="hard";
    vector<vector<int>>dp(s.size()+1,vector<int>(5,infinity));
    dp[0][0]=0;
    vector<int>arr(n);
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    for(int i=0;i<s.size();i++){
        for(int j=0;j<5;j++){
            if(s[i]!=hard[j]){
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            } else {
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
                dp[i+1][j]=min(dp[i+1][j],arr[i]+dp[i][j]);
            }
        }
    }
    cout<<*min_element(dp[n].begin(),dp[n].begin()+4)<<endl;
    return 0;
}