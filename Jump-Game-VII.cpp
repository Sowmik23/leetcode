1class Solution {
2public:
3    bool canReach(string s, int minJump, int maxJump) {
4        
5        int n = s.length();
6
7        if (s.back() & 1) return false;
8
9        s[0] = 'v';
10        int reach = 0, maxR = maxJump;
11
12        for (int i = minJump; i < n; i++) {
13            if (i > maxR) return false;
14
15            reach += s[i - minJump] == 'v';
16            reach -= (i > maxJump) && s[i - maxJump - 1] == 'v';
17
18            if (reach && (~s[i] & 1)) {
19                s[i] = 'v';
20                maxR = i + maxJump;
21            }
22        }
23
24        return reach;
25    }
26};