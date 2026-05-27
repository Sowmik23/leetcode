1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        vector<int> lastLow(26, -1), firstUp(26, -1);
5        for (int i = 0; i < word.size(); i++) {
6            char c = word[i];
7            if (islower(c)) {
8                lastLow[c - 'a'] = i;
9            } else {
10                if (firstUp[c - 'A'] == -1) {
11                    firstUp[c - 'A'] = i;
12                }
13            }
14        }
15        int ans = 0;
16        for (int i = 0; i < 26; i++) {
17            if (lastLow[i] != -1 && firstUp[i] != -1 &&
18                lastLow[i] < firstUp[i]) {
19                ans++;
20            }
21        }
22        return ans;
23    }
24};