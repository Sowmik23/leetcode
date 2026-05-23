1class Solution {
2public:
3    bool check(vector<int>& nums) {
4        
5        int n = nums.size();
6        int cnt = 0;
7        for(int i=1;i<n;i++){
8            if(nums[i]<nums[i-1]){
9                cnt++;
10            }
11        }
12        if(nums[0]<nums[n-1]) cnt++;
13        return cnt<=1;
14    }
15};