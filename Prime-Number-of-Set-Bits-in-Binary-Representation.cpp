1class Solution {
2public:
3    int countPrimeSetBits(int left, int right) {
4        
5        //use bitset for counting set bit
6        int cnt = 0, hash[20] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1};
7        for (int i = left; i <= right; i++) {
8            bitset<20> b(i);
9            if(hash[b.count()]) cnt++;
10        }
11        return cnt;
12    }
13};