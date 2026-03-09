1class Solution {
2public:
3    int numberOfStableArrays(int zero, int one, int limit) {
4        //O(zero * one)
5        vector<vector<vector<long long>>> dp(
6            zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2)));
7        long long mod = 1e9 + 7;
8        for (int i = 0; i <= min(zero, limit); i++) {
9            dp[i][0][0] = 1;
10        }
11        for (int j = 0; j <= min(one, limit); j++) {
12            dp[0][j][1] = 1;
13        }
14        for (int i = 1; i <= zero; i++) {
15            for (int j = 1; j <= one; j++) {
16                if (i > limit) {
17                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1] -
18                                  dp[i - limit - 1][j][1];
19                } else {
20                    dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
21                }
22                dp[i][j][0] = (dp[i][j][0] % mod + mod) % mod;
23                if (j > limit) {
24                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0] -
25                                  dp[i][j - limit - 1][0];
26                } else {
27                    dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0];
28                }
29                dp[i][j][1] = (dp[i][j][1] % mod + mod) % mod;
30            }
31        }
32        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
33    }
34};