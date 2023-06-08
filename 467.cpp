// We define the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this:
// "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
// Given a string p, return the number of unique non-empty substrings of p are present in s.
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int findSubString(string &p);
int main(){
    ios;
    string p;
    cin>>p;
    cout<<findSubString(p)<<endl;
    return 0;
}
int findSubString(string &p){
    vector<int>cnts(26,0);
    int cnt=1;
    cnts[p[0]-'a']=1;
    for(int i=1;i<p.size();i++){
        if(p[i]-p[i-1]==1 or p[i-1]-p[i]==25){
            cnt++;
        } else {
            cnt=1;
        }
        cnts[p[i]-'a']=max(cnts[p[i]-'a'],cnt);
    }
    int ans=0;
    for(int i=0;i<26;i++){
        ans+=cnts[i];
    }
    return ans;
}