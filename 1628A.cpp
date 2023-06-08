// Mihai has just learned about the MEX concept and since he liked it so much, he decided to use it right away.

// Given an array a of n non-negative integers, Mihai wants to create a new array b that is formed in the following way:

// While a is not empty:

// Choose an integer k (1≤k≤|a|).
// Append the MEX of the first k numbers of the array a to the end of array b and erase them from the array a, shifting the positions of the remaining numbers in a.
// But, since Mihai loves big arrays as much as the MEX concept, he wants the new array b to be the lexicographically maximum. So, Mihai asks you to tell him what the maximum array b that can be created by constructing the array optimally is.

// An array x is lexicographically greater than an array y if in the first position where x and y differ xi>yi or if |x|>|y| and y is a prefix of x (where |x| denotes the size of the array x).

// The MEX of a set of non-negative integers is the minimal non-negative integer such that it is not in the set. For example, MEX({1,2,3}) =0 and MEX({0,1,2,4,5}) =3.

// Input
// The first line of the input contains a single integer t (1≤t≤100) — the number of test cases. The description of test cases follows.

// The first line of each test case contains a single integer n (1≤n≤2⋅105) — the number of elements in the array a.

// The second line of each test case contains n non-negative integers a1,…,an (0≤ai≤n), where ai is the i-th integer from the array a.

// It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

// Output
// For each test case print m — the length of the maximum array b Mihai can create, followed by m integers denoting the elements of the array b.
#include <bits/stdc++.h>
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define YY cout<<"YES"<<endl
#define NN cout<<"NO"<<endl
#define yy cout<<"Yes"<<endl
#define nn cout<<"No"<<endl
#define endl "\n"
#define ll long long
#define ld long double
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
#define pi 2*acos(0.0)
constexpr int infinity=1e9+7;
constexpr ll linf=1e18+7;
using namespace std;
inline ll llmax(ll a,ll b){
    return a>b?a:b;
}
inline ll llmin(ll a,ll b){
    return a<b?a:b;
}
vector<int>findSuffixMex(vector<int>&arr);
int main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int>suffix=findSuffixMex(arr);
        vector<int>ans;
        int start=0,mex=-1;
        set<int>s;
        map<int,int>cnt;
        int maxi=*max_element(arr.begin(),arr.end());
        for(int i=0;i<=maxi+1;i++){
            s.insert(i);
        }
        while(start<arr.size()){
            int end=start;
            while(end<arr.size() and mex!=suffix[start]){
                s.erase(arr[end]);
                cnt[arr[end]]++;
                mex=*s.begin();
                end++;
            }
            ans.push_back(mex);
            while(start<end){
                if(--cnt[arr[start]]==0){
                    s.insert(arr[start]);
                    cnt.erase(arr[start]);
                }
                start++;
            }
            mex=-1;
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
vector<int>findSuffixMex(vector<int>&arr){
    vector<int>ans(arr.size());
    int maxi=*max_element(arr.begin(),arr.end());
    set<int>s;
    for(int i=0;i<=maxi+1;i++){
        s.insert(i);
    }
    for(int i=arr.size()-1;i>=0;i--){
        s.erase(arr[i]);
        ans[i]=*s.begin();
    }
    return ans;
}