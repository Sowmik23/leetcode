class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        
        //interesting logic

        // If the number of stones of type 0 is even, Alice wins if and only if there is at least one stone of type 1 and at least one stone of type 2.

        // If the number of stones of type 0 is odd, Alice wins if and only if, without considering the stones of type 0, Bob wins and the reason is not that all the stones are eventually removed. Based on the analysis above, this means that either the number of type 1 stones exceeds the number of type 2 stones by more than 2, or the number of type 2 stones exceeds the number of type 1 stones by more than 2.

        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int val : stones) {
            if (int type = val % 3; type == 0) {
                ++cnt0;
            } else if (type == 1) {
                ++cnt1;
            } else {
                ++cnt2;
            }
        }
        if (cnt0 % 2 == 0) {
            return cnt1 >= 1 && cnt2 >= 1;
        }
        return cnt1 - cnt2 > 2 || cnt2 - cnt1 > 2;
    }
};