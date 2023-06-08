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
class DSU{
    private:
    vi rank,parent;
    void _merge(int smaller,int larger){
        this->parent[smaller]=larger;
        this->rank[larger]+=this->rank[smaller];
    }
    int _findParent(int x){
        if(x==this->parent[x]){
            return x;
        } else {
            return this->parent[x]=this->_findParent(this->parent[x]);
        }
    }
    bool _findUnion(int x,int y){
        int parx=this->_findParent(x);
        int pary=this->_findParent(y);
        if(parx!=pary){
            int larger=(this->rank[parx]>=this->rank[pary])?parx:pary;
            int smaller=(larger==parx)?pary:parx;
            this->_merge(smaller,larger);
            return false;
        } else {
            return true;
        }
    }
    public:
    DSU(int n){
        this->parent=vi(n);
        this->rank=vi(n,1);
        for(int i=0;i<n;i++){
            this->parent[i]=i;
        }
    }
    bool isCycle(int x,int y){
        return this->_findUnion(x,y);
    }
};
vector<vi>findMST(vector<vi>&edges,int n);
void simulatedAnnealing(vector<vi>start,vector<vi>&weights);
int main(){
    cout<<"Enter the number of vertices: ";
    Input(int,n);
    vector<vi>graph(n,vi(n,0));
    cout<<"Enter the number of edges in the graph: ";
    Input(int,m);
    cout<<"Enter the edges:-"<<endl;
    vector<vi>edges;
    for(int i=0;i<m;i++){
        cout<<"Enter the edge: ";
        int u,v,weight;
        cin>>u>>v>>weight;
        if(u>v){
            swap(u,v);
        }
        graph[u][v]=weight;
        graph[v][u]=weight;
        edges.push_back({weight,u,v});
    }
    vector<vi>mst=findMST(edges,n);
    simulatedAnnealing(mst,graph);
    return 0;
}
vector<vi>findMST(vector<vi>&edges,int n){
    PQ<vi,vector<vi>,greater<vi>>pq;
    for(vi &edge:edges){
        pq.push(edge);
    }
    DSU dsu(n);
    vector<vi>ans(n,vi(n,0));
    int cnt=0;
    while(cnt!=n-1){
        vi edge=pq.top(); pq.pop();
        if(!dsu.isCycle(edge[1],edge[2])){
            ans[edge[1]][edge[2]]=edge[0];
            ans[edge[2]][edge[1]]=edge[0];
            cnt++;
        }
    }
    return ans;
}
void simulatedAnnealing(vector<vi>start,vector<vi>&weights){
    return;
    cout<<"Enter the number of iterations: ";
    Input(int,iterations);
    cout<<"Enter the steps per iteration: ";
    Input(int,steps);
    int sum=0;
    for(int i=0;i<start.size();i++){
        for(int j=0;j<start[i].size();j++){
            sum+=start[i][j];
        }
    }
    for(int i=0;i<start.size();i++){
        if(!start[0][i]){
            start[0][i]=start[i][0]=weights[i][0];
            sum+=weights[i][0];
            break;
        }
    }
    for(int iteration=0;iteration<iterations;iteration++){
        
    }
}