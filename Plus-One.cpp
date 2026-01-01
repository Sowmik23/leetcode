1class Solution {
2public:
3    vector<int> plusOne(vector<int>& digits) {
4        
5        vector<int> res;
6        int n = digits.size();
7
8        int carry = 0;
9        int x; 
10        for(int i=n-1;i>=0;i--){
11            if(i==n-1){
12                x = digits[i]+1;
13            } else x = digits[i] + carry;
14            if(x>9){
15                carry = 1;
16                res.push_back(10-x);
17            }else {
18                carry = 0;
19                res.push_back(x);
20            }
21        }
22        if(carry) res.push_back(1);
23        reverse(res.begin(), res.end());
24        return res;
25    }
26};