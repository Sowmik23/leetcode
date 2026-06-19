1class Solution {
2public:
3    int largestAltitude(vector<int>& gain) {
4        
5        int mx = 0;
6        int x = 0;
7        for(int i=0;i<gain.size();i++){
8            x = gain[i]+x;
9            mx = max(mx, x);
10        }
11        return mx;
12    }
13};