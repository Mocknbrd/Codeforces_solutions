// You are given a book with n chapters.

// Each chapter has a specified list of other chapters that need to be understood in order to understand this chapter. To understand a chapter, you must read it after you understand every chapter on its required list.

// Currently you don't understand any of the chapters. You are going to read the book from the beginning till the end repeatedly until you understand the whole book. Note that if you read a chapter at a moment when you don't understand some of the required chapters, you don't understand this chapter.

// Determine how many times you will read the book to understand every chapter, or determine that you will never understand every chapter no matter how many times you read the book.

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤2⋅104).

// The first line of each test case contains a single integer n (1≤n≤2⋅105) — number of chapters.

// Then n lines follow. The i-th line begins with an integer ki (0≤ki≤n−1) — number of chapters required to understand the i-th chapter. Then ki integers ai,1,ai,2,…,ai,ki (1≤ai,j≤n,ai,j≠i,ai,j≠ai,l for j≠l) follow — the chapters required to understand the i-th chapter.

// It is guaranteed that the sum of n and sum of ki over all testcases do not exceed 2⋅105.

// Output
// For each test case, if the entire book can be understood, print how many times you will read it, otherwise print −1.
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
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
constexpr ll linf=1e18+7;
constexpr int iinf=1e9+10;
using namespace std;
vector<int>mem;
bool checkDag(vector<vector<int>>&dag,vector<int>ideg);
int solve(vector<vector<int>>&dag,int vertex);
int main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>dag(n);
        vector<int>ideg(n,0);
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            for(int j=0;j<k;j++){
                int element;
                cin>>element;
                dag[--element].push_back(i);
                ideg[i]++;
            }
        }
        if(!checkDag(dag,ideg)){
            cout<<-1<<endl;
        } else {
            int ans=0;
            mem=vector<int>(n,-1);
            for(int i=0;i<n;i++){
                if(ideg[i]==0){
                    ans=max(ans,1+solve(dag,i));
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
bool checkDag(vector<vector<int>>&dag,vector<int>ideg){
    int cnt=0;
    queue<int>q;
    for(int i=0;i<ideg.size();i++){
        if(ideg[i]==0){
            q.push(i);
        }
    }
    while(q.size()){
        int curr=q.front();
        q.pop();
        cnt++;
        for(int &neighbour:dag[curr]){
            if(--ideg[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return cnt==ideg.size();
}
int solve(vector<vector<int>>&dag,int vertex){
    if(mem[vertex]!=-1){
        return mem[vertex];
    } else {
        int ans=0;
        for(int &neighbour:dag[vertex]){
            ans=max(ans,(vertex>neighbour)+solve(dag,neighbour));
        }
        return mem[vertex]=ans;
    }
}