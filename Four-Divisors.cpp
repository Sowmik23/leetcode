1class Solution {
2public:
3    int sumFourDivisors(vector<int>& nums) {
4        
5        int res = 0;
6        for(auto &num : nums){
7            auto last = 0;
8            for(auto d = 2; d*d<=num;d++){
9                if(num%d==0) {
10                    if(last==0) last = d;
11                    else {
12                        last = 0;
13                        break;
14                    }
15                }
16            }
17            if(last>0 and last!=num/last){
18                res+=1+num+last+num/last;
19            }
20        }
21        return res;
22    }
23};