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
bool isPrime(int n);
int main(){
    ios;
    int t;
    cin>>t;
    vector<int>primes;
    int cnt=0,number=2;
    while(cnt<11){
        if(isPrime(number)){
            primes.push_back(number);
            cnt++;
        }
        number++;
    }
    while(t--){
        int n;
        cin>>n;
        vi arr(n);
        inputArray(arr);
        map<int,vi>mp;
        for(int i=0;i<arr.size();i++){
            for(int &prime:primes){
                if(arr[i]%prime==0){
                    mp[prime].push_back(i);
                    break;
                }
            }
        }
        cout<<mp.size()<<endl;
        int color=1;
        for(map<int,vi>::iterator it=mp.begin();it!=mp.end();it++){
            for(int &index:it->second){
                arr[index]=color;
            }
            color++;
        }
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}