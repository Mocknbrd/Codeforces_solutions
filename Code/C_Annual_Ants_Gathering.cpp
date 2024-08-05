#include <bits/stdc++.h>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc++11-extensions"
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void testcase();
int dfs(vector<vector<int> > &tree,int vertex,int parent);
int main(){
    ios;
    testcase();
    return 0;
}
void findSubTreeSize(vector<vector<int> >&tree,vector<int> &subtree,vector<int> &centroids,int vertex,int parent);
void testcase(){
    int n;
    cin >> n;
    vector<vector<int> >tree(n + 1);
    vector<int> degree(tree.size(),0);
    for(int _ = 0; _ < n - 1; _++){
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    if(n == 1){
        cout << "YES" << endl;
    } else {
        vector<int> centroids,subtree(n + 1,0);
        findSubTreeSize(tree,subtree,centroids,1,0);
        for(int start: centroids){
            if(dfs(tree,start,0) != (int)2e9){
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
    }
    return;
}
int dfs(vector<vector<int> >&tree,int vertex,int parent){
    int ans = 1;
    priority_queue<int,vector<int>,greater<int> >pq;
    for(int child: tree[vertex]){
        if(child != parent){
            int childAns = dfs(tree,child,vertex);
            if(childAns == (int)2e9){
                return (int)2e9;
            }
            pq.push(childAns);
        }
    }
    while(pq.empty() == false){
        if(ans < pq.top()){
            return (int)2e9;
        }
        ans += pq.top();
        pq.pop();
    }
    return ans;
}
void findSubTreeSize(vector<vector<int> >&tree,vector<int> &subtree,vector<int> &centroids,int vertex,int parent){
    subtree[vertex] = 1;
    bool isCentroid = true;
    int n = tree.size() - 1;
    for(int child: tree[vertex]){
        if(child != parent){
            findSubTreeSize(tree,subtree,centroids,child,vertex);
            subtree[vertex] += subtree[child];
            if(subtree[child] * 2 > n){
                isCentroid = false;
            }
        }
    }
    if((n - subtree[vertex]) * 2 > n){
        isCentroid = false;
    }
    if(isCentroid == true){
        centroids.push_back(vertex);
    }
}
#pragma GCC diagnostic pop