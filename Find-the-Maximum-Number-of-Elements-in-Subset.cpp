1class Solution {
2public:
3    int maximumLength(vector<int>& nums) {
4        
5        unordered_map<long long, int> cnt;
6        for (int num : nums) {
7            cnt[num]++;
8        }
9        int ans = 0;
10        // ans is at least the number of occurrences of 1, rounded down to an
11        // odd number
12        if (cnt[1] % 2 == 0) {
13            ans = cnt[1] - 1;
14        } else {
15            ans = cnt[1];
16        }
17        cnt.erase(1);
18        for (auto& [num, _] : cnt) {
19            int res = 0;
20            long long x = num;
21            for (; cnt.contains(x) && cnt[x] > 1; x *= x) {
22                res += 2;
23            }
24            ans = max(ans, res + (cnt.contains(x) ? 1 : -1));
25        }
26        return ans;
27    }
28};