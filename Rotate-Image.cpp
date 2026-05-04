1class Solution {
2public:
3    void rotate(vector<vector<int>>& matrix) {
4        
5        int m = matrix.size();
6        int n = matrix[0].size();
7        
8        for(int i=0;i<m;i++){
9            for(int j=0;j<i;j++){
10                swap(matrix[i][j], matrix[j][i]);
11            }
12        }
13        
14        for(int i=0;i<m;i++){
15            for(int j=0;j<n/2;j++){
16                swap(matrix[i][j], matrix[i][n-j-1]);
17            }
18        }
19    }
20};