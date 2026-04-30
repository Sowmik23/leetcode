1class Solution {
2public:
3    int maxPathScore(vector<vector<int>>& grid, int k) {
4        
5        int m = grid.size();
6        int n = grid[0].size();
7        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int>(k+1, INT_MIN)));
8        dp[0][0][0] = 0;
9
10        for(int i=0;i<m;i++){
11            for(int j=0;j<n;j++){
12                for(int c=0;c<=k;c++){
13                    if(dp[i][j][c] == INT_MIN) continue;
14                    if(i+1<m){
15                        int val = grid[i+1][j];
16                        int cost = (val==0 ? 0 : 1);
17                        if(c+cost <=k){
18                            dp[i+1][j][c+cost] = max(dp[i+1][j][c+cost], dp[i][j][c] + val);
19                        }
20                    }
21                    if(j+1<n){
22                        int val = grid[i][j+1];
23                        int cost = (val==0 ? 0 : 1);
24                        if(c+cost<=k) {
25                            dp[i][j+1][c+cost] = max(dp[i][j+1][c+cost], dp[i][j][c] + val);
26                        }
27                    }
28                }
29            }
30        }
31        int res = INT_MIN;
32        for(int c=0;c<=k;c++){
33            res = max(res, dp[m-1][n-1][c]);
34        }
35        return res < 0? -1 : res;
36    }
37};