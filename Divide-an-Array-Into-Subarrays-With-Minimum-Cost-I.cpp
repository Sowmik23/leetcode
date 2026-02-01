1class Solution {
2public:
3    int minimumCost(vector<int>& nums) {
4
5        int min1 = 100; 
6        int min2 = 100;
7        for(int i = 1; i < nums.size(); i++){
8            if(nums[i] < min1){
9                min2 = min1;
10                min1 = nums[i];
11            }
12            else if(nums[i] < min2){
13                min2 = nums[i];
14            }
15        }
16        return nums[0] + min1 + min2;
17    }
18};