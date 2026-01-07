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
12
13        
14
15
16static int MOD=1e9+7;
17class Solution {
18public:
19    long long totalTreeSum=0,result=0;
20    int SumUnder(TreeNode* root)             //Get the totalSum under the node `root` including root.
21    {
22        if(!root)
23            return 0;
24        long long sum=SumUnder(root->left)+SumUnder(root->right)+root->val; //Get the sum of current subtree.
25        result=max(result,sum*(totalTreeSum-sum));    //Get the max product after making current subtree as a separate tree
26        return sum;
27    }
28    int maxProduct(TreeNode* root) 
29    {
30        totalTreeSum=SumUnder(root);
31        SumUnder(root);
32        return result%MOD;
33    }
34};