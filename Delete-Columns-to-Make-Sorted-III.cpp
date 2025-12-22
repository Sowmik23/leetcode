1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        
5        //DP: Longest increasing subsequence 
6
7        int m = strs.size();
8        int n = strs[0].size();
9        int res = n -1;
10        int k;
11        vector<int> dp(n, 1);
12        for(int j=0;j<n;j++){
13            for(int i=0;i<j;i++){
14                for(k=0;k<m;k++){
15                    if(strs[k][i]>strs[k][j]) break;
16                }
17                if(k==m and dp[i]+1>dp[j]){
18                    dp[j] = dp[i] + 1;
19                }
20            }
21            res = min(res, n-dp[j]);
22        }
23        return res;
24    }
25};