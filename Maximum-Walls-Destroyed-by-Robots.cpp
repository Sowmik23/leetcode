1// class Solution {
2// public:
3//     int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
4        
5//     }
6// };
7
8class Solution {
9    const int LL = 0, LR = 1, RL = 2, RR = 3; 
10public:
11    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
12        robots.push_back(-1), robots.push_back(2e9);
13        distance.push_back(0), distance.push_back(0);
14        vector<int> rIndices(robots.size());
15        iota(rIndices.begin(), rIndices.end(), 0);
16        sort(rIndices.begin(), rIndices.end(), [&](int idx1, int idx2) {
17            return robots[idx1] < robots[idx2];
18        });
19        int wallSize = walls.size();
20        sort(walls.begin(), walls.end());
21        int curr = 0;
22        int lbot = rIndices[curr], rbot = rIndices[curr + 1];
23        // dp[LL/LR/RL/RR]: the directions of the robots around the wall fire to
24        int dp[4] = {0};
25        for (int i = 0; i < wallSize; i++) {
26            while (walls[i] > robots[rbot]) {
27                ++curr;
28                lbot = rIndices[curr];
29                rbot = rIndices[curr + 1];
30                int maxL = max(dp[LL], dp[RL]);
31                int maxR = max(dp[LR], dp[RR]);
32                dp[LL] = dp[LR] = maxL;
33                dp[RL] = dp[RR] = maxR;
34            }
35            dp[LL] += walls[i] >= robots[rbot] - distance[rbot];
36            dp[LR] += walls[i] == robots[rbot];
37            dp[RL] += walls[i] <= robots[lbot] + distance[lbot] 
38                        || walls[i] >= robots[rbot] - distance[rbot];
39            dp[RR] += walls[i] <= robots[lbot] + distance[lbot]
40                        || walls[i] == robots[rbot];
41        }
42        return *max_element(dp, dp + 4);
43    }
44};