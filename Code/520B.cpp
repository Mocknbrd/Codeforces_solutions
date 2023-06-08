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
int recurse(int m,int n);
int main(){
    ios;
    int n,m;
    cin>>n>>m;
    cout<<recurse(m,n)<<endl;
    return 0;
}
int recurse(int m,int n){
    if(m<=n){
        return n-m;
    } else if(m%2){
        return recurse(m+1,n)+1;
    } else {
        return recurse(m/2,n)+1;
    }
}