#include <bits/stdc++.h>    
using namespace std;
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define see(statement) cout<<statement<<endl
#define YY see("YES")
#define NN see("NO")
#define yy see("Yes")
#define nn see("No")
#define endl "\n"
#define f first
#define Aa see("Alice")
#define AA see("ALICE")
#define Bb see("Bob")
#define BB see("BOB")
#define s second
#define pb push_back
#define rb pop_back
#define gcd(a,b) __gcd(a,b)
#define sz() size()
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
#define vld vector<ld>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pld pair<ll,ld>
#define vpii vector<pii>
#define vpll vector<pll>
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
#define pi 2*acos(0.0)
#define PQ priority_queue
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define loop(type,it,init,condition,update) for(type it=init;condition;update)
#define enum_sub_type(type,submask,mask,equal) loop(type,submask,mask,(equal?submask>=0:submask>0),submask=(submask-1)&mask)
#define enum_sub(submask,mask,equal) enum_sub_type(int,submask,mask,equal) 
#define range_la(type,i,start,end,step,buffer) loop(type,i,start,i+buffer<end,i+=step)
#define inc_la(i,start,end,buffer) range_la(int,i,start,end,1,buffer)
#define range_type(type,i,start,end,step) loop(type,i,start,(step>0?i<end:i>=end),i+=step)
#define range(i,start,end,step) range_type(int,i,start,end,step)
#define inc(i,start,end) range(i,start,end,1)
#define dec(i,start,end) range(i,start,end,-1)
#define inc_type(type,i,start,end) range_type(type,i,start,end,1)
#define dec_type(type,i,start,end) range_type(type,i,start,end,-1)
#define inc_la_type(type,i,start,end,buffer) range_la(type,i,start,end,1,buffer)
#define each(element,container) for(auto &element:container)
#define iter_for(it,container) for(auto it=container.begin();it!=container.end();it++)
#define iter_rev(it,container) for(auto it=container.rbegin();it!=container.rend();it++)
#define sorted(arr) sort(all(arr))
#define custSort(container,comparator) sort(all(container),comparator)
#define cnt(container,value) count(all(container),value)
#define isSorted(container) is_sorted(all(container))
#define rsort(arr) sort(arr); reverse(all(arr));
#define slice(start,end) substr(start,end-(start)+1)
#define rev(arr) reverse(all(arr))
#define char_index(c) (c>='A' and c<='Z'?c-'A':c-'a')
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
template<typename tmp>
inline void inputArray(vector<tmp>&arr,int start=0){
    inc(i,start,arr.size()){
        cin>>arr[i];
    }
}
template<typename tmp>
inline void inputMatrix(vector<vector<tmp>>&matrix,int r=0,int c=0){
    inc(i,r,matrix.size()){
        inc(j,c,matrix[i].size()){
            cin>>matrix[i][j];
        }
    }
}
template<typename tmp> 
inline void printArray(vector<tmp>&arr,int start=0){
    inc(i,start,arr.size()){
        cout<<arr[i]<<" ";
    }
    br();
}
template<typename tmp>
inline void printMatrix(vector<vector<tmp>>&matrix,int r=0,int c=0){
    inc(i,r,matrix.size()){
        inc(j,c,matrix[i].size()){
            cout<<matrix[i][j]<<" ";
        }
        br();
    }
}
template<typename tmp> tmp mod(tmp number,tmp base){
    while(number<0){
        number+=base;
    }
    return number%base;
}
template<typename tmp> tmp lcm(tmp a,tmp b){
    return (a*b)/gcd(a,b);
}
template<typename tmp> tmp ceil(tmp num,tmp den){
    return (num/den)+(num%den!=0);
}
template<typename tmp>
inline bool inBetween(tmp left,tmp mid,tmp right,bool incLeft=true,bool incRight=true){
    return (incLeft?mid>=left:mid>left) and (incRight?mid<=right:mid<right);
}
constexpr int inf=1e9+10;
constexpr ll linf=1e18+10;
const ll llzero=cast(0,ll);
void testCase();
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
    int n,k;
    cin>>n>>k;
    vi arr(n),cnts(31,0);
    inc(i,0,n){
        cin>>arr[i];
        inc(pos,0,31){
            if((arr[i]>>pos)&1){
                continue;
            } else {
                cnts[pos]++;
            }
        }
    }
    dec(pos,30,0){
        if(cnts[pos]<=k and k>0){
            k-=cnts[pos];
            each(value,arr){
                value|=(1<<pos);
            }
        }
    }
    int ans=arr[0];
    each(value,arr){
        ans=(ans&value);
    }
    see(ans);
    return;
}
