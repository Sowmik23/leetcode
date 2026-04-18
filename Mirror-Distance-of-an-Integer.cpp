1class Solution {
2public:
3    int mirrorDistance(int n) {
4        
5        int x = n;
6        int rev = 0;
7        while(x>0){
8            rev = rev * 10 + x%10;
9            x/=10;
10        }
11        return abs(n-rev);
12    }
13};