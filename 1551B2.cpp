// This problem is an extension of the problem "Wonderful Coloring - 1". It has quite many differences, so you should read this statement completely.

// Recently, Paul and Mary have found a new favorite sequence of integers a1,a2,…,an. They want to paint it using pieces of chalk of k colors. The coloring of a sequence is called wonderful if the following conditions are met:

// each element of the sequence is either painted in one of k colors or isn't painted;
// each two elements which are painted in the same color are different (i. e. there's no two equal values painted in the same color);
// let's calculate for each of k colors the number of elements painted in the color — all calculated numbers must be equal;
// the total number of painted elements of the sequence is the maximum among all colorings of the sequence which meet the first three conditions.
// E. g. consider a sequence a=[3,1,1,1,1,10,3,10,10,2] and k=3. One of the wonderful colorings of the sequence is shown in the figure.

// The example of a wonderful coloring of the sequence a=[3,1,1,1,1,10,3,10,10,2] and k=3. Note that one of the elements isn't painted.
// Help Paul and Mary to find a wonderful coloring of a given sequence a.

// Input
// The first line contains one integer t (1≤t≤10000) — the number of test cases. Then t test cases follow.

// Each test case consists of two lines. The first one contains two integers n and k (1≤n≤2⋅105, 1≤k≤n) — the length of a given sequence and the number of colors, respectively. The second one contains n integers a1,a2,…,an (1≤ai≤n).

// It is guaranteed that the sum of n over all test cases doesn't exceed 2⋅105.

// Output
// Output t lines, each of them must contain a description of a wonderful coloring for the corresponding test case.

// Each wonderful coloring must be printed as a sequence of n integers c1,c2,…,cn (0≤ci≤k) separated by spaces where

// ci=0, if i-th element isn't painted;
// ci>0, if i-th element is painted in the ci-th color.
// Remember that you need to maximize the total count of painted elements for the wonderful coloring. If there are multiple solutions, print any one.
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
int main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n);
        map<int,vector<int>>occur;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(occur[arr[i]].size()<k){
                occur[arr[i]].push_back(i);
            }
        }
        vector<int>allOccur;
        for(map<int,vector<int>>::iterator it=occur.begin();it!=occur.end();it++){
            for(int &pos:it->second){
                allOccur.push_back(pos);
            }
        }
        while(allOccur.size()%k){
            allOccur.pop_back();
        }
        vector<int>color(arr.size(),0);
        for(int i=0;i<allOccur.size();i++){
            color[allOccur[i]]=i%k+1;
        }
        for(int i=0;i<color.size();i++){
            cout<<color[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}