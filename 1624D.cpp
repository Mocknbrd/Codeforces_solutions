// You have a string s consisting of lowercase Latin alphabet letters.

// You can color some letters in colors from 1 to k. It is not necessary to paint all the letters. But for each color, there must be a letter painted in that color.

// Then you can swap any two symbols painted in the same color as many times as you want.

// After that, k strings will be created, i-th of them will contain all the characters colored in the color i, written in the order of their sequence in the string s.

// Your task is to color the characters of the string so that all the resulting k strings are palindromes, and the length of the shortest of these k strings is as large as possible.

// Read the note for the first test case of the example if you need a clarification.

// Recall that a string is a palindrome if it reads the same way both from left to right and from right to left. For example, the strings abacaba, cccc, z and dxd are palindromes, but the strings abab and aaabaa — are not.

// Input
// The first line of input data contains a single integer t (1≤t≤104) — the number of input data sets in the test.

// The descriptions of the input data sets follow.

// The first line of the description of each input data set contains two integers n and k (1≤k≤n≤2⋅105) — the length of the string and the number of colors in which its letters can be painted. The second line of the description of each input data set contains a string s of length n consisting of lowercase letters of the Latin alphabet.

// It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each set of input data, output a single integer  — the maximum length of the shortest palindrome string that can be obtained.
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
int main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int>cnts(26,0);
        for(char &c:s){
            cnts[c-'a']++;
        }
        int pairs=0,odd=0;
        for(int &cnt:cnts){
            pairs+=cnt/2;
            odd+=cnt%2;
        }
        int ans=2*pairs/k;
        odd+=pairs%k;
        ans+=(odd>=k);
        cout<<ans<<endl;
    }
    return 0;
}