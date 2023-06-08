// You are given a sequence a consisting of n integers a1,a2,…,an, and an integer x. Your task is to make the sequence a sorted (it is considered sorted if the condition a1≤a2≤a3≤⋯≤an holds).

// To make the sequence sorted, you may perform the following operation any number of times you want (possibly zero): choose an integer i such that 1≤i≤n and ai>x, and swap the values of ai and x.

// For example, if a=[0,2,3,5,4], x=1, the following sequence of operations is possible:

// choose i=2 (it is possible since a2>x), then a=[0,1,3,5,4], x=2;
// choose i=3 (it is possible since a3>x), then a=[0,1,2,5,4], x=3;
// choose i=4 (it is possible since a4>x), then a=[0,1,2,3,4], x=5.
// Calculate the minimum number of operations you have to perform so that a becomes sorted, or report that it is impossible.

// Input
// The first line contains one integer t (1≤t≤500) — the number of test cases.

// Each test case consists of two lines. The first line contains two integers n and x (1≤n≤500, 0≤x≤500) — the number of elements in the sequence and the initial value of x.

// The second line contains n integers a1, a2, ..., an (0≤ai≤500).

// The sum of values of n over all test cases in the input does not exceed 500.

// Output
// For each test case, print one integer — the minimum number of operations you have to perform to make a sorted, or −1, if it is impossible
#include <bits/stdc++.h>
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define YY cout<<"YES"<<endl;
#define NN cout<<"NO"<<endl;
#define yy cout<<"Yes"<<endl;
#define nn cout<<"No"<<endl;
#define endl "\n"
#define int long long
using namespace std;
int getFirst(vector<int>&arr,int start,int x);
signed main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ans=0,start=0;
        while(!is_sorted(arr.begin(),arr.end()) and start<arr.size()){
            int next=getFirst(arr,start,x);
            if(next<arr.size()){
                swap(x,arr[next]);
                ans++;
            }
            start=next+1;
        }
        if(is_sorted(arr.begin(),arr.end())){
            cout<<ans<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
    return 0;
}
int getFirst(vector<int>&arr,int start,int x){
    while(start<arr.size() and arr[start]<=x){
        start++;
    }
    return start;
}