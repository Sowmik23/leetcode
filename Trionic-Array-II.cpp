1class Solution {
2public:
3    long long maxSumTrionic(vector<int>& nums) {
4
5        //interview for Senior Staff Engineer
6        
7        int n = nums.size();
8        int p, q, j;
9        long long max_sum, sum, res;
10        long long ans = LLONG_MIN;
11        for (int i = 0; i < n; i++) {
12            j = i + 1;
13            res = 0;
14            // first segment
15            for (; j < n && nums[j - 1] < nums[j]; j++);
16            p = j - 1;
17            if (p == i) {
18                continue;
19            }
20            // second segment
21            res += nums[p] + nums[p - 1];
22            for (; j < n && nums[j - 1] > nums[j]; j++) {
23                res += nums[j];
24            }
25            q = j - 1;
26            if (q == p || q == n - 1 || (nums[j] <= nums[q])) {
27                i = q;
28                continue;
29            }
30            // third segment
31            res += nums[q + 1];
32            // find the maximum sum of the third segment
33            max_sum = 0;
34            sum = 0;
35            for (int k = q + 2; k < n && nums[k] > nums[k - 1]; k++) {
36                sum += nums[k];
37                max_sum = max(max_sum, sum);
38            }
39            res += max_sum;
40            // find the maximum sum of the first segment
41            max_sum = 0;
42            sum = 0;
43            for (int k = p - 2; k >= i; k--) {
44                sum += nums[k];
45                max_sum = max(max_sum, sum);
46            }
47            res += max_sum;
48            // update answer
49            ans = max(ans, res);
50            i = q - 1;
51        }
52        return ans;
53    }
54};