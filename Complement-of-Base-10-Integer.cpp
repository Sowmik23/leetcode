1class Solution {
2public:
3    int bitwiseComplement(int n) {
4        //Reality: num & mask = result
5        
6        if(n==0) return 1;
7        unsigned mask = ~0;
8        while(mask & n) mask = mask << 1;
9        return ~n ^ mask;
10    }
11};