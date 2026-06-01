1class Solution {
2public:
3    int minimumCost(vector<int>& cost) {
4        
5        sort(cost.rbegin(), cost.rend());
6        int i = 0;
7
8        int totalCost = 0;
9        while(i<cost.size()){
10            totalCost+=cost[i];
11            i++;
12            if(i<cost.size()){
13                totalCost+=cost[i];
14            }
15            i+=2;
16        }
17        return totalCost;
18    }
19};
20// 2 2 5 6 7 9