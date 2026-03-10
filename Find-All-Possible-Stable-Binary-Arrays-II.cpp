1class Solution {
2public:
3    int numberOfStableArrays(int zero, int one, int limit) {
4        
5        //TODO: task : memory is overheaded now 
6        int mod = 1e9 + 7;
7        vector<vector<vector<int>>> memo(
8            zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));
9
10        function<int(int, int, int)> dp = [&](int zero, int one,
11                                              int lastBit) -> int {
12            if (zero == 0) {
13                return (lastBit == 0 || one > limit) ? 0 : 1;
14            } else if (one == 0) {
15                return (lastBit == 1 || zero > limit) ? 0 : 1;
16            }
17
18            if (memo[zero][one][lastBit] == -1) {
19                int res = 0;
20                if (lastBit == 0) {
21                    res = (dp(zero - 1, one, 0) + dp(zero - 1, one, 1)) % mod;
22                    if (zero > limit) {
23                        res = (res - dp(zero - limit - 1, one, 1) + mod) % mod;
24                    }
25                } else {
26                    res = (dp(zero, one - 1, 0) + dp(zero, one - 1, 1)) % mod;
27                    if (one > limit) {
28                        res = (res - dp(zero, one - limit - 1, 0) + mod) % mod;
29                    }
30                }
31                memo[zero][one][lastBit] = res % mod;
32            }
33            return memo[zero][one][lastBit];
34        };
35
36        return (dp(zero, one, 0) + dp(zero, one, 1)) % mod;
37    }
38};