// Let's call the string beautiful if it does not contain a substring of length at least 2, which is a palindrome. Recall that a palindrome is a string that reads the same way from the first character to the last and from the last character to the first. For example, the strings a, bab, acca, bcabcbacb are palindromes, but the strings ab, abbbaa, cccb are not.

// Let's define cost of a string as the minimum number of operations so that the string becomes beautiful, if in one operation it is allowed to change any character of the string to one of the first 3 letters of the Latin alphabet (in lowercase).

// You are given a string s of length n, each character of the string is one of the first 3 letters of the Latin alphabet (in lowercase).

// You have to answer m queries — calculate the cost of the substring of the string s from li-th to ri-th position, inclusive.

// Input
// The first line contains two integers n and m (1≤n,m≤2⋅105) — the length of the string s and the number of queries.

// The second line contains the string s, it consists of n characters, each character one of the first 3 Latin letters.

// The following m lines contain two integers li and ri (1≤li≤ri≤n) — parameters of the i-th query.

// Output
// For each query, print a single integer — the cost of the substring of the string s from li-th to ri-th position, inclusive.
#include <bits/stdc++.h>
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define YY cout<<"YES"<<endl;
#define NN cout<<"NO"<<endl;
#define yy cout<<"Yes"<<endl;
#define nn cout<<"No"<<endl;
#define endl "\n"
#define int long long
using namespace std;
signed main(){
    ios;
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    string t="abc";
    int curr=0;
    vector<vector<int>>prefix(6,vector<int>(n+1,0));
    do {
        for(int i=0;i<s.size();i++){
            prefix[curr][i+1]=prefix[curr][i]+(s[i]!=t[i%3]);
        }
        curr++;
    } while(next_permutation(t.begin(),t.end()));
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        int ans=1e9;
        for(int j=0;j<6;j++){
            ans=min(ans,prefix[i][r]-prefix[i][l-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}