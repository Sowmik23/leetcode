1class Solution {
2public:
3    int maxDistance(int side, vector<vector<int>>& points, int k) {
4        
5        vector<long long> arr;
6
7        for(auto &p: points){
8            int x = p[0], y = p[1];
9            if(x==0) arr.push_back(y);
10            else if(y==side) arr.push_back(side+x);
11            else if(x==side) arr.push_back(side*3LL - y);
12            else arr.push_back(side*4LL - x);
13        }
14
15        sort(arr.begin(), arr.end());
16        auto check = [&](long long limit) -> bool {
17            for(long long start: arr){
18                long long end = start + side*4LL -limit;
19                long long cur = start;
20                for(int i=0;i<k-1;i++){
21                    auto it = ranges::lower_bound(arr, cur + limit);
22                    if(it==arr.end() || *it > end){
23                        cur = -1;
24                        break;
25                    }
26                    cur = *it;
27                }
28                if(cur>=0) return true;
29            }
30            return false;
31        };
32        
33        long long lo = 1, hi = side;
34        int ans = 0;
35        while(lo<=hi){
36            long long mid = (lo + hi)/2;
37            if(check(mid)){
38                lo = mid + 1;
39                ans = mid;
40            } else hi = mid - 1;
41        }
42        return ans;
43    }
44};