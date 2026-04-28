1class Solution {
2public:
3    int minOperations(vector<vector<int>>& grid, int x) {
4        
5        //Time: O(m*n * log mn)
6        vector<int> arr;
7        int res = 0;
8
9        for(int i=0;i<grid.size();i++){
10            for(int j=0;j<grid[i].size();j++){
11                arr.push_back(grid[i][j]);
12            }
13        }
14
15        int len = arr.size();
16
17        //find the middle index:: O(n)
18        nth_element(arr.begin(), arr.begin()+len/2, arr.end());
19
20        int median = arr[len/2];
21        for(auto &num: arr){
22            if(num%x != median%x) return -1;
23            res += abs(median-num)/x;
24        }
25        return res;
26    }
27};