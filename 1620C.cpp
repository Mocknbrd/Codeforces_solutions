// You are given an integer k and a string s that consists only of characters 'a' (a lowercase Latin letter) and '*' (an asterisk).

// Each asterisk should be replaced with several (from 0 to k inclusive) lowercase Latin letters 'b'. Different asterisk can be replaced with different counts of letter 'b'.

// The result of the replacement is called a BA-string.

// Two strings a and b are different if they either have different lengths or there exists such a position i that ai≠bi.

// A string a is lexicographically smaller than a string b if and only if one of the following holds:

// a is a prefix of b, but a≠b;
// in the first position where a and b differ, the string a has a letter that appears earlier in the alphabet than the corresponding letter in b.
// Now consider all different BA-strings and find the x-th lexicographically smallest of them.

// Input
// The first line contains a single integer t (1≤t≤2000) — the number of testcases.

// The first line of each testcase contains three integers n, k and x (1≤n≤2000; 0≤k≤2000; 1≤x≤1018). n is the length of string s.

// The second line of each testcase is a string s. It consists of n characters, each of them is either 'a' (a lowercase Latin letter) or '*' (an asterisk).

// The sum of n over all testcases doesn't exceed 2000. For each testcase x doesn't exceed the total number of different BA-strings. String s contains at least one character 'a'.

// Output
// For each testcase, print a single string, consisting only of characters 'b' and 'a' (lowercase Latin letters) — the x-th lexicographically smallest BA-string.
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
    int t;
    cin>>t;
    while(t--){
        ll n,k,x;
        cin>>n>>k>>x;
        string s;
        cin>>s;
        x--;
        ll cnt=0;
        vector<ll>segments;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                if(cnt){
                    segments.push_back(cnt*k+1);
                }
                segments.push_back(-1);
                cnt=0;
            } else {
                cnt++;
            }
        }
        if(cnt){
            segments.push_back(cnt);
        }
        for(int i=segments.size()-1;i>=0;i--){
            if(segments[i]!=-1){
                ll tmp=segments[i];
                segments[i]=x%segments[i];
                x/=tmp;
            }
        }
        string ans;
        for(int i=0;i<segments.size();i++){
            if(segments[i]==-1){
                ans+='a';
            } else {
                for(int j=0;j<segments[i];j++){
                    ans+='b';
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}