1class Solution {
2public:
3    int minPartitions(string n) {
4        
5        int res = 0;
6        for(int i=0;i<n.size();i++){
7            res = max(res, n[i]-'0');
8        }
9        
10        return res;
11    }
12};