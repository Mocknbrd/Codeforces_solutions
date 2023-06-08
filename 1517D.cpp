// You are wandering in the explorer space of the 2050 Conference.

// The explorer space can be viewed as an undirected weighted grid graph with size n×m. The set of vertices is {(i,j)|1≤i≤n,1≤j≤m}. Two vertices (i1,j1) and (i2,j2) are connected by an edge if and only if |i1−i2|+|j1−j2|=1.

// At each step, you can walk to any vertex connected by an edge with your current vertex. On each edge, there are some number of exhibits. Since you already know all the exhibits, whenever you go through an edge containing x exhibits, your boredness increases by x.

// For each starting vertex (i,j), please answer the following question: What is the minimum possible boredness if you walk from (i,j) and go back to it after exactly k steps?

// You can use any edge for multiple times but the boredness on those edges are also counted for multiple times. At each step, you cannot stay on your current vertex. You also cannot change direction while going through an edge. Before going back to your starting vertex (i,j) after k steps, you can visit (i,j) (or not) freely.

// Input
// The first line contains three integers n, m and k (2≤n,m≤500,1≤k≤20).

// The j-th number (1≤j≤m−1) in the i-th line of the following n lines is the number of exibits on the edge between vertex (i,j) and vertex (i,j+1).

// The j-th number (1≤j≤m) in the i-th line of the following n−1 lines is the number of exibits on the edge between vertex (i,j) and vertex (i+1,j).

// The number of exhibits on each edge is an integer between 1 and 106.

// Output
// Output n lines with m numbers each. The j-th number in the i-th line, answerij, should be the minimum possible boredness if you walk from (i,j) and go back to it after exactly k steps.

// If you cannot go back to vertex (i,j) after exactly k steps, answerij should be −1.
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
constexpr int LONG_INFINITY=1e18+7;
using namespace std;
int mem[501][501][21];
int solve(vector<vector<int>>&row,vector<vector<int>>&col,int r,int c,int steps);
signed main(){
    ios;
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>col(n,vector<int>(m-1,1)),row(n-1,vector<int>(m,1));
    for(int i=0;i<col.size();i++){
        for(int j=0;j<col[i].size();j++){
            cin>>col[i][j];
        }
    }
    for(int i=0;i<row.size();i++){
        for(int j=0;j<row[i].size();j++){
            cin>>row[i][j];
        }
    }
    memset(mem,-1,sizeof(mem));
    vector<vector<int>>ans(n,vector<int>(m,-1));
    if(k%2==0){
        for(int r=0;r<ans.size();r++){
            for(int c=0;c<ans[r].size();c++){
                ans[r][c]=2*solve(row,col,r,c,k/2);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
int solve(vector<vector<int>>&row,vector<vector<int>>&col,int r,int c,int steps){
    int n=col.size(),m=row[0].size();
    if(mem[r][c][steps]!=-1){
        return mem[r][c][steps];
    } else if(steps==0){
        return 0;
    } else {
        int ans=LONG_INFINITY;
        if(r+1<n){
            ans=min(ans,row[r][c]+solve(row,col,r+1,c,steps-1));
        }
        if(r-1>=0){
            ans=min(ans,row[r-1][c]+solve(row,col,r-1,c,steps-1));
        }
        if(c+1<m){
            ans=min(ans,col[r][c]+solve(row,col,r,c+1,steps-1));
        }
        if(c-1>=0){
            ans=min(ans,col[r][c-1]+solve(row,col,r,c-1,steps-1));
        }
        return mem[r][c][steps]=ans;
    }
}