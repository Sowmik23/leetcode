1class Solution {
2public:
3    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
4        
5        int n = capacity.size();
6        sort(capacity.begin(), capacity.end());
7        int sum = accumulate(apple.begin(), apple.end(), 0);
8        int cnt = 0;
9
10        for(int i=n-1;i>=0;i--){
11            sum-=capacity[i];
12            cnt++;
13            if(sum<=0) break;
14        }
15        return cnt;
16    }
17};