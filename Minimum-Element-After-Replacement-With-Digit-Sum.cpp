1class Solution {
2public:
3    int minElement(vector<int>& nums) {
4        
5        int res = INT_MAX;
6        for(auto &num: nums){
7            int x = num;
8            int sum = 0;
9            while(x){
10                sum+= x%10;
11                x/=10;
12            }
13            res = min(res, sum);
14        }
15        return res;
16    }
17};