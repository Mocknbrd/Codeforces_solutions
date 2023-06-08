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
        Input(int,n); Input(int,m);
        vector<vi>perm(n,vi(m+1,0));
        inputMatrix(perm,0,1);
        vector<vi>where(n,vi(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++){
                where[i][perm[i][j]]=j;
            }
        }
        set<vi>present;
        for(int i=0;i<n;i++){
            vi tmp(m+1,0);
            for(int j=1;j<=m;j++){
                tmp[where[i][j]]=j;
                present.insert(tmp);
            }
        }
        for(int i=0;i<n;i++){
            vi tmp(m+1,0);
            int ans=0;
            for(int j=1;j<=m;j++){
                tmp[perm[i][j]]=j;
                if(present.count(tmp)){
                    ans++;
                } else {
                    break;
                }
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}