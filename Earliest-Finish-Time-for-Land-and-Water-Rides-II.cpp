1class Solution {
2public:
3    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
4        
5        int land_water =
6            solve(landStartTime, landDuration, waterStartTime, waterDuration);
7        int water_land =
8            solve(waterStartTime, waterDuration, landStartTime, landDuration);
9        return min(land_water, water_land);
10    }
11private:
12    int solve(vector<int>& start1, vector<int>& duration1, vector<int>& start2,
13              vector<int>& duration2) {
14        int finish1 = INT_MAX;
15        for (int i = 0; i < start1.size(); i++) {
16            finish1 = min(finish1, start1[i] + duration1[i]);
17        }
18
19        int finish2 = INT_MAX;
20        for (int i = 0; i < start2.size(); i++) {
21            finish2 = min(finish2, max(start2[i], finish1) + duration2[i]);
22        }
23        return finish2;
24    }
25
26};