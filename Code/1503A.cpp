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
#define range(i,start,end,step) for(int i=start;i<end;i+=step)
#define increment(i,start,end) range(i,start,end,1)
#define sort(arr) sort(arr.begin(),arr.end())
#define rsort(tmp,arr) sort(arr.begin(),arr.end(),greater<tmp>())
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
        Input(int,n);
        Input(string,s);
        vi ones,zeros;
        increment(i,0,n){
            if(s[i]=='0'){
                zeros.push_back(i);
            } else {
                ones.push_back(i);
            }
        }
        if(s[0]=='0' or s.back()=='0' or zeros.size()%2){
            NN;
        } else {
            YY;
            string ans1(n,'*'),ans2(n,'*');
            increment(i,0,ones.size()){
                if(i<ones.size()/2){
                    ans1[ones[i]]='(';
                    ans2[ones[i]]='(';
                } else {
                    ans1[ones[i]]=')';
                    ans2[ones[i]]=')';
                }
            }
            vector<pair<char,char>>add={{')','('},{'(',')'}};
            increment(i,0,zeros.size()){
                ans1[zeros[i]]=add[i%2].first;
                ans2[zeros[i]]=add[i%2].second;
            }
            cout<<ans1<<endl;
            cout<<ans2<<endl;
        }
    }
    return 0;
}