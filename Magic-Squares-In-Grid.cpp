1class Solution {
2public:
3    int numMagicSquaresInside(vector<vector<int>>& grid) {
4        
5        //manual scan
6        //Time: O(m*n)
7        int ans = 0;
8        int m = grid.size();
9        int n = grid[0].size();
10        for (int row = 0; row + 2 < m; row++) {
11            for (int col = 0; col + 2 < n; col++) {
12                if (isMagicSquare(grid, row, col)) {
13                    ans++;
14                }
15            }
16        }
17        return ans;
18    }
19 private:
20    bool isMagicSquare(vector<vector<int>>& grid, int row, int col) {
21        bool seen[10] = {false};
22        for (int i = 0; i < 3; i++) {
23            for (int j = 0; j < 3; j++) {
24                int num = grid[row + i][col + j];
25                if (num < 1 || num > 9) return false;
26                if (seen[num]) return false;
27                seen[num] = true;
28            }
29        }
30
31        // Check if diagonal sums are the same
32        int diagonal1 =
33            grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
34        int diagonal2 =
35            grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];
36
37        if (diagonal1 != diagonal2) return false;
38
39        // Check if all row sums are the same as the diagonal sums
40        int row1 = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
41        int row2 = grid[row + 1][col] + grid[row + 1][col + 1] +
42                   grid[row + 1][col + 2];
43        int row3 = grid[row + 2][col] + grid[row + 2][col + 1] +
44                   grid[row + 2][col + 2];
45
46        if (!(row1 == diagonal1 && row2 == diagonal1 && row3 == diagonal1)) {
47            return false;
48        }
49
50        // Check if all column sums are the same as the diagonal sums
51        int col1 = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
52        int col2 = grid[row][col + 1] + grid[row + 1][col + 1] +
53                   grid[row + 2][col + 1];
54        int col3 = grid[row][col + 2] + grid[row + 1][col + 2] +
55                   grid[row + 2][col + 2];
56
57        if (!(col1 == diagonal1 && col2 == diagonal1 && col3 == diagonal1)) {
58            return false;
59        }
60
61        return true;
62    }   
63};