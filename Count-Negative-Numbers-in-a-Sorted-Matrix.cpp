1class Solution {
2public:
3    int countNegatives(vector<vector<int>>& grid) {
4        
5        //Two pointers
6        int n = grid.size();
7        int m = grid[0].size();
8        int i=0, ans=0, j = m-1;
9        while(i<n){
10            if(j>=0 and grid[i][j]<0){
11                j--;
12            }
13            else {
14                i++;
15                
16                ans+=(m-j-1);
17               // cout<<ans<<endl;
18                j = m-1;
19            }
20        }
21        return ans;
22    }
23};