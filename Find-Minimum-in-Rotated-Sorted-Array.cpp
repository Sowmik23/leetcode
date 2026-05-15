1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        
5        int left = 0, right = nums.size()-1, mid;
6        while(left<right){
7            mid = left+(right-left)/2;
8            if(nums[mid]<nums[nums.size()-1]) right = mid;
9            else left = mid+1;
10        }
11        return nums[left];
12    }
13};