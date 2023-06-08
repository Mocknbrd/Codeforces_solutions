// You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

// Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
// Return the maximum number of points you can earn by applying the above operation some number of times.
#include<iostream>
#include<vector>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int deleteAndEarn(vector<int>&arr);
int solve(vector<int>&values,vector<int>&mem,int index);
int main(){
    ios;
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<deleteAndEarn(arr)<<endl;
    return 0;
}
int deleteAndEarn(vector<int>&arr){
    int size=1e4+1;
    vector<int>values(size,0),mem(size,-1);
    for(int element:arr){
        values[element]+=element;
    }
    return solve(values,mem,0);
}
int solve(vector<int>&values,vector<int>&mem,int index){
    if(index>=values.size()){
        return 0;
    } else if(mem[index]!=-1){
        return mem[index];
    } else {
        int skip=solve(values,mem,index+1);
        int take=values[index]+solve(values,mem,index+2);
        return mem[index]=max(skip,take);
    }
}