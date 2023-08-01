#include <bits/stdc++.h>
using namespace std;
void testcase();
bool isContained(vector<pair<int,int>> &sortedparts,int left,int right);
pair<int,int> findSegment(vector<pair<int,int>> &sortedparts,int index);
int main(){
    int t = 1;
    cin >> t;
    while(t--){
        testcase();
    }
    return 0;
}
void testcase(){
    int n,m;
    cin >> n >> m;
    string arr;
    cin >> arr;
    vector<pair<int,int>> sortedparts;
    int start = 0;
    while(start < n){
        int end = start + 1;
        while(end < n and arr[end] >= arr[end - 1]){
            end++;
        }
        sortedparts.push_back({start + 1,end});
        start = end;
    }
    set<pair<int,int>>covered;
    while(m--){
        int left,right;
        cin >> left >> right;
        if(isContained(sortedparts,left,right) == false){
            pair<int,int> leftSegment = findSegment(sortedparts,left);
            pair<int,int> rightSegment = findSegment(sortedparts,right);
            int start = left,end = right;
            if(left == leftSegment.first or left - 2 < 0 or arr[left - 2] == '0'){
                start = leftSegment.first;
            }
            if(right == rightSegment.second or right == n or arr[right] == '1'){
                end = rightSegment.second;
            }
            if(start < end){
                covered.insert({start,end});
            }
        }
    }
    if(is_sorted(arr.begin(),arr.end())){
        cout << 1 << endl;
    } else {
        cout << covered.size() + 1 << endl;
    }
    return;
}
bool isContained(vector<pair<int,int>> &sortedparts,int left,int right){
    int start = 0,end = sortedparts.size() - 1;
    while(start <= end){
        int mid = (start + end) >> 1;
        pair<int,int> curr = sortedparts[mid];
        if(left >= curr.first and right <= curr.second){
            return true;
        } else if(left < curr.first){
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return false;
}
pair<int,int> findSegment(vector<pair<int,int>> &sortedparts,int index){
    int start = 0,end = sortedparts.size() - 1;
    while(start <= end){
        int mid = (start + end) >> 1;
        pair<int,int> curr = sortedparts[mid];
        if(index >= curr.first and index <= curr.second){
            return curr;
        } else if(index < curr.first){
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return sortedparts[0];
}