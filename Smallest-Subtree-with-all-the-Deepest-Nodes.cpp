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
14    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
15        
16        int depth = findDepth(root);
17
18        postOrder(root, 0, depth);
19        return res;
20    }
21private:
22    TreeNode* res = nullptr;
23    int postOrder(TreeNode* root, int level, int depth){
24        if(!root) return level;
25
26        int left = postOrder(root->left, level+1, depth);
27        int right = postOrder(root->right, level+1, depth);
28        if(left==depth and right==depth){
29            res = root;
30        }
31        return max(left, right);
32    }
33    int findDepth(TreeNode* root){
34        if(!root) return 0;
35        return max(findDepth(root->left), findDepth(root->right))+1;
36    }
37};