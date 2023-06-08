// Consider a simplified penalty phase at the end of a football match.

// A penalty phase consists of at most 10 kicks, the first team takes the first kick, the second team takes the second kick, then the first team takes the third kick, and so on. The team that scores more goals wins; if both teams score the same number of goals, the game results in a tie (note that it goes against the usual football rules). The penalty phase is stopped if one team has scored more goals than the other team could reach with all of its remaining kicks. For example, if after the 7-th kick the first team has scored 1 goal, and the second team has scored 3 goals, the penalty phase ends — the first team cannot reach 3 goals.

// You know which player will be taking each kick, so you have your predictions for each of the 10 kicks. These predictions are represented by a string s consisting of 10 characters. Each character can either be 1, 0, or ?. This string represents your predictions in the following way:

// if si is 1, then the i-th kick will definitely score a goal;
// if si is 0, then the i-th kick definitely won't score a goal;
// if si is ?, then the i-th kick could go either way.
// Based on your predictions, you have to calculate the minimum possible number of kicks there can be in the penalty phase (that means, the earliest moment when the penalty phase is stopped, considering all possible ways it could go). Note that the referee doesn't take into account any predictions when deciding to stop the penalty phase — you may know that some kick will/won't be scored, but the referee doesn't.

// Input
// The first line contains one integer t (1≤t≤1000) — the number of test cases.

// Each test case is represented by one line containing the string s, consisting of exactly 10 characters. Each character is either 1, 0, or ?.

// Output
// For each test case, print one integer — the minimum possible number of kicks in the penalty phase.
#include <iostream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <cstring>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
using namespace std;
int solve(string &s);
int solver(string &s,vector<vector<vector<int>>>&mem,int rem1,int rem2,int index,int mask1,int mask2);
int main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
    }
    return 0;
}
int solve(string &s){
    vector<vector<vector<int>>>mem(10,vector<vector<int>>(1<<5,vector<int>(1<<5,-1)));
    return solver(s,mem,5,5,0,0,0);
}
int solver(string &s,vector<vector<vector<int>>>&mem,int rem1,int rem2,int index,int mask1,int mask2){
    if(index==s.size()){
        return 0;
    } else if(mem[index][mask1][mask2]!=-1){
        return mem[index][mask1][mask2];
    } else {
        int goal1=__builtin_popcount(mask1);
        int goal2=__builtin_popcount(mask2);
        if(goal1>goal2+rem2 or goal2>goal1+rem1){
            return mem[index][mask1][mask2]=0;
        } else if(index%2){
            if(s[index]!='?'){
                int digit=s[index]-'0';
                return mem[index][mask1][mask2]=1+solver(s,mem,rem1,rem2-1,index+1,mask1,mask2^(digit<<(index/2)));
            } else {
                int score=1+solver(s,mem,rem1,rem2-1,index+1,mask1,mask2^(1<<(index/2)));
                int miss=1+solver(s,mem,rem1,rem2-1,index+1,mask1,mask2);
                return mem[index][mask1][mask2]=min(score,miss);
            }
        } else {
            if(s[index]!='?'){
                int digit=s[index]-'0';
                return mem[index][mask1][mask2]=1+solver(s,mem,rem1-1,rem2,index+1,mask1^(digit<<(index/2)),mask2);
            } else {
                int score=1+solver(s,mem,rem1-1,rem2,index+1,mask1^(1<<(index/2)),mask2);
                int miss=1+solver(s,mem,rem1-1,rem2,index+1,mask1,mask2);
                return mem[index][mask1][mask2]=min(score,miss);
            }
        }
    }
}