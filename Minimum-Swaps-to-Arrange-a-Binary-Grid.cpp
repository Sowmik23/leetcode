1class Solution {
2public:
3    int minSwaps(vector<vector<int>>& grid) {
4
5        int n = grid.size();
6        vector<int> zeros(n);
7
8        for(int i=0;i<n;i++){
9            int cnt = 0;
10            for(int j=n-1;j>=0 and grid[i][j]==0; j--) cnt++;
11            zeros[i] = cnt;
12        }
13
14        int swapCnt = 0;
15        for(int i=0;i<n;i++){
16            int need = n-i-1;
17            int j = i;
18            while(j<n and zeros[j]<need) j++;
19            if(j==n) return -1;
20            while(j>i){
21                swap(zeros[j], zeros[j-1]);
22                j--;
23                swapCnt++;
24            }
25        }
26        return swapCnt;
27    }
28};