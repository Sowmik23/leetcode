1class Solution {
2public:
3    vector<int> sortByBits(vector<int>& arr) {
4        
5        sort(arr.begin(), arr.end(), [&](auto& x, auto& y){
6            //find number of bits of each a, b
7            int a = x, b = y;
8            int cntA = 0, cntB = 0;
9            while(a){
10                cntA+= (1&a);
11                a = a>>1;
12            }
13            while(b){
14                cntB+= (1&b);
15                b = b>>1;
16            }
17            //cout<<cntA<<" "<<cntB<<" : "<<endl;
18            if(cntA==cntB) return x<y;
19            return cntA<=cntB;
20        });
21
22        return arr;
23    }
24};