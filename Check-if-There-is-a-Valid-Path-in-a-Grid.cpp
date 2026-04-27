1class Solution {
2public:
3    bool hasValidPath(vector<vector<int>>& grid) {
4        
5        int m = grid.size(), n = grid[0].size();
6
7        vector<vector<pair<int, int>>> dir(7);
8        dir[1] = {{0,-1},{0,1}};   // left right
9        dir[2] = {{-1,0},{1,0}};   // up down
10        dir[3] = {{0,-1},{1,0}};   // left down
11        dir[4] = {{0,1},{1,0}};    // right down
12        dir[5] = {{0,-1},{-1,0}};  // left up
13        dir[6] = {{0,1},{-1,0}};   // right up
14
15        queue<pair<int, int>> q;
16        vector<vector<int>> vec(m, vector<int>(n, 0));
17
18        q.push({0, 0});
19        vec[0][0] = 1;
20
21        while(!q.empty()){
22            auto [r, c] = q.front();
23            q.pop();
24
25            if(r==m-1 and c==n-1) return true;
26
27            for(auto [dr,dc]: dir[grid[r][c]]) {
28                int nr = r + dr;
29                int nc = c + dc;
30
31                if(nr<0 or nc<0 or nr>=m or nc>=n or vec[nr][nc]) continue;
32
33                //check reverse connection
34                for(auto [bdr, bdc]: dir[grid[nr][nc]]){
35                    if(nr + bdr == r and nc + bdc == c){
36                        vec[nr][nc] = 1;
37                        q.push({nr, nc});
38                    }
39                }
40            }
41        }
42        return false;
43    }
44};