1class Solution {
2public:
3    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
4        
5        //Only for 10 leetpoints
6
7        vector<vector<int>> tree(n);
8        for (const auto& edge : hierarchy) {
9            tree[edge[0] - 1].push_back(edge[1] - 1);
10        }
11
12        // dp[node][parentBought][budget]
13        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(budget + 1, 0)));
14        dfs(0, present, future, tree, dp, budget);
15
16        int ans = 0;
17        for (int b = 0; b <= budget; ++b) {
18            ans = max(ans, dp[0][0][b]);
19        }
20        return ans;
21    }
22 private:
23    void dfs(int u, const vector<int>& present, const vector<int>& future,
24             const vector<vector<int>>& tree, vector<vector<vector<int>>>& dp, int budget) {
25        // Store children dp
26        vector<pair<vector<int>, vector<int>>> childDPs;
27
28        for (int v : tree[u]) {
29            dfs(v, present, future, tree, dp, budget);
30            childDPs.emplace_back(dp[v][0], dp[v][1]);
31        }
32
33        for (int parentBought = 0; parentBought <= 1; ++parentBought) {
34            int price = parentBought ? present[u] / 2 : present[u];
35            int profit = future[u] - price;
36
37            vector<int> curr(budget + 1, 0);
38
39            // Option 1: don't buy u
40            vector<int> base(budget + 1, 0);
41            for (const auto& child : childDPs) {
42                vector<int> next(budget + 1, 0);
43                for (int b1 = 0; b1 <= budget; ++b1) {
44                    if (base[b1] == 0 && b1 != 0) continue;
45                    for (int b2 = 0; b1 + b2 <= budget; ++b2) {
46                        next[b1 + b2] = max(next[b1 + b2], base[b1] + child.first[b2]);
47                    }
48                }
49                base = move(next);
50            }
51
52            for (int b = 0; b <= budget; ++b) {
53                curr[b] = max(curr[b], base[b]);
54            }
55
56            // Option 2: buy u
57            if (price <= budget) {
58                vector<int> baseBuy(budget + 1, 0);
59                for (const auto& child : childDPs) {
60                    vector<int> next(budget + 1, 0);
61                    for (int b1 = 0; b1 <= budget; ++b1) {
62                        if (baseBuy[b1] == 0 && b1 != 0) continue;
63                        for (int b2 = 0; b1 + b2 <= budget; ++b2) {
64                            next[b1 + b2] = max(next[b1 + b2], baseBuy[b1] + child.second[b2]);
65                        }
66                    }
67                    baseBuy = move(next);
68                }
69
70                for (int b = price; b <= budget; ++b) {
71                    curr[b] = max(curr[b], baseBuy[b - price] + profit);
72                }
73            }
74
75            dp[u][parentBought] = move(curr);
76        }
77    }   
78};