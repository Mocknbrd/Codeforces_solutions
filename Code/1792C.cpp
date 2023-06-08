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
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ll,ld>
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
#define pi 2*acos(0.0)
#define PQ priority_queue
template<typename A,typename B>
#define Input(A,x) A x; cin>>x
#define Init(B,x,value) B x; x=value
const int infinity=1e9+7;
const ll linf=1e18+7;
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
template<typename tmp>
inline void inputArray(vector<tmp>&arr){
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
}
template<typename tmp>
inline void inputMatrix(vector<vector<tmp>>&matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cin>>matrix[i][j];
        }
    }
}
class Node{
    public:
    int start,end,sum;
    Node*left,*right;
    Node(int start,int end,int sum){
        this->start=start;
        this->end=end;
        this->sum=sum;
        this->left=nullptr;
        this->right=nullptr;
    }
};
class SegmentTree{
    private:
    Node*root;
    Node*_build(vector<bool>&arr,int start,int end){
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
    int _query(Node*node,int start,int end){
        if(!node or start>node->end or end<node->start){
            return 0;
        } else if(node->start>=start and node->end<=end){
            return node->sum;
        } else {
            return this->_query(node->left,start,end)+this->_query(node->right,start,end);
        }
    }
    void _update(Node*node,int index,int value){
        if(!node or index<node->start or index>node->end){
            return;
        } else {
            if(node->start==node->end){
                node->sum=value;
            } else {
                this->_update(node->left,index,value);
                this->_update(node->right,index,value);
                node->sum=node->left->sum+node->right->sum;
            }
        }
    }
    public:
    SegmentTree(vector<bool>&arr){
        this->root=this->_build(arr,1,arr.size()-1);
    }
    int query(int start,int end){
        return this->_query(this->root,start,end);
    }
    void update(int index,int value){
        this->_update(this->root,index,value);
    }
};
int main(){
    ios;
    Input(int,t);
    while(t--){
        Input(int,n);
        vi arr(n);
        inputArray(arr);
        vi where(n+1,0);
        for(int i=0;i<arr.size();i++){
            where[arr[i]]=i+1;
        }
        vector<bool>left(n+1,false);
        for(int i=1;i+1<left.size();i++){
            left.back()=true;
            left[i]=(where[i]<where[i+1]);
        }
        SegmentTree tree(left);
        int ans=0,start=1,end=n;
        while(tree.query(start,end)!=end-start+1 and start<end){
            ans++;
            if(left[end-1]==0){
                left[end-1]=1;
                tree.update(end-1,1);
            }
            start++,end--;
        }
        cout<<ans<<endl;
    }
    return 0;
}