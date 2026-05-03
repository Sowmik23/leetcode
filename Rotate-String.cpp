1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4        
5        if(s.size()!=goal.size()) return false;
6        
7        string tmp = s+s;
8        if(tmp.contains(goal)) return true;
9        return false;
10    }
11};