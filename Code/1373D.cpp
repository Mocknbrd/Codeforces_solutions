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
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
#define pi 2*acos(0.0)
#define PQ priority_queue
#define range(i,start,end,step) for(int i=start;i<end;i+=step)
#define increment(i,start,end) range(i,start,end,1)
template<typename A,typename B>
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
const int infinity=1e9+7;
const ll linf=1e18+7;
const ll llzero=typecast<ll>(0);
int main(){
    ios;
    Input(int,t);
    while(t--){
        Input(int,n);
        vll arr(n);
        inputArray(arr);
        vector<vll>dp(n+1,vll(3,0));
        increment(i,0,n+1){
            if(i+1<=n){
                dp[i+1][0]=max(dp[i+1][0],dp[i][0]+(i%2==0)*arr[i]);
                dp[i+1][2]=max(dp[i+1][2],max({dp[i][0],dp[i][1],dp[i][2]})+(i%2==0)*arr[i]);
            }
            if(i+2<=n){
                dp[i+2][1]=max(dp[i+2][1],max({dp[i][0],dp[i][1]})+(i%2==0?arr[i+1]:arr[i]));
            }
        }
        cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<endl;
    }
    return 0;
}