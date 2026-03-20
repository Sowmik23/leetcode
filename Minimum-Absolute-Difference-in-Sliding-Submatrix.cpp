1class Solution {
2public:
3    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
4        
5        int m = grid.size(), n = grid[0].size();
6        vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1));
7        for (int i = 0; i + k <= m; i++) {
8            for (int j = 0; j + k <= n; j++) {
9                vector<int> kgrid;
10                for (int x = i; x < i + k; x++) {
11                    for (int y = j; y < j + k; y++) {
12                        kgrid.push_back(grid[x][y]);
13                    }
14                }
15                int kmin = INT_MAX;
16                sort(kgrid.begin(), kgrid.end());
17                for (int t = 1; t < kgrid.size(); t++) {
18                    if (kgrid[t] == kgrid[t - 1]) {
19                        continue;
20                    }
21                    kmin = min(kmin, kgrid[t] - kgrid[t - 1]);
22                }
23                if (kmin != INT_MAX) {
24                    res[i][j] = kmin;
25                }
26            }
27        }
28        return res;
29    }
30};