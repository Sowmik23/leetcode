class Solution {
public:
    long long countCommas(long long n) {
        
        long long res = 0;
        long long x = 1000;
        while(x<=n){
            res+=(n-x)+1;
            x*=1000;
        }
        return res;
    }
};