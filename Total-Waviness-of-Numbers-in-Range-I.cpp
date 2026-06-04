1class Solution {
2public:
3    int totalWaviness(int num1, int num2) {
4        
5        auto getWaviness = [](int x) -> int {
6            string s = to_string(x);
7            int waviness = 0;
8
9            for (size_t i = 1; i < s.size() - 1; ++i) {
10                bool isPeak = s[i] > s[i - 1] && s[i] > s[i + 1];
11                bool isValley = s[i] < s[i - 1] && s[i] < s[i + 1];
12                if (isPeak || isValley) {
13                    ++waviness;
14                }
15            }
16
17            return waviness;
18        };
19
20        int total = 0;
21        for (int i = num1; i <= num2; ++i) {
22            total += getWaviness(i);
23        }
24
25        return total;
26    }
27};