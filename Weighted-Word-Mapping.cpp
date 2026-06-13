1class Solution {
2public:
3    string mapWordWeights(vector<string>& words, vector<int>& weights) {
4        
5        string ans;
6        ans.reserve(words.size());
7        for (string word : words) {
8            int s = 0;
9            for (char c : word) {
10                s += weights[c - 'a'];
11            }
12            ans += 'z' - s % 26;
13        }
14        return ans;
15    }
16};