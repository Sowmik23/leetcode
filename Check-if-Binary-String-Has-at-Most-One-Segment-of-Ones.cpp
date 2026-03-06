1class Solution {
2public:
3    bool checkOnesSegment(string s) {
4
5        return s.find("01") == string::npos;
6    }
7};