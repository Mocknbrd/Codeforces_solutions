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
    Input(int,t);
    while(t--){
        Input(int,n); Input(int,k);
        vll arr(n);
        inputArray(arr);
        ll maxElement=*max_element(arr.begin(),arr.end());
        ll element=1;
        while(element<maxElement){
            element*=k;
        }
        while(element>0){
            int mask=0;
            for(int i=0;i<arr.size();i++){
                mask^=((arr[i]>=element)<<i);
            }
            int cnt=__builtin_popcount(mask);
            if(cnt==1){
                int index=log2(mask&(-mask));
                arr[index]-=element;
            } else if(cnt>=2){
                break;
            }
            element/=k;
        }
        if(*max_element(arr.begin(),arr.end())==0){
            YY;
        } else {
            NN;
        }
    }
    return 0;
}