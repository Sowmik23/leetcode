1class Solution {
2public:
3    struct Item {
4        int val;
5        int left;
6        int right;
7    };
8    vector<int> maxValue(vector<int>& nums) {
9        int n = nums.size();
10        vector<int> res(n, 0);
11        vector<Item> stk;
12
13        for(int i=0;i<n;i++){
14            Item curr = {nums[i], i, i};
15
16            while(!stk.empty() and stk.back().val > nums[i]){
17                Item top = stk.back();
18                stk.pop_back();
19                curr.val = max(curr.val, top.val);
20                curr.left = top.left;
21            }
22
23            stk.push_back(curr);
24        }  
25
26        for(size_t i=0;i<stk.size();i++){
27            for(int j=stk[i].left;j<=stk[i].right;j++){
28                res[j] = stk[i].val;
29            }
30        }
31        return res;
32    }
33};