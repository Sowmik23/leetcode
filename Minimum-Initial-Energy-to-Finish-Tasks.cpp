1class Solution {
2public:
3    int minimumEffort(vector<vector<int>>& tasks) {
4        
5        sort(tasks.begin(), tasks.end(), [&](vector<int>& a, vector<int>& b) {
6            return a[1] - a[0] < b[1] - b[0];
7        });
8        int ans = 0;
9        for (auto task : tasks) {
10            ans = max(ans + task[0], task[1]);
11        }
12        return ans;
13    }
14};