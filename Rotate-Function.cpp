1class Solution {
2public:
3    int maxRotateFunction(vector<int>& nums) {
4        
5        int n = nums.size();
6        int total = accumulate(nums.begin(), nums.end(), 0);
7
8        int sum = 0;
9        for(int i=0;i<n;i++) sum+=nums[i]*i;
10
11        int res = sum;
12        for(int i=n-1;i>0;i--){
13            sum+= total - n*nums[i];
14            res = max(res, sum); 
15        }
16        return res;
17    }
18};