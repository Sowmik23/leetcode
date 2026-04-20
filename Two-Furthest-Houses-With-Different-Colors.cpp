1class Solution {
2public:
3    int maxDistance(vector<int>& colors) {
4        
5        int n = colors.size();
6        int fromLeft = 0;
7        int fromRight = n-1;
8        while(colors[fromLeft]==colors[n-1]) fromLeft++;
9        while(colors[fromRight]==colors[0]) fromRight--;
10
11        //cout<<fromLeft<<" "<<n-fromLeft-1<<" "<<fromRight<<endl;
12        return max(fromRight, n-fromLeft-1);
13    }
14};