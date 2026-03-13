1class Solution {
2public:
3    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
4        
5        //Binary Search
6        
7        static constexpr double eps = 1e-7;
8        int maxWorkerTimes =
9            *max_element(workerTimes.begin(), workerTimes.end());
10        long long l = 1, r = static_cast<long long>(maxWorkerTimes) *
11                             mountainHeight * (mountainHeight + 1) / 2;
12        long long ans = 0;
13
14        while (l <= r) {
15            long long mid = (l + r) / 2;
16            long long cnt = 0;
17            for (int t : workerTimes) {
18                long long work = mid / t;
19                // find the largest k such that 1+2+...+k <= work
20                long long k = (-1.0 + sqrt(1 + work * 8)) / 2 + eps;
21                cnt += k;
22            }
23            if (cnt >= mountainHeight) {
24                ans = mid;
25                r = mid - 1;
26            } else {
27                l = mid + 1;
28            }
29        }
30
31        return ans;
32    }
33};