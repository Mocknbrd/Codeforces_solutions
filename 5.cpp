// Given a string s, return the longest palindromic substring in s.
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
#include<cstring>
#include<map>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
string longestPalindromicSubstr(string s);
int main(){
    ios;
    string s;
    cin>>s;
    cout<<longestPalindromicSubstr(s)<<endl;
    return 0;
}
string longestPalindromicSubstr(string s){
    bool dp[1001][1001];
    memset(dp,false,sizeof(dp));
    for(int i=0;i<s.size();i++){
        dp[i][i]=true;
    }
    int start=0,end=0;
    for(int i=s.size();i>=0;i--){
        for(int j=i+1;j<s.size();j++){
            if(s[i]==s[j] and (j-i==1 or dp[i+1][j-1])){
                dp[i][j]=true;
                if(end-start<j-i){
                    start=i;
                    end=j;
                }
            }
        }
    }
    return s.substr(start,end-start+1);
}