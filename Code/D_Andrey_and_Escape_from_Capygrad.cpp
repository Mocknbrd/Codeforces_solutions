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
class Node{
    public:
    int start,end,value;
    Node*left,*right;
    Node(int start,int end,int value){
        this->start = start;
        this->end = end;
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class SegmentTree{
    private:
    Node*root;
    Node*__build(vi &arr,int start,int end){
        if(start is end){
            Node*node = new Node(start,end,arr[start]);
            return node;
        } else {
            int mid = (start + end) >> 1;
            Node*left = this->__build(arr,start,mid);
            Node*right = this->__build(arr,mid + 1,end);
            Node*node = new Node(start,end,max(left->value,right->value));
            node->left = left;
            node->right = right;
            return node;
        }
    }
    int __query(Node*node,int start,int end){
        if(!node or start > node->end or end < node->start){
            return -inf;
        } elif(node->start >= start and node->end <= end){
            return node->value;
        } else {
            int left = this->__query(node->left,start,end);
            int right = this->__query(node->right,start,end);
            return max(left,right);
        }
    }
    void __update(Node*node,int pos,int value){
        if(!node or pos < node->start or pos > node->end){
            return;
        } elif(node->start is node->end and node->start is pos){
            node->value = max(node->value,value);
        } else {
            this->__update(node->left,pos,value);
            this->__update(node->right,pos,value);
            if(node->left){
                node->value = max(node->value,node->left->value);
            }
            if(node->right){
                node->value = max(node->value,node->right->value);
            }
        }
    }
    public:
    SegmentTree(vi &arr){
        this->root = this->__build(arr,0,arr.sz() - 1);
    }
    int query(int start,int end){
        return this->__query(this->root,start,end);
    }
    void update(int pos,int value){
        this->__update(this->root,pos,value);
    }
};
void testcase();
int main(){
    ios;
    int t = 1;
    cin >> t;
    while(t--){
        testcase();
    }
    return 0;
}
void testcase(){
    int n;
    cin >> n;
    vec(pair(pii,pii))arr(n);
    inc(i,0,n){
        cin >> arr[i].f.f >> arr[i].f.s >> arr[i].s.f >> arr[i].s.s;
    }
    sorted(arr);
    vi begin,end;
    inc(i,0,n){
        begin.pb(arr[i].f.f);
        end.pb(arr[i].f.s);
    }
    int q;
    cin >> q;
    vi ans(begin.sz(),-inf);
    SegmentTree tree(ans);
    ans.back() = arr.back().s.s;
    dec(index,n - 2,0){
        int leftbound = inf,rightbound = -inf;
        {
            int left = index + 1,right = n - 1;
            while(left <= right){
                int mid = (left + right) >> 1;
                if(inBetween(begin[mid],arr[index].s.f,end[mid]) or inBetween(begin[mid],arr[index].s.s,end[mid])){
                    leftbound = mid;
                    right = mid - 1;
                } elif(arr[index].s.s < begin[mid]){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        {
            int left = index + 1,right = n - 1;
            while(left <= right){
                int mid = (left + right) >> 1;
                if(inBetween(begin[mid],arr[index].s.f,end[mid]) or inBetween(begin[mid],arr[index].s.s,end[mid])){
                    rightbound = mid;
                    left = mid + 1;
                } elif(arr[index].s.s < begin[mid]){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        ans[index] = max(arr[index].s.s,tree.query(leftbound,rightbound));
        tree.update(index,ans[index]);
    }
    while(q--){
        int start;
        cin >> start;
        int leftBound = inf,rightBound = -inf;
        {
            int left = 0,right = begin.sz() - 1;
            while(left <= right){
                int mid = (left + right) >> 1;
                if(start >= begin[mid] and start <= end[mid]){
                    leftBound = mid;
                    right = mid - 1;
                } elif(start < begin[mid]){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        {
            int left = 0,right = begin.sz() - 1;
            while(left <= right){
                int mid = (left + right) >> 1;
                if(start >= begin[mid] and start <= end[mid]){
                    rightBound = mid;
                    left = mid + 1;
                } elif(start < begin[mid]){
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        cout << max(start,tree.query(leftBound,rightBound)) << " ";
    }
    br();
    return;
}