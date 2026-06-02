1class Solution {
2public:
3    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
4        
5
6        int n = landStartTime.size();
7        int m = waterStartTime.size();
8        int res = INT_MAX;
9        for (int i = 0; i < n; i++) {
10            for (int j = 0; j < m; j++) {
11                int land = landStartTime[i] + landDuration[i];
12                int land_water =
13                    max(land, waterStartTime[j]) + waterDuration[j];
14                res = min(res, land_water);
15
16                int water = waterStartTime[j] + waterDuration[j];
17                int water_land = max(water, landStartTime[i]) + landDuration[i];
18                res = min(res, water_land);
19            }
20        }
21        return res;
22    }
23};