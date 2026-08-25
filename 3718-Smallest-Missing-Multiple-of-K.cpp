class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        unordered_set<int> st(nums.begin(), nums.end());

        int i = 1;
        while(true){
            int x = k * i;
            if(st.count(x)>0){
                i++;
                continue;
            }
            return x;
        }
        return 0;
    }
};