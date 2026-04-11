1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        unordered_map<int, vector<int>> mp;
5
6
7        int res = INT_MAX;
8        for(int i=0;i<nums.size();i++){
9            mp[nums[i]].push_back(i);
10        }
11        for(auto &it: mp){
12            auto x = it.second;
13            if(x.size()>=3){
14                for(int i=0;i<=x.size()-3;i++){
15                    int sum = abs(x[i]-x[i+1]) + abs(x[i]-x[i+2]) + abs(x[i+1]-x[i+2]);
16                    res = min(res, sum);
17                }
18            }
19        }
20        return res==INT_MAX ? -1 : res;
21    }
22};