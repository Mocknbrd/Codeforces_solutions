// There is a new attraction in Singapore Zoo: The Infinite Zoo.

// The Infinite Zoo can be represented by a graph with an infinite number of vertices labeled 1,2,3,…. There is a directed edge from vertex u to vertex u+v if and only if u&v=v, where & denotes the bitwise AND operation. There are no other edges in the graph.

// Zookeeper has q queries. In the i-th query she will ask you if she can travel from vertex ui to vertex vi by going through directed edges.

// Input
// The first line contains an integer q (1≤q≤105) — the number of queries.

// The i-th of the next q lines will contain two integers ui, vi (1≤ui,vi<230) — a query made by Zookeeper.

// Output
// For the i-th of the q queries, output "YES" in a single line if Zookeeper can travel from vertex ui to vertex vi. Otherwise, output "NO".

// You can print your answer in any case. For example, if the answer is "YES", then the output "Yes" or "yeS" will also be considered as correct answer.
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
constexpr int infinity=1e9+7;
constexpr ll linf=1e18+7;
using namespace std;
int main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int u,v;
        cin>>u>>v;
        bool ok=(u<=v);
        int ones=0;
        for(int pos=0;pos<=30;pos++){
            ones+=((u>>pos)&1);
            ones-=((v>>pos)&1);
            if(ones<0){
                ok=false;
                break;
            }
        }
        ok?YY:NN;
    }
    return 0;
}