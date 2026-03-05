1class Solution {
2public:
3    int minOperations(string s) {
4
5        int mn = INT_MAX;
6        char prev = s[0];
7        int cnt0 = 0, cnt1 = 0;
8
9        for(int i=0;i<s.size();i++){
10            if(i%2==0) {
11                if(s[i]=='0') cnt1++;
12                else cnt0++;
13            }
14            else {
15                if(s[i]=='1') cnt1++;
16                else cnt0++;
17            }
18        }   
19        return min(cnt0, cnt1);
20    }
21};