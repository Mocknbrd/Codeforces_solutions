// Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".

// Notice that in this problem, we are not adding '1' after single characters.

// Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.

// Find the minimum length of the run-length encoded version of s after deleting at most k characters.
#include<iostream>
#include <vector>
#include<cstring>
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int numLength(int n);
int solve(string &s, int index, int k);
int minCompressedLength(string &s,int k);
int mem[101][101];
int main(){
    ios;
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<minCompressedLength(s,k)<<endl;
    return 0;
}
int numLength(int n){
    if(n==1){
        return 0;
    } else if(n<10){
        return 1;
    } else if(n<100){
        return 2;
    } else {
        return 3;
    }
}
int minCompressedLength(string &s,int k){
    memset(mem,-1,sizeof(mem));
    return solve(s,0,k);
}
int solve(string &s, int index, int k){
    if(k<0){
        return 1e9;
    } else if(index==s.size() or k==s.size()-index){
        return 0;
    } else if(mem[index][k]!=-1){
        return mem[index][k];
    } else {
        int ans=1e9;
        int cnt[26]={0};
        for(int next=index,most=0;next<s.size();next++){
            most=max(most,++cnt[s[next]-'a']);
            ans=min(ans,1+numLength(most)+solve(s,next+1,k-(next-index+1-most)));
        }
        return mem[index][k]=ans;
    }
}