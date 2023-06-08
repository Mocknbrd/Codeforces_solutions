// You are given a string s consisting of n characters. Each character of s is either 0 or 1.

// A substring of s is a contiguous subsequence of its characters.

// You have to choose two substrings of s (possibly intersecting, possibly the same, possibly non-intersecting — just any two substrings). After choosing them, you calculate the value of the chosen pair of substrings as follows:

// let s1 be the first substring, s2 be the second chosen substring, and f(si) be the integer such that si is its binary representation (for example, if si is 11010, f(si)=26);
// the value is the bitwise OR of f(s1) and f(s2).
// Calculate the maximum possible value you can get, and print it in binary representation without leading zeroes.

// Input
// The first line contains one integer n — the number of characters in s.

// The second line contains s itself, consisting of exactly n characters 0 and/or 1.

// All non-example tests in this problem are generated randomly: every character of s is chosen independently of other characters; for each character, the probability of it being 1 is exactly 12.

// This problem has exactly 40 tests. Tests from 1 to 3 are the examples; tests from 4 to 40 are generated randomly. In tests from 4 to 10, n=5; in tests from 11 to 20, n=1000; in tests from 21 to 40, n=106.

// Hacks are forbidden in this problem.

// Output
// Print the maximum possible value you can get in binary representation without leading zeroes.
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
void removeLeadingZeros(string &s,int &n);
string operate(string &s1,string &s2);
signed main(){
    ios;
    int n;
    cin>>n;
    string s;
    cin>>s;
    removeLeadingZeros(s,n);
    if(s.empty()){
        cout<<"0"<<endl;
    } else {
        int zero=n;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zero=i;
                break;
            }
        }
        string ans=s;
        int suffix=n-zero;
        for(int add=suffix-zero;add<=suffix;add++){
            string s2=s.substr(0,zero+add);
            string res=operate(s,s2);
            if(res>ans){
                ans=res;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
void removeLeadingZeros(string &s,int &n){
    reverse(s.begin(),s.end());
    while(s.back()=='0'){
        s.pop_back();
        n--;
    }
    reverse(s.begin(),s.end());
}
string operate(string &s1,string &s2){
    string ans="";
    int end1=s1.size()-1,end2=s2.size()-1;
    while(end1>=0 and end2>=0){
        int digit1=s1[end1--]-'0';
        int digit2=s2[end2--]-'0';
        int digit=digit1|digit2;
        ans+=digit+'0';
    }
    while(end1>=0){
        ans+=s1[end1--];
    }
    while(end2>=0){
        ans+=s2[end2--];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}