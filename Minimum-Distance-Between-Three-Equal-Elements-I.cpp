1class Solution {
2public:
3    int minimumDistance(vector<int>& nums) {
4        
5        unordered_map<int, vector<int>> mp;
6
7
8        int res = INT_MAX;
9        for(int i=0;i<nums.size();i++){
10            mp[nums[i]].push_back(i);
11        }
12        for(auto &it: mp){
13            auto x = it.second;
14            if(x.size()>=3){
15                for(int i=0;i<=x.size()-3;i++){
16                    int sum = abs(x[i]-x[i+1]) + abs(x[i]-x[i+2]) + abs(x[i+1]-x[i+2]);
17                    res = min(res, sum);
18                }
19            }
20        }
21        return res==INT_MAX ? -1 : res;
22    }
23};