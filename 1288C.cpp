// You are given two integers n and m. Calculate the number of pairs of arrays (a,b) such that:

// the length of both arrays is equal to m;
// each element of each array is an integer between 1 and n (inclusive);
// ai≤bi for any index i from 1 to m;
// array a is sorted in non-descending order;
// array b is sorted in non-ascending order.
// As the result can be very large, you should print it modulo 109+7.

// Input
// The only line contains two integers n and m (1≤n≤1000, 1≤m≤10).

// Output
// Print one integer – the number of arrays a and b satisfying the conditions described above modulo 109+7.
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
const int mod=1e9+7;
int mem[1021][21];
int solve(int n,int k);
signed main(){
    ios;
    int n,m;
    cin>>n>>m;
    memset(mem,-1,sizeof(mem));
    cout<<solve(n+2*m-1,2*m)<<endl;
    return 0;
}
int solve(int n,int k){
    if(n<k){
        return 0;
    } else if(k==0){
        return 1;
    } else if(mem[n][k]!=-1){
        return mem[n][k];
    } else {
        return mem[n][k]=solve(n-1,k)+solve(n-1,k-1);
    }
}