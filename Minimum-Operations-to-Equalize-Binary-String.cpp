1class Solution {
2public:
3    int minOperations(string s, int k) {
4        int zero = 0;
5        int len = s.length();
6
7        for (int i = 0; i < len; i++)
8            zero += ~s[i] & 1;
9
10        if (!zero)
11            return 0;
12
13        if (len == k)
14            return ((zero == len) << 1) - 1;
15
16        int base = len - k;
17
18        int odd = max(
19            (zero + k - 1) / k,
20            (len - zero + base - 1) / base
21        );
22
23        odd += ~odd & 1;
24
25        int even = max(
26            (zero + k - 1) / k,
27            (zero + base - 1) / base
28        );
29
30        even += even & 1;
31
32        int res = INT_MAX;
33
34        if ((k & 1) == (zero & 1))
35            res = min(res, odd);
36
37        if (~zero & 1)
38            res = min(res, even);
39
40        return res == INT_MAX ? -1 : res;
41    }
42};