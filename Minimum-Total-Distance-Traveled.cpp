1class Solution {
2public:
3    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
4        
5        sort(robot.begin(), robot.end());
6        sort(factory.begin(), factory.end());
7
8        vector<int> factoryPositions;
9        for (auto& f : factory)
10            for (int i = 0; i < f[1]; i++) 
11                factoryPositions.push_back(f[0]);
12
13        int robotCount = robot.size();
14        int factoryCount = factoryPositions.size();
15        vector<vector<long long>> memo(robotCount, vector<long long>(factoryCount, -1));
16
17        return calculateMinDistance(0, 0, robot, factoryPositions, memo);
18    }
19
20    long long calculateMinDistance(int robotIdx, int factoryIdx,
21                                   vector<int>& robot,
22                                   vector<int>& factoryPositions,
23                                   vector<vector<long long>>& memo) {
24        if (robotIdx == robot.size()) return 0;
25        if (factoryIdx == factoryPositions.size()) return 1e12;
26        if (memo[robotIdx][factoryIdx] != -1) return memo[robotIdx][factoryIdx];
27
28        // Option 1: Assign current robot to current factory
29        long long assign = abs(robot[robotIdx] - factoryPositions[factoryIdx]) +
30                           calculateMinDistance(robotIdx + 1, factoryIdx + 1,
31                                                robot, factoryPositions, memo);
32
33        // Option 2: Skip current factory for the current robot
34        long long skip = calculateMinDistance(robotIdx, factoryIdx + 1, robot,
35                                              factoryPositions, memo);
36
37        return memo[robotIdx][factoryIdx] = min(assign, skip); 
38    }
39};