1class Solution {
2public:
3    int numOfStrings(vector<string>& patterns, string word) {
4        
5        //KMP
6        auto check = [](const string& pattern, const string& word) -> bool {
7            int m = pattern.size();
8            int n = word.size();
9            // generate the prefix array of the pattern
10            vector<int> pi(m);
11            for (int i = 1, j = 0; i < m; i++) {
12                while (j > 0 && pattern[i] != pattern[j]) {
13                    j = pi[j - 1];
14                }
15                if (pattern[i] == pattern[j]) {
16                    ++j;
17                }
18                pi[i] = j;
19            }
20            // using prefix arrays for matching
21            for (int i = 0, j = 0; i < n; i++) {
22                while (j > 0 && word[i] != pattern[j]) {
23                    j = pi[j - 1];
24                }
25                if (word[i] == pattern[j]) {
26                    ++j;
27                }
28                if (j == m) {
29                    return true;
30                }
31            }
32            return false;
33        };
34
35        int res = 0;
36        for (const string& pattern : patterns) {
37            res += check(pattern, word);
38        }
39        return res;
40    }
41};