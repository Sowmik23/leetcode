1const int MX = 1000001;
2vector<int> factors[MX];
3bool initialized = []() {
4    for (int i = 2; i < MX; ++i) {
5        if (factors[i].empty()) {
6            for (int j = i; j < MX; j += i) {
7                factors[j].push_back(i);
8            }
9        }
10    }
11    return true;
12}();
13
14class Solution {
15public:
16    int minJumps(vector<int>& nums) {
17        int n = nums.size();
18        unordered_map<int, vector<int>> edges;
19        for (int i = 0; i < n; ++i) {
20            for (int p : factors[nums[i]]) {
21                edges[p].push_back(i);
22            }
23        }
24        int res = 0;
25        vector<bool> seen(n, false);
26        seen[0] = true;
27        vector<int> q = {0};
28        while (true) {
29            vector<int> q2;
30            for (int i : q) {
31                if (i == n - 1) return res;
32                if (i > 0 && !seen[i - 1]) {
33                    seen[i - 1] = true;
34                    q2.push_back(i - 1);
35                }
36                if (i < n - 1 && !seen[i + 1]) {
37                    seen[i + 1] = true;
38                    q2.push_back(i + 1);
39                }
40                if (factors[nums[i]].size() == 1) {
41                    int p = nums[i];
42                    if (edges.count(p)) {
43                        for (int j : edges[p]) {
44                            if (!seen[j]) {
45                                seen[j] = true;
46                                q2.push_back(j);
47                            }
48                        }
49                        edges[p].clear();
50                    }
51                }
52            }
53            q = move(q2);
54            res++;
55        }
56    }
57};