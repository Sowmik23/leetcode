1class Solution {
2public:
3    vector<int> separateDigits(vector<int>& nums) {
4        
5        vector<int> res;
6        
7        for(auto& n: nums){
8            string str = to_string(n);
9            for(auto& ch: str){
10                int x = ch-'0';
11               // cout<<ch<<" "<<x<<" ";
12                res.push_back(x);
13            }
14        }
15        return res;
16    }
17};