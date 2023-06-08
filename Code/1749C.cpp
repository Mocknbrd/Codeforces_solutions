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
void inputArray(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
}
void inputMatrix(vector<vector<int>>&matrix){
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
        vector<int>arr(n);
        inputArray(arr);
        multiset<int>s(arr.begin(),arr.end());
        int ans=0,start=0,end=n;
        while(start<=end){
            int mid=(start+end)>>1;
            multiset<int>t=s;
            bool win=true;
            for(int i=1;i<=mid;i++){
                auto it=upper_bound(t.begin(),t.end(),mid-i+1);
                if(it==s.begin()){
                    win=false;
                    break;
                } else {
                    t.erase(--it);
                    if(t.size()){
                        t.erase(t.begin());
                    }
                }
            }
            if(win){
                ans=mid;
                start=mid+1;
            } else {
                end=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}