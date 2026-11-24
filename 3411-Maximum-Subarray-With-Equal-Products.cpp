class Solution {
public:
    int maxLength(vector<int>& nums) {
        
        //the main window shrinking logic is: 
        //while gcd is > 1 then shrink otherwise expand

        int left = 0, right = 0;
        int n = nums.size();
        int prod = 1;
        int res = 2;

        while(right<n){
            int x = gcd(prod, nums[right]);
            while(x>1){
                prod/=nums[left];
                left++;
                x = gcd(prod, nums[right]);
            }
            prod*=nums[right];
            res = max(res, right-left+1);
            right++;
        }
        return res;
    }
};