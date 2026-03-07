1class Solution {
2public:
3    int minFlips(string s) {
4        
5        int n = s.size();
6        s += s;
7        string s1, s2;
8        
9        for(int i = 0; i < s.size(); i++) {
10            s1 += i % 2 ? '0' : '1';
11            s2 += i % 2 ? '1' : '0';
12        }
13        int ans1 = 0, ans2 = 0, ans = INT_MAX;
14        for(int i = 0; i < s.size(); i++) {
15            if(s1[i] != s[i]) ++ans1;
16            if(s2[i] != s[i]) ++ans2;
17            if(i >= n) { //the most left element is outside of sliding window, we need to subtract the ans if we did `flip` before.
18                if(s1[i - n] != s[i - n]) --ans1;
19                if(s2[i - n] != s[i - n]) --ans2;
20            }
21            if(i >= n - 1)
22                ans = min({ans1, ans2, ans});
23        }
24        return ans;
25    }
26};