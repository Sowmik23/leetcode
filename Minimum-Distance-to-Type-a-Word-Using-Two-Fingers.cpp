1class Solution {
2public:
3    int minimumDistance(string word) {
4        
5        int n = word.size();
6        int dp[300][26][26];
7
8        for(int i=0;i<n;i++){
9            int t = word[i]-'A';
10            for(int j=0;j<26;j++){
11                for(int k=0;k<26;k++){
12                    dp[i+1][j][k] = 1e6;
13                }
14            }
15
16            for(int j=0;j<26;j++){
17                for(int k=0;k<26;k++){
18                    dp[i+1][j][t] = min(dp[i+1][j][t], dp[i][j][k] + cal(k, t));
19                    dp[i+1][t][k] = min(dp[i+1][t][k], dp[i][j][k] + cal(j, t));
20                }
21            }
22        }
23
24        int res = 1e6;
25        for(int j=0;j<26;j++){
26            for(int k=0;k<26;k++){
27                res = min(res, dp[n][j][k]);
28            }
29        }
30
31        return res;
32    }
33private:
34    int cal(int a, int b){
35        int ax = a/6, ay = a%6, bx = b/6, by = b%6;
36        return abs(ax - bx) + abs(ay - by);
37    }
38};