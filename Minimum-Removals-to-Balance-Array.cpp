1class Solution {
2public:
3    int minRemoval(vector<int>& nums, int k) {
4        
5        int n = nums.size();
6        int res = n, j = 0;
7        sort(nums.begin(), nums.end());
8
9        for(int i = 0;i<n;i++){
10            while(j<n and nums[j]<=(long long)k*nums[i]){
11                j++;
12            }
13            res = min(res, n - (j-i));
14        }
15        return res;
16    }
17};