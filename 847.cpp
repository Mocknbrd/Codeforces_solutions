// You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.

// Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int minCost(vector<vector<int>>&graph);
int main(){
    ios;
    int n;
    cin>>n;
    vector<vector<int>>graph(n);
    for(int i=0;i<n;i++){
        int ne;
        cin>>ne;
        graph[i]=vector<int>(ne,1);
        for(int j=0;j<ne;j++){
            cin>>graph[i][j];
        }
    }
    cout<<minCost(graph)<<endl;
    return 0;
}
int minCost(vector<vector<int>>&graph){
    int n=graph.size();
    vector<vector<bool>>seen(n,vector<bool>(1<<n,false));
    queue<pair<int,pair<int,int>>>q;
    for(int i=0;i<n;i++){
        q.push(make_pair(i,make_pair(1<<i,0)));
        seen[i][1<<i]=true;
    }
    while(q.size()){
        pair<int,pair<int,int>>curr=q.front();
        q.pop();
        int vertex=curr.first;
        int mask=curr.second.first;
        int cost=curr.second.second;
        for(int neighbour:graph[vertex]){
            int nmask=mask|(1<<neighbour);
            if(!seen[neighbour][nmask]){
                if(nmask==(1<<n)-1){
                    return cost+1;
                } else {
                    q.push(make_pair(neighbour,make_pair(nmask,cost+1)));
                }
                seen[neighbour][nmask]=true;
            }
        }
    }
    return 0;
}