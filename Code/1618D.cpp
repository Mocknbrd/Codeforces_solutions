// You are given an array a of n integers, and another integer k such that 2k≤n.

// You have to perform exactly k operations with this array. In one operation, you have to choose two elements of the array (let them be ai and aj; they can be equal or different, but their positions in the array must not be the same), remove them from the array, and add ⌊aiaj⌋ to your score, where ⌊xy⌋ is the maximum integer not exceeding xy.

// Initially, your score is 0. After you perform exactly k operations, you add all the remaining elements of the array to the score.

// Calculate the minimum possible score you can get.

// Input
// The first line of the input contains one integer t (1≤t≤500) — the number of test cases.

// Each test case consists of two lines. The first line contains two integers n and k (1≤n≤100; 0≤k≤⌊n2⌋).

// The second line contains n integers a1,a2,…,an (1≤ai≤2⋅105).

// Output
// Print one integer — the minimum possible score you can get.
#include <iostream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <cstring>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define int long long
using namespace std;
int solve(vector<int>&arr,int k);
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
        sort(arr.begin(),arr.end(),greater<int>());
        cout<<solve(arr,k)<<endl;
    }
    return 0;
}
int solve(vector<int>&arr,int k){
    vector<int>denominator,numerator;
    for(int i=0;i<k;i++){
        denominator.push_back(arr[i]);
    }
    for(int i=k;i<2*k;i++){
        numerator.push_back(arr[i]);
    }
    int ans=0;
    for(int i=2*k;i<arr.size();i++){
        ans+=arr[i];
    }
    for(int i=0;i<k;i++){
        ans+=numerator[i]/denominator[i];
    }
    return ans;
}