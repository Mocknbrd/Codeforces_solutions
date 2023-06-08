// A and B are preparing themselves for programming contests.

// After several years of doing sports programming and solving many problems that require calculating all sorts of abstract objects, A and B also developed rather peculiar tastes.

// A likes lowercase letters of the Latin alphabet. He has assigned to each letter a number that shows how much he likes that letter (he has assigned negative numbers to the letters he dislikes).

// B likes substrings. He especially likes the ones that start and end with the same letter (their length must exceed one).

// Also, A and B have a string s. Now they are trying to find out how many substrings t of a string s are interesting to B (that is, t starts and ends with the same letter and its length is larger than one), and also the sum of values of all letters (assigned by A), except for the first and the last one is equal to zero.

// Naturally, A and B have quickly found the number of substrings t that are interesting to them. Can you do it?

// Input
// The first line contains 26 integers xa, xb, ..., xz ( - 105 ≤ xi ≤ 105) — the value assigned to letters a, b, c, ..., z respectively.

// The second line contains string s of length between 1 and 105 characters, consisting of Lating lowercase letters— the string for which you need to calculate the answer.

// Output
// Print the answer to the problem.
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
    vector<int>score(26);
    for(int i=0;i<score.size();i++){
        cin>>score[i];
    }
    string s;
    cin>>s;
    vector<ll>prefix(s.size()+1,0);
    vector<vector<int>>pos(26);
    for(int i=1;i<prefix.size();i++){
        prefix[i]=prefix[i-1]+score[s[i-1]-'a'];
        pos[s[i-1]-'a'].push_back(i);
    }
    ll ans=0;
    for(int cc=0;cc<26;cc++){
        map<ll,int>m;
        for(int &p:pos[cc]){
            ans+=m[prefix[p-1]];
            m[prefix[p]]++;
        }
        m.clear();
    }
    cout<<ans<<endl;
    return 0;
}