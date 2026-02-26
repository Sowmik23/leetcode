1class Solution {
2public:
3    int numSteps(string s) {
4        
5                int N = s.size();
6
7        int operations = 0;
8        int carry = 0;
9        for (int i = N - 1; i > 0; i--) {
10            if (((s[i] - '0') + carry) % 2) {
11                operations += 2;
12                carry = 1;
13            } else {
14                operations++;
15            }
16        }
17
18        return operations + carry;
19    }
20};