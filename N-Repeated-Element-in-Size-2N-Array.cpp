1class Solution {
2public:
3    int repeatedNTimes(vector<int>& nums) {
4        
5        set<int> st;
6        for(auto& n: nums){
7            if(st.count(n)>0) return n;
8            else st.insert(n);
9        }
10        return -1;
11    }
12};