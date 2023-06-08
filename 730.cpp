// Given a string s, return the number of different non-empty palindromic subsequences in s. Since the answer may be very large, return it modulo 109 + 7.

// A subsequence of a string is obtained by deleting zero or more characters from the string.

// A sequence is palindromic if it is equal to the sequence reversed.

// Two sequences a1, a2, ... and b1, b2, ... are different if there is some i for which ai != bi.
#include<iostream>
#include<vector>
#include<string>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int solve(string &s,int start,int end,int alpha);
int numPalindromeSubSequences(string &s);
int mem[1001][1001][26];
int main(){
    ios;
    string s;
    cin>>s;
    cout<<numPalindromeSubSequences(s)<<endl;
    return 0;
}
int numPalindromeSubSequences(string &s){
    memset(mem,-1,sizeof(mem));
    int ans=0;
    for(int alpha=0;alpha<26;alpha++){
        ans+=solve(s,0,s.size()-1,alpha);
    }
    return ans;
}
int solve(string &s,int start,int end,int alpha){
    if(start>end){
        return 0;
    } else if(start==end){
        return s[start]-'a'==alpha;
    } else if(mem[start][end][alpha]!=-1){
        return mem[start][end][alpha];
    } else {
        if(s[start]!=s[end] or (s[start]==s[end] and s[start]-'a'!=alpha)){
            int first=solve(s,start+1,end,alpha);
            int second=solve(s,start,end-1,alpha);
            int third=solve(s,start+1,end-1,alpha);
            return mem[start][end][alpha]=first+second-third;
        } else {
            int ans=2;
            for(int beta=0;beta<26;beta++){
                ans+=solve(s,start+1,end-1,beta);
            }
            return mem[start][end][alpha]=ans;
        }
    }
}