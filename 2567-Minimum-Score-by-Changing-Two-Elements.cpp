class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        
        int n = nums.size();
        if(n<=3) return 0;

        sort(nums.begin(), nums.end());

        //case: void first 2
        int mx = nums[n-1];
        int mn = nums[2];

        //case: void last 2
        int mx2 = nums[n-3];
        int mn2 = nums[0];

        //case: void first and last one
        int mx3 = nums[n-2];
        int mn3 = nums[1];


        return min({(mx-mn), (mx2-mn2), (mx3-mn3)});

        //We can also do it in O(N):: without sorting and tracking first and last 2 numbers in sorting order
    }
};