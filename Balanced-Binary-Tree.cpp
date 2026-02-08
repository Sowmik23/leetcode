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
14    bool ans;
15    bool isBalanced(TreeNode* root) {
16        
17        if(!root) return true;
18        ans = true;
19        int tmp = recursive(root);
20        return ans;
21    }
22private:
23    int recursive(TreeNode* root){
24        
25        if(!root) return 0;
26        if(!ans) return 0;
27        
28        int l = recursive(root->left);
29        int r = recursive(root->right);
30        
31        if(abs(l-r)>1) ans = false;
32        return 1+max(l, r);
33    }
34};
35
36