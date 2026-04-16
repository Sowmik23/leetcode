1class Solution {
2public:
3    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
4
5        int n = nums.size();
6        vector<int> res;
7        unordered_map<int, set<int>> mp;
8
9        for(int i = 0; i < n; i++){
10            mp[nums[i]].insert(i);
11        }
12
13        for(auto q : queries){
14            auto &st = mp[nums[q]];
15
16            if(st.size() == 1){
17                res.push_back(-1);
18                continue;
19            }
20
21            auto curr = st.find(q);
22
23            // next (circular)
24            auto nextPtr = next(curr);
25            if(nextPtr == st.end()) nextPtr = st.begin();
26
27            // prev (circular)
28            auto prevPtr = (curr == st.begin()) ? prev(st.end()) : prev(curr);
29
30            int d1 = abs(q - *nextPtr);
31            int d2 = abs(q - *prevPtr);
32
33            d1 = min(d1, n - d1);
34            d2 = min(d2, n - d2);
35
36            res.push_back(min(d1, d2));
37        }
38
39        return res;
40    }
41};