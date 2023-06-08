// One day n friends gathered together to play "Mafia". During each round of the game some player must be the supervisor and other n - 1 people take part in the game. For each person we know in how many rounds he wants to be a player, not the supervisor: the i-th person wants to play ai rounds. What is the minimum number of rounds of the "Mafia" game they need to play to let each person play at least as many rounds as they want?

// Input
// The first line contains integer n (3 ≤ n ≤ 105). The second line contains n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 109) — the i-th number in the list is the number of rounds the i-th person wants to play.

// Output
// In a single line print a single integer — the minimum number of game rounds the friends need to let the i-th person play at least ai rounds.

// Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.
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
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
using namespace std;
signed main(){
    ios;
    int n;
    cin>>n;
    vector<int>arr(n);
    int sum=0;
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int ans=max(*max_element(arr.begin(),arr.end()),sum/(n-1)+(sum%(n-1)!=0));
    cout<<ans<<endl;
    return 0;
}