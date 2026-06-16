1class Solution {
2public:
3    string processStr(string s) {
4        
5        //simulation
6        string result = "";
7        for (auto it : s) {
8            if (it == '*') {
9                if (result.size()) {
10                    result.pop_back();
11                }
12            } else if (it == '#') {
13                result += result;
14            } else if (it == '%') {
15                result = string(result.rbegin(), result.rend());
16            } else {
17                result += it;
18            }
19        }
20        return result;
21    }
22};