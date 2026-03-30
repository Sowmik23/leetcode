1class Solution {
2public:
3    bool checkStrings(string s1, string s2) {
4        
5        int counts[256] = {0};
6
7        for (int i = 0; i < s1.length(); i++) {
8            // int offset = (i & 1) << 7;
9            int offset = (i % 2 == 0) ? 0 : 128;
10            counts[offset + s1[i]]++;
11            counts[offset + s2[i]]--;
12        }
13
14        for (int i = 0; i < 256; i++) {
15            if (counts[i] != 0) {
16                return false;
17            }
18        }
19
20        return true;
21    }
22};