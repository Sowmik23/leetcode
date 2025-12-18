1class Solution {
2public:
3    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
4        
5        int n = prices.size();
6        vector<long long> profitSum(n+1, 0), priceSum(n+1, 0);
7
8        for(int i=0;i<n;i++){
9            profitSum[i+1] = profitSum[i] + prices[i]*strategy[i];
10            priceSum[i+1] = priceSum[i] + prices[i];
11        }
12        long long res = profitSum[n];
13        for(int i=k-1;i<n;i++){
14            long long leftProfit = profitSum[i-k+1];
15            long long rightProfit = profitSum[n] - profitSum[i+1];
16            long long changeProfit = priceSum[i+1] - priceSum[i- k/2 +1];
17            res = max(res, leftProfit + changeProfit + rightProfit);
18        }
19        return res;
20    }
21};