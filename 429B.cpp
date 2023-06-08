// Summer is coming! It's time for Iahub and Iahubina to work out, as they both want to look hot at the beach. The gym where they go is a matrix a with n lines and m columns. Let number a[i][j] represents the calories burned by performing workout at the cell of gym in the i-th line and the j-th column.

// Iahub starts with workout located at line 1 and column 1. He needs to finish with workout a[n][m]. After finishing workout a[i][j], he can go to workout a[i + 1][j] or a[i][j + 1]. Similarly, Iahubina starts with workout a[n][1] and she needs to finish with workout a[1][m]. After finishing workout from cell a[i][j], she goes to either a[i][j + 1] or a[i - 1][j].

// There is one additional condition for their training. They have to meet in exactly one cell of gym. At that cell, none of them will work out. They will talk about fast exponentiation (pretty odd small talk) and then both of them will move to the next workout.

// If a workout was done by either Iahub or Iahubina, it counts as total gain. Please plan a workout for Iahub and Iahubina such as total gain to be as big as possible. Note, that Iahub and Iahubina can perform workouts with different speed, so the number of cells that they use to reach meet cell may differs.

// Input
// The first line of the input contains two integers n and m (3 ≤ n, m ≤ 1000). Each of the next n lines contains m integers: j-th number from i-th line denotes element a[i][j] (0 ≤ a[i][j] ≤ 105).

// Output
// The output contains a single number — the maximum total gain possible.
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
signed main(){
    ios;
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>>dp1(n,vector<int>(m,0));
    vector<vector<int>>dp2=dp1,dp3=dp1,dp4=dp1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int top=(i>0?dp1[i-1][j]:0);
            int left=(j>0?dp1[i][j-1]:0);
            dp1[i][j]=matrix[i][j]+max(top,left);
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            int left=(j>0?dp2[i][j-1]:0);
            int bottom=(i+1<n?dp2[i+1][j]:0);
            dp2[i][j]=matrix[i][j]+max(left,bottom);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=m-1;j>=0;j--){
            int top=(i>0?dp3[i-1][j]:0);
            int right=(j+1<m?dp3[i][j+1]:0);
            dp3[i][j]=matrix[i][j]+max(top,right);
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int bottom=(i+1<n?dp4[i+1][j]:0);
            int right=(j+1<m?dp4[i][j+1]:0);
            dp4[i][j]=matrix[i][j]+max(bottom,right);
        }
    }
    int ans=0;
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            int first=dp1[i-1][j]+dp4[i+1][j]+dp2[i][j-1]+dp3[i][j+1];
            int second=dp1[i][j-1]+dp4[i][j+1]+dp2[i+1][j]+dp3[i+1][j];
            ans=max({ans,first,second});
        }
    }
    cout<<ans<<endl;
    return 0;
}