1class Solution {
2public:
3    string findDifferentBinaryString(vector<string>& nums) {
4        
5        string ans="";
6        for(int i=0; i<nums.size(); i++) 
7            ans+= nums[i][i]=='0' ? '1' : '0';          
8        return ans;
9    }
10};