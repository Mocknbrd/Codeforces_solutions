// A string is binary, if it consists only of characters "0" and "1".

// String v is a substring of string w if it has a non-zero length and can be read starting from some position in string w. For example, string "010" has six substrings: "0", "1", "0", "01", "10", "010". Two substrings are considered different if their positions of occurrence are different. So, if some string occurs multiple times, we should consider it the number of times it occurs.

// You are given a binary string s. Your task is to find the number of its substrings, containing exactly k characters "1".

// Input
// The first line contains the single integer k (0 ≤ k ≤ 106). The second line contains a non-empty binary string s. The length of s does not exceed 106 characters.

// Output
// Print the single number — the number of substrings of the given string, containing exactly k characters "1".

// Please do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.
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
    int k;
    cin>>k;
    string s;
    cin>>s;
    unordered_map<int,int>cnts;
    cnts[0]=1;
    int ans=0,curr=0;
    for(int i=0;i<s.size();i++){
        curr+=s[i]-'0';
        ans+=cnts[curr-k];
        cnts[curr]++;
    }
    cout<<ans<<endl;
    return 0;
}