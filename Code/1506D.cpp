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
#define pii pair<int,int>
#define pll pair<ll,ll>
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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi arr(n);
        inputArray(arr);
        map<int,int>cnt;
        for(int &element:arr){
            cnt[element]++;
        }
        PQ<int>pq;
        for(pair<const int,int>&pair:cnt){
            pq.push(pair.second);
        }
        int ans=n;
        while(pq.size()>=2){
            int curr1=pq.top(); pq.pop();
            int curr2=pq.top(); pq.pop();
            if(--curr1){
                pq.push(curr1);
            }
            if(--curr2){
                pq.push(curr2);
            }
            ans-=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}