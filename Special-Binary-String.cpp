1class Solution {
2public:
3    string makeLargestSpecial(string s) {
4        
5        int cnt = 0, i = 0;
6        vector<string> res;
7        for(int j=0;j<s.size();j++){
8            if(s[j]=='1') cnt++;
9            else cnt--;
10            if(cnt==0){
11                res.push_back('1'+makeLargestSpecial(s.substr(i+1, j-i-1))+'0');
12                i = j+1;
13            }
14        }
15        sort(res.begin(), res.end(), greater<string>());
16        string res2 = "";
17        for(int i=0;i<res.size();i++) res2+=res[i];
18        return res2;
19    }
20};