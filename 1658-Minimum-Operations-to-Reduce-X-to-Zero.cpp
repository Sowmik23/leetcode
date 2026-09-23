class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);

        int remaining = sum - x;
        if(remaining==0) return n;

        int cnt = 0;
        int i = 0, j = 0;

        //now find the max subarray that's sum is equal to remaining
        sum = 0;
        int mx = 0;
        while(j<n){
            sum+=nums[j];
            while(i<n and sum>remaining){
                sum-=nums[i];
                i++;
            }
            if(sum==remaining) mx = max(mx, j-i+1);
            j++;
        }

        if(mx==0) return -1;

        return n-mx;
    }
};