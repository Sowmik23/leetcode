1class Solution {
2public:
3    int maximalRectangle(vector<vector<char>>& matrix) {
4         if(matrix.empty()) return 0;
5    const int m = matrix.size();
6    const int n = matrix[0].size();
7    int left[n], right[n], height[n];
8    fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);
9    int maxA = 0;
10    for(int i=0; i<m; i++) {
11        int cur_left=0, cur_right=n; 
12        for(int j=0; j<n; j++) { // compute height (can do this from either side)
13            if(matrix[i][j]=='1') height[j]++; 
14            else height[j]=0;
15        }
16        for(int j=0; j<n; j++) { // compute left (from left to right)
17            if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
18            else {left[j]=0; cur_left=j+1;}
19        }
20        // compute right (from right to left)
21        for(int j=n-1; j>=0; j--) {
22            if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);
23            else {right[j]=n; cur_right=j;}    
24        }
25        // compute the area of rectangle (can do this from either side)
26        for(int j=0; j<n; j++)
27            maxA = max(maxA,(right[j]-left[j])*height[j]);
28    }
29    return maxA;
30    }
31};