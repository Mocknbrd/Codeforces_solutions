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
#define cd complex<double>
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
#define range_look_ahead(i,start,end,step,buffer) loop(i,start,i+buffer<end,i+=step)
#define increment_look_ahead(i,start,end,buffer) range_look_ahead(i,start,end,1,buffer)
#define range(i,start,end,step) loop(i,start,(step>0?i<end:i>=end),i+=step)
#define increment(i,start,end) range(i,start,end,1)
#define decrement(i,start,end) range(i,start,end,-1)
#define for_each(element,container) for(auto &element:container)
#define iterate_forward(it,container) for(auto it=container.begin();it!=container.end();it++)
#define iterate_reverse(it,container) for(auto it=container.rbegin();it!=container.rend();it++)
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
void findHeight(map<int,vi>&tree,vi &height,int vertex,int parent);
int findDiameter(map<int,vi>&tree,vi &height,vi &dp,int vertex,int parent);
int main(){
    ios;
    int n,m;
    cin>>n>>m;
    map<int,vi>tree;
    vi height(n+1,0),dp(n+1,-1);
    increment(i,0,m){
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    findHeight(tree,height,1,0);
    cout<<findDiameter(tree,height,dp,1,0)<<endl;
    return 0;
}
void findHeight(map<int,vi>&tree,vi &height,int vertex,int parent){
    height[vertex]=0;
    for_each(neighbour,tree[vertex]){
        if(neighbour!=parent){
            findHeight(tree,height,neighbour,vertex);
            height[vertex]=max(height[vertex],1+height[neighbour]);
        }
    }
}
int findDiameter(map<int,vi>&tree,vi &height,vi &dp,int vertex,int parent){
    if(dp[vertex]!=-1){
        return dp[vertex];
    } else {
        int diameter=height[vertex];
        for_each(first,tree[vertex]){
            int newDiameter=0;
            if(first!=parent){
                newDiameter+=1+height[first];
                diameter=max(diameter,newDiameter);
                for_each(second,tree[vertex]){
                    if(second!=parent and second!=first){
                        newDiameter+=1+height[second];
                        diameter=max(diameter,newDiameter);
                        diameter=max(diameter,findDiameter(tree,height,dp,second,vertex));
                        newDiameter-=1+height[second];
                    }
                }
                diameter=max(diameter,findDiameter(tree,height,dp,first,vertex));
            }
        }
        return dp[vertex]=diameter;
    }
}