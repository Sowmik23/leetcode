1class Solution {
2public:
3    int maxProductPath(vector<vector<int>>& grid) {
4        
5        //Learn to respect negative number
6        //Time: O(mn)
7
8        const int mod = 1000000000 + 7;
9        int m = grid.size(), n = grid[0].size();
10        vector<vector<long long>> maxgt(m, vector<long long>(n));
11        vector<vector<long long>> minlt(m, vector<long long>(n));
12
13        maxgt[0][0] = minlt[0][0] = grid[0][0];
14        for (int i = 1; i < n; i++) {
15            maxgt[0][i] = minlt[0][i] = maxgt[0][i - 1] * grid[0][i];
16        }
17        for (int i = 1; i < m; i++) {
18            maxgt[i][0] = minlt[i][0] = maxgt[i - 1][0] * grid[i][0];
19        }
20
21        for (int i = 1; i < m; i++) {
22            for (int j = 1; j < n; j++) {
23                if (grid[i][j] >= 0) {
24                    maxgt[i][j] =
25                        max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
26                    minlt[i][j] =
27                        min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
28                } else {
29                    maxgt[i][j] =
30                        min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
31                    minlt[i][j] =
32                        max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
33                }
34            }
35        }
36        if (maxgt[m - 1][n - 1] < 0) {
37            return -1;
38        } else {
39            return maxgt[m - 1][n - 1] % mod;
40        }
41    }
42};