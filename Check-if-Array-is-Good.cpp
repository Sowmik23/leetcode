1class Solution {
2public:
3    bool isGood(vector<int>& nums) {
4
5        int n = nums.size();
6        if(n<2) return false;
7
8        sort(nums.begin(), nums.end());
9
10        if(nums[n-1]!=n-1 or nums[n-2]!=n-1) return false;
11
12        int cnt = 1;
13        for(int i=0;i<n-1;i++){
14            //cout<<cnt<<" "<<nums[i]<<endl;
15            if(nums[i]!=cnt) return false;
16            cnt++;
17        }
18        return true;
19    }
20};