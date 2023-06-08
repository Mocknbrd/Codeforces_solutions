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
constexpr int infinity=1e9+7;
constexpr ll linf=1e18+7;template<typename tmp>
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
int main(){
    ios;
    int n,m;
    cin>>n>>m;
    vi edges(n+1,0),weaker(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        if(u>v){
            swap(u,v);
        }
        edges[u]++,edges[v]++;
        weaker[v]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=(edges[i]==weaker[i]);
    }
    int q;
    cin>>q;
    while(q--){
        int query;
        cin>>query;
        if(query==3){
            cout<<ans<<endl;
        } else {
            int u,v;
            cin>>u>>v;
            if(u>v){
                swap(u,v);
            }
            if(query==1){
                ans-=(edges[u]==weaker[u]);
                edges[u]++,edges[v]++;
                weaker[v]++;
            } else {
                edges[u]--,edges[v]--;
                weaker[v]--;
                ans+=(edges[u]==weaker[u]);
            }
        }
    }
    return 0;
}