#include <bits/stdc++.h>
using namespace std;
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define puts(statement) cout<<statement<<endl
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
#define win(type,it1,it2,init1,init2,end,step) for(type it1=init1,it2=init2;max(it1,it2)<end;it1+=step,it2+=step)
#define win_inc(type,it1,it2,init1,init2,end) win(type,it1,it2,init1,init2,end,1)
#define iter_for(it,container) for(auto it=container.begin();it!=container.end();it++)
#define iter_rev(it,container) for(auto it=container.rbegin();it!=container.rend();it++)
#define sort(arr) sort(arr.begin(),arr.end())
#define rsort(arr) sort(arr); reverse(all(arr));
#define char_index(c) (c>='A' and c<='Z'?c-'A':c-'a')
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
vi findFactors(int n);
int main(){
    ios;
    Input(int,t);
    while(t--){
        Input(string,s);
        vi factors=findFactors(s.size());
        vi cnts(26,0);
        map<char,vi>charpos;
        inc(int,i,0,s.size()){
            cnts[char_index(s[i])]++;
            charpos[s[i]].pb(i);
        }
        vpii sortedCnt;
        inc(int,i,0,26){
            sortedCnt.pb({cnts[i],i});
        }
        rsort(sortedCnt);
        int ans=inf,f=inf;
        each(factor,factors){
            int freq=factor,letters=s.size()/freq;
            if(letters<=26){
                int diff=0;
                inc(int,i,0,26){
                    if(i<letters){
                        diff+=max(0,sortedCnt[i].first-freq);
                    } else {
                        diff+=sortedCnt[i].first;
                    }
                }
                if(diff<ans){
                    ans=diff;
                    f=freq;
                }
            }
        }
        int mask=0;
        inc(int,i,0,s.size()/f){
            mask|=(1<<sortedCnt[i].second);
        }
        vb modify(s.size(),true);
        vi seen(26,0);
        inc(int,i,0,26){
            char character='a'+i;
            if((mask>>i)&1){
                if(charpos[character].size()>=f){
                    mask^=(1<<i);
                    inc(int,j,0,f){
                        modify[charpos[character][j]]=false;
                    }
                    seen[i]=f;
                } else {
                    each(pos,charpos[character]){
                        modify[pos]=false;
                    }
                    seen[i]+=charpos[character].size();
                }
            } 
        }
        inc(int,i,0,s.size()){
            if(modify[i]){
                int replacement=log2(mask&(-mask));
                s[i]='a'+replacement;
                if(++seen[replacement]==f){
                    mask^=(1<<replacement);
                }
            }
        }
        puts(ans);
        puts(s);
    }
    return 0;
}
vi findFactors(int n){
    vi ans;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ans.pb(i);
            if(i!=n/i){
                ans.pb(n/i);
            }
        }
    }
    return ans;
}