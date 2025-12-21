1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        
5        const int n = strs.size();
6        int m = strs[0].size();
7        int i, j;
8        vector<bool> arr(n-1, false);
9        int cnt = 0;
10        for( i=0;i<m;i++){
11            for( j=0;j<n-1;j++)
12                if(!arr[j] and strs[j][i]>strs[j+1][i]){
13                    cnt++;
14                    break;
15                }
16            if(j<n-1) continue;
17            for(j=0;j<n-1;j++){
18                if(strs[j][i]<strs[j+1][i]) arr[j] = true;
19            }
20        }
21        return cnt;
22    }
23};