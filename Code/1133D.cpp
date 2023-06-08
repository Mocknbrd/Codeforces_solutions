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
#define cd complex<double>
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ll,ld>
#define vpii vector<pii>
#define vpll vector<pll>
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
#define pi 2*acos(0.0)
#define PQ priority_queue
#define loop(it,init,condition,update) for(auto it=init;condition;update)
#define enumerate_subsets(submask,mask,equal) loop(submask,mask,(equal?submask>=0:submask>0),submask=(submask-1)&mask) 
#define range_look_ahead(i,start,end,step,buffer) loop(i,start,i+buffer<end,i+=step)
#define inc_look_ahead(i,start,end,buffer) range_look_ahead(i,start,end,1,buffer)
#define range(i,start,end,step) loop(i,start,(step>0?i<end:i>=end),i+=step)
#define inc(i,start,end) range(i,start,end,1)
#define dec(i,start,end) range(i,start,end,-1)
#define for_each(element,container) for(auto &element:container)
#define iterate_forward(it,container) for(auto it=container.begin();it!=container.end();it++)
#define iterate_reverse(it,container) for(auto it=container.rbegin();it!=container.rend();it++)
#define sort(arr) sort(arr.begin(),arr.end())
#define rsort(arr) sort(arr.begin(),arr.end(),greater<auto>())
#define char_index(c,caps) caps?c-'A':c-'a'
#define Input(A,x) A x; cin>>x
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
template<typename tmp>
inline void inputArray(vector<tmp>&arr,int start=0){
    inc(i,start,arr.size()){
        cin>>arr[i];
    }
}
template<typename tmp>
inline void inputMatrix(vector<vector<tmp>>&matrix,int r=0,int c=0){
    inc(i,r,matrix.size()){
        inc(j,c,matrix[i].size()){
            cin>>matrix[i][j];
        }
    }
}
template<typename tmp> 
inline void printArray(vector<tmp>&arr){
    for_each(element,arr){
        cout<<element<<" ";
    }
    cout<<endl;
}
template<typename tmp>
inline void printMatrix(vector<vector<tmp>>&matrix){
    inc(i,0,matrix.size()){
        inc(j,0,matrix[i].size()){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
const int infinity=1e9+7;
const ll linf=1e18+7;
const ll llzero=typecast<ll>(0);
int main(){
    ios;
    Input(int,n);
    vi a(n),b(n);
    inputArray(a);
    inputArray(b);
    map<ld,int>fractions;
    int ans=0;
    inc(i,0,n){
        if(a[i]==0){
            ans+=(b[i]==0);
        } else {
            int gcd=__gcd(abs(a[i]),abs(b[i]));
            a[i]/=gcd;
            b[i]/=gcd;
            fractions[typecast<ld>(-b[i])/typecast<ld>(a[i])]++;
        }
    }
    int add=0;
    for_each(element,fractions){
        add=max(add,element.second);
    }
    ans+=add;
    cout<<ans<<endl;
    return 0;
}