// This is an easy version of the problem. The actual problems are different, but the easy version is almost a subtask of the hard version. Note that the constraints and the output format are different.

// You are given a string s consisting of n lowercase Latin letters.

// You have to color all its characters one of the two colors (each character to exactly one color, the same letters can be colored the same or different colors, i.e. you can choose exactly one color for each index in s).

// After coloring, you can swap any two neighboring characters of the string that are colored different colors. You can perform such an operation arbitrary (possibly, zero) number of times.

// The goal is to make the string sorted, i.e. all characters should be in alphabetical order.

// Your task is to say if it is possible to color the given string so that after coloring it can become sorted by some sequence of swaps. Note that you have to restore only coloring, not the sequence of swaps.

// Input
// The first line of the input contains one integer n (1≤n≤200) — the length of s.

// The second line of the input contains the string s consisting of exactly n lowercase Latin letters.

// Output
// If it is impossible to color the given string so that after coloring it can become sorted by some sequence of swaps, print "NO" (without quotes) in the first line.

// Otherwise, print "YES" in the first line and any correct coloring in the second line (the coloring is the string consisting of n characters, the i-th character should be '0' if the i-th character is colored the first color and '1' otherwise).
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
constexpr int infinity=1e18+7;
using namespace std;
signed main(){
    ios;
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>s1,s2;
    unordered_map<int,char>mp;
    for(int i=0;i<s.size();i++){
        mp[i]=s[i];
    }
    for(int i=0;i<s.size();i++){
        if(s1.empty() or mp[s1.back()]<=s[i]){
            s1.push_back(i);
        } else if(s2.empty() or mp[s2.back()]<=s[i]){
            s2.push_back(i);
        }
    }
    if(s1.size()+s2.size()==s.size()){
        vector<int>ans(n);
        for(int &index:s1){
            ans[index]=0;
        }
        for(int &index:s2){
            ans[index]=1;
        }
        YY;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
        }
        cout<<endl;
    } else {
        NN;
    }
    return 0;
}