1class Solution {
2public:
3    int search(vector<int>& nums, int target) {
4        
5        int n = nums.size();
6        int left = 0, right = n-1;
7
8        while(left<=right){
9            int mid = left+(right-left)/2;
10            if(nums[mid]==target) return mid;
11
12            if(nums[mid]<=nums[right]){ //the right half is sorted
13                if(target>=nums[mid] and target<=nums[right]) left = mid+1;
14                else right = mid-1;
15            }
16            else if(nums[left]<=nums[mid]){ //the left half is sorted
17                if(target>=nums[left] and target<=nums[mid]) right = mid - 1;
18                else left = mid+1;
19            }
20        }
21        return -1;
22    }
23};