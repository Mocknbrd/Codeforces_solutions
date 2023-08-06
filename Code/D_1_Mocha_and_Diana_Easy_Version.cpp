#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define see(statement) cout << statement << endl
#define YY see("YES")
#define NN see("NO")
#define yy see("Yes")
#define nn see("No")
#define is ==
#define isnt !=
#define f first
#define Aa see("Alice")
#define AA see("ALICE")
#define Bb see("Bob")
#define BB see("BOB")
#define s second
#define pb push_back
#define rb pop_back
#define rf pop_front
#define gcd(a,b) __gcd(a,b)
#define sz() size()
#define vec(type) vector<type>
#define ins(element) insert(element)
#define br() cout<<endl
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
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
#define pi 2*acos(0.0)
#define max_heap(tmp) priority_queue<tmp>
#define min_heap(tmp) priority_queue<tmp,vector<tmp>,greater<tmp>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
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
#define dec(i,start,end) rng(i,start,end,-1)
#define inc_type(type,i,start,end) rng_type(type,i,start,end,1)
#define dec_type(type,i,start,end) rng_type(type,i,start,end,-1)
#define inc_la_type(type,i,start,end,buffer) rng_la(type,i,start,end,1,buffer)
#define each_key(element,container) for(const auto &element:container)
#define each(element,container) for(auto &element:container)
#define iter_for(it,container) for(auto it = container.begin();it != container.end();it++)
#define iter_rev(it,container) for(auto it = container.rbegin();it != container.rend();it++)
#define until(condition) while(!(condition))
#define sorted(arr) sort(all(arr))
#define custSort(container,comparator) sort(all(container),comparator)
#define cnt(container,value) count(all(container),value)
#define isSorted(container) is_sorted(all(container))
#define rev(arr) reverse(all(arr))
#define rsort(arr) sorted(arr); rev(arr);
#define slice(start,end) substr(start,end - (start) + 1)
#define char_index(c) (c >= 'A' and c <= 'Z' ? c - 'A' : c - 'a')
inline ll llmax(ll a,ll b){
    return a > b ? a : b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
template<typename tmp1,typename tmp2>
vector<pair<tmp1,tmp2>>zipped(vector<tmp1>&arr1,vector<tmp2>&arr2){
    vector<pair<tmp1,tmp2>>ans;
    inc(i,0,arr1.sz()){
        ans.pb({arr1[i],arr2[i]});
    }
    return ans;
}
template<typename tmp>
vec(tmp)uniqueConsec(vector<tmp>&arr){
    vec(tmp)ans;
    inc(i,0,arr.sz()){
        if(ans.sz() is 0 or ans.back() isnt arr[i]){
            ans.pb(arr[i]);
        }
    }
    return ans;
}
template<typename tmp>
vector<pair<int,tmp>>enumerated(vec(tmp)&arr){
    vector<pair<int,tmp>>ans;
    inc(i,0,arr.sz()){
        ans.pb({i,arr[i]});
    }
    return ans;
}
template<typename tmp>
inline void readArray(vec(tmp)&arr,int start = 0){
    inc(i,start,arr.size()){
        cin >> arr[i];
    }
}
template<typename tmp>
inline void readMatrix(vec(tmp)&matrix,int r = 0,int c = 0){
    inc(i,r,matrix.size()){
        inc(j,c,matrix[i].size()){
            cin >> matrix[i][j];
        }
    }
}
template<typename tmp>
inline void writeArray(vec(tmp)&arr,int start = 0){
    inc(i,start,arr.size()){
        cout << arr[i] << " ";
    }
    br();
}
template<typename tmp>
inline tmp findMaxIndex(vec(tmp)&arr,int start = 0){
    tmp ans = start;
    inc(i,start,arr.sz()){
        ans = (arr[ans] > arr[i] ? ans : i);
    }
    return ans;
}
template<typename tmp>
inline tmp findMinIndex(vec(tmp)&arr,int start = 0){
    tmp ans = start;
    inc(i,start,arr.sz()){
        ans = (arr[ans] < arr[i] ? ans : i);
    }
    return ans;
}
template<typename tmp>
inline void writeMatrix(vec(vec(tmp))&matrix,int r = 0,int c = 0){
    inc(i,r,matrix.size()){
        inc(j,c,matrix[i].size()){
            cout << matrix[i][j] << " ";
        }
        br();
    }
}
template<typename tmp> tmp mod(tmp number,tmp base){
    while(number < 0){
        number += base;
    }
    return number % base;
}
template<typename tmp> tmp lcm(tmp a,tmp b){
    return (a / gcd(a,b)) * (b / gcd(a,b));
}
template<typename tmp> tmp ceil(tmp num,tmp den){
    return (num / den) + (num % den != 0);
}
template<typename tmp>
inline bool inBetween(tmp left,tmp mid,tmp right,bool incLeft = true,bool incRight = true){
    return (incLeft ? mid >= left : mid > left) and (incRight ? mid <= right : mid < right);
}
constexpr int inf = 2e9;
constexpr ll linf = 2e18;
void testcase();
class DSU {
    private:
    vi parents,ranks;
    void merge(int smaller,int larger){
        this->parents[smaller] = larger;
        this->ranks[larger] += this->ranks[smaller];
    }
    int find(int x){
        if(this->parents[x] is x){
            return x;
        } else {
            return this->parents[x] = this->find(this->parents[x]);
        }
    }
    public:
    DSU(int n){
        this->parents = vi(n + 1,0);
        this->ranks = vi(n + 1,1);
        inc(i,0,this->parents.sz()){
            this->parents[i] = i;
        }
    }
    void findUnion(int x,int y){
        int parx = this->find(x);
        int pary = this->find(y);
        if(parx isnt pary){
            if(this->ranks[parx] > this->ranks[pary] or parx < pary){
                this->merge(pary,parx);
            } else {
                this->merge(parx,pary);
            }
        }
    }
    bool cycle(int x,int y){
        return this->find(x) is this->find(y);
    }
    vi findComponents(){
        vi ans;
        inc(i,1,this->parents.sz()){
            if(i is this->parents[i]){
                ans.pb(i);
            }
        }
        return ans;
    }
};
set<int>findCommon(vi &first,vi &second);
int main(){
    ios;
    int t = 1;
    // cin >> t;
    while(t--){
        testcase();
    }
    return 0;
}
void testcase(){
    int n,m1,m2;
    cin >> n >> m1 >> m2;
    DSU dsu1(n),dsu2(n);
    while(m1--){
        int u,v;
        cin >> u >> v;
        dsu1.findUnion(u,v);
    }
    while(m2--){
        int u,v;
        cin >> u >> v;
        dsu2.findUnion(u,v);
    }
    vi first = dsu1.findComponents(),second = dsu2.findComponents();
    set<int>common = findCommon(first,second);
    vi arr(all(common));
    set<pii> edges;
    inc(i,1,arr.sz()){
        edges.insert({arr[0],arr[i]});
        dsu1.findUnion(arr[0],arr[i]);
        dsu2.findUnion(arr[0],arr[i]);
    }
    vi notfirst,notsecond;
    each(vertex,first){
        if(common.count(vertex) is false){
            notfirst.pb(vertex);
        }
    }
    each(vertex,second){
        if(common.count(vertex) is false){
            notsecond.pb(vertex);
        }
    }
    inc(i,0,notfirst.sz()){
        inc(j,0,notsecond.sz()){
            if(dsu1.cycle(notfirst[i],notsecond[j]) is false and dsu2.cycle(notfirst[i],notsecond[j]) is false){
                edges.insert({min(notfirst[i],notsecond[j]),max(notfirst[i],notsecond[j])});
                dsu1.findUnion(notfirst[i],notsecond[j]);
                dsu2.findUnion(notfirst[i],notsecond[j]);
            }
        }
    }
    see(edges.sz());
    each(edge,edges){
        see(edge.f << " " << edge.s);
    }
    return;
}
set<int>findCommon(vi &first,vi &second){
    set<int>ans,ref(all(second));
    each(vertex,first){
        if(ref.count(vertex) is true){
            ans.ins(vertex);
        }
    }
    return ans;
}