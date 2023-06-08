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
#define loop(type,it,init,condition,update) for(type it=init;condition;update)
#define enum_sub(type,submask,mask,equal) loop(type,submask,mask,(equal?submask>=0:submask>0),submask=(submask-1)&mask) 
#define range_look_ahead(type,i,start,end,step,buffer) loop(type,i,start,i+buffer<end,i+=step)
#define inc_look_ahead(type,i,start,end,buffer) range_look_ahead(type,i,start,end,1,buffer)
#define range(type,i,start,end,step) loop(type,i,start,(step>0?i<end:i>=end),i+=step)
#define inc(type,i,start,end) range(type,i,start,end,1)
#define dec(type,i,start,end) range(type,i,start,end,-1)
#define each(element,container) for(auto &element:container)
#define win(type,it1,it2,init1,init2,end,step) for(type it1=init1,it2=init2;max(it1,it2)<end;it1+=step,it2+=step)
#define win_inc(type,it1,it2,init1,init2,end) win(type,it1,it2,init1,init2,end,1)
#define iter_for(it,container) for(auto it=container.begin();it!=container.end();it++)
#define iter_rev(it,container) for(auto it=container.rbegin();it!=container.rend();it++)
#define sort(arr) sort(arr.begin(),arr.end())
#define rsort(arr) sort(arr.begin(),arr.end(),greater<auto>())
#define char_index(c) tolower(c)-'a'
#define Input(A,x) A x; cin>>x
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
template<typename tmp>
inline void inputArray(vector<tmp>&arr,int start=0){
    inc(tmp,i,start,arr.size()){
        cin>>arr[i];
    }
}
template<typename tmp>
inline void inputMatrix(vector<vector<tmp>>&matrix,int r=0,int c=0){
    inc(tmp,i,r,matrix.size()){
        inc(tmp,j,c,matrix[i].size()){
            cin>>matrix[i][j];
        }
    }
}
template<typename tmp> 
inline void printArray(vector<tmp>&arr,int start=0){
    inc(int,i,start,arr.size()){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
template<typename tmp>
inline void printMatrix(vector<vector<tmp>>&matrix,int r=0,int c=0){
    inc(tmp,i,r,matrix.size()){
        inc(tmp,j,c,matrix[i].size()){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
}
const int infinity=1e9+7;
const ll linf=1e18+7;
const ll llzero=typecast<ll>(0);
bool possibleAssignment(int number,vi &masks);
bool solve(int index,int mask,vi &digits,vi &masks,vector<vi>&dp);
int main(){
    ios;
    Input(int,n);
    vi masks(n,0);
    inc(int,i,0,n){
        int mask=0;
        inc(int,_,0,6){
            Input(int,number);
            mask|=(1<<number);
        }
        masks[i]=mask;
    }
    int start=0,end=999,ans=0;
    while(start<=end){
        int mid=(start+end)>>1;
        bool flag=true;
        inc(int,it,1,mid+1){
            if(!possibleAssignment(it,masks)){
                flag=false;
                break;
            }
        }
        if(flag){
            ans=mid;
            start=mid+1;
        } else {
            end=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
bool possibleAssignment(int number,vi &masks){
    vi digits;
    while(number){
        digits.push_back(number%10);
        number/=10;
    }
    vector<vi>dp(digits.size(),vi((1<<4),-1));
    return solve(0,0,digits,masks,dp);
}
bool solve(int index,int mask,vi &digits,vi &masks,vector<vi>&dp){
    if(index==digits.size()){
        return true;
    } else if(dp[index][mask]!=-1){
        return dp[index][mask];
    } else {
        inc(int,i,0,masks.size()){
            if((mask>>i)&1){
                continue;
            } else if((masks[i]>>digits[index])&1 and solve(index+1,mask|(1<<i),digits,masks,dp)){
                return dp[index][mask]=true;
            }
        }
        return dp[index][mask]=false;
    }
}