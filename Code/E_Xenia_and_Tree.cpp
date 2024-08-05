#include <bits/stdc++.h>
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc++11-extensions"
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define see(statement) cout << statement << endl
#define YY see("YES")
#define NN see("NO")
#define yy see("Yes")
#define nn see("No")
#define is ==
#define isnt !=
#define None nullptr
#define fi first
#define sc second
#define Aa see("Alice")
#define AA see("ALICE")
#define Bb see("Bob")
#define BB see("BOB")
#define pb(value) push_back(value)
#define pf(value) push_front(value)
#define rb() pop_back()
#define rf() pop_front()
#define MANY {int t; cin >> t; while(t--)testcase();}
#define SINGLE {testcase();}
#define this (*this)
#define sz() size()
#define vt(type) vector<type>
#define ins(element) insert(element)
#define bg() begin()
#define bk() back()
#define fr() front()
#define ed() end()
#define mp(value1,value2) make_pair(value1,value2)
#define br() cout << endl
#define cast(element,type) static_cast<type>(element)
#define ll long long
#define cd complex<double>
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vb vector<bool>
#define vvb vector<vb>
#define vld vector<ld>
#define pair(t1,t2) pair<t1,t2>
#define pii pair(int,int)
#define pll pair(ll,ll)
#define pld pair(ll,ld)
#define vpii vector<pii>
#define vpll vector<pll>
#define map(type1,type2) map<type1,type2>
#define elif else if
#define loop(type,it,init,condition,update) for(type it = init;condition;update)
#define list(first,second,container) for(auto &[first,second]: container)
#define enumerate(first,second,container) list(first,second,enumerated(container))
#define zip(first,second,container1,container2) list(first,second,zipped(container1,container2))
#define enum_sub_type(type,submask,mask,equal) loop(type,submask,mask,(equal ? submask >= 0 : submask > 0),submask = (submask - 1) & mask)
#define enum_sub(submask,mask,equal) enum_sub_type(int,submask,mask,equal)
#define rng_la(type,i,start,end,step,buffer) loop(type,i,start,i + buffer < end,i += step)
#define inc_la(i,start,end,buffer) rng_la(int,i,start,end,1,buffer)
#define slid_win(left,right,size,end) for(int left = 1, right = size; right < end; left++,right++)
#define rng_type(type,i,start,end,step) loop(type,i,start,(step > 0 ? i < end : i >= end),i += step)
#define rng(i,start,end,step) rng_type(int,i,start,end,step)
#define inc(i,start,end) rng(i,start,end,1)
#define each(element,container) for(auto &element:container)
template<typename tmp>
inline void readArray(vt(tmp)&arr,int start = 0){
    inc(i,start,arr.size()){
        cin >> arr[i];
    }
}
template<typename tmp>
inline void readMatrix(vt(tmp)&matrix,int r = 0,int c = 0){
    inc(i,r,matrix.size()){
        inc(j,c,matrix[i].size()){
            cin >> matrix[i][j];
        }
    }
}
const int inf = 1e9;
void testcase();
vb removed;
vt(vpii)ancestors;
vi subtree,ans;
vvi tree;
int findSubTreeSize(vvi &tree,int vertex,int parent = -1);
int findCentroid(vvi &tree,int vertex,int parent,int size);
void findDistanceFromCentroid(vvi &tree,int vertex,int parent,int centroid,int curr);
void buildCentroidDecomposition(vvi &tree,int vertex);
void update(int vertex);
void query(int vertex);
int main(){
    ios;
    SINGLE;
    return 0;
}
void testcase(){
    int n,q;
    cin >> n >> q;
    tree.assign(n,vi());
    inc(i,0,n - 1){
        int u,v;
        cin >> u >> v;
        tree[--u].pb(--v);
        tree[v].pb(u);
    }
    removed.resize(n,false);
    subtree.resize(n,0);
    ancestors.resize(n);
    ans.resize(n,inf);
    buildCentroidDecomposition(tree,0);
    update(0);
    while(q--){
        int type,vertex;
        cin >> type >> vertex;
        vertex--;
        if(type is 1){
            update(vertex);
        } else {
            query(vertex);
        }
    }
    return;
}
void query(int vertex){
    int res = ans[vertex];
    each(centroid,ancestors[vertex]){
        res = min(res,centroid.sc + ans[centroid.fi]);
    }
    see(res);
}
void update(int vertex){
    each(centroid,ancestors[vertex]){
        ans[centroid.fi] = min(ans[centroid.fi],centroid.sc);
    }
    ans[vertex] = 0;
}
int findSubTreeSize(vvi &tree,int vertex,int parent){
    subtree[vertex] = 1;
    each(child,tree[vertex]){
        if(child isnt parent and removed[child] is false){
            subtree[vertex] += findSubTreeSize(tree,child,vertex);
        }
    }
    return subtree[vertex];
}
int findCentroid(vvi &tree,int vertex,int parent,int size){
    each(child,tree[vertex]){
        if(child is parent or removed[child] is true){
            continue;
        }
        if(subtree[child] * 2 > size){
            return findCentroid(tree,child,vertex,size);
        }
    }
    return vertex;
}
void findDistanceFromCentroid(vvi &tree,int vertex,int parent,int centroid,int curr){
    each(child,tree[vertex]){
        if(child is parent or removed[child] is true){
            continue;
        }
        findDistanceFromCentroid(tree,child,vertex,centroid,curr + 1);
    }
    ancestors[vertex].pb(mp(centroid,curr));
}
void buildCentroidDecomposition(vvi &tree,int vertex){
    int centroid = findCentroid(tree,vertex,-1,findSubTreeSize(tree,vertex,-1));
    each(child,tree[centroid]){
        findDistanceFromCentroid(tree,child,centroid,centroid,1);
    }
    removed[centroid] = true;
    each(child,tree[centroid]){
        if(removed[child] is false){
            buildCentroidDecomposition(tree,child);
        }
    }
}
#pragma GCC diagnostic pop