class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        int idx = 0;
        for(auto &num: nums){
            int d_sum = 0;
            while(num){
                d_sum+=num%10;
                num/=10;
            }
            if(d_sum==idx) return idx;
            idx++;
        }

        return -1;
    }
};