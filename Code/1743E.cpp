// Monocarp is playing a video game. In the game, he controls a spaceship and has to destroy an enemy spaceship.

// Monocarp has two lasers installed on his spaceship. Both lasers 1 and 2 have two values:

// pi — the power of the laser;
// ti — the reload time of the laser.
// When a laser is fully charged, Monocarp can either shoot it or wait for the other laser to charge and shoot both of them at the same time.

// An enemy spaceship has h durability and s shield capacity. When Monocarp shoots an enemy spaceship, it receives (P−s) damage (i. e. (P−s) gets subtracted from its durability), where P is the total power of the lasers that Monocarp shoots (i. e. pi if he only shoots laser i and p1+p2 if he shoots both lasers at the same time). An enemy spaceship is considered destroyed when its durability becomes 0 or lower.

// Initially, both lasers are zero charged.

// What's the lowest amount of time it can take Monocarp to destroy an enemy spaceship?

// Input
// The first line contains two integers p1 and t1 (2≤p1≤5000; 1≤t1≤1012) — the power and the reload time of the first laser.

// The second line contains two integers p2 and t2 (2≤p2≤5000; 1≤t2≤1012) — the power and the reload time of the second laser.

// The third line contains two integers h and s (1≤h≤5000; 1≤s<min(p1,p2)) — the durability and the shield capacity of an enemy spaceship. Note that the last constraint implies that Monocarp will always be able to destroy an enemy spaceship.

// Output
// Print a single integer — the lowest amount of time it can take Monocarp to destroy an enemy spaceship.
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
#define int long long
using namespace std;
signed main(){
    ios;
    vector<int>p(2),t(2);
    cin>>p[0]>>t[0];
    cin>>p[1]>>t[1];
    int h,s;
    cin>>h>>s;
    vector<int>dp(h+1,1e18);
    dp[0]=0;
    for(int i=0;i<h;i++){
        for(int j=1;j<=h;j++){
            for(int k=0;k<2;k++){
                int next=min(h,i+j*(p[k]-s)+j*t[k]/t[k^1]*(p[k^1]-s));
                if(next==h){
                    dp[next]=min(dp[next],dp[i]+j*t[k]);
                }
                if(j*t[k]>=t[k^1]){
                    next=min(h,i+(j-1)*(p[k]-s)+(j*t[k]/t[k^1]-1)*(p[k^1]-s)+p[0]+p[1]-s);
                    dp[next]=min(dp[next],dp[i]+j*t[k]);
                }
            }
        }
    }
    cout<<dp.back()<<endl;
    return 0;
}