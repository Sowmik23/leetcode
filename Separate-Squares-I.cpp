1class Solution {
2public:
3    double separateSquares(vector<vector<int>>& squares) {
4        
5        //binary search on the answer
6
7        double total_area = 0;
8        double mx_y = 0;
9
10        for(auto &point: squares){
11            int x = point[0];
12            int y = point[1];
13            int l = point[2];
14            total_area += (double) l*l;
15            mx_y = max(mx_y, y+l);
16        }
17        double low = 0, high = mx_y;
18        double eps = 1e-5;
19        while(abs(high-low)>eps){
20            double mid = (high+low)/2.0;
21            if(isBalanced(mid, total_area, squares)) high = mid;
22            else low = mid;
23        }
24        return high;
25    }
26private:
27    bool isBalanced(double mid, double &total_area, vector<vector<int>> &squares){
28        double area = 0;
29        for(auto &point: squares){
30            int x = point[0];
31            int y = point[1];
32            int l = point[2];
33            if(y<mid){
34                double ln = min(mid-y, (double)l);
35                area += (double) ln*l;
36            } 
37        }
38        return area >= total_area/2;
39    }
40    double min(double x, double y){
41        return x<y ? x : y;
42    }
43    int max(int x, int y){
44        return x> y ? x: y;
45    }
46};