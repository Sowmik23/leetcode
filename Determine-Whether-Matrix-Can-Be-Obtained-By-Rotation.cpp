1class Solution {
2public:
3    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
4        
5        bool c[4];
6        memset(c,true,sizeof(c));
7        int n=mat.size();
8
9        for(int i=0;i<n;i++){
10            for(int j=0;j<n;j++) {
11                if(mat[i][j]!=target[i][j]) c[0]=false;
12                if(mat[i][j]!=target[n-j-1][i]) c[1]=false;
13                if(mat[i][j]!=target[n-i-1][n-j-1]) c[2]=false;
14                if(mat[i][j]!=target[j][n-i-1]) c[3]=false;
15            }
16        }
17        return c[0]||c[1]||c[2]||c[3];
18    }
19};