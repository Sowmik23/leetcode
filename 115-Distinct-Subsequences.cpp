class Solution {
public:
    int numDistinct(string s, string t) {
        
        //dynamic programming
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return recursive(dp, s, t, m, n);
    }
private:
     int recursive(vector<vector<int>> &dp, string s, string t, int i, int j){
        if(j==0) return 1; //base case
        else if(i==0 or j>i) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        unsigned ans = 0;
        if(s[i-1]==t[j-1]) ans = recursive(dp, s, t, i-1, j-1) + recursive(dp, s, t, i-1, j);
        else ans = recursive(dp, s, t, i-1, j);
        return dp[i][j] = ans;
     }
};