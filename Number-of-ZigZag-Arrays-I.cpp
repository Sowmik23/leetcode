1class Solution {
2public:
3    int zigZagArrays(int n, int l, int r) {
4        
5        const int MOD = 1000000007;
6        int m = r - l + 1;
7        vector<int> dp(m, 1);
8
9        for (int i = 2; i <= n; i++) {
10            reverse(dp.begin(), dp.end());
11            int sum = 0;
12            for (auto& d : dp)
13                sum = (sum + exchange(d, sum)) % MOD;
14        }
15
16        return ((accumulate(dp.begin(), dp.end(), 0LL) % MOD) << 1) % MOD;
17    }
18};