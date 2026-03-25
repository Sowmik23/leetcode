1class Solution {
2public:
3    bool canPartitionGrid(vector<vector<int>>& grid) {
4        
5        long long Tsum=0;
6        for(auto& row : grid)
7            Tsum+=accumulate(row.begin(), row.end(), 0LL);
8        if (Tsum&1) return 0;
9        const long long target=Tsum/2;
10        const int r=grid.size(), c=grid[0].size();
11        long long rowSum=0, colSum=0;
12        for(int i=0; rowSum<target && i<r; i++){
13            rowSum+=accumulate(grid[i].begin(), grid[i].end(), 0LL);
14        }
15        if (rowSum==target) return 1;
16        for(int j=0; colSum<target && j<c; j++){
17            for(int i=0; i<r; i++) colSum+=grid[i][j];
18        }
19        return colSum==target;
20    }
21};