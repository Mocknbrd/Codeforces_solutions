#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode*left,*right;
    BinaryTreeNode(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
class SegTreeNode{
    public:
    int start,end,mini;
    SegTreeNode*left,*right;
    SegTreeNode(int start,int end,int mini){
        this->start=start;
        this->end=end;
        this->mini=mini;
        this->left=nullptr;
        this->right=nullptr;
    }
};
class BinaryTree{
    private:
    BinaryTreeNode*root;
    public:
    BinaryTree(vector<int>&arr){
        int index=1;
        this->root=new BinaryTreeNode(arr[0]);
        queue<BinaryTreeNode*>q;
        q.push(this->root);
        while(q.size()){
            BinaryTreeNode*curr=q.front();
            q.pop();
            if(index<arr.size() and arr[index]!=0){
                curr->left=new BinaryTreeNode(arr[index]);
                q.push(curr->left);
            }
            index++;
            if(index<arr.size() and arr[index]!=0){
                curr->right=new BinaryTreeNode(arr[index]);
                q.push(curr->right);
            }
            index++;
        }
    }
    map<int,int>nodeLevels(){
        map<int,int>ans;
        queue<BinaryTreeNode*>q;
        q.push(this->root);
        int level=0;
        while(q.size()){
            int n=q.size();
            for(int i=0;i<n;i++){
                BinaryTreeNode*curr=q.front();
                q.pop();
                if(!ans.count(curr->data)){
                    ans[curr->data]=level;
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            level++;
        }
        return ans;
    }
};
class SegTree{
    private:
    SegTreeNode*root;
    SegTreeNode*_build(vector<int>&nodeLevels,map<int,int>&nodeLevelMap,int start,int end){
        if(start==end){
            SegTreeNode*node=new SegTreeNode(start,end,nodeLevelMap[nodeLevels[start]]);
            return node;
        } else {
            int mid=(start+end)/2;
            SegTreeNode*left=this->_build(nodeLevels,nodeLevelMap,start,mid);
            SegTreeNode*right=this->_build(nodeLevels,nodeLevelMap,mid+1,end);
            SegTreeNode*node=new SegTreeNode(start,end,min(left->mini,right->mini));
            node->left=left;
            node->right=right;
            return node;
        }
    }
    int _query(SegTreeNode*node,int start,int end){
        if(!node or start>node->end or end<node->start){
            return 1e9;
        } else if(node->start>=start and node->end<=end){
            return node->mini;
        } else {
            return min(this->_query(node->left,start,end),this->_query(node->right,start,end));
        }
    }
    public:
    SegTree(vector<int>&nodeLevels,map<int,int>&nodeLevelMap){
        int n=nodeLevels.size();
        this->root=this->_build(nodeLevels,nodeLevelMap,0,n-1);
    }
    int query(int start,int end){
        return this->_query(this->root,start,end);
    }
};
int main(){
    vector<int>arr={2,4,7,6,8,5,4,9,8,0,0,0,3,0,0,0,0,4,2,7,1,0,0,0,0,0,0};
    BinaryTree binaryTree(arr);
    map<int,int>nodeLevelMap=binaryTree.nodeLevels();
    vector<int>sortedNodes;
    for(map<int,int>::iterator it=nodeLevelMap.begin();it!=nodeLevelMap.end();it++){
        sortedNodes.push_back(it->first);
    }
    SegTree segTree(sortedNodes,nodeLevelMap);
    int query=0;
    while(query!=-1){
        cout<<"Next query? ";
        cin>>query;
        if(query!=-1){
            cout<<"Enter the value: ";
            int value;
            cin>>value;
            int first=lower_bound(sortedNodes.begin(),sortedNodes.end(),value)-sortedNodes.begin();
            cout<<"The least level where a number greater than or equal to "<<value<<" occurs is: "<<segTree.query(first,sortedNodes.size()-1)<<endl;
        }
    }
    return 0;
}