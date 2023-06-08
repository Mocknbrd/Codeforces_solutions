// Each New Year Timofey and his friends cut down a tree of n vertices and bring it home. After that they paint all the n its vertices, so that the i-th vertex gets color ci.

// Now it's time for Timofey birthday, and his mother asked him to remove the tree. Timofey removes the tree in the following way: he takes some vertex in hands, while all the other vertices move down so that the tree becomes rooted at the chosen vertex. After that Timofey brings the tree to a trash can.

// Timofey doesn't like it when many colors are mixing together. A subtree annoys him if there are vertices of different color in it. Timofey wants to find a vertex which he should take in hands so that there are no subtrees that annoy him. He doesn't consider the whole tree as a subtree since he can't see the color of the root vertex.

// A subtree of some vertex is a subgraph containing that vertex and all its descendants.

// Your task is to determine if there is a vertex, taking which in hands Timofey wouldn't be annoyed.

// Input
// The first line contains single integer n (2 ≤ n ≤ 105) — the number of vertices in the tree.

// Each of the next n - 1 lines contains two integers u and v (1 ≤ u, v ≤ n, u ≠ v), denoting there is an edge between vertices u and v. It is guaranteed that the given graph is a tree.

// The next line contains n integers c1, c2, ..., cn (1 ≤ ci ≤ 105), denoting the colors of the vertices.

// Output
// Print "NO" in a single line, if Timofey can't take the tree in such a way that it doesn't annoy him.

// Otherwise print "YES" in the first line. In the second line print the index of the vertex which Timofey should take in hands. If there are multiple answers, print any of them.
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
bool canBeRoot(vector<vector<int>>&tree,vector<int>&color,int root);
bool isSameColorSubTree(vector<vector<int>>&tree,vector<int>&color,int vertex,int parent);
signed main(){
    ios;
    int n;
    cin>>n;
    vector<vector<int>>tree(n),edges;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        edges.push_back({u,v});
    }
    vector<int>color(n);
    for(int i=0;i<color.size();i++){
        cin>>color[i];
    }
    int vertex=0;
    for(vector<int>&edge:edges){
        if(color[edge[0]]!=color[edge[1]]){
            if(canBeRoot(tree,color,edge[0])){
                vertex=edge[0];
            } else if(canBeRoot(tree,color,edge[1])){
                vertex=edge[1];
            } else {
                vertex=-1;
            }
            break;
        }
    }
    if(vertex!=-1){
        YY;
        cout<<vertex<<endl;
    } else {
        NN;
    }
    return 0;
}
bool canBeRoot(vector<vector<int>>&tree,vector<int>&color,int root){
    bool ans=true;
    for(int &neighbour:tree[root]){
        ans=(ans and isSameColorSubTree(tree,color,neighbour,root));
    }
    return ans;
}
bool isSameColorSubTree(vector<vector<int>>&tree,vector<int>&color,int vertex,int parent){
    bool ans=true;
    for(int &neighbour:tree[vertex]){
        if(neighbour!=parent){
            ans=(ans and color[neighbour]==color[vertex] and isSameColorSubTree(tree,color,neighbour,vertex));
        }
    }
    return ans;
}