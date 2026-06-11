1class Solution {
2    static constexpr int mod = 1e9 + 7;
3    int qpow(int x, int y) {
4        int res = 1;
5        for (; y; y >>= 1) {
6            if (y & 1) {
7                res = 1ll * res * x % mod;
8            }
9            x = 1ll * x * x % mod;
10        }
11        return res;
12    }
13    int dfs(vector<vector<int>>& g, int x, int f) {
14        int max_dep = 0;
15        for (auto& y : g[x]) {
16            if (y == f) {
17                continue;
18            }
19            max_dep = max(max_dep, dfs(g, y, x) + 1);
20        }
21        return max_dep;
22    }
23
24public:
25    int assignEdgeWeights(vector<vector<int>>& edges) {
26        int n = edges.size() + 1;
27        vector<vector<int>> g(n + 1);
28        for (auto& e : edges) {
29            int u = e[0];
30            int v = e[1];
31            g[u].emplace_back(v);
32            g[v].emplace_back(u);
33        }
34        int max_dep = dfs(g, 1, 0);
35        return qpow(2, max_dep - 1);
36    }
37};