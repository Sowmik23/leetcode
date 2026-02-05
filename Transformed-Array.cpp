1class Solution {
2public:
3    vector<int> constructTransformedArray(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> res(n);
6        for (int i = 0; i < n; i++) {
7            res[i] = nums[((i + nums[i]) % n + n) % n];
8        }
9        return res;
10    }
11};