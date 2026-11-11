class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long res = INT_MAX;
        res = min(((long long)cost1*need1 + (long long)cost2*need2), (long long)max(need1, need2)*costBoth);
        if(need1<need2){
            long long x = (long long)need1*costBoth + (long long)(need2-need1)*cost2;
            res = min(res, x);
        } else {
            long long x = (long long)need2*costBoth + (long long)(need1-need2)*cost1;
            res = min(res, x);
        }

        return res;
    }
};