1class Solution {
2public:
3    bool judgeCircle(string moves) {
4        
5        int updownlevel = 0;
6        int leftrightlevel = 0;
7        for(int i=0;i<moves.size();i++){
8            if(moves[i]=='R') leftrightlevel +=1;
9            else if(moves[i]=='L') leftrightlevel -=1;
10            else if(moves[i]=='U') updownlevel +=1;
11            else if(moves[i]=='D') updownlevel -=1;
12        }
13        
14        if(leftrightlevel==0 and updownlevel==0) return true;
15        else return false;
16    }
17};