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
14    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
15        
16        unordered_map<int, pair<int, int>> mp;
17        unordered_map<int, int> childs;
18
19        for(auto& description: descriptions){
20            if(description[2]==1) {
21                int prevRight = mp[description[0]].second ? mp[description[0]].second : 0;
22                mp[description[0]] = {description[1], prevRight};
23            }
24            else {
25                int prevLeft = mp[description[0]].first ? mp[description[0]].first : 0;
26                mp[description[0]] = {prevLeft, description[1]};
27            }
28            childs[description[1]]++;
29        }
30
31        int root = -1;
32        for(auto& m: mp){
33            if(childs.find(m.first)==childs.end()) root = m.first;
34        }
35
36        TreeNode* rt = new TreeNode(root);
37        return dfs(rt, root, mp);
38    }
39private:
40    TreeNode* dfs(TreeNode* rt, int rootVal, unordered_map<int, pair<int, int>> &mp){
41
42        //if(rootVal==0) return nullptr;
43        
44        if(mp.find(rootVal)!=mp.end()){
45
46            int left = mp[rootVal].first ? mp[rootVal].first : 0;
47            int right = mp[rootVal].second ? mp[rootVal].second : 0;
48            //cout<<rootVal<<" "<<left<<" "<<right<<endl;
49
50            rt->left = left==0 ? nullptr : new TreeNode(left);
51            rt->right = right==0 ? nullptr : new TreeNode(right);
52            
53            if(left) dfs(rt->left, left, mp);
54            if(right) dfs(rt->right, right, mp);
55        }
56       return rt;
57    }
58};