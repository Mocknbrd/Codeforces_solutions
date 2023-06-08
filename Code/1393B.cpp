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
    int n;
    cin>>n;
    vi arr(1e5+1,0);
    for(int i=0;i<n;i++){
        int plank;
        cin>>plank;
        arr[plank]++;
    }
    ll cnt2=0,cnt4=0;
    for(int i=0;i<arr.size();i++){
        cnt2+=arr[i]/2;
        cnt4+=arr[i]/4;
    }
    int q;
    cin>>q;
    while(q--){
        char sign;
        int plank;
        cin>>sign>>plank;
        cnt2-=arr[plank]/2;
        cnt4-=arr[plank]/4;
        if(sign=='+'){
            arr[plank]++;
        } else {
            arr[plank]--;
        }
        cnt2+=arr[plank]/2;
        cnt4+=arr[plank]/4;
        if(cnt4>=1 and cnt2>=4){
            YY;
        } else {
            NN;
        }
    }
    return 0;
}