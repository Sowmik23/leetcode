1class Solution {
2public:
3    int closestTarget(vector<string>& words, string target, int startIndex) {
4        
5        int n = words.size();
6        int res = n;
7        for (int i = 0; i < n; ++i) {
8            if (words[i] == target) {
9                int dist = abs(i - startIndex);
10                res = min(res, min(dist, n - dist));
11            }
12        }
13
14        return res < n ? res : -1;
15    }
16};