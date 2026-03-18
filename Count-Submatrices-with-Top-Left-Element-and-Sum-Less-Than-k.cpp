1class Solution {
2public:
3    int countSubmatrices(vector<vector<int>>& grid, int k) {
4        
5        int n = grid.size(), m = grid[0].size();
6        vector<int> cols(m);
7        int res = 0;
8        for (int i = 0; i < n; i++) {
9            int rows = 0;
10            for (int j = 0; j < m; j++) {
11                cols[j] += grid[i][j];
12                rows += cols[j];
13                if (rows <= k) {
14                    res++;
15                }
16            }
17        }
18        return res;
19    }
20};