class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        
        //TIME: O(n)
        //top-down
        // vector<int> dp(n+1, -1);
        // return recursive(0, n, costs, dp);

        //bottom up
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            dp[i] = dp[i-1] + costs[i-1] + 1;
            if(i>=2) dp[i] = min(dp[i], dp[i-2] + costs[i-1] + 4);
            if(i>=3) dp[i] = min(dp[i], dp[i-3] + costs[i-1] + 9);
        }
        return dp[n];
    }
private:
    int recursive(int i, int n, vector<int> &costs, vector<int> &dp){

        if(i==n) return 0;
        //if(i>n) return 99999;
        if(dp[i]!=-1) return dp[i];
        int x = INT_MAX;
        int y = INT_MAX;
        int z = INT_MAX;
        if(i+1<=n) x = costs[i]+1 + recursive(i+1, n, costs, dp);
        if(i+2<=n) y = costs[i+1]+4 + recursive(i+2, n, costs, dp);
        if(i+3<=n) z = costs[i+2]+9 + recursive(i+3, n, costs, dp);
        return dp[i] = min({x, y, z});
    }
};