1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int maxLevelSum(TreeNode* root) {
15        
16        if(!root) return 0;
17        queue<TreeNode*> q;
18        q.push(root);
19        int level = 1;
20        int res = 1;
21        int mx = INT_MIN;
22
23        while(!q.empty()){
24            int n = q.size();
25            int sum = 0;
26            for(int i=0;i<n;i++){
27                auto top = q.front();
28                q.pop();
29                sum+=top->val;
30                if(top->left) q.push(top->left);
31                if(top->right) q.push(top->right);
32            }
33            if(mx<sum) {
34                mx = sum;
35                res = level;
36            }
37            level++;
38        }
39        return res;
40    }
41};