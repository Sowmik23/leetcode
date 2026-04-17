1class Solution {
2public:
3    int minMirrorPairDistance(vector<int>& nums) {
4        
5        int n = nums.size();
6        unordered_map<int, int> mp;
7        int res = INT_MAX;
8
9        for(int i = 0;i<n;i++){
10            int num=nums[i];
11            int x = nums[i];
12            int rev = 0;
13            while(x>0){
14                rev = rev*10 + x%10;
15                x/=10;
16            }
17            //cout<<nums[i]<<" "<<rev<<endl;
18            if(mp.find(num)!=mp.end()){
19                res = min(res, i-mp[num]);
20            }
21            mp[rev] = i;
22        }
23        return res == INT_MAX ? -1 : res;
24    }
25};