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
#define typecast static_cast
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
#define loop(it,init,condition,update) for(auto it=init;condition;update)
#define range(i,start,end,step) loop(i,start,i<end,i+=step)
#define increment(i,start,end) range(i,start,end,1)
#define decrement(i,start,end) range(i,start,end,-1)
#define for_each(element,container) for(auto &element:container)
#define sort(arr) sort(arr.begin(),arr.end())
#define rsort(arr) sort(arr.begin(),arr.end(),greater<auto>())
#define char_index(c,caps) caps?c-'A':c-'a'
#define Input(A,x) A x; cin>>x
#define Init(B,x,value) B x; x=value
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
template<typename tmp>
inline void inputArray(vector<tmp>&arr,int start=0){
    increment(i,start,arr.size()){
        cin>>arr[i];
    }
}
template<typename tmp>
inline void inputMatrix(vector<vector<tmp>>&matrix,int r=0,int c=0){
    increment(i,r,matrix.size()){
        increment(j,c,matrix[i].size()){
            cin>>matrix[i][j];
        }
    }
}
const int infinity=1e9+7;
const ll linf=1e18+7;
const ll llzero=typecast<ll>(0);
int main(){
    ios;
    Input(int,t);
    while(t--){
        int n,q;
        cin>>n>>q;
        vi arr(n);
        inputArray(arr);
        int index=n-1,start=0,end=n-1;
        while(start<=end){
            int mid=(start+end)>>1;
            int iq=q;
            bool flag=true;
            increment(i,mid,n){
                if(arr[i]>iq and --iq<0){
                    flag=false;
                    break;
                }
            }
            if(flag){
                index=mid;
                end=mid-1;
            } else {
                start=mid+1;
            }
        }
        increment(i,0,n){
            if(i<index){
                if(arr[i]<=q){
                    cout<<1;
                } else {
                    cout<<0;
                }
            } else {
                cout<<1;
            }
        }
        cout<<endl;
    }
    return 0;
}