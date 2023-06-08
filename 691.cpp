// We are given n different types of stickers. Each sticker has a lowercase English word on it.

// You would like to spell out the given string target by cutting individual letters from your collection of stickers and rearranging them. You can use each sticker more than once if you want, and you have infinite quantities of each sticker.

// Return the minimum number of stickers that you need to spell out target. If the task is impossible, return -1.

// Note: In all test cases, all words were chosen randomly from the 1000 most common US English words, and target was chosen as a concatenation of two random words.
#include<iostream>
#include<vector>
#include<string>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int minStickers(vector<string>&stickers,string &target);
int solve(string &target,int mask);
vector<int>mem;
vector<vector<int>>arr;
int main(){
    ios;
    int n;
    cin>>n;
    vector<string>stickers(n,"");
    for(int i=0;i<n;i++){
        cin>>stickers[i];
    }
    string target;
    cin>>target;
    cout<<minStickers(stickers,target)<<endl;
    return 0;
}
int minStickers(vector<string>&stickers,string &target){
    int n=target.size();
    for(int i=0;i<stickers.size();i++){
        vector<int>chars(26,0);
        for(char ch:stickers[i]){
            chars[ch-'a']++;
        }
        arr.push_back(chars);
    }
    mem=vector<int>(1<<n,-1);
    return solve(target,0);
}
int solve(string &target,int mask){
    int n=target.size();
    if(mask==(1<<n)-1){
        return 0;
    } else if(mem[mask]!=-1){
        return mem[mask];
    } else {
        int ans=1e9;
        for(vector<int>words:arr){
            int nmask=0;
            for(int i=0;i<target.size();i++){
                if(((mask>>i)&1)==0 and words[target[i]-'a']){
                    nmask^=(1<<i);
                    words[target[i]-'a']--;
                }
            }
            if(nmask){
                ans=min(ans,1+solve(target,mask^nmask));
            }
        }
        return mem[mask]=ans;
    }
}