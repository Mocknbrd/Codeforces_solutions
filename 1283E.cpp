// Oh, New Year. The time to gather all your friends and reflect on the heartwarming events of the past year...

// n friends live in a city which can be represented as a number line. The i-th friend lives in a house with an integer coordinate xi. The i-th friend can come celebrate the New Year to the house with coordinate xi−1, xi+1 or stay at xi. Each friend is allowed to move no more than once.

// For all friends 1≤xi≤n holds, however, they can come to houses with coordinates 0 and n+1 (if their houses are at 1 or n, respectively).

// For example, let the initial positions be x=[1,2,4,4]. The final ones then can be [1,3,3,4], [0,2,3,3], [2,2,5,5], [2,1,3,5] and so on. The number of occupied houses is the number of distinct positions among the final ones.

// So all friends choose the moves they want to perform. After that the number of occupied houses is calculated. What is the minimum and the maximum number of occupied houses can there be?

// Input
// The first line contains a single integer n (1≤n≤2⋅105) — the number of friends.

// The second line contains n integers x1,x2,…,xn (1≤xi≤n) — the coordinates of the houses of the friends.

// Output
// Print two integers — the minimum and the maximum possible number of occupied houses after all moves are performed.
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
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
constexpr int infinity=1e9+7;
constexpr ll linf=1e18+7;
using namespace std;
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
int main(){
    ios;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    vector<int>dirs={0,-1,1};
    vector<vector<int>>minDp(n,vector<int>(3,infinity)),maxDp(n,vector<int>(3,0));
    for(int i=0;i<3;i++){
        minDp[0][i]=1;
        maxDp[0][i]=1;
    }
    for(int i=1;i<arr.size();i++){
        for(int dir=0;dir<dirs.size();dir++){
            int cx=arr[i]+dirs[dir];
            for(int pdir=0;pdir<dirs.size();pdir++){
                int px=arr[i-1]+dirs[pdir];
                if(px<=cx){
                    maxDp[i][dir]=max(maxDp[i][dir],maxDp[i-1][pdir]+(px<cx));
                    minDp[i][dir]=min(minDp[i][dir],minDp[i-1][pdir]+(px<cx));
                }
            }
        }
    }
    int ans1=*min_element(minDp.back().begin(),minDp.back().end());
    int ans2=*max_element(maxDp.back().begin(),maxDp.back().end());
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}