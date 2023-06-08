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
#define sort(arr) sort(arr.begin(),arr.end())
#define rsort(tmp,arr) sort(arr.begin(),arr.end(),greater<tmp>())
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
    int n,k;
    cin>>n>>k;
    vi alice,bob,both;
    int ans=0;
    increment(i,0,n){
        int t,a,b;
        cin>>t>>a>>b;
        if(a and b){
            both.push_back(t);
        } else if(a){
            alice.push_back(t);
        } else if(b){
            bob.push_back(t);
        }
        ans+=t;
    }
    if(alice.size()+both.size()<k or bob.size()+both.size()<k){
        cout<<-1<<endl;
    } else {
        sort(alice); sort(bob); sort(both);
        alice.insert(alice.begin(),0),bob.insert(bob.begin(),0),both.insert(both.begin(),0);
        increment(i,1,alice.size()){
            alice[i]+=alice[i-1];
        }
        increment(i,1,bob.size()){
            bob[i]+=bob[i-1];
        }
        increment(i,1,both.size()){
            both[i]+=both[i-1];
        }
        increment(cnt,0,both.size()){
            if(k-cnt<alice.size() and k-cnt<bob.size()){
                int time=both[cnt]+alice[k-cnt]+bob[k-cnt];
                ans=min(ans,time);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}