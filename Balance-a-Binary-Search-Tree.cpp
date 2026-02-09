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
14    TreeNode* balanceBST(TreeNode* root) {
15        
16        //first inorder traverse and keep all element in an arr
17        vector<int> inorder;
18        inorderTraverse(root, inorder);
19        int n = inorder.size();
20
21        return makeBalanceBst(inorder, 0, n-1);
22    }
23private:
24    void inorderTraverse(TreeNode* root, vector<int> &inorder) {
25        if(!root) return;
26        inorderTraverse(root->left, inorder);
27        inorder.push_back(root->val);
28        inorderTraverse(root->right, inorder);
29    }
30    TreeNode* makeBalanceBst(const vector<int> &inorder, int left, int right) {
31
32        if(left>right) return nullptr;
33        int mid = left + (right-left)/2;
34
35        TreeNode* leftSubTree = makeBalanceBst(inorder, left, mid-1);
36        TreeNode* rightSubTree = makeBalanceBst(inorder, mid+1, right);
37
38        return new TreeNode(inorder[mid], leftSubTree, rightSubTree);
39    }
40};