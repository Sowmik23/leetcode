1class Solution {
2public:
3    int countMajoritySubarrays(vector<int>& nums, int target) {
4        
5        int n = nums.size();
6        int ans = 0;
7        for (int i = 0; i < n; ++i) {
8            int cnt = 0;
9            for (int j = i; j < n; ++j) {
10                cnt += (nums[j] == target ? 1 : -1);
11                if (cnt > 0) {
12                    ++ans;
13                }
14            }
15        }
16        return ans;
17    }
18};