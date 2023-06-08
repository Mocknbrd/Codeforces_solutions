// Recently Irina arrived to one of the most famous cities of Berland — the Berlatov city. There are n showplaces in the city, numbered from 1 to n, and some of them are connected by one-directional roads. The roads in Berlatov are designed in a way such that there are no cyclic routes between showplaces.

// Initially Irina stands at the showplace 1, and the endpoint of her journey is the showplace n. Naturally, Irina wants to visit as much showplaces as she can during her journey. However, Irina's stay in Berlatov is limited and she can't be there for more than T time units.

// Help Irina determine how many showplaces she may visit during her journey from showplace 1 to showplace n within a time not exceeding T. It is guaranteed that there is at least one route from showplace 1 to showplace n such that Irina will spend no more than T time units passing it.

// Input
// The first line of the input contains three integers n, m and T (2 ≤ n ≤ 5000,  1 ≤ m ≤ 5000,  1 ≤ T ≤ 109) — the number of showplaces, the number of roads between them and the time of Irina's stay in Berlatov respectively.

// The next m lines describes roads in Berlatov. i-th of them contains 3 integers ui, vi, ti (1 ≤ ui, vi ≤ n, ui ≠ vi, 1 ≤ ti ≤ 109), meaning that there is a road starting from showplace ui and leading to showplace vi, and Irina spends ti time units to pass it. It is guaranteed that the roads do not form cyclic routes.

// It is guaranteed, that there is at most one road between each pair of showplaces.

// Output
// Print the single integer k (2 ≤ k ≤ n) — the maximum number of showplaces that Irina can visit during her journey from showplace 1 to showplace n within time not exceeding T, in the first line.

// Print k distinct integers in the second line — indices of showplaces that Irina will visit on her route, in the order of encountering them.

// If there are multiple answers, print any of them.
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
#define ld long double
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
constexpr int infinity=1e9+7;
constexpr ll linf=1e18+7;
using namespace std;
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
vector<int> topSort(vector<vector<pair<int,int>>>&dag,vector<int>degree);
int main(){
    ios;
    int n,m,t;
    cin>>n>>m>>t;
    vector<vector<pair<int,int>>>dag(n+1);
    vector<int>degree(n+1,0);
    for(int i=0;i<m;i++){
        int u,v,time;
        cin>>u>>v>>time;
        dag[u].push_back(make_pair(v,time));
        degree[v]++;
    }
    vector<int>order=topSort(dag,degree);
    vector<vector<int>>dp(n+1,vector<int>(n+1,infinity)),parent(n+1,vector<int>(n+1,-1));
    dp[n][1]=0;
    for(int numVertices=2;numVertices<=n;numVertices++){
        for(int &vertex:order){
            for(pair<int,int>&edge:dag[vertex]){
                int neighbour=edge.first;
                int weight=edge.second;
                if(dp[neighbour][numVertices-1]+weight<dp[vertex][numVertices]){
                    dp[vertex][numVertices]=dp[neighbour][numVertices-1]+weight;
                    parent[vertex][numVertices]=neighbour;
                }
            }
        }
    }
    vector<int>ans;
    int vertices=-1;
    for(int numVertices=n;numVertices>=1;numVertices--){
        if(dp[1][numVertices]<=t){
            ans.push_back(1);
            ans.push_back(parent[1][numVertices--]);
            vertices=numVertices;
            break;
        }
    }
    while(ans.back()!=n){
        ans.push_back(parent[ans.back()][vertices--]);
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
vector<int> topSort(vector<vector<pair<int,int>>>&dag,vector<int>degree){
    queue<int>q;
    for(int i=1;i<dag.size();i++){
        if(degree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(q.size()){
        int vertex=q.front();
        q.pop();
        ans.push_back(vertex);
        for(pair<int,int>&edge:dag[vertex]){
            int neighbour=edge.first;
            if(--degree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}