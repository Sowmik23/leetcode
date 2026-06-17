1class Solution {
2    typedef long long ll;
3public:
4    char processStr(string s, ll k) {
5
6        //interesting problem
7        int n = s.size();
8        vector<ll> lens;
9        ll len = 0;
10
11        for (auto& ch : s) {
12            if (ch == '*')
13                len = max(len - 1, 0LL);
14            else if (ch == '#')
15                len *= 2;
16            else if (ch != '%')
17                len++;
18
19            lens.push_back(len);
20        }
21
22        if (k >= len) return '.';
23
24        for (int i = n - 1;; i--) {
25            switch (s[i]) {
26            case '*':
27                break;
28            case '#':
29                if (k >= lens[i] / 2)
30                    k -= lens[i] / 2;
31                break;
32            case '%':
33                k = lens[i] - 1 - k;
34                break;
35            default: // s[i] is a character
36                if (lens[i] == k + 1)
37                    return s[i];
38            }
39        }
40    }
41};