1class Solution {
2public:
3    int maximumJumps(vector<int>& nums, int target) {
4        
5        int n = nums.size();
6        vector<int> dp(n, INT_MIN);
7        dp[0] = 0;
8        for(int i=1;i<n;i++){
9            for(int j=0;j<i;j++){
10                if(abs(nums[j]-nums[i]) <= target){
11                    dp[i] = max(dp[i], dp[j]+1);
12                }
13            }
14        }
15        return dp[n-1] < 0 ? -1 : dp[n-1];
16    }
17};