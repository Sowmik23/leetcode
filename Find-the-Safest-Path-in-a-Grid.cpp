1class Solution {
2public:
3
4    int maximumSafenessFactor(vector<vector<int>>& grid) {
5        int n = grid.size();
6        queue<pair<int, int>> multiSourceQueue;
7
8        // Mark thieves as 0 and empty cells as -1, and push thieves to the queue
9        for (int i = 0; i < n; i++) {
10            for (int j = 0; j < n; j++) {
11                if (grid[i][j] == 1) {
12                    multiSourceQueue.push({i, j});
13                    grid[i][j] = 0;
14                } else {
15                    grid[i][j] = -1;
16                }
17            }
18        }
19
20        // Calculate safeness factor for each cell using BFS
21        while (!multiSourceQueue.empty()) {
22            int size = multiSourceQueue.size();
23            while (size-- > 0) {
24                auto curr = multiSourceQueue.front();
25                multiSourceQueue.pop();
26                // Check neighboring cells
27                for (auto& d : dir) {
28                    int di = curr.first + d[0];
29                    int dj = curr.second + d[1];
30                    int val = grid[curr.first][curr.second];
31                    // Check if the neighboring cell is valid and unvisited
32                    if (isValidCell(grid, di, dj) && grid[di][dj] == -1) {
33                        grid[di][dj] = val + 1;
34                        multiSourceQueue.push({di, dj});
35                    }
36                }
37            }
38        }
39
40        // Priority queue to prioritize cells with higher safeness factor
41        priority_queue<vector<int>> pq;
42        // Push starting cell to the priority queue
43        pq.push(vector<int>{grid[0][0], 0, 0}); // [maximum_safeness_till_now, x-coordinate, y-coordinate]
44        grid[0][0] = -1; // Mark the source cell as visited
45
46        // BFS to find the path with maximum safeness factor
47        while (!pq.empty()) {
48            auto curr = pq.top();
49            pq.pop();
50
51            // If reached the destination, return safeness factor
52            if (curr[1] == n - 1 && curr[2] == n - 1) {
53                return curr[0];
54            }
55
56            // Explore neighboring cells
57            for (auto& d : dir) {
58                int di = d[0] + curr[1];
59                int dj = d[1] + curr[2];
60                if (isValidCell(grid, di, dj) && grid[di][dj] != -1) {
61                    // Update safeness factor for the path and mark the cell as visited
62                    pq.push(vector<int>{min(curr[0], grid[di][dj]), di, dj});
63                    grid[di][dj] = -1;
64                }
65            }
66        }
67
68        return -1; // No valid path found
69    }
70
71private:
72
73    // Directions for moving to neighboring cells: right, left, down, up
74    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
75
76    // Check if a given cell lies within the grid
77    bool isValidCell(vector<vector<int>>& mat, int i, int j) {
78        int n = mat.size();
79        return i >= 0 && j >= 0 && i < n && j < n;
80    }
81};