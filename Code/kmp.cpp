#include<bits/stdc++.h>
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define YY cout<<"YES"<<endl
#define NN cout<<"NO"<<endl
#define yy cout<<"Yes"<<endl
#define nn cout<<"No"<<endl
#define int long long
using namespace std;
vector<int>kmp(string &s,string &p);
signed main(){
    cout<<"Enter the string: ";
    string s;
    cin>>s;
    cout<<"Enter the pattern: ";
    string p;
    cin>>p;
    vector<int>ans=kmp(s,p);
    cout<<"The positions where the pattern occurs in the string is: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
vector<int>kmp(string &s,string &p){
    vector<int>lps(p.size(),-1);
    vector<int>pos(26,-1);
    for(int i=0;i<p.size();i++){
        lps[i]=pos[p[i]-'a'];
        pos[p[i]-'a']=i;
    }
    int i=0,j=-1;
    vector<int>ans;
    while(i<s.size()){
        if(s[i]==p[j+1]){
            i++;
            j++;
        }
        if(j+1==p.size()){
            ans.push_back(i-p.size());
            j=lps[j];
        } else if(s[i]!=p[j+1]){
            if(j!=-1){
                j=lps[j];
            } else {
                i++;
            }
        }
    }
    return ans;
}