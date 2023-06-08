// You are given a regular polygon with n vertices labeled from 1 to n in counter-clockwise order. The triangulation of a given polygon is a set of triangles such that each vertex of each triangle is a vertex of the initial polygon, there is no pair of triangles such that their intersection has non-zero area, and the total area of all triangles is equal to the area of the given polygon. The weight of a triangulation is the sum of weigths of triangles it consists of, where the weight of a triagle is denoted as the product of labels of its vertices.

// Calculate the minimum weight among all triangulations of the polygon.

// Input
// The first line contains single integer n (3≤n≤500) — the number of vertices in the regular polygon.

// Output
// Print one integer — the minimum weight among all triangulations of the given polygon.
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
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
int solve(int n);
int main(){
    ios;
    int n;
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}
int solve(int n){
    vector<vector<int>>dp(n+1,vector<int>(n+1,1e9));
    for(int gap=0;gap<n;gap++){
        for(int i=1,j=i+gap;j<=n;i++,j++){
            if(gap==0 or gap==1){
                dp[i][j]=0;
            } else if(gap==2){
                dp[i][j]=i*(i+1)*(i+2);
            } else {
                for(int k=i+1;k<j;k++){
                    dp[i][j]=min(dp[i][j],i*j*k+dp[i][k]+dp[k][j]);
                }
            }
        }
    }
    return dp[1][n];
}