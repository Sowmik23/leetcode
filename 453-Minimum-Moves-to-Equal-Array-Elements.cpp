class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int mn = INT_MAX;
        for(auto &num: nums) mn =min(mn, num);

        int moves = 0;
        for(auto &num: nums){
            moves+=(num-mn);
        }
        return moves;
    }
};