1class Solution {
2public:
3    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
4        
5        int n = positions.size();
6        vector<int> indices(n), result;
7        stack<int> stack;
8
9        for (int index = 0; index < n; ++index) {
10            indices[index] = index;
11        }
12
13        sort(indices.begin(), indices.end(),
14             [&](int lhs, int rhs) { return positions[lhs] < positions[rhs]; });
15
16        for (int currentIndex : indices) {
17            // Add right-moving robots to the stack
18            if (directions[currentIndex] == 'R') {
19                stack.push(currentIndex);
20            } else {
21                while (!stack.empty() && healths[currentIndex] > 0) {
22                    // Pop the top robot from the stack for collision check
23                    int topIndex = stack.top();
24                    stack.pop();
25
26                    // Top robot survives, current robot is destroyed
27                    if (healths[topIndex] > healths[currentIndex]) {
28                        healths[topIndex] -= 1;
29                        healths[currentIndex] = 0;
30                        stack.push(topIndex);
31                    } else if (healths[topIndex] < healths[currentIndex]) {
32                        // Current robot survives, top robot is destroyed
33                        healths[currentIndex] -= 1;
34                        healths[topIndex] = 0;
35                    } else {
36                        // Both robots are destroyed
37                        healths[currentIndex] = 0;
38                        healths[topIndex] = 0;
39                    }
40                }
41            }
42        }
43
44        // Collect surviving robots
45        for (int index = 0; index < n; ++index) {
46            if (healths[index] > 0) {
47                result.push_back(healths[index]);
48            }
49        }
50        return result;
51    }
52};