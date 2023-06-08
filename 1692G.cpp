// Given an array a of length n and an integer k, find the number of indices 1≤i≤n−k such that the subarray [ai,…,ai+k] with length k+1 (not with length k) has the following property:

// If you multiply the first element by 20, the second element by 21, ..., and the (k+1)-st element by 2k, then this subarray is sorted in strictly increasing order.
// More formally, count the number of indices 1≤i≤n−k such that
// 20⋅ai<21⋅ai+1<22⋅ai+2<⋯<2k⋅ai+k.
// Input
// The first line contains an integer t (1≤t≤1000) — the number of test cases.

// The first line of each test case contains two integers n, k (3≤n≤2⋅105, 1≤k<n) — the length of the array and the number of inequalities.

// The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the elements of the array.

// The sum of n across all test cases does not exceed 2⋅105.

// Output
// For each test case, output a single integer — the number of indices satisfying the condition in the statement.
#include<bits/stdc++.h>
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define int long long
using namespace std;
signed main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int start=0,end=0;
        int ans=0;
        while(end+1<arr.size()){
            if(arr[end+1]>arr[end]/2){
                end++;
            } else {
                int length=end-start+1;
                int subarrays=length-k;
                ans+=max<int>(0,subarrays);
                start=++end;
            }
        }
        int length=end-start+1;
        ans+=max<int>(0,length-k);
        cout<<ans<<endl;
    }
    return 0;
}