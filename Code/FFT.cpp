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
#define loop(it,init,condition,update) for(auto it=init;condition;update)
#define enumerate_subsets(submask,mask,equal) loop(submask,mask,(equal?submask>=0:submask>0),submask=(submask-1)&mask) 
#define range_look_ahead(i,start,buffer,step,end) loop(i,start,i+buffer<end,i+=step)
#define increment_look_ahead(i,start,buffer,end) range_look_ahead(i,start,buffer,1,end)
#define range(i,start,end,step) loop(i,start,(step>0?i<end:i>=end),i+=step)
#define increment(i,start,end) range(i,start,end,1)
#define decrement(i,start,end) range(i,start,end,-1)
#define for_each(element,container) for(auto &element:container)
#define sort(arr) sort(arr.begin(),arr.end())
#define rsort(arr) sort(arr.begin(),arr.end(),greater<auto>())
#define char_index(c,caps) caps?c-'A':c-'a'
#define Input(A,x) A x; cin>>x
#define Init(B,x,value) B x; x=value
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
template<typename tmp>
inline void inputArray(vector<tmp>&arr,int start=0){
    increment(i,start,arr.size()){
        cin>>arr[i];
    }
}
template<typename tmp>
inline void inputMatrix(vector<vector<tmp>>&matrix,int r=0,int c=0){
    increment(i,r,matrix.size()){
        increment(j,c,matrix[i].size()){
            cin>>matrix[i][j];
        }
    }
}
template<typename tmp> 
inline void printArray(vector<tmp>&arr){
    for_each(element,arr){
        cout<<element<<" ";
    }
    cout<<endl;
}
template<typename tmp>
inline void printMatrix(vector<vector<tmp>>&matrix){
    increment(i,0,matrix.size()){
        increment(j,0,matrix[i].size()){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
const int infinity=1e9+7;
const ll linf=1e18+7;
const ll llzero=typecast<ll>(0);
vector<double>polynomialMultiplication(vector<double>&coeff1,vector<double>&coeff2);
vector<cd>FFT(vector<cd>&arr,bool invert);
int main(){
    cout<<"Enter the degrees of the polynomials: ";
    int d1,d2;
    cin>>d1>>d2;
    cout<<"Enter the coefficient representation of the first polynomial: ";
    vector<double>coeff1(d1+1);
    for(int i=0;i<coeff1.size();i++){
        cin>>coeff1[i];
    }
    cout<<"Enter the coefficient representation of the second polynomial: ";
    vector<double>coeff2(d2+1);
    for(int i=0;i<coeff2.size();i++){
        cin>>coeff2[i];
    }
    vector<double>ans=polynomialMultiplication(coeff1,coeff2);
    cout<<"The result of the multiplication of the two polynomials is: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
vector<double>polynomialMultiplication(vector<double>&coeff1,vector<double>&coeff2){
    int d1=coeff1.size()-1,d2=coeff2.size()-1;
    int size=d1+d2+1;
    coeff1.resize(size);
    coeff2.resize(size);
    int requiredSize=1;
    while(requiredSize<size){
        requiredSize<<=1;
    }
    vector<cd>complexCoeff1(coeff1.begin(),coeff1.end());
    vector<cd>complexCoeff2(coeff2.begin(),coeff2.end());
    complexCoeff1.resize(requiredSize);
    complexCoeff2.resize(requiredSize);
    vector<cd>value1=FFT(complexCoeff1,false);
    vector<cd>value2=FFT(complexCoeff2,false);
    for(int i=0;i<requiredSize;i++){
        value1[i]*=value2[i];
    }
    vector<cd>res=FFT(value1,true);
    vector<double>ans(size);
    for(int i=0;i<size;i++){
        ans[i]=real(res[i]);
    }
    return ans;
}
vector<cd>FFT(vector<cd>&arr,bool invert){
    int n=arr.size();
    if(n==1){
        return arr;
    } else {
        vector<cd>even,odd;
        for(int i=0;i<arr.size();i+=2){
            even.push_back(arr[i]);
        }
        for(int i=1;i<arr.size();i+=2){
            odd.push_back(arr[i]);
        }
        vector<cd>evenRes=FFT(even,invert);
        vector<cd>oddRes=FFT(odd,invert);
        vector<cd>ans(n);
        double angle=(2*pi/n)*(invert?-1:1);
        cd w(1),wn(cos(angle),sin(angle));
        for(int i=0;i<n/2;i++){
            ans[i]=evenRes[i]+w*oddRes[i];
            ans[i+n/2]=evenRes[i]-w*oddRes[i];
            if(invert){
                ans[i]/=2;
                ans[i+n/2]/=2;
            }
            w*=wn;
        }
        return ans;
    }
}