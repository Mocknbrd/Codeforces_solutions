// After his wife's tragic death, Eurydice, Orpheus descended to the realm of death to see her. Reaching its gates was uneasy, but passing through them proved to be even more challenging. Mostly because of Cerberus, the three-headed hound of Hades.

// Orpheus, a famous poet, and musician plans to calm Cerberus with his poetry and safely walk past him. He created a very peculiar poem for Cerberus. It consists only of lowercase English letters.

// We call a poem's substring a palindrome if and only if it reads the same backwards and forwards. A string a is a substring of a string b if a can be obtained from b by deleting several (possibly zero or all) characters from the beginning and several (possibly zero or all) characters from the end.

// Unfortunately, Cerberus dislikes palindromes of length greater than 1. For example in the poem abaa the hound of Hades wouldn't like substrings aba and aa.

// Orpheus can only calm Cerberus if the hound likes his poetry. That's why he wants to change his poem so that it does not contain any palindrome substrings of length greater than 1.

// Orpheus can modify the poem by replacing a letter at any position with any lowercase English letter. He can use this operation arbitrarily many times (possibly zero). Since there can be many palindromes in his poem, he may have to make some corrections. But how many, exactly? Given the poem, determine the minimal number of letters that have to be changed so that the poem does not contain any palindromes of length greater than 1.

// Input
// The first line of the input contains a single integer t (1≤t≤105) denoting the number of test cases, then t test cases follow.

// The first and only line of each test case contains a non-empty string of lowercase English letters, Orpheus' poem.

// The sum of the length of Orpheus' poems in all test cases will not exceed 105.

// Output
// You should output t lines, i-th line should contain a single integer, answer to the i-th test case.
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
signed main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1] or (i>=2 and s[i]==s[i-2])){
                s[i]='*';
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}