// The only difference between easy and hard versions is constraints.

// You are given a sequence a consisting of n positive integers.

// Let's define a three blocks palindrome as the sequence, consisting of at most two distinct elements (let these elements are a and b, a can be equal b) and is as follows: [a,a,…,ax,b,b,…,by,a,a,…,ax]. There x,y are integers greater than or equal to 0. For example, sequences [], [2], [1,1], [1,2,1], [1,2,2,1] and [1,1,2,1,1] are three block palindromes but [1,2,3,2,1], [1,2,1,2,1] and [1,2] are not.

// Your task is to choose the maximum by length subsequence of a that is a three blocks palindrome.

// You have to answer t independent test cases.

// Recall that the sequence t is a a subsequence of the sequence s if t can be derived from s by removing zero or more elements without changing the order of the remaining elements. For example, if s=[1,2,1,3,1,2,1], then possible subsequences are: [1,1,1,1], [3] and [1,2,1,3,1,2,1], but not [3,2,3] and [1,1,1,1,2].

// Input
// The first line of the input contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

// The first line of the test case contains one integer n (1≤n≤2⋅105) — the length of a. The second line of the test case contains n integers a1,a2,…,an (1≤ai≤200), where ai is the i-th element of a. Note that the maximum value of ai can be up to 200.

// It is guaranteed that the sum of n over all test cases does not exceed 2⋅105 (∑n≤2⋅105).

// Output
// For each test case, print the answer — the maximum possible length of some subsequence of a that is a three blocks palindrome.
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
#define check(statement) cout<<"**************Check: "<<statement<<" **************"<<endl;
constexpr ll LONG_INFINITY=1e18+7;
constexpr int INT_INFINITY=1e9+10;
using namespace std;
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
        int maxElement=*max_element(arr.begin(),arr.end());
        vector<vector<int>>prefix(maxElement+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int element=1;element<=maxElement;element++){
                prefix[element][i+1]=(arr[i]==element)+prefix[element][i];
            }
            ans=max(ans,prefix[arr[i]][i+1]);
        }
        for(int element=1;element<=maxElement;element++){
            int total=prefix[element].back();
            for(int occur=1;occur<=total/2;occur++){
                int first=lower_bound(prefix[element].begin(),prefix[element].end(),occur)-prefix[element].begin();
                int last=upper_bound(prefix[element].begin(),prefix[element].end(),total-occur)-prefix[element].begin()-1;
                if(first<last){
                    for(int middle=1;middle<=maxElement;middle++){
                        if(middle!=element){
                            ans=max(ans,2*occur+prefix[middle][last+1]-prefix[middle][first]);
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}