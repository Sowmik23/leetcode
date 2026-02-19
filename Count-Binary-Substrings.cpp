1class Solution {
2public:
3    int countBinarySubstrings(string s) {
4        
5        int ans = 0, prev = 0, cur = 1;
6        for (int i = 1; i < s.length(); i++) {
7            if (s[i-1] != s[i]) {
8                ans += min(prev, cur);
9                prev = cur;
10                cur = 1;
11            } else {
12                cur++;
13            }
14        }
15        return ans + min(prev, cur);
16    }
17};