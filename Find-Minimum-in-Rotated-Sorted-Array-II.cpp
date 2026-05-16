1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        
5        int n = nums.size() - 1;
6        int last = nums[n];
7        int left = 0, right = n;
8
9        while (left < n && nums[left] == last)
10            left++;
11
12        while (left < right) {
13            int mid = left + right >> 1;
14
15            if (nums[mid] > last)
16                left = mid + 1;
17            else
18                right = mid;
19        }
20
21        return nums[left];
22    }
23};