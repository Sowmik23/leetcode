1using vll = std::vector<long long>;
2
3class Solution {
4public:
5    long long maximumScore(vector<vector<int>>& grid) {
6        
7        // cpy pst
8        int n = grid[0].size();
9        if (n == 1) {
10            return 0;
11        }
12
13        vector<vector<vll>> dp(n, vector<vll>(n + 1, vll(n + 1, 0)));
14        vector<vll> prevMax(n + 1, vll(n + 1, 0));
15        vector<vll> prevSuffixMax(n + 1, vll(n + 1, 0));
16        vector<vll> colSum(n, vll(n + 1, 0));
17
18        for (int c = 0; c < n; c++) {
19            for (int r = 1; r <= n; r++) {
20                colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
21            }
22        }
23
24        for (int i = 1; i < n; i++) {
25            for (int currH = 0; currH <= n; currH++) {
26                for (int prevH = 0; prevH <= n; prevH++) {
27                    if (currH <= prevH) {
28                        long long extraScore =
29                            colSum[i][prevH] - colSum[i][currH];
30                        dp[i][currH][prevH] =
31                            std::max(dp[i][currH][prevH],
32                                     prevSuffixMax[prevH][0] + extraScore);
33                    } else {
34                        long long extraScore =
35                            colSum[i - 1][currH] - colSum[i - 1][prevH];
36                        dp[i][currH][prevH] = std::max(
37                            {dp[i][currH][prevH], prevSuffixMax[prevH][currH],
38                             prevMax[prevH][currH] + extraScore});
39                    }
40                }
41            }
42
43            for (int currH = 0; currH <= n; currH++) {
44                prevMax[currH][0] = dp[i][currH][0];
45                for (int prevH = 1; prevH <= n; prevH++) {
46                    long long penalty =
47                        (prevH > currH) ? (colSum[i][prevH] - colSum[i][currH])
48                                        : 0;
49                    prevMax[currH][prevH] =
50                        std::max(prevMax[currH][prevH - 1],
51                                 dp[i][currH][prevH] - penalty);
52                }
53
54                prevSuffixMax[currH][n] = dp[i][currH][n];
55                for (int prevH = n - 1; prevH >= 0; prevH--) {
56                    prevSuffixMax[currH][prevH] = std::max(
57                        prevSuffixMax[currH][prevH + 1], dp[i][currH][prevH]);
58                }
59            }
60        }
61
62        long long ans = 0;
63        for (int k = 0; k <= n; k++) {
64            ans = std::max({ans, dp[n - 1][n][k], dp[n - 1][0][k]});
65        }
66
67        return ans;
68
69    }
70};