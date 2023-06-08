// Programmers working on a large project have just received a task to write exactly m lines of code. There are n programmers working on a project, the i-th of them makes exactly ai bugs in every line of code that he writes.

// Let's call a sequence of non-negative integers v1, v2, ..., vn a plan, if v1 + v2 + ... + vn = m. The programmers follow the plan like that: in the beginning the first programmer writes the first v1 lines of the given task, then the second programmer writes v2 more lines of the given task, and so on. In the end, the last programmer writes the remaining lines of the code. Let's call a plan good, if all the written lines of the task contain at most b bugs in total.

// Your task is to determine how many distinct good plans are there. As the number of plans can be large, print the remainder of this number modulo given positive integer mod.

// Input
// The first line contains four integers n, m, b, mod (1 ≤ n, m ≤ 500, 0 ≤ b ≤ 500; 1 ≤ mod ≤ 109 + 7) — the number of programmers, the number of lines of code in the task, the maximum total number of bugs respectively and the modulo you should use when printing the answer.

// The next line contains n space-separated integers a1, a2, ..., an (0 ≤ ai ≤ 500) — the number of bugs per line for each programmer.

// Output
// Print a single integer — the answer to the problem modulo mod.
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
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
constexpr ll LONG_INFINITY=1e18+7;
constexpr int INT_INFINITY=1e9+10;
using namespace std;
int main(){
    ios;
    int n,m,b;
    cin>>n>>m>>b;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<vector<int>>>dp(2,vector<vector<int>>(m+1,vector<int>(b+1,0)));
    dp[0][0][0]=1;
    for(int it=1;it<=n;it++){
        int i=(it&1);
        for(int lines=0;lines<=m;lines++){
            for(int bugs=0;bugs<=b;bugs++){
                dp[i][lines][bugs]=dp[i^1][lines][bugs];
                if(lines>0 and bugs>=arr[it-1]){
                    dp[i][lines][bugs]+=dp[i][lines-1][bugs-arr[it-1]];
                }
            }
        }
    }
    int ans=0;
    for(int bugs=0;bugs<=b;bugs++){
        ans+=dp[n&1][m][bugs];
    }
    cout<<ans<<endl;
    return 0;
}