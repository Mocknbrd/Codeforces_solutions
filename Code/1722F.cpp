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
int numLs(int upperLeftRow,int upperLeftCol,int bottomRightRow,int bottomRightCol,vector<string>&matrix);
bool inBound(int row,int col,vector<string>&arr);
int main(){
    ios;
    Input(int,t);
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string>matrix(n);
        inc(int,i,0,n){
            cin>>matrix[i];
        }
        bool cornerTouch=false;
        inc_look_ahead(int,row,0,n,1){
            inc_look_ahead(int,col,0,m,1){
                if(matrix[row][col]==matrix[row+1][col+1] and matrix[row][col+1]==matrix[row+1][col] and matrix[row][col]!=matrix[row+1][col]){
                    cornerTouch=true;
                    break;
                }
            }
            if(cornerTouch){
                break;
            }
        }
        if(cornerTouch or n<2 or m<2){
            NN;
        } else {
            bool ans=true;
            inc(int,i,0,n){
                int start=0;
                while(start<m){
                    if(matrix[i][start]=='*'){
                        int end=start;
                        while(end<m and matrix[i][end]==matrix[i][start]){
                            end++;
                        }
                        if(end-start>2){
                            ans=false;
                            break;
                        }
                        start=end;
                    } else {
                        start++;
                    }
                }
                if(!ans){
                    break;
                }
            }
            inc(int,j,0,m){
                int start=0;
                while(start<n){
                    if(matrix[start][j]=='*'){
                        int end=start;
                        while(end<n and matrix[start][j]==matrix[end][j]){
                            end++;
                        }
                        if(end-start>2){
                            ans=false;
                            break;
                        }
                        start=end;
                    } else {
                        start++;
                    }
                }
                if(!ans){
                    break;
                }
            }
            inc(int,i,0,n){
                inc(int,j,0,m){
                    if(matrix[i][j]=='*'){
                        int num=0;
                        num=numLs(i,j,i+1,j+1,matrix)+numLs(i-1,j,i,j+1,matrix)+numLs(i-1,j-1,i,j,matrix)+numLs(i,j-1,i+1,j,matrix);
                        if(num!=1){
                            ans=false;
                            break;
                        }
                    }
                }
                if(!ans){
                    break;
                }
            }
            ans?YY:NN;
        }
    }
    return 0;
}
int numLs(int upperLeftRow,int upperLeftCol,int bottomRightRow,int bottomRightCol,vector<string>&matrix){
    int ans=0;
    if(inBound(upperLeftRow,upperLeftCol,matrix) and inBound(bottomRightRow,bottomRightCol,matrix)){
        vector<vector<string>>patterns={{"**",".*"},{"*.","**"},{".*","**"},{"**","*."}};
        each(pattern,patterns){
            ans+=(matrix[upperLeftRow][upperLeftCol]==pattern[0][0] and matrix[upperLeftRow][bottomRightCol]==pattern[0][1] and matrix[bottomRightRow][upperLeftCol]==pattern[1][0] and matrix[bottomRightRow][bottomRightCol]==pattern[1][1]);
        }
    }
    return ans;
}
bool inBound(int row,int col,vector<string>&arr){
    return row>=0 and row<arr.size() and col>=0 and col<arr[0].size();
}