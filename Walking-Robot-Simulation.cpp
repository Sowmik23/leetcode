1class Solution {
2public:
3    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
4        
5        set<string> st;
6        for (auto &obs : obstacles) {
7            st.insert(to_string(obs[0]) + " " + to_string(obs[1]));
8        }
9        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
10        int d = 0, x = 0, y = 0, result = 0;
11        for (int c : commands) {
12            if (c == -1) {
13                d++;
14                if (d == 4) {
15                    d = 0;
16                }
17            } 
18            else if (c == -2) {
19                d--;
20                if (d == -1) {
21                    d = 3;
22                }
23            } 
24            else {
25                while (c-- > 0 && !st.count(to_string(x + dirs[d][0]) + " " + to_string(y + dirs[d][1]))) {
26                    x += dirs[d][0];
27                    y += dirs[d][1];
28                }
29            }
30            result = max(result, x * x + y * y);
31        }
32        return result;
33    }
34};