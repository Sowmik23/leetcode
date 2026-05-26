1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        
5        unordered_set<char> s(word.begin(), word.end());
6        int ans = 0;
7        for (char c = 'a'; c <= 'z'; c++) {
8            if (s.count(c) && s.count(c - 'a' + 'A')) {
9                ans++;
10            }
11        }
12        return ans;
13    }
14};