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
inline void inputArray(vector<tmp>&arr,int start=0){
    for(int i=start;i<arr.size();i++){
        cin>>arr[i];
    }
}
template<typename tmp>
inline void inputMatrix(vector<vector<tmp>>&matrix,int r=0,int c=0){
    for(int i=r;i<matrix.size();i++){
        for(int j=c;j<matrix[i].size();j++){
            cin>>matrix[i][j];
        }
    }
}
int main(){
    ios;
    Input(int,t);
    while(t--){
        int n,m,x;
        cin>>n>>m>>x;
        vi height(n);
        inputArray(height);
        PQ<pii,vector<pii>,greater<pii>>pq;
        for(int i=1;i<=m;i++){
            pq.push({0,i});
        }
        YY;
        for(int i=0;i<n;i++){
            pii curr=pq.top(); pq.pop();
            curr.first+=height[i];
            cout<<curr.second<<" ";
            pq.push(curr);
        }
        cout<<endl;
    }
    return 0;
}