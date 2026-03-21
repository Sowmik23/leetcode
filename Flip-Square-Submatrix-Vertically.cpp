1class Solution {
2public:
3    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
4        
5        for(int i0 = x,i1=x+k-1;i0<i1;i0++,i1--){
6            for(int j=y;j<y+k;j++){
7                swap(grid[i0][j], grid[i1][j]);
8            }
9        }
10        return grid;
11    }
12};