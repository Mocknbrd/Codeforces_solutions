// Given a matrix and a target, return the number of non-empty submatrices that sum to target.

// A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

// Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.
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
int submatrixTarget(vector<vector<int>>&matrix,int target);
int main(){
    ios;
    int m,n;
    cin>>m>>n;
    vector<vector<int>>matrix(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    int target;
    cin>>target;
    cout<<submatrixTarget(matrix,target)<<endl;
    return 0;
}
int submatrixTarget(vector<vector<int>>&matrix,int target){
    for(int i=0;i<matrix.size();i++){
        for(int j=1;j<matrix[i].size();j++){
            matrix[i][j]+=matrix[i][j-1];
        }
    }
    int ans=0;
    for(int col1=0;col1<matrix[0].size();col1++){
        for(int col2=col1;col2<matrix[0].size();col2++){
            unordered_map<int,int>cnt;
            cnt[0]=1;
            int curr=0;
            for(int row=0;row<matrix.size();row++){
                curr+=matrix[row][col2]-(col1>0?matrix[row][col1-1]:0);
                ans+=cnt.count(curr-target)?cnt[curr-target]:0;
                cnt[curr]++;
            }
        }
    }
    return ans;
}