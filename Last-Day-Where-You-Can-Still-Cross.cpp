1class Solution {
2public:
3    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
4        
5        // Binary Search + Breadth-First Search
6        int left = 1;
7        int right = row*col;
8
9        while(left<right){
10            int mid = right-(right-left)/2;
11            if(canCross(row, col, cells, mid)){
12                left = mid;
13            }
14            else right = mid-1;
15        }
16        return left;
17    }
18private:
19    vector<int> directions = {1, 0, -1, 0, 1};
20    bool canCross(int row, int col, vector<vector<int>> &cells, int day){
21        vector<vector<int>> grid(row+1, vector<int> (col+1, 0));
22        
23        for(int i=0;i<day;i++){
24            grid[cells[i][0]][cells[i][1]] = 1; //mark cells from the given list as blocked
25        }
26
27        queue<pair<int, int>> q;
28        for(int i=1;i<=col;i++){
29            if(grid[1][i]==0){
30                q.push({1, i});
31                grid[1][i] = 1; //mark as water
32            }
33        }
34
35        while(!q.empty()){
36            pair<int, int> top = q.front();
37            q.pop();
38            int r = top.first;
39            int c = top.second;
40            for(int i=0;i<4;i++){
41                int nr = r + directions[i];
42                int nc = c + directions[i+1];
43                if(nr>0 and nc>0 and nr<=row and nc<=col and grid[nr][nc]==0){
44                    grid[nr][nc] = 1;
45                    if(nr==row) return true;
46                    q.push({nr, nc});
47                }
48            }
49        }
50        return false;
51    }
52};