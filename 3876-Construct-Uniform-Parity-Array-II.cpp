class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        int mn = nums1[0];
        bool hasOdd = false;
        for(auto &num: nums1){
            if(num<mn) mn = num;
            if(num&1) hasOdd = true;
        }
        if(mn&1) return true; //if mn is odd
        return !hasOdd; //else there is no odd number
    }
};