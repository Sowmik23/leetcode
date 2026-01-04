1class Solution {
2public:
3    int numOfWays(int n) {
4        
5        //nice problem
6        const int mod = 1e9+7;
7        long a121 = 6;
8        long a123 = 6;
9        long b121, b123;
10        for(int i=1;i<n;i++){
11            b121 = a121*3 + a123 *2;
12            b123 = a121*2 + a123 * 2;
13            a121 = b121%mod;
14            a123 = b123%mod;
15        }
16        return (a121 + a123)%mod;
17    }
18};