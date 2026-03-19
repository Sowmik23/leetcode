1class Solution {
2public:
3    int numberOfSubmatrices(vector<vector<char>>& grid) {
4        
5        int n = grid.size(), m = grid[0].size();
6        int ans = 0;
7        vector<vector<array<int, 2>>> sum(n + 1, vector<array<int, 2>>(m + 1));
8        for (int i = 0; i < n; i++) {
9            for (int j = 0; j < m; j++) {
10                if (grid[i][j] == 'X') {
11                    sum[i + 1][j + 1][0] =
12                        sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] + 1;
13                    sum[i + 1][j + 1][1] = 1;
14                } else if (grid[i][j] == 'Y') {
15                    sum[i + 1][j + 1][0] =
16                        sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] - 1;
17                    sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
18                } else {
19                    sum[i + 1][j + 1][0] =
20                        sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0];
21                    sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
22                }
23                ans += (!sum[i + 1][j + 1][0] && sum[i + 1][j + 1][1]) ? 1 : 0;
24            }
25        }
26        return ans;
27    }
28};