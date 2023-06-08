// Alice and Bob are playing a game. Initially, they are given a non-empty string s, consisting of lowercase Latin letters. The length of the string is even. Each player also has a string of their own, initially empty.

// Alice starts, then they alternate moves. In one move, a player takes either the first or the last letter of the string s, removes it from s and prepends (adds to the beginning) it to their own string.

// The game ends when the string s becomes empty. The winner is the player with a lexicographically smaller string. If the players' strings are equal, then it's a draw.

// A string a is lexicographically smaller than a string b if there exists such position i that aj=bj for all j<i and ai<bi.

// What is the result of the game if both players play optimally (e. g. both players try to win; if they can't, then try to draw)?

// Input
// The first line contains a single integer t (1≤t≤1000) — the number of testcases.

// Each testcase consists of a single line — a non-empty string s, consisting of lowercase Latin letters. The length of the string s is even.

// The total length of the strings over all testcases doesn't exceed 2000.

// Output
// For each testcase, print the result of the game if both players play optimally. If Alice wins, print "Alice". If Bob wins, print "Bob". If it's a draw, print "Draw".
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
constexpr int infinity=1e9+7;
constexpr ll linf=1e18+7;
using namespace std;
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
vector<vector<int>>mem;
int determineOutcome(string &s,int start,int end);
vector<vector<int>>moves={{1,0},{0,-1}};
int main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        mem=vector<vector<int>>(s.size(),vector<int>(s.size(),-2));
        int ans=determineOutcome(s,0,s.size()-1);
        switch(ans){
            case 1: cout<<"Alice"<<endl;
                break;
            case -1: cout<<"Bob"<<endl;
                break;
            default: cout<<"Draw"<<endl;
                break;
        }
    }
    return 0;
}
int determineOutcome(string &s,int start,int end){
    if(start>end){
        return 0;
    } else if(mem[start][end]!=-2){
        return mem[start][end];
    } else {
        int aliceOutcome=-2;
        for(vector<int>&alice:moves){
            char aliceChar=alice.front()*s[start]+abs(alice.back())*s[end];
            int bobOutcome=2;
            for(vector<int>&bob:moves){
                char bobChar=bob.front()*s[start+alice.front()]+abs(bob.back())*s[end+alice.back()];
                int outcome=determineOutcome(s,start+alice.front()+bob.front(),end+alice.back()+bob.back());
                if(outcome==0 and bobChar!=aliceChar){
                    outcome=(bobChar>aliceChar?1:-1);
                }
                bobOutcome=min(bobOutcome,outcome);
            }
            aliceOutcome=max(aliceOutcome,bobOutcome);
        }
        return mem[start][end]=aliceOutcome;
    }
}