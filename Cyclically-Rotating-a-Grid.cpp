1class Solution {
2public:
3    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
4        int m = grid.size();
5        int n = grid[0].size();
6        int nlayer = min(m / 2, n / 2);  // level count
7        // enumerate each layer counterclockwise starting from the top-left
8        // corner
9        for (int layer = 0; layer < nlayer; ++layer) {
10            vector<int> r, c,
11                val;  // each element's row index, column index, and value
12            for (int i = layer; i < m - layer - 1; ++i) {  // left
13                r.push_back(i);
14                c.push_back(layer);
15                val.push_back(grid[i][layer]);
16            }
17            for (int j = layer; j < n - layer - 1; ++j) {  // down
18                r.push_back(m - layer - 1);
19                c.push_back(j);
20                val.push_back(grid[m - layer - 1][j]);
21            }
22            for (int i = m - layer - 1; i > layer; --i) {  // right
23                r.push_back(i);
24                c.push_back(n - layer - 1);
25                val.push_back(grid[i][n - layer - 1]);
26            }
27            for (int j = n - layer - 1; j > layer; --j) {  // up
28                r.push_back(layer);
29                c.push_back(j);
30                val.push_back(grid[layer][j]);
31            }
32            int total = val.size();  // total number of elements in each layer
33            int kk = k % total;      // equivalent number of rotations
34            // find the value at each index after rotation
35            for (int i = 0; i < total; ++i) {
36                int idx =
37                    (i + total - kk) % total;  // the index corresponding to the
38                                               // value after rotation
39                grid[r[i]][c[i]] = val[idx];
40            }
41        }
42        return grid;
43    }
44};