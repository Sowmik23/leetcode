1class Solution {
2public:
3    long long totalWaviness(long long num1, long long num2) {
4        
5        return calc(num2) - calc(num1 -1);
6    }
7private:
8    long long calc(long long num){
9        if(num<100) return 0;
10        s = to_string(num);
11        memset(vis, 0, sizeof(vis));
12
13        return solve(0, 10, 10, 1,1).second;
14    }
15    string s;
16    long long dp[18][11][11][2][2][2];
17    bool vis[18][11][11][2][2];
18
19    pair<long long, long long> solve(int idx, int pp, int p, bool tight, bool lead){
20        if(idx==s.size()) return {1, 0};
21
22        if(vis[idx][pp][p][tight][lead]) {
23            return {dp[idx][pp][p][tight][lead][0],
24            dp[idx][pp][p][tight][lead][1]};
25        }
26
27        vis[idx][pp][p][tight][lead] = true;
28
29        long long cnt = 0;
30        long long wave = 0;
31
32        int lim = tight ? s[idx] - '0' : 9;
33
34        for (int d = 0; d <= lim; d++) {
35            bool ntight = tight && (d == lim);
36            bool nlead = lead && (d == 0);
37
38            int np = nlead ? 10 : d;
39            int npp = nlead ? 10 : (lead ? 10 : p);
40
41            bool wavy = false;
42            if (pp != 10 && p != 10) {
43                if ((pp < p && p > d) || (pp > p && p < d))
44                    wavy = true;
45            }
46
47            auto [c, w] = solve(idx + 1, npp, np, ntight, nlead);
48
49            cnt += c;
50            wave += w + (wavy ? c : 0);
51        }
52
53        dp[idx][pp][p][tight][lead][0] = cnt;
54        dp[idx][pp][p][tight][lead][1] = wave;
55
56        return {cnt, wave};
57    }
58};