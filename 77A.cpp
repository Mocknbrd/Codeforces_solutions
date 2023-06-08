#include <bits/stdc++.h>
using namespace std;
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define YY cout<<"YES"<<endl
#define NN cout<<"NO"<<endl
#define yy cout<<"Yes"<<endl
#define nn cout<<"No"<<endl
#define endl "\n"
#define typecast static_cast
#define ll long long
#define cd complex<double>
#define ld long double
#define vi vector<int>
#define vll vector<ll>
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
#define loop(type,it,init,condition,update) for(type it=init;condition;update)
#define enum_sub(type,submask,mask,equal) loop(type,submask,mask,(equal?submask>=0:submask>0),submask=(submask-1)&mask) 
#define range_look_ahead(type,i,start,end,step,buffer) loop(type,i,start,i+buffer<end,i+=step)
#define inc_look_ahead(type,i,start,end,buffer) range_look_ahead(type,i,start,end,1,buffer)
#define range(type,i,start,end,step) loop(type,i,start,(step>0?i<end:i>=end),i+=step)
#define inc(type,i,start,end) range(type,i,start,end,1)
#define dec(type,i,start,end) range(type,i,start,end,-1)
#define each(element,container) for(auto &element:container)
#define win(type,it1,it2,init1,init2,end,step) for(type it1=init1,it2=init2;max(it1,it2)<end;it1+=step,it2+=step)
#define win_inc(type,it1,it2,init1,init2,end) win(type,it1,it2,init1,init2,end,1)
#define iter_for(it,container) for(auto it=container.begin();it!=container.end();it++)
#define iter_rev(it,container) for(auto it=container.rbegin();it!=container.rend();it++)
#define sort(arr) sort(arr.begin(),arr.end())
#define rsort(arr) sort(arr); reverse(all(arr));
#define char_index(c) tolower(c)-'a'
#define Input(A,x) A x; cin>>x
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
template<typename tmp>
inline void inputArray(vector<tmp>&arr,int start=0){
    inc(tmp,i,start,arr.size()){
        cin>>arr[i];
    }
}
template<typename tmp>
inline void inputMatrix(vector<vector<tmp>>&matrix,int r=0,int c=0){
    inc(tmp,i,r,matrix.size()){
        inc(tmp,j,c,matrix[i].size()){
            cin>>matrix[i][j];
        }
    }
}
template<typename tmp> 
inline void printArray(vector<tmp>&arr,int start=0){
    inc(int,i,start,arr.size()){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
template<typename tmp>
inline void printMatrix(vector<vector<tmp>>&matrix,int r=0,int c=0){
    inc(tmp,i,r,matrix.size()){
        inc(tmp,j,c,matrix[i].size()){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
}
const int infinity=1e9+7;
const ll linf=1e18+7;
const ll llzero=typecast<ll>(0);
int main(){
    ios;
    map<string,int>mapping;
    vector<string>heros={"Anka","Chapay","Cleo","Troll","Dracul","Snowy","Hexadecimal"};
    inc(int,i,0,heros.size()){
        mapping[heros[i]]=i;
    }
    set<pii>likes;
    Input(int,n);
    while(n--){
        string first,second,third;
        cin>>first>>second>>third;
        likes.insert({mapping[first],mapping[third]});
    }
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    int diff=infinity;
    vi sizes={0,0,0};
    inc(int,first,1,8){
        inc(int,second,1,8){
            inc(int,third,1,8){
                if(first+second+third==7){
                    int a=p1/first,b=p2/second,c=p3/third;
                    if(max({a,b,c})-min({a,b,c})<diff){
                        diff=max({a,b,c})-min({a,b,c});
                        sizes[0]=first;
                        sizes[1]=second;
                        sizes[2]=third;
                    }
                }
            }
        }
    }
    rsort(sizes);
    int left=(1<<8)-1,index=0,liking=0;
    while(left and index<sizes.size()){
        int size=sizes[index];
        int ans=0,maxi=-1;
        enum_sub(int,submask,left,false){
            if(__builtin_popcount(submask)==size){
                int cnt=0;
                each(element,likes){
                    cnt+=((submask>>element.first)&1 and (submask>>element.second)&1);
                }
                if(cnt>maxi){
                    ans=submask;
                    maxi=cnt;
                }
            }
        }
        liking+=maxi;
        left^=ans;
        index++;
    }
    cout<<diff<<" "<<liking<<endl;
    return 0;
}