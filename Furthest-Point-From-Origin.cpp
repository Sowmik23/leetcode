1class Solution {
2public:
3    int furthestDistanceFromOrigin(string moves) {
4        
5        int dashCnt = 0;
6        int left = 0, right = 0;
7        for(auto &ch: moves){
8            if(ch=='_') dashCnt++;
9            else if(ch=='R') right++;
10            else left++;
11        }
12
13        return max(abs((left+dashCnt)-right), abs((dashCnt+right)-left));
14    }
15};