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
#define enumerate_subsets(type,submask,mask,equal) loop(type,submask,mask,(equal?submask>=0:submask>0),submask=(submask-1)&mask) 
#define range_look_ahead(type,i,start,end,step,buffer) loop(type,i,start,i+buffer<end,i+=step)
#define inc_look_ahead(type,i,start,end,buffer) range_look_ahead(i,start,end,1,buffer)
#define range(type,i,start,end,step) loop(type,i,start,(step>0?i<end:i>=end),i+=step)
#define inc(type,i,start,end) range(type,i,start,end,1)
#define dec(type,i,start,end) range(type,i,start,end,-1)
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
inline void printArray(vector<tmp>&arr){
    for_each(element,arr){
        cout<<element<<" ";
    }
    cout<<endl;
}
template<typename tmp>
inline void printMatrix(vector<vector<tmp>>&matrix){
    inc(tmp,i,0,matrix.size()){
        inc(tmp,j,0,matrix[i].size()){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
const int infinity=1e9+7;
const ll linf=1e18+7;
const ll llzero=typecast<ll>(0);
void primeSieve(int n,vll &primes);
int main(){
    ios;
    Input(int,n);
    vi arr(n);
    inputArray(arr);
    int one=0,two=0;
    inc(int,i,0,n){
        one+=(arr[i]==1);
        two+=(arr[i]==2);
    }
    vll primes;
    primeSieve(2*n,primes);
    vi ans;
    int sum=0;
    while(one and two){
        int next=upper_bound(primes.begin(),primes.end(),sum)-primes.begin();
        int nextPrime=primes[next];
        if(nextPrime-sum>=2){
            ans.push_back(2);
            two--;
        } else {
            ans.push_back(1);
            one--;
        }
        sum+=ans.back();
    }
    while(one--){
        ans.push_back(1);
    }
    while(two--){
        ans.push_back(2);
    }
    printArray(ans);
    return 0;
}
void primeSieve(int n,vll &primes){
    vector<bool>isPrime(n+1,true);
    isPrime[0]=isPrime[1]=false;
    inc(ll,number,2,n+1){
        if(isPrime[number]){
            primes.push_back(number);
            range(ll,i,number*number,n+1,number){
                isPrime[i]=false;
            }
        }
    }
}