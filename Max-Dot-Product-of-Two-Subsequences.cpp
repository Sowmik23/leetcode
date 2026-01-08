1// class Solution {
2// public:
3//     int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
4        
5//         //dynamic programming
6//         // This is a perfect problem for dynamic programming because every 
7//         // decision we make will affect future decisions.
8
9//         //handle the case: if one array's all elements are negative
10//         int firstMx = INT_MIN;
11//         int firstMn = INT_MAX;
12//         int secondMx = INT_MIN;
13//         int secondMn = INT_MIN;
14
15//         for(int i=0;i<nums1.size();i++){
16//             firstMx = max(firstMx, nums1[i]);
17//             firstMn = min(firstMn, nums1[i]);
18//         }
19
20//          for(int i=0;i<nums2.size();i++){
21//             secondMx = max(secondMx, nums2[i]);
22//             secondMn = min(secondMn, nums2[i]);
23//         }
24
25//         if(firstMx<0 and secondMn>0) return firstMx*secondMn;
26//         if(secondMx<0 and firstMn>0) return secondMx*firstMn;
27
28//         cout<<"pass"<<endl;
29
30//         memo = vector(nums1.size()+1, vector<int>(nums2.size()+1, 0));
31//         // return recursive(nums1, nums2, memo, 0, 0);
32//         return  dp(0, 0, nums1, nums2);
33   
34//     }
35// private:
36//     vector<vector<int>> memo;
37//     int recursive(vector<int>&nums1, vector<int> &nums2, vector<vector<int>> &memo, int i, int j){
38
39//         if(i==nums1.size() or j==nums2.size()) return 0;
40//         if(memo[i][j]!=0) return memo[i][j];
41
42//         int a = (nums1[i]*nums2[j]) + recursive(nums1, nums2, memo, i+1, j+1);
43//         int mx = max(a, max(recursive(nums1, nums2, memo, i+1, j), recursive(nums1, nums2, memo, i, j+1)));
44
45//         return memo[i][j] = mx;
46//     }
47
48//     int dp(int i, int j, vector<int>& nums1, vector<int>& nums2) {
49//         if (i == nums1.size() || j == nums2.size()) {
50//             return 0;
51//         }
52        
53//         if (memo[i][j] != 0) {
54//             return memo[i][j];
55//         }
56        
57//         int use = nums1[i] * nums2[j] + dp(i + 1, j + 1, nums1, nums2);
58//         memo[i][j] = max(use, max(dp(i + 1, j, nums1, nums2), dp(i, j + 1, nums1, nums2)));
59//         return memo[i][j];
60//     }
61// };
62
63class Solution {
64public:
65    vector<vector<int>> memo;
66    
67    int dp(int i, int j, vector<int>& nums1, vector<int>& nums2) {
68        if (i == nums1.size() || j == nums2.size()) {
69            return 0;
70        }
71        
72        if (memo[i][j] != 0) {
73            return memo[i][j];
74        }
75        
76        int use = nums1[i] * nums2[j] + dp(i + 1, j + 1, nums1, nums2);
77        memo[i][j] = max(use, max(dp(i + 1, j, nums1, nums2), dp(i, j + 1, nums1, nums2)));
78        return memo[i][j];
79    }
80    
81    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
82        int firstMax = INT_MIN;
83        int secondMax = INT_MIN;
84        int firstMin = INT_MAX;
85        int secondMin = INT_MAX;
86        
87        for (int num: nums1) {
88            firstMax = max(firstMax, num);
89            firstMin = min(firstMin, num);
90        }
91        
92        for (int num: nums2) {
93            secondMax = max(secondMax, num);
94            secondMin = min(secondMin, num);
95        }
96        
97        if (firstMax < 0 && secondMin > 0) {
98            return firstMax * secondMin;
99        }
100        
101        if (firstMin > 0 && secondMax < 0) {
102            return firstMin * secondMax;
103        } 
104
105        memo = vector(nums1.size(), vector(nums2.size(), 0));
106        return dp(0, 0, nums1, nums2);
107    }
108};