class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int mx = 1;
        int len = 1;
        for(int i=1;i<n;){
            if(nums[i]>nums[i-1]){
                len = 1;
                while(i<n and nums[i]>nums[i-1]) {
                    i++;
                    len++;
                }
                mx = max(mx, len);
            } else if(nums[i]<nums[i-1]){
                len = 1;
                while(i<n and nums[i]<nums[i-1]) {
                    i++;
                    len++;
                }
                mx = max(mx, len);
            } else i++;
        }
        return mx;
    }
};