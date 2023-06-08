// A sequence a=[a1,a2,…,al] of length l has an ascent if there exists a pair of indices (i,j) such that 1≤i<j≤l and ai<aj. For example, the sequence [0,2,0,2,0] has an ascent because of the pair (1,4), but the sequence [4,3,3,3,1] doesn't have an ascent.

// Let's call a concatenation of sequences p and q the sequence that is obtained by writing down sequences p and q one right after another without changing the order. For example, the concatenation of the [0,2,0,2,0] and [4,3,3,3,1] is the sequence [0,2,0,2,0,4,3,3,3,1]. The concatenation of sequences p and q is denoted as p+q.

// Gyeonggeun thinks that sequences with ascents bring luck. Therefore, he wants to make many such sequences for the new year. Gyeonggeun has n sequences s1,s2,…,sn which may have different lengths.

// Gyeonggeun will consider all n2 pairs of sequences sx and sy (1≤x,y≤n), and will check if its concatenation sx+sy has an ascent. Note that he may select the same sequence twice, and the order of selection matters.

// Please count the number of pairs (x,y) of sequences s1,s2,…,sn whose concatenation sx+sy contains an ascent.

// Input
// The first line contains the number n (1≤n≤100000) denoting the number of sequences.

// The next n lines contain the number li (1≤li) denoting the length of si, followed by li integers si,1,si,2,…,si,li (0≤si,j≤106) denoting the sequence si.

// It is guaranteed that the sum of all li does not exceed 100000.

// Output
// Print a single integer, the number of pairs of sequences whose concatenation has an ascent.
#include<bits/stdc++.h>
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define endl "\n"
#define YY cout<<"YES"<<endl
#define NN cout<<"NO"<<endl
#define yy cout<<"Yes"<<endl
#define nn cout<<"No"<<endl
#define int long long
using namespace std;
signed main(){
    ios;
    int n;
    cin>>n;
    vector<int>first,last;
    for(int i=0;i<n;i++){
        bool isNonIncreasing=true;
        vector<int>arr={static_cast<int>(1e9)};
        int size;
        cin>>size;
        for(int j=0;j<size;j++){
            int curr;
            cin>>curr;
            if(curr>arr.back()){
                isNonIncreasing=false;
            }
            arr.push_back(curr);
        }
        if(isNonIncreasing){
            first.push_back(arr[1]);
            last.push_back(arr.back());
        }
    }
    int ans=0;
    sort(first.begin(),first.end());
    for(int i=0;i<last.size();i++){
        int index=upper_bound(first.begin(),first.end(),last[i])-first.begin();
        ans+=index;
    }
    cout<<n*n-ans<<endl;
    return 0;
}