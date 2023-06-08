// In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.
// Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.
// For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
// Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.
// It is guaranteed an answer exists.
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
#include<map>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
vector<int>smallestTeam(vector<string>&skills,vector<vector<string>>&people);
int main(){
    ios;
    int n;
    cin>>n;
    vector<string>skills(n,"");
    for(int i=0;i<n;i++){
        cin>>skills[i];
    }
    int p;
    cin>>p;
    vector<vector<string>>people(p);
    for(int i=0;i<p;i++){
        cin>>n;
        people[i]=vector<string>(n,"");
        for(int j=0;j<n;j++){
            cin>>people[i][j];
        }
    }
    vector<int>ans=smallestTeam(skills,people);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
vector<int>smallestTeam(vector<string>&skills,vector<vector<string>>&people){
    int n=skills.size();
    unordered_map<string,int>pos;
    for(int i=0;i<skills.size();i++){
        pos[skills[i]]=i;
    }
    vector<int>score(people.size(),0);
    for(int i=0;i<people.size();i++){
        for(string skill:people[i]){
            score[i]|=(1<<pos[skill]);
        }
    }
    vector<int>dp(1<<n,1e9);
    vector<vector<int>>ans(1<<n);
    dp[0]=0;
    for(int mask=0;mask<(1<<n);mask++){
        if(dp[mask]!=1e9){
            for(int i=0;i<score.size();i++){
                int nmask=mask|score[i];
                if(1+dp[mask]<dp[nmask]){
                    dp[nmask]=1+dp[mask];
                    ans[nmask]=ans[mask];
                    ans[nmask].push_back(i);
                }
            }
        }
    }
    return ans[(1<<n)-1];
}