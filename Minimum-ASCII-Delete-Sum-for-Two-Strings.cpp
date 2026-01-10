1class Solution {
2public:
3    int minimumDeleteSum(string s1, string s2) {
4        
5        //Dynamic Programming
6        //Edit Distance variance
7
8        //recursive: O(n*3^n)  n = max(s1.size(), s2.size())
9
10        // return recursive(s1, s2, s1.size()-1, s2.size()-1);
11
12        //recursion with memoization
13
14        vector<vector<int>> memo(s1.size(), vector<int> (s2.size(), -1));
15        //pass by reference, otherwise memory limit exceed
16        return recursionWithMemo(s1, s2, s1.size()-1, s2.size()-1, memo);
17
18        //tabulation
19        //Time: O(m*n)
20        /*
21        int m = s1.size();
22        int n = s2.size();
23        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
24
25        dp[0][0] = 0;
26        
27        //cost when s2=="";
28        for(int i=1;i<=m;i++){
29            dp[i][0] = dp[i-1][0] + getASCIIValue(s1[i-1]);
30        }
31
32        //cost when s1=="";
33        for(int i=1;i<=n;i++){
34            dp[0][i] = dp[0][i-1] + getASCIIValue(s2[i-1]);
35        }
36
37        for(int i=1;i<=m;i++){
38            for(int j=1;j<=n;j++){
39                if(s1[i-1]==s2[j-1]){
40                    dp[i][j] = dp[i-1][j-1];
41                }
42                else {
43                    int deleteS1 = getASCIIValue(s1[i-1]) + dp[i-1][j];
44                    int deleteS2 = getASCIIValue(s2[j-1]) + dp[i][j-1];
45                    int deleteBoth = getASCIIValue(s1[i-1]) + getASCIIValue(s2[j-1]) + dp[i-1][j-1];
46                    dp[i][j] = min({deleteS1, deleteS2, deleteBoth});
47                }
48            }
49        }
50        return dp[m][n];
51        */
52    }
53private:
54    int recursive(string s1, string s2, int i, int j){
55        if(i<0 and j<0) return 0;
56        if(i<0){
57            int d = 0;
58            for(int idx=0;idx<=j;idx++){
59                d+=getASCIIValue(s2[idx]);
60            }
61            return d;
62        }
63        if(j<0) {
64            int d = 0;
65            for(int idx=0;idx<=i;idx++){
66                d+=getASCIIValue(s1[idx]);
67            }
68            return d;
69        }
70
71        if(s1[i]==s2[j]) return recursive(s1, s2, i-1, j-1);
72        else {
73            int a = getASCIIValue(s1[i]) + recursive(s1, s2, i-1, j);
74            int b = getASCIIValue(s2[j]) + recursive(s1, s2, i, j-1);
75            int c = getASCIIValue(s1[i])+getASCIIValue(s2[j]) + recursive(s1, s2, i-1, j-1);
76            return min({a, b});
77        }
78    }
79    int recursionWithMemo(string &s1, string &s2, int i, int j, vector<vector<int>> &memo){
80        if(i<0 and j<0) return 0;
81        if(i<0){
82            int d = 0;
83            for(int idx=0;idx<=j;idx++){
84                d+=getASCIIValue(s2[idx]);
85            }
86            return d;
87        }
88        if(j<0){
89            int d = 0;
90            for(int idx=0;idx<=i;idx++){
91                d+=getASCIIValue(s1[idx]);
92            }
93            return d;
94        }
95        if(memo[i][j]!=-1) return memo[i][j];
96
97        if(s1[i]==s2[j]) return recursionWithMemo(s1, s2, i-1, j-1, memo);
98        else {
99            int a = getASCIIValue(s1[i]) + recursionWithMemo(s1, s2, i-1, j, memo);
100            int b = getASCIIValue(s2[j]) + recursionWithMemo(s1, s2, i, j-1, memo);
101            int c = getASCIIValue(s1[i]) + getASCIIValue(s2[j]) + recursionWithMemo(s1, s2, i-1, j-1, memo);
102            return memo[i][j] = min({a, b, c});
103        }
104    }
105    int getASCIIValue(char ch){
106        return (int) ch;
107    }
108};