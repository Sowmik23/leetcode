1class Solution {
2public:
3    vector<int> leftRightDifference(vector<int>& nums) {
4        
5        int n = nums.size();
6        vector<int> ans(n);
7
8        int leftSum = 0;
9        for (int i = 0; i < n; ++i) {
10            ans[i] = leftSum;
11            leftSum += nums[i];
12        }
13
14        int rightSum = 0;
15        for (int i = n - 1; i >= 0; --i) {
16            ans[i] = abs(ans[i] - rightSum);
17            rightSum += nums[i];
18        }
19
20        return ans;
21    }
22};