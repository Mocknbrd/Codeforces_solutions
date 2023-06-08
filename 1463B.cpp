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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vll arr(n);
        inputArray(arr);
        vll even=arr,odd=arr;
        for(int i=0;i<n;i+=2){
            odd[i]=1;
        }
        for(int i=1;i<n;i+=2){
            even[i]=1;
        }
        ll first=0,second=0,sum=0;
        for(int i=0;i<n;i++){
            first+=abs(arr[i]-even[i]);
            second+=abs(arr[i]-odd[i]);
            sum+=arr[i];
        }
        if(2*first<=sum){
            for(int i=0;i<n;i++){
                cout<<even[i]<<" ";
            }
        } else {
            for(int i=0;i<n;i++){
                cout<<odd[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}