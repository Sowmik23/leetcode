1class Solution {
2public:
3    long long maxMatrixSum(vector<vector<int>>& matrix) {
4        
5        int m = matrix.size();
6        int n = matrix[0].size();
7        int mnAbsVal = INT_MAX;
8        int neg = 0;
9        long long sum = 0;
10
11        for(int i=0;i<m;i++){
12            for(int j=0;j<n;j++){
13                int x = matrix[i][j];
14                if(x<0) neg++;
15                sum+=abs(x);
16                mnAbsVal = min(mnAbsVal, abs(x));
17            }
18        }
19        if(neg%2!=0) sum -= 2*mnAbsVal;
20        return sum;
21    }
22};