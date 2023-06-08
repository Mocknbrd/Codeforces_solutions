// You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.
// The kth ancestor of a tree node is the kth node in the path from that node to the root node.
// Implement the TreeAncestor class:
// TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the tree and the parent array.
// int getKthAncestor(int node, int k) return the kth ancestor of the given node node. If there is no such ancestor, return -1.
#include <iostream>
#include <vector>
#include<cmath>
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
class TreeAncestor{
    private:
    vector<vector<int>>mem;
    public:
    TreeAncestor(int n,vector<int>&parents){
        mem=vector<vector<int>>(n,vector<int>(log2(n)+1,-1));
        for(int i=0;i<n;i++){
            mem[i][0]=parents[i];
        }
        for(int power=1;power<=log2(n);power++){
            for(int node=0;node<n;node++){
                int mid=mem[node][power-1];
                if(mid!=-1){
                    mem[node][power]=mem[mid][power-1];
                }
            }
        }
    }
    int getKthAncestor(int node,int k){
        while(node!=-1 and k){
            int pos=log2(k&(-k));
            k-=k&(-k);
            node=mem[node][pos];
        }
        return node;
    }
};