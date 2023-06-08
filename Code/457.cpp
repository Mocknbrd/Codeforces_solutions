#include<iostream>
#include<vector>
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool hasCycle(vector<int>&nums);
int mod(int n,int mod);
int nextIndex(vector<int>&nums,int curr,int first);
int main(){
    ios;
    int n;
    cin>>n;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<hasCycle(nums)<<endl;
    return 0;
}
bool hasCycle(vector<int>&nums){
    int n=nums.size();
    if(n<=1){
        return false;
    } else {
        for(int i=0;i<n;i++){
            int slow=i,fast=i,first=nums[i];
            do{
                int fast=nextIndex(nums,fast,first);
                if(fast!=-1){
                    fast=nextIndex(nums,fast,first);
                    if(fast!=-1){
                        slow=nextIndex(nums,slow,first);
                    }
                }
            } while(slow!=-1 and fast!=-1 and fast!=slow);
            if(slow!=-1 and slow==fast){
                return true;
            } else {
                slow=i;
                while(first*nums[slow]>0){
                    int next=mod(slow+nums[slow],n);
                    nums[slow]=0;
                    slow=next;
                }
            }
        }
        return false;
    }
}
int mod(int n,int mod){
    if(n>=0){
        return n%mod;
    } else {
        return n%mod+mod;
    }
}
int nextIndex(vector<int>&nums,int curr,int first){
    if(first*nums[curr]<=0){
        return -1;
    } else {
        int next=mod(curr+nums[curr],nums.size());
        return next==curr?-1:next;
    }
}