// Ashish has two strings a and b, each of length n, and an integer k. The strings only contain lowercase English letters.

// He wants to convert string a into string b by performing some (possibly zero) operations on a.

// In one move, he can either

// choose an index i (1≤i≤n−1) and swap ai and ai+1, or
// choose an index i (1≤i≤n−k+1) and if ai,ai+1,…,ai+k−1 are all equal to some character c (c≠ 'z'), replace each one with the next character (c+1), that is, 'a' is replaced by 'b', 'b' is replaced by 'c' and so on.
// Note that he can perform any number of operations, and the operations can only be performed on string a.

// Help Ashish determine if it is possible to convert string a into b after performing some (possibly zero) operations on it.

// Input
// The first line contains a single integer t (1≤t≤105) — the number of test cases. The description of each test case is as follows.

// The first line of each test case contains two integers n (2≤n≤106) and k (1≤k≤n).

// The second line of each test case contains the string a of length n consisting of lowercase English letters.

// The third line of each test case contains the string b of length n consisting of lowercase English letters.

// It is guaranteed that the sum of values n among all test cases does not exceed 106.

// Output
// For each test case, print "Yes" if Ashish can convert a into b after some moves, else print "No".

// You may print the letters of the answer in any case (upper or lower).
#include<bits/stdc++.h>
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define YY cout<<"YES"<<endl
#define NN cout<<"NO"<<endl
#define yy cout<<"Yes"<<endl
#define nn cout<<"No"<<endl
#define int long long
using namespace std;
signed main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string a,b;
        cin>>a>>b;
        vector<int>have(27,0),need(27,0);
        for(char &ch:a){
            have[ch-'a']++;
        }
        for(char &ch:b){
            need[ch-'a']++;
        }
        bool ans=true;
        for(int i=0;i<26;i++){
            if(have[i]<need[i] or (have[i]-=need[i])%k){
                ans=false;
                break;
            }
            have[i+1]+=have[i];
        }
        ans?yy:nn;
    }
    return 0;
}