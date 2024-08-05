#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wc++11-extensions"
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
void testcase();
long long power(int b,int e){
    if(e == 0){
        return 1; 
    } else {
        return b * power(b,e - 1);
    }
}
int main(){
    ios;
    int t = 1;
    cin >> t;
    while(t--){
        testcase();
    }
    return 0;
}
void testcase(){
    int a,b,c;
    long long k;
    cin >> a >> b >> c >> k;
    for(int i = power(10,a - 1); i < power(10,a); i++){
        int left = max(power(10,c - 1) - i,power(10,b - 1));
        int right = min(power(10,b) - 1,power(10,c) - i - 1);
        int length = right - left + 1;
        if(left > right){
            continue;
        }
        if(length >= k){
            int j = left + k - 1;
            cout << i << " + " << j << " = " << i + j << endl;
            return;
        } else {
            k -= length;
        }
    }
    cout << -1 << endl;
    return;
}
#pragma GCC diagnostic pop