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
        Input(string,s);
        map<char,vi>pos;
        inc(int,i,0,s.size()){
            pos[s[i]].push_back(i);
        }
        vi ans(s.size(),0);
        char mini=*min_element(s.begin(),s.end());
        int start=pos[mini][0];
        while(start<s.size()){
            ans[start]=1;
            int next=s.size();
            inc(char,digit,s[start],'9'+1){
                if(pos.count(digit)){
                    int index=upper_bound(pos[digit].begin(),pos[digit].end(),start)-pos[digit].begin();
                    if(index<pos[digit].size()){
                        next=pos[digit][index];
                        break;
                    }
                }
            }
            start=next;
        }
        int index=-1;
        char value='9'+1;
        inc(int,i,0,ans.size()){
            if(ans[i]==0 and s[i]<value){
                index=i;
                value=s[i];
            }
        }
        string one,two;
        inc(int,i,0,ans.size()){
            if(ans[i]==0 or s[i]>value){
                ans[i]=2;
                two+=s[i];
            } else {
                one+=s[i];
            }
        }
        bool first=true,second=true;
        inc_look_ahead(int,i,0,one.size(),1){
            if(one[i]>one[i+1]){
                first=false;
                break;
            }
        }
        inc_look_ahead(int,i,0,two.size(),1){
            if(two[i]>two[i+1]){
                second=false;
                break;
            }
        }
        if(first and second){
            inc(int,i,0,ans.size()){
                cout<<ans[i];
            }
            cout<<endl;
        } else {
            cout<<"-"<<endl;
        }
    }
    return 0;
}