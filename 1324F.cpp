// You are given a tree consisting of n vertices. A tree is a connected undirected graph with n−1 edges. Each vertex v of this tree has a color assigned to it (av=1 if the vertex v is white and 0 if the vertex v is black).

// You have to solve the following problem for each vertex v: what is the maximum difference between the number of white and the number of black vertices you can obtain if you choose some subtree of the given tree that contains the vertex v? The subtree of the tree is the connected subgraph of the given tree. More formally, if you choose the subtree that contains cntw white vertices and cntb black vertices, you have to maximize cntw−cntb.

// Input
// The first line of the input contains one integer n (2≤n≤2⋅105) — the number of vertices in the tree.

// The second line of the input contains n integers a1,a2,…,an (0≤ai≤1), where ai is the color of the i-th vertex.

// Each of the next n−1 lines describes an edge of the tree. Edge i is denoted by two integers ui and vi, the labels of vertices it connects (1≤ui,vi≤n,ui≠vi).

// It is guaranteed that the given edges form a tree.

// Output
// Print n integers res1,res2,…,resn, where resi is the maximum possible difference between the number of white and black vertices in some subtree that contains the vertex i.
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
vector<int>mem;
void dfs(vector<vector<int>>&tree,vector<int>&color,int vertex,int parent);
void backtrack(vector<vector<int>>&tree,vector<int>&ans,int vertex,int parent);
int main(){
    ios;
    int n;
    cin>>n;
    vector<int>color(n);
    for(int i=0;i<n;i++){
        cin>>color[i];
        color[i]=(color[i]==0)?-1:1;
    }
    vector<vector<int>>tree(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    mem=vector<int>(n,0);
    dfs(tree,color,0,-1);
    vector<int>ans(n);
    backtrack(tree,ans,0,-1);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
void dfs(vector<vector<int>>&tree,vector<int>&color,int vertex,int parent){
    mem[vertex]=color[vertex];
    for(int &neighbour:tree[vertex]){
        if(neighbour!=parent){
            dfs(tree,color,neighbour,vertex);
            mem[vertex]+=max(0,mem[neighbour]);
        }
    }
}
void backtrack(vector<vector<int>>&tree,vector<int>&ans,int vertex,int parent){
    ans[vertex]=mem[vertex];
    for(int &neighbour:tree[vertex]){
        if(neighbour!=parent){
            mem[vertex]-=max(0,mem[neighbour]);
            mem[neighbour]+=max(0,mem[vertex]);
            backtrack(tree,ans,neighbour,vertex);
            mem[neighbour]-=max(0,mem[vertex]);
            mem[vertex]+=max(0,mem[neighbour]);
        }
    }
}