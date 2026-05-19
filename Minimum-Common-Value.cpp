1class Solution {
2public:
3    int getCommon(vector<int>& nums1, vector<int>& nums2) {
4        
5        int i = 0, j = 0;
6        while(i<nums1.size() and j<nums2.size()){
7            if(nums1[i]==nums2[j]) return nums1[i];
8            if(nums1[i]<nums2[j]) i++;
9            else j++;
10        }
11        return -1;
12    }
13};