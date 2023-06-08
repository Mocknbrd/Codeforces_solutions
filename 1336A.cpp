// Writing light novels is the most important thing in Linova's life. Last night, Linova dreamed about a fantastic kingdom. She began to write a light novel for the kingdom as soon as she woke up, and of course, she is the queen of it.


 
// There are n cities and n−1 two-way roads connecting pairs of cities in the kingdom. From any city, you can reach any other city by walking through some roads. The cities are numbered from 1 to n, and the city 1 is the capital of the kingdom. So, the kingdom has a tree structure.

// As the queen, Linova plans to choose exactly k cities developing industry, while the other cities will develop tourism. The capital also can be either industrial or tourism city.

// A meeting is held in the capital once a year. To attend the meeting, each industry city sends an envoy. All envoys will follow the shortest path from the departure city to the capital (which is unique).

// Traveling in tourism cities is pleasant. For each envoy, his happiness is equal to the number of tourism cities on his path.

// In order to be a queen loved by people, Linova wants to choose k cities which can maximize the sum of happinesses of all envoys. Can you calculate the maximum sum for her?

// Input
// The first line contains two integers n and k (2≤n≤2⋅105, 1≤k<n)  — the number of cities and industry cities respectively.

// Each of the next n−1 lines contains two integers u and v (1≤u,v≤n), denoting there is a road connecting city u and city v.

// It is guaranteed that from any city, you can reach any other city by the roads.

// Output
// Print the only line containing a single integer  — the maximum possible sum of happinesses of all envoys.
#include<bits/stdc++.h>
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define int long long
using namespace std;
unordered_map<int,int>subtree,depth;
void dfs(vector<vector<int>>&tree,vector<bool>&seen,int vertex);
void bfs(vector<vector<int>>&tree);
signed main(){
    ios;
    int n,k;
    cin>>n>>k;
    vector<vector<int>>tree(n);
    for(int i=0;i<n-1;i++){
        int s,e;
        cin>>s>>e;
        tree[s].push_back(e);
        tree[e].push_back(s);
    }
    vector<bool>seen(n,false);
    dfs(tree,seen,0);
    bfs(tree);
    vector<int>cost;
    for(int i=0;i<n;i++){
        cost.push_back(depth[i]-subtree[i]+1);
    }
    sort(cost.begin(),cost.end(),greater<int>());
    int ans=0;
    for(int i=0;i<k;i++){
        ans+=cost[i];
    }
    cout<<ans<<endl;
    return 0;
}
void dfs(vector<vector<int>>&tree,vector<bool>&seen,int vertex){
    seen[vertex]=true;
    subtree[vertex]=1;
    for(int neighbour:tree[vertex]){
        if(!seen[neighbour]){
            dfs(tree,seen,neighbour);
            subtree[vertex]+=subtree[neighbour];
        }
    }
}
void bfs(vector<vector<int>>&tree){
    int level=0;
    queue<int>q;
    vector<bool>seen(tree.size(),false);
    q.push(0);
    while(q.size()){
        int n=q.size();
        for(int i=0;i<n;i++){
            int curr=q.front();
            q.pop();
            seen[curr]=true;
            depth[curr]=level;
            for(int neighbour:tree[curr]){
                if(!seen[neighbour]){
                    seen[neighbour]=true;
                    q.push(neighbour);
                }
            }
        }
    }
}