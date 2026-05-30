1class Solution {
2public:
3    vector<int> bt;
4
5    void update(int x, int v) {
6        for (; x < bt.size(); x += x & -x) {
7            bt[x] = max(bt[x], v);
8        }
9    }
10
11    int query(int x) {
12        int res = 0;
13        for (; x > 0; x -= x & -x) {
14            res = max(res, bt[x]);
15        }
16        return res;
17    }
18
19    vector<bool> getResults(vector<vector<int>>& queries) {
20
21        // Fenwick Tree
22        int mx = 50000;
23
24        set<int> st = {0, mx};
25
26        for (auto& q : queries) {
27            if (q[0] == 1) {
28                st.insert(q[1]);
29            }
30        }
31
32        bt.resize(mx + 1);
33
34        int pre = 0;
35
36        for (int x : st) {
37            if (x == 0) {
38                continue;
39            }
40            update(x, x - pre);
41            pre = x;
42        }
43
44        reverse(queries.begin(), queries.end());
45        vector<bool> ans;
46        for (auto& q : queries) {
47            if (q[0] == 2) {
48                int x = q[1];
49                int sz = q[2];
50                auto it = st.upper_bound(x);
51                --it;
52                int pre = *it;
53                int max_space = query(pre);
54                max_space = max(max_space, x - pre);
55                ans.push_back(max_space >= sz);
56            } else {
57                int x = q[1];
58                auto it = st.find(x);
59                int pre = *prev(it);
60                int nxt = *next(it);
61                update(nxt, nxt - pre);
62                st.erase(it);
63            }
64        }
65
66        reverse(ans.begin(), ans.end());
67
68        return ans;
69    }
70};