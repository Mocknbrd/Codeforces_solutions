#include <bits/stdc++.h>
using namespace std;
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define YY cout<<"YES"<<endl
#define NN cout<<"NO"<<endl
#define yy cout<<"Yes"<<endl
#define nn cout<<"No"<<endl
#define endl "\n"
#define typecast static_cast
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ll,ld>
#define vpii vector<pii>
#define vpll vector<pll>
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
#define pi 2*acos(0.0)
#define PQ priority_queue
#define loop(it,init,condition,update) for(auto it=init;condition;update)
#define enumerate_subsets(submask,mask,equal) loop(submask,mask,(equal?submask>=0:submask>0),submask=(submask-1)&mask) 
#define range_look_ahead(i,start,buffer,step,end) loop(i,start,i+buffer<end,i+=step)
#define increment_look_ahead(i,start,buffer,end) range_look_ahead(i,start,buffer,1,end)
#define range(i,start,end,step) loop(i,start,(step>0?i<end:i>=end),i+=step)
#define increment(i,start,end) range(i,start,end,1)
#define decrement(i,start,end) range(i,start,end,-1)
#define for_each(element,container) for(auto &element:container)
#define sort(arr) sort(arr.begin(),arr.end())
#define rsort(arr) sort(arr.begin(),arr.end(),greater<auto>())
#define char_index(c,caps) caps?c-'A':c-'a'
#define Input(A,x) A x; cin>>x
#define Init(B,x,value) B x; x=value
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
template<typename tmp>
inline void inputArray(vector<tmp>&arr,int start=0){
    increment(i,start,arr.size()){
        cin>>arr[i];
    }
}
template<typename tmp>
inline void inputMatrix(vector<vector<tmp>>&matrix,int r=0,int c=0){
    increment(i,r,matrix.size()){
        increment(j,c,matrix[i].size()){
            cin>>matrix[i][j];
        }
    }
}
template<typename tmp> 
inline void printArray(vector<tmp>&arr){
    for_each(element,arr){
        cout<<element<<" ";
    }
    cout<<endl;
}
template<typename tmp>
inline void printMatrix(vector<vector<tmp>>&matrix){
    increment(i,0,matrix.size()){
        increment(j,0,matrix[i].size()){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
const int infinity=1e9+7;
const ll linf=1e18+7;
const ll llzero=typecast<ll>(0);
class Node{
    public:
    int start,end,sum,lazy;
    Node*left,*right;
    Node(int start,int end,int sum){
        this->start=start;
        this->end=end;
        this->sum=sum;
        this->lazy=0;
        this->left=nullptr;
        this->right=nullptr;
    }
};
class SegmentTree{
    private:
    Node*root;
    Node*_build(vector<int>&arr,int start,int end){
        if(start==end){
            Node*node=new Node(start,end,arr[start]);
            return node;
        } else {
            int mid=(start+end)>>1;
            Node*left=this->_build(arr,start,mid);
            Node*right=this->_build(arr,mid+1,end);
            Node*node=new Node(start,end,left->sum+right->sum);
            node->left=left;
            node->right=right;
            return node;
        }
    }
    void _update(Node*node,int start,int end,int change){
        if(!node or start>node->end or end<node->start){
            return;
        }
        if(node->lazy!=0){
            node->sum+=(node->end-node->start+1)*node->lazy;
            if(node->start!=node->end){
                node->left->lazy+=node->lazy;
                node->right->lazy+=node->lazy;
            }
            node->lazy=0;
        }
        if(node->start>=start and node->end<=end){
            node->sum+=(node->end-node->start+1)*change;
            if(node->start!=node->end){
                node->left->lazy+=change;
                node->right->lazy+=change;
            }
        } else {
            this->_update(node->left,start,end,change);
            this->_update(node->right,start,end,change);
            node->sum=node->left->sum+node->right->sum;
        }
    }
    int _query(Node*node,int start,int end){
        if(!node or start>node->end or end<node->start){
            return 0;
        } 
        if(node->lazy!=0){
            node->sum+=(node->end-node->start+1)*node->lazy;
            if(node->start!=node->end){
                node->left->lazy+=node->lazy;
                node->right->lazy+=node->lazy;
            }
            node->lazy=0;
        }
        if(node->start>=start and node->end<=end){
            return node->sum;
        } else {
            return this->_query(node->left,start,end)+this->_query(node->right,start,end);
        }
    }
    public:
    SegmentTree(vector<int>&arr){
        this->root=this->_build(arr,0,arr.size()-1);
    }
    void update(int start,int end,int change){
        this->_update(this->root,start,end,change);
    }
    int query(int start,int end){
        return this->_query(this->root,start,end);
    }
};
int main(){
    cout<<"Enter the number of elements in the array: ";
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SegmentTree tree(arr);
    cout<<"Enter 1 for range update and 2 for range sum"<<endl;
    int op=1;
    while(op!=0){
        cout<<"Do you want to perform an operation: ";
        cin>>op;
        if(op!=0){
            cout<<"Enter the starting index and the ending index: ";
            int start,end;
            cin>>start>>end;
            switch(op){
                case 1: {
                    cout<<"Enter the increment/decrement: ";
                    int change;
                    cin>>change;
                    tree.update(start,end,change);
                    cout<<"The change was successful"<<endl;
                } break;
                case 2: {
                    cout<<"The range sum is: "<<tree.query(start,end)<<endl;
                } break;
                default: cout<<"Incorrect opcode entered"<<endl;
                    break;
            }
        }
        for(int i=0;i<100;i++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}