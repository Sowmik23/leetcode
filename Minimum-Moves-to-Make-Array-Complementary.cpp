1class Solution {
2public:
3    int minMoves(vector<int>& nums, int limit) {
4
5        int n = nums.size();
6        int res = INT_MAX;
7
8        //Brute Force: TLE
9
10        /*
11        //check every possible targe from 1+1 to limit + limit
12        for(int target=2*1;target<=2*limit;target++){
13            int moves = 0;
14            for(int i=0;i<n/2;i++){
15                int x = min(nums[i], nums[n-1-i]);
16                int y = max(nums[i], nums[n-1-i]);
17
18                //case-01: already adds up to target
19                if(x+y==target) moves+=0;
20                //case-02: by changing just 1 number
21                else if(target>=x+1 and target<=y+limit) moves+=1;
22                //case-03: target is too small or too big
23                else moves+=2;
24            }
25            res = min(res, moves);
26        }
27        */
28
29        //Optimized version
30        vector<int> diff(2*limit+2, 0);
31        for(int i=0;i<n/2;i++){
32            int x = min(nums[i], nums[n-1-i]);
33            int y = max(nums[i], nums[n-1-i]);
34
35            diff[2]+=2;
36            diff[x+1] -=1;
37            diff[x+y] -=1;
38            diff[x+y+1] +=1;
39            diff[y+limit+1] +=1;
40        }
41
42        int curr = 0;
43        for(int target=2*1;target<=2*limit;target++){
44            curr+=diff[target];
45            res = min(res, curr);
46        }
47        return res;
48    }
49};