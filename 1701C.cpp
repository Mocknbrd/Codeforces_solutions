#include <bits/stdc++.h>
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
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
#define pi 2*acos(0.0)
constexpr int infinity=1e9+7;
constexpr ll linf=1e18+7;
using namespace std;
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
int main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>cnt(n+1,0);
        for(int i=0;i<m;i++){
            int worker;
            cin>>worker;
            cnt[worker]++;
        }
        int ans=2*m,start=0,end=ans;
        while(start<=end){
            int mid=(start+end)/2;
            ll left=0,extra=0;
            for(int worker=1;worker<=n;worker++){
                int tasks=min(mid,cnt[worker]);
                left+=cnt[worker]-tasks;
                extra+=(mid-tasks)/2;
            }
            if(extra>=left){
                ans=mid;
                end=mid-1;
            } else {
                start=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}