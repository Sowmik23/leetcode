1class Solution {
2public:
3    long long maximumProfit(vector<int>& prices, int k) {
4        
5        int n = prices.size();
6        vector<vector<vector<long long>>> memo(n, vector<vector<long long>>(k+1, vector<long long>(3, -1)));
7
8        function<long long(int, int, int)> dfs = [&](int i, int j, int state) -> long long {
9            if(j==0) return 0;
10            if(i==0) return state == 0? 0 : (state==1 ? -prices[0] : prices[0]);
11            if(memo[i][j][state]!=-1) return memo[i][j][state];
12
13            int p = prices[i];
14            long long res;
15            if(state==0) {
16                res = max(dfs(i-1, j, 0), max(
17                    dfs(i-1, j, 1) + p, dfs(i-1, j, 2) -p));
18            } else if(state==1){
19                res = max(dfs(i-1, j, 1), dfs(i-1, j-1, 0)-p);
20            } else {
21                res = max(dfs(i-1, j, 2), dfs(i-1, j-1, 0)+p);
22            }
23            memo[i][j][state] = res;
24            return res;
25        };
26        return dfs(n-1, k, 0);
27    }
28};