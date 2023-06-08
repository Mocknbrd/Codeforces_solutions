// Parsa has a humongous tree on n vertices.

// On each vertex v he has written two integers lv and rv.

// To make Parsa's tree look even more majestic, Nima wants to assign a number av (lv≤av≤rv) to each vertex v such that the beauty of Parsa's tree is maximized.

// Nima's sense of the beauty is rather bizarre. He defines the beauty of the tree as the sum of |au−av| over all edges (u,v) of the tree.

// Since Parsa's tree is too large, Nima can't maximize its beauty on his own. Your task is to find the maximum possible beauty for Parsa's tree.

// Input
// The first line contains an integer t (1≤t≤250) — the number of test cases. The description of the test cases follows.

// The first line of each test case contains a single integer n (2≤n≤105) — the number of vertices in Parsa's tree.

// The i-th of the following n lines contains two integers li and ri (1≤li≤ri≤109).

// Each of the next n−1 lines contains two integers u and v (1≤u,v≤n,u≠v) meaning that there is an edge between the vertices u and v in Parsa's tree.

// It is guaranteed that the given graph is a tree.

// It is guaranteed that the sum of n over all test cases doesn't exceed 2⋅105.

// Output
// For each test case print the maximum possible beauty for Parsa's tree.
#include<bits/stdc++.h>
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define int long long
using namespace std;
vector<int>start,ending;
vector<bool>seen;
int dfs(vector<vector<int>>&tree,vector<vector<int>>&range);
void solve(vector<vector<int>>&tree,vector<vector<int>>&range,int &ans,int vertex);
signed main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<vector<int>>range(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>range[i][0]>>range[i][1];
        }
        vector<vector<int>>tree(n);
        for(int i=0;i<n-1;i++){
            int s,e;
            cin>>s>>e;
            tree[s].push_back(e);
            tree[e].push_back(s);
        }
        cout<<dfs(tree,range)<<endl;
    }
    return 0;
}
int dfs(vector<vector<int>>&tree,vector<vector<int>>&range){
    start=vector<int>(tree.size(),0);
    ending=start;
    seen=vector<bool>(tree.size(),false);
    int ans=0;
    solve(tree,range,ans,1);
    return ans;
}
void solve(vector<vector<int>>&tree,vector<vector<int>>&range,int &ans,int vertex){
    seen[vertex]=true;
    for(int &neighbour:tree[vertex]){
        if(!seen[neighbour]){
            solve(tree,range,ans,neighbour);
            start[vertex]+=max(start[neighbour]+abs(range[vertex][0]-range[neighbour][0]),ending[neighbour]+abs(range[vertex][0]-range[neighbour][1]));
            ending[vertex]+=max(start[neighbour]+abs(range[vertex][1]-range[neighbour][0]),ending[neighbour]+abs(range[vertex][1]-range[neighbour][1]));
        }
    }
    ans=max(start[vertex],ending[vertex]);
}