// You are given two strings a and b of the same length. Choose an index and split both strings at the same index, splitting a into two strings: aprefix and asuffix where a = aprefix + asuffix, and splitting b into two strings: bprefix and bsuffix where b = bprefix + bsuffix. Check if aprefix + bsuffix or bprefix + asuffix forms a palindrome.

// When you split a string s into sprefix and ssuffix, either ssuffix or sprefix is allowed to be empty. For example, if s = "abc", then "" + "abc", "a" + "bc", "ab" + "c" , and "abc" + "" are valid splits.

// Return true if it is possible to form a palindrome string, otherwise return false.

// Notice that x + y denotes the concatenation of strings x and y.
#include<iostream>
#include<vector>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
bool checkPalindrome(string &a,string &b);
bool isPalindrome(string &s,int start,int end);
bool check(string &a,string &b);
int main(){
    ios;
    string a,b;
    cin>>a>>b;
    cout<<checkPalindrome(a,b)<<endl;
    return 0;
}
bool checkPalindrome(string &a,string &b){
    return check(a,b) or check(b,a);
}
bool check(string &a,string &b){
    int start=0,end=b.size()-1;
    while(start<end){
        if(a[start]!=b[end]){
            break;
        }
        start++;
        end--;
    }
    return start>=end or isPalindrome(a,start,end) or isPalindrome(b,start,end);
}
bool isPalindrome(string &s,int start,int end){
    while(start<end){
        if(s[start++]!=s[end--]){
            return false;
        }
    }
    return true;
}