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
        Input(int,n);
        Input(string,s);
        vi pos;
        vi pb(n+1,0),pc(n+1,0);
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                pos.push_back(i+1);
            }
            pb[i+1]=pb[i]+(s[i]=='b');
            pc[i+1]=pc[i]+(s[i]=='c');
        }
        int ans=1e9;
        for(int i=0;i+2<pos.size();i++){
            int start=pos[i],end=pos[i+2];
            if(pb[end]-pb[start-1]<3 and pc[end]-pc[start-1]<3){
                ans=min(ans,end-start+1);
            }
        }
        for(int i=0;i+1<pos.size();i++){
            int start=pos[i],end=pos[i+1];
            if(pb[end]-pb[start-1]<2 and pc[end]-pc[start-1]<2){
                ans=min(ans,end-start+1);
            }
        }
        if(ans==1e9){
            cout<<-1<<endl;
        } else {
            cout<<ans<<endl;
        }
    }
    return 0;
}