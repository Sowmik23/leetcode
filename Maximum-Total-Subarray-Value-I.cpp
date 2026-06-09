1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        
5        int m1 = INT_MAX, m2 = INT_MIN;
6        for (int x : nums) {
7            m1 = min(m1, x);
8            m2 = max(m2, x);
9        }
10        return (long long)(m2 - m1) * k;
11    }
12};