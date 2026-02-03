1class Solution {
2public:
3    bool isTrionic(vector<int>& nums) {
4        
5        int n = nums.size(), i = 1;
6        while (i < n && nums[i - 1] < nums[i]) {
7            i++;
8        }
9        int p = i - 1;
10        while (i < n && nums[i - 1] > nums[i]) {
11            i++;
12        }
13        int q = i - 1;
14        while (i < n && nums[i - 1] < nums[i]) {
15            i++;
16        }
17        int flag = i - 1;
18        return (p != 0) && (q != p) && (flag == n - 1 && flag != q);
19    }
20};