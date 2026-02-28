1class Solution {
2public:
3    int concatenatedBinary(int n) {
4        
5        long mod = 1e9+7;
6        int base=1;
7        int res = 0;
8        while(n>0){
9            int x = n;
10            while(x){
11                int a = x%2;
12                x /=2;
13                res+=(base*a)%mod;
14                base = (base*2)%mod;
15                res%=mod;
16            }
17            n--;
18        }
19        return res%mod;
20    }
21};