// You are given an array of integers nums and an integer target.

// Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.
#include <iostream>
#include <vector>
#include<algorithm>
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0), cout.tie(0);
using namespace std;
int mod = 1e9 + 7;
int numSubSeq(vector<int> &arr, int target);
int multiply(int a, int b);
int power(int b, int e);
int main(){
    ios;
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    cout<<numSubSeq(arr,target)<<endl;
    return 0;
}
int multiply(int a, int b){
    if(b==0){
        return 0;
    } else if(b%2==0){
        int ans=multiply(a,b/2);
        return (ans%mod+ans%mod)%mod;
    } else {
        int ans=multiply(a,b-1);
        return (a%mod+ans%mod)%mod;
    }
}
int power(int b, int e){
    if(e==0){
        return 1;
    } else if(e%2==0){
        int ans=power(b,e/2);
        return multiply(ans,ans);
    } else {
        int ans=power(b,e-1);
        return multiply(b,ans);
    }
}
int numSubSeq(vector<int> &arr, int target){
    sort(arr.begin(),arr.end());
    int start=0,end=0,ans=0;
    while(end<arr.size() and arr[start]+arr[end]<=target){
        end++;
    }
    end--;
    while(start<=end){
        if(arr[start]+arr[end]<=target){
            ans=(ans%mod+power(2,end-start)%mod)%mod;
            start++;
        } else {
            end--;
        }
    }
    return ans;
}