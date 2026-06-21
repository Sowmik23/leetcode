1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        
5        const int MAX_COST = 100000;
6        vector<int> freq(MAX_COST + 1, 0);
7
8        for (int cost : costs) {
9            freq[cost]++;
10        }
11
12        int answer = 0;
13
14        for (int cost = 1; cost <= MAX_COST; cost++) {
15
16            if (freq[cost] == 0) continue;
17
18            int canBuy = min(freq[cost], coins / cost);
19
20            answer += canBuy;
21
22            coins -= canBuy * cost;
23
24            if (coins < cost) continue;
25        }
26
27        return answer;
28    }
29};