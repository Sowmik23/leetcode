1class LCA {
2public: //TODO: seems very hard 
3
4    LCA(const vector<vector<int>>& edges, const int root = 1) {
5        n = edges.size() + 1;
6        m = (log(n) / log(2)) + 1;
7        e.resize(n + 1);
8        d.resize(n + 1);
9        f.resize(n + 1, vector<int>(m, 0));
10        for (auto& edge : edges) {
11            int u = edge[0];
12            int v = edge[1];
13            e[u].push_back(v);
14            e[v].push_back(u);
15        }
16        dfs(root, 0);
17        for (int i = 1; i < m; i++) {
18            for (int x = 1; x <= n; x++) {
19                f[x][i] = f[f[x][i - 1]][i - 1];
20            }
21        }
22    }
23    void dfs(int x, int fa) {
24        f[x][0] = fa;
25        for (auto& y : e[x]) {
26            if (y == fa) {
27                continue;
28            }
29            d[y] = d[x] + 1;
30            dfs(y, x);
31        }
32    }
33
34    int lca(int x, int y) {
35        if (d[x] > d[y]) {
36            swap(x, y);
37        }
38        for (int i = m - 1; i >= 0; i--) {
39            if (d[x] <= d[f[y][i]]) {
40                y = f[y][i];
41            }
42        }
43        if (x == y) {
44            return x;
45        }
46        for (int i = m - 1; i >= 0; i--) {
47            if (f[y][i] != f[x][i]) {
48                x = f[x][i];
49                y = f[y][i];
50            }
51        }
52        return f[x][0];
53    }
54
55    int dis(int x, int y) { return d[x] + d[y] - d[lca(x, y)] * 2; }
56
57private:
58    int n;
59    int m;
60    vector<int> d;
61    vector<vector<int>> e;
62    vector<vector<int>> f;
63};
64
65const int MOD = 1e9 + 7;
66const int N = 100010;
67int p2[N];
68auto init = [] {
69    p2[0] = 1;
70    for (int i = 1; i < N; i++) {
71        p2[i] = p2[i - 1] * 2 % MOD;
72    }
73    return 0;
74}();
75
76class Solution {
77public:
78    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
79                                  vector<vector<int>>& queries) {
80        LCA lca(edges, 1);
81        int m = queries.size();
82        vector<int> res(m);
83        for (int i = 0; i < m; i++) {
84            int x = queries[i][0];
85            int y = queries[i][1];
86            if (x != y) {
87                res[i] = p2[lca.dis(x, y) - 1];
88            }
89        }
90        return res;
91    }
92};