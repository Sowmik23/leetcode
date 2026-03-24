1class Solution {
2public:
3    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
4
5     const int MOD = 12345;
6        int n = grid.size(), m = grid[0].size();
7        vector<vector<int>> p(n, vector<int>(m));
8
9        long long suffix = 1;
10        for (int i = n - 1; i >= 0; i--) {
11            for (int j = m - 1; j >= 0; j--) {
12                p[i][j] = suffix;
13                suffix = suffix * grid[i][j] % MOD;
14            }
15        }
16
17        long long prefix = 1;
18        for (int i = 0; i < n; i++) {
19            for (int j = 0; j < m; j++) {
20                p[i][j] = p[i][j] * prefix % MOD;
21                prefix = prefix * grid[i][j] % MOD;
22            }
23        }
24
25        return p;
26    }
27};