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
        int n,q;
        cin>>n>>q;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int index=0;
        map<int,vector<int>>winner;
        for(int round=1;round<n;round++){
            index=(arr[index]>arr[round]?index:round);
            winner[index].push_back(round);
        }
        for(int i=0;i<q;i++){
            int idx,k;
            cin>>idx>>k;
            idx--;
            int ans=upper_bound(winner[idx].begin(),winner[idx].end(),k)-winner[idx].begin();
            if(k>=n and arr[idx]==n){
                ans+=k-n+1;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}