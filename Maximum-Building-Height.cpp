1class Solution {
2public:
3    int maxBuilding(int n, vector<vector<int>>& restrictions) {
4        
5        auto&& r = restrictions;
6        // Add restriction (1, 0)
7        r.push_back({1, 0});
8        sort(r.begin(), r.end());
9
10        // Add restriction (n, n-1)
11        if (r.back()[0] != n) {
12            r.push_back({n, n - 1});
13        }
14
15        int m = r.size();
16
17        // Pass restrictions from left to right
18        for (int i = 1; i < m; ++i) {
19            r[i][1] = min(r[i][1], r[i - 1][1] + (r[i][0] - r[i - 1][0]));
20        }
21        // Pass restrictions from right to left
22        for (int i = m - 2; i >= 0; --i) {
23            r[i][1] = min(r[i][1], r[i + 1][1] + (r[i + 1][0] - r[i][0]));
24        }
25
26        int ans = 0;
27        for (int i = 0; i < m - 1; ++i) {
28            // Calculate the maximum height of the buildings between r[i][0] and
29            // r[i][1]
30            int best = ((r[i + 1][0] - r[i][0]) + r[i][1] + r[i + 1][1]) / 2;
31            ans = max(ans, best);
32        }
33
34        return ans;
35    }
36};