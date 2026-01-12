1class Solution {
2public:
3    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
4        
5        int res = 0;
6        int x = points[0][0];
7        int y = points[0][1];
8        for(int i=1;i<points.size();i++){
9            int x1 = points[i][0];
10            int y1 = points[i][1];
11
12            int distance = getDistance(x, y, x1, y1);
13            x = x1;
14            y = y1;
15            res+=distance;
16        }
17        return res;
18    }
19private:
20    int getDistance(int x1, int y1, int x2, int y2){
21        return max(abs(x1-x2), abs(y1-y2));
22    }
23};