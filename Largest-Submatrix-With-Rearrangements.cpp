1class Solution {
2public:
3    int largestSubmatrix(vector<vector<int>>& matrix) {
4        
5        int m = matrix.size();
6        int n = matrix[0].size();
7        int res = 0;
8
9        for(int i=0;i<m;i++){
10            for(int j=0;j<n;j++){
11                if(matrix[i][j]!=0 and i>0){
12                    matrix[i][j]+=matrix[i-1][j];
13                }
14            }
15
16            vector<int> currRow = matrix[i];
17            sort(currRow.begin(), currRow.end(), greater());
18            for(int j=0;j<n;j++){
19                res = max(res, currRow[j]*(j+1));
20            }
21        }
22        return res;
23    }
24};