1class Solution {
2public:
3    long long getDescentPeriods(vector<int>& prices) {
4        
5        int n = prices.size();
6        long long res = 1;
7        int prev = 1;
8        for(int i=1;i<n;i++){
9            if(prices[i]==prices[i-1]-1) {
10                prev++;
11            } else prev = 1;
12            res+=prev;
13        }
14        return res;
15    }
16};