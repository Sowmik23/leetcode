1class Solution {
2public:
3    int numSpecial(vector<vector<int>>& mat) {
4
5        int m = mat.size();
6        int n = mat[0].size();
7        unordered_map<int, int> rowMap, colMap;
8        for(int i=0;i<m;i++){
9            for(int j=0;j<n;j++){
10                rowMap[i]+=mat[i][j];
11                colMap[j]+=mat[i][j];
12            }
13        }
14
15        int cnt = 0;
16        for(int i=0;i<m;i++){
17            for(int j=0;j<n;j++){
18                if(mat[i][j]==1 and rowMap[i]==1 and colMap[j]==1) cnt++;
19            }
20        }
21        return cnt;
22    }
23};