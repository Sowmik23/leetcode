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
14    int ans = 0;
15    int sumRootToLeaf(TreeNode* root) {
16        
17        string str = "";
18        dfs(root, str);
19        
20        return ans;
21    }
22private:
23    void dfs(TreeNode* root, string str){
24        
25        string x = to_string(root->val);
26        str+=x;
27        
28        if(root->left==NULL and root->right==NULL) {
29            //cout<<str<<endl;
30            
31            int x = 0;
32            for(int i=0;i<str.size();i++){
33                x+= pow(2, str.size()-i-1)*(str[i]-'0');
34            }
35            //cout<<x<<endl;
36            ans+=x;
37            
38            return ;
39        }
40        
41        
42        if(root->left!=NULL) dfs(root->left, str);
43        if(root->right!=NULL) dfs(root->right, str);
44        
45        str.pop_back();
46    }
47};