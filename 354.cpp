#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
#include<cstring>
#include<map>
#include<algorithm>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
int maxEnvelopes(vector<vector<int>>&envelopes);
int main(){
    ios;
    int n;
    vector<vector<int>>envelopes(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        cin>>envelopes[i][0]>>envelopes[i][1];
    }
    cout<<maxEnvelopes(envelopes)<<endl;
    return 0;
}
int maxEnvelopes(vector<vector<int>>&envelopes){
    sort(envelopes.begin(),envelopes.end(),[](vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        } else {
            return a[0]<b[0];
        }
    });
    vector<int>ans;
    for(int i=0;i<envelopes.size();i++){
        int index=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
        if(index==ans.size()){
            ans.push_back(envelopes[i][1]);
        } else {
            ans[index]=envelopes[i][1];
        }
    }
    return ans.size();
}