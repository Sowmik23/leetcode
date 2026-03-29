1class Solution {
2public:
3    bool canBeEqual(string s1, string s2) {
4
5        return ((s1[0] == s2[0] && s1[2] == s2[2]) ||
6                (s1[0] == s2[2] && s1[2] == s2[0])) &&
7               ((s1[1] == s2[1] && s1[3] == s2[3]) ||
8                (s1[1] == s2[3] && s1[3] == s2[1]));
9    }
10};