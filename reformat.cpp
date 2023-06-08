#include <bits/stdc++.h>
using namespace std;
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);void testCase();
bool dfs(vector<string>&arr,int r,int c,int cnt,int &black,set<pair<int,int>>&seen);
int main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        testCase();
    }
    return 0;
}
void testCase(){
    int m;
    cin>>m;
    vector<string>arr(2);
    for(int i=0;i<2;i++){
        cin>>arr[i];
    }
    set<pair<int,int>>seen;
    int black=count(arr[0].begin(),arr[0].end(),'B')+count(arr[1].begin(),arr[1].end(),'B');
    bool ans1=false,ans2=false;
    if(arr[0][0]=='B'){
        ans1=dfs(arr,0,0,0,black,seen);
    }
    seen.clear();
    if(arr[1][0]=='B'){
        ans2=dfs(arr,1,0,0,black,seen);
    }
    if(ans1 or ans2){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    return;
}
bool dfs(vector<string>&arr,int r,int c,int cnt,int &black,set<pair<int,int>>&seen){
    int n=2,m=arr[0].size();
    cnt++;
    if(c==m-1 and (arr[(r+1)%2][c]=='W' or seen.count({(r+1)%2,c}))){
        return cnt==black;
    } else {
        seen.insert(make_pair(r,c));
        for(int hi=-1;hi<2;hi++){
            int nr=r+hi;
            if(nr>=0 and nr<n and arr[nr][c]=='B' and !seen.count({nr,c}) and dfs(arr,nr,c,cnt,black,seen)){
                return true;
            }
        }
        for(int v=-1;v<2;v++){
            int nc=c+v;
            if(nc>=0 and nc<m and arr[r][nc]=='B' and !seen.count({r,nc}) and dfs(arr,r,nc,cnt,black,seen)){
                return true;
            }
        }
        return false;
    }
}