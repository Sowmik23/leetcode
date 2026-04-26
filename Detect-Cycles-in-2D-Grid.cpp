1class UnionFind {
2public:
3    vector<int> parent;
4    vector<int> size;
5    int n;
6    int setCount;
7
8public:
9    UnionFind(int _n) : n(_n), setCount(_n), parent(_n), size(_n, 1) {
10        iota(parent.begin(), parent.end(), 0);
11    }
12
13    int findset(int x) {
14        return parent[x] == x ? x : parent[x] = findset(parent[x]);
15    }
16
17    void unite(int x, int y) {
18        if (size[x] < size[y]) {
19            swap(x, y);
20        }
21        parent[y] = x;
22        size[x] += size[y];
23        --setCount;
24    }
25
26    bool findAndUnite(int x, int y) {
27        int parentX = findset(x);
28        int parentY = findset(y);
29        if (parentX != parentY) {
30            unite(parentX, parentY);
31            return true;
32        }
33        return false;
34    }
35};
36class Solution {
37public:
38    bool containsCycle(vector<vector<char>>& grid) {
39        
40        int m = grid.size();
41        int n = grid[0].size();
42        UnionFind uf(m * n);
43        for (int i = 0; i < m; ++i) {
44            for (int j = 0; j < n; ++j) {
45                if (i > 0 && grid[i][j] == grid[i - 1][j]) {
46                    if (!uf.findAndUnite(i * n + j, (i - 1) * n + j)) {
47                        return true;
48                    }
49                }
50                if (j > 0 && grid[i][j] == grid[i][j - 1]) {
51                    if (!uf.findAndUnite(i * n + j, i * n + j - 1)) {
52                        return true;
53                    }
54                }
55            }
56        }
57        return false;
58    }
59};