#include <bits/stdc++.h>
using namespace std;
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define puts(statement) cout<<statement<<endl
#define cin(statement) cin>>statement
#define YY puts("YES")
#define NN puts("NO")
#define yy puts("Yes")
#define nn puts("No")
#define endl "\n"
#define pb push_back
#define rb pop_back
#define typecast static_cast
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
#define enum_sub(type,submask,mask,equal) loop(type,submask,mask,(equal?submask>=0:submask>0),submask=(submask-1)&mask) 
#define range_look_ahead(type,i,start,end,step,buffer) loop(type,i,start,i+buffer<end,i+=step)
#define inc_look_ahead(type,i,start,end,buffer) range_look_ahead(type,i,start,end,1,buffer)
#define range(type,i,start,end,step) loop(type,i,start,(step>0?i<end:i>=end),i+=step)
#define inc(type,i,start,end) range(type,i,start,end,1)
#define dec(type,i,start,end) range(type,i,start,end,-1)
#define each(element,container) for(auto &element:container)
#define iter_for(it,container) for(auto it=container.begin();it!=container.end();it++)
#define iter_rev(it,container) for(auto it=container.rbegin();it!=container.rend();it++)
#define sort(arr) sort(arr.begin(),arr.end())
#define rsort(arr) sort(arr); reverse(all(arr));
#define slice(start,end) substr(start,end-start+1)
#define char_index(c) (c>='A' and c<='Z'?c-'A':c-'a')
#define Input(A,x) A x; cin>>x
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
template<typename tmp>
tmp mod(tmp number,tmp base){
    while(number<0){
        number+=base;
    }
    return number%base;
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
template<typename tmp>
inline bool inBetween(tmp left,tmp mid,tmp right,bool incLeft=true,bool incRight=true){
    return (incLeft?mid>=left:mid>left) and (incRight?mid<=right:mid<right);
}
constexpr int inf=1e9+7;
constexpr ll linf=1e18+7;
int main(){
    ios;
    Input(int,t);
    while(t--){
        Input(int,n);
        vector<string>arr(n);
        inc(int,i,0,n){
            cin>>arr[i];
        }
        map<int,int>up,down,left,right;
        inc(int,r,0,n){
            inc(int,c,0,n){
                if(arr[r][c]=='1'){
                    up[mod(r-c,n)]++;
                    down[mod(c-r,n)]++;
                    left[mod(c-r,n)]++;
                    right[mod(r-c,n)]++;
                }
            }
        }
        int dir=0,shift=0,maxi=0;
        vector<map<int,int>>mapvec={up,down,left,right};
        inc(int,i,0,4){
            each(element,mapvec[i]){
                if(element.second>maxi){
                    dir=i+1;
                    shift=element.first;
                    maxi=element.second;
                }
            }
        }
        int ans=0;
        inc(int,r,0,n){
            inc(int,c,0,n){
                int nr=r,nc=c;
                switch(dir){
                    case 1: nr=mod(nr-shift,n);
                        break;
                    case 2: nr=mod(nr+shift,n);
                        break;
                    case 3: nc=mod(nc-shift,n);
                        break;
                    default: nc=mod(nc+shift,n);
                        break;
                }
                ans+=((arr[r][c]=='0' and nr==nc) or (arr[r][c]=='1' and nr!=nc));
            }
        }
        puts(ans);
    }
    return 0;
}