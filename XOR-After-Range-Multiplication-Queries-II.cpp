1class Solution {
2public:
3    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
4        
5        int n = nums.size();
6        int limit = sqrt(n);
7        
8        // group queries with small k for later processing
9        unordered_map<int, vector<vector<int>>> lightK;
10
11        for(auto& q : queries){
12            int l = q[0], r = q[1], k = q[2], v = q[3];
13            if(k >= limit){ // large k: apply brute force
14                for(int i = l; i <= r; i += k)
15                    nums[i] = (1LL * nums[i] * v) % mod;
16            } else { // small k: process later
17                lightK[k].push_back(q);
18            } 
19        }
20
21        for(auto& [k, query] : lightK){
22            // process small queries grouped by step size k
23            vector<long long> diff(n, 1);
24            for(auto& q : query){
25                int l = q[0], r = q[1], v = q[3];
26                // multiply starting position
27                diff[l] = (diff[l] * v) % mod;
28                // cancel the multiplication using modular inverse
29                int steps = (r - l) / k;
30                int next = l + (steps + 1) * k;
31                if(next < n){
32                    diff[next] = (diff[next] * modInv(v)) % mod;
33                }
34            }
35            
36            // propagate the multipliers with a step size of k
37            for(int i = 0; i < n; i++){
38                if(i >= k) diff[i] = (diff[i] * diff[i-k]) % mod;
39                nums[i] = (1LL * nums[i] * diff[i]) % mod;
40            }
41        }
42
43        int ans = 0;
44        for(auto& num : nums) ans ^= num;
45
46        return ans;  
47    }
48private:
49    const int mod = 1e9 + 7;
50    long long power(long long base, long long exp){
51        long long res = 1;
52        while(exp > 0){
53            if(exp & 1) res = (res * base) % mod;
54            base = (base * base) % mod;
55            exp >>= 1;
56        }
57        return res;
58    }
59
60    long long modInv(long long n){
61        return power(n, mod - 2);
62    }
63};