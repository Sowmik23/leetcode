1class SegTree {
2    vector<int> maxv, minv;
3    int n;
4
5public:
6    SegTree(vector<int>& nums) {
7        n = nums.size();
8        maxv.resize(n * 4);
9        minv.resize(n * 4);
10        build(1, 0, n - 1, nums);
11    }
12
13    void build(int node, int l, int r, vector<int>& nums) {
14        if (l == r) {
15            maxv[node] = minv[node] = nums[l];
16            return;
17        }
18        int m = (l + r) / 2;
19        build(node * 2, l, m, nums);
20        build(node * 2 + 1, m + 1, r, nums);
21        maxv[node] = max(maxv[node * 2], maxv[node * 2 + 1]);
22        minv[node] = min(minv[node * 2], minv[node * 2 + 1]);
23    }
24
25    int queryMax(int node, int l, int r, int ql, int qr) {
26        if (ql <= l && r <= qr) {
27            return maxv[node];
28        }
29        int m = (l + r) / 2, res = INT_MIN;
30        if (ql <= m) {
31            res = max(res, queryMax(node * 2, l, m, ql, qr));
32        }
33        if (qr > m) {
34            res = max(res, queryMax(node * 2 + 1, m + 1, r, ql, qr));
35        }
36        return res;
37    }
38
39    int queryMin(int node, int l, int r, int ql, int qr) {
40        if (ql <= l && r <= qr) {
41            return minv[node];
42        }
43        int m = (l + r) / 2, res = INT_MAX;
44        if (ql <= m) {
45            res = min(res, queryMin(node * 2, l, m, ql, qr));
46        }
47        if (qr > m) {
48            res = min(res, queryMin(node * 2 + 1, m + 1, r, ql, qr));
49        }
50        return res;
51    }
52};
53
54class Solution {
55public:
56    long long maxTotalValue(vector<int>& nums, int k) {
57
58        //TODO
59        int n = nums.size();
60        SegTree seg(nums);
61        priority_queue<tuple<int, int, int>> pq;
62        for (int l = 0; l < n; l++) {
63            pq.emplace(seg.queryMax(1, 0, n - 1, l, n - 1) -
64                           seg.queryMin(1, 0, n - 1, l, n - 1),
65                       l, n - 1);
66        }
67        long long ans = 0;
68        while (k--) {
69            auto [val, l, r] = pq.top();
70            pq.pop();
71            ans += val;
72            if (r > l) {
73                pq.emplace(seg.queryMax(1, 0, n - 1, l, r - 1) -
74                               seg.queryMin(1, 0, n - 1, l, r - 1),
75                           l, r - 1);
76            }
77        }
78        return ans;
79    }
80};