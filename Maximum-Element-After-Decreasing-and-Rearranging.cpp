1class Solution {
2public:
3    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
4
5        sort(arr.begin(), arr.end());
6        int mx = 1;
7
8        for(int i=1;i<arr.size();i++) {
9            if(arr[i]>=mx+1) {
10                mx++;
11            }
12        }
13        return mx;
14    }
15};