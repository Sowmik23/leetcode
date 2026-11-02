class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        //find median then sum the diff
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = nums[n/2];
        int res = 0;
        for(auto &num: nums){
            res += abs(num-median);
        }
        return res;
    }
};