1class Solution {
2public:
3    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
4        
5        const int mod = 1e9+7;
6        int n = nums.size();
7        for(auto q: queries){
8            int l = q[0];
9            int r = q[1];
10            int k = q[2];
11            int v = q[3];
12            for(int i=l;i<=r;i+=k){
13                nums[i] = (1ll*nums[i]*v)%mod;
14            }
15        }
16        int res = 0;
17        for(auto n: nums) res^=n;
18        return res;
19    }
20};