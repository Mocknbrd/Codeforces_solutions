// Polycarp often uses his smartphone. He has already installed n applications on it. Application with number i takes up ai units of memory.

// Polycarp wants to free at least m units of memory (by removing some applications).

// Of course, some applications are more important to Polycarp than others. He came up with the following scoring system — he assigned an integer bi to each application:

// bi=1 — regular application;
// bi=2 — important application.
// According to this rating system, his phone has b1+b2+…+bn convenience points.

// Polycarp believes that if he removes applications with numbers i1,i2,…,ik, then he will free ai1+ai2+…+aik units of memory and lose bi1+bi2+…+bik convenience points.

// For example, if n=5, m=7, a=[5,3,2,1,4], b=[2,1,1,2,1], then Polycarp can uninstall the following application sets (not all options are listed below):

// applications with numbers 1,4 and 5. In this case, it will free a1+a4+a5=10 units of memory and lose b1+b4+b5=5 convenience points;
// applications with numbers 1 and 3. In this case, it will free a1+a3=7 units of memory and lose b1+b3=3 convenience points.
// applications with numbers 2 and 5. In this case, it will free a2+a5=7 memory units and lose b2+b5=2 convenience points.
// Help Polycarp, choose a set of applications, such that if removing them will free at least m units of memory and lose the minimum number of convenience points, or indicate that such a set does not exist.

// Input
// The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

// The first line of each test case contains two integers n and m (1≤n≤2⋅105, 1≤m≤109) — the number of applications on Polycarp's phone and the number of memory units to be freed.

// The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the number of memory units used by applications.

// The third line of each test case contains n integers b1,b2,…,bn (1≤bi≤2) — the convenience points of each application.

// It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case, output on a separate line:

// -1, if there is no set of applications, removing which will free at least m units of memory;
// the minimum number of convenience points that Polycarp will lose if such a set exists.
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
#define infinity static_cast<int>(1e18+7);
using namespace std;
signed main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>a(n,0),b(n,0),one,two;
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            if(b[i]==1){
                one.push_back(a[i]);
            } else {
                two.push_back(a[i]);
            }
        }
        if(sum<m){
            cout<<-1<<endl;
        } else {
            sort(one.begin(),one.end(),greater<int>());
            sort(two.begin(),two.end(),greater<int>());
            vector<int>first(one.size()+1,0),second(two.size()+1,0);
            for(int i=0;i<one.size();i++){
                first[i+1]=first[i]+one[i];
            }
            for(int i=0;i<two.size();i++){
                second[i+1]=second[i]+two[i];
            }
            int ans=infinity;
            for(int firstPrefix=0;firstPrefix<first.size();firstPrefix++){
                int secondPrefix=lower_bound(second.begin(),second.end(),m-first[firstPrefix])-second.begin();
                if(secondPrefix<second.size()){
                    ans=min(ans,firstPrefix+2*secondPrefix);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}