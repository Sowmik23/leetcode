1struct Edge {
2    int u, v, w, type;
3};
4
5class DSU {
6public:
7    vector<int> parent;
8
9    DSU(const vector<int>& p) : parent(p) {}
10
11    int find(int x) {
12        return parent[x] == x ? x : (parent[x] = find(parent[x]));
13    }
14
15    void join(int x, int y) {
16        int px = find(x);
17        int py = find(y);
18        if (px != py) {
19            parent[px] = py;
20        }
21    }
22};
23
24const int MAX_STABILITY = 2e5;
25
26class Solution {
27public:
28    int maxStability(int n, vector<vector<int>>& edges, int k) {
29        int ans = -1;
30
31        if (edges.size() < n - 1) {
32            return -1;
33        }
34
35        vector<Edge> sortedEdges;
36        sortedEdges.reserve(edges.size());
37        for (const auto& edge : edges) {
38            sortedEdges.push_back({edge[0], edge[1], edge[2], edge[3]});
39        }
40
41        vector<Edge> mustEdges;
42        vector<Edge> optionalEdges;
43
44        for (const auto& edge : sortedEdges) {
45            if (edge.type == 1) {
46                mustEdges.push_back(edge);
47            } else {
48                optionalEdges.push_back(edge);
49            }
50        }
51
52        if (mustEdges.size() > n - 1) {
53            return -1;
54        }
55        sort(optionalEdges.begin(), optionalEdges.end(),
56             [](const Edge& a, const Edge& b) { return b.w < a.w; });
57
58        int selectedInit = 0;
59        int mustMinStability = MAX_STABILITY;
60        vector<int> initialParent(n);
61        iota(initialParent.begin(), initialParent.end(), 0);
62        DSU dsuInit(initialParent);
63
64        for (const auto& edge : mustEdges) {
65            if (dsuInit.find(edge.u) == dsuInit.find(edge.v) ||
66                selectedInit == n - 1) {
67                return -1;
68            }
69
70            dsuInit.join(edge.u, edge.v);
71            selectedInit++;
72            mustMinStability = std::min(mustMinStability, edge.w);
73        }
74
75        int l = 0;
76        int r = mustMinStability;
77
78        while (l < r) {
79            int mid = l + ((r - l + 1) >> 1);
80
81            DSU dsu(dsuInit.parent);
82
83            int selected = selectedInit;
84            int doubledCount = 0;
85
86            for (const auto& edge : optionalEdges) {
87                if (dsu.find(edge.u) == dsu.find(edge.v)) {
88                    continue;
89                }
90
91                if (edge.w >= mid) {
92                    dsu.join(edge.u, edge.v);
93                    selected++;
94                } else if (doubledCount < k && edge.w * 2 >= mid) {
95                    doubledCount++;
96                    dsu.join(edge.u, edge.v);
97                    selected++;
98                } else {
99                    break;
100                }
101
102                if (selected == n - 1) {
103                    break;
104                }
105            }
106
107            if (selected != n - 1) {
108                r = mid - 1;
109            } else {
110                ans = mid;
111                l = mid;
112            }
113        }
114
115        return ans;
116    }
117};