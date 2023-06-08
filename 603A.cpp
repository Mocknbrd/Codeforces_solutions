// Kevin has just recevied his disappointing results on the USA Identification of Cows Olympiad (USAICO) in the form of a binary string of length n. Each character of Kevin's string represents Kevin's score on one of the n questions of the olympiad—'1' for a correctly identified cow and '0' otherwise.

// However, all is not lost. Kevin is a big proponent of alternative thinking and believes that his score, instead of being the sum of his points, should be the length of the longest alternating subsequence of his string. Here, we define an alternating subsequence of a string as a not-necessarily contiguous subsequence where no two consecutive elements are equal. For example, {0, 1, 0, 1}, {1, 0, 1}, and {1, 0, 1, 0} are alternating sequences, while {1, 0, 0} and {0, 1, 0, 1, 1} are not.

// Kevin, being the sneaky little puffball that he is, is willing to hack into the USAICO databases to improve his score. In order to be subtle, he decides that he will flip exactly one substring—that is, take a contiguous non-empty substring of his score and change all '0's in that substring to '1's and vice versa. After such an operation, Kevin wants to know the length of the longest possible alternating subsequence that his string could have.

// Input
// The first line contains the number of questions on the olympiad n (1 ≤ n ≤ 100 000).

// The following line contains a binary string of length n representing Kevin's results on the USAICO.

// Output
// Output a single integer, the length of the longest possible alternating subsequence that Kevin can create in his string after flipping a single substring.
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
int findLAS(string &s);
signed main(){
    ios;
    int n;
    cin>>n;
    string s;
    cin>>s;
    int las=findLAS(s);
    int ans=las+(las<=n-1)+(las<=n-2);
    cout<<ans<<endl;
    return 0;
}
int findLAS(string &s){
    vector<vector<int>>dp(s.size(),vector<int>(2,0));
    dp[0][s[0]-'0']=1;
    for(int i=1;i<dp.size();i++){
        int digit=s[i]-'0';
        dp[i][digit]=1+dp[i-1][digit^1];
        dp[i][digit^1]=dp[i-1][digit^1];
    }
    return max(dp.back()[0],dp.back()[1]);
}