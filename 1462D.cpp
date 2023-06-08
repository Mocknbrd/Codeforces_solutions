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
#define Set(B,x,value) B x; x=value
const int infinity=1e9+7;
const ll linf=1e18+7;
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
    Input(int,t);
    while(t--){
        Input(int,n);
        vi arr(n);
        inputArray(arr);
        Set(int,sum,0); Set(int,ans,0);
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        for(int k=0;k<n;k++){
            if(sum%(n-k)==0){
                Set(int,cnt,0); Set(int,s,0); Set(int,target,sum/(n-k));
                for(int i=0;i<arr.size();i++){
                    s+=arr[i];
                    if(s>target){
                        break;
                    } else if(s==target){
                        cnt++;
                        s=0;
                    }
                }
                if(cnt==n-k){
                    ans=k;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}