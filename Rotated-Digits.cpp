1class Solution {
2public:
3    int rotatedDigits(int n) {
4        
5        int count = 0;
6        
7        for (int i = 1; i <= n; i++) {
8            int num = i;
9            bool isValid = true;
10            bool hasChange = false;
11            
12            while (num > 0) {
13                int digit = num % 10;
14                if (digit == 3 || digit == 4 || digit == 7) {
15                    isValid = false;
16                    break;
17                }
18                if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
19                    hasChange = true;
20                }
21                num /= 10;
22            }   
23            if (isValid && hasChange) {
24                count++;
25            }
26        }
27        return count;
28    }
29};