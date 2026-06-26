1class Solution {
2public:
3    long long countMajoritySubarrays(vector<int>& nums, int target) {
4        
5        int n = nums.size();
6        vector<int> pre(n*2 + 1, 0);
7
8        pre[n] = 1;
9        int cnt = n;
10        long long res = 0;
11        long long preSum = 0;
12        for(int i=0;i<n;i++){
13            if(nums[i]==target){
14                preSum+=pre[cnt];
15                cnt++;
16                pre[cnt]++;
17            } else {
18                cnt--;
19                preSum -=pre[cnt];
20                pre[cnt]++;
21            }
22            res+=preSum;
23        }
24        return res;
25    }
26};
27