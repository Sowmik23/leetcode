1class Solution {
2public:
3    int getMinDistance(vector<int>& nums, int target, int start) {
4        
5        int i = start, j = start;
6
7        int res = INT_MAX;
8        int n = nums.size();
9
10        while(i>=0 and j<n){
11            if(nums[i] == target) {
12                res = min(res, i);
13                return abs(start - res);
14            } 
15            if(nums[j] == target) {
16                res = min(res, j);
17                return abs(start - res);
18            }
19            i--;
20            j++;
21        }
22        while(i>=0){
23            if(nums[i]==target) return abs(start-i);
24            i--;
25        }
26        while(j<n){
27            if(nums[j]==target) return abs(start-j);
28            j++;
29        }
30        return abs(start-res);
31    }
32};