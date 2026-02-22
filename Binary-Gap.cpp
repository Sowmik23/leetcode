1class Solution {
2public:
3    int binaryGap(int n) {
4        
5        vector<int> bits(32, 0);
6        int b = 0;
7        for(int i=0;i<32;i++){
8            if((n>>i)&1!=0) {
9                bits[b]=i;
10                b++;
11            }
12        }
13        int res = 0;
14        for(int i=0;i<b-1;i++){
15            res = max(res, bits[i+1]-bits[i]);
16        }
17        return res;
18    }
19};