1class Solution {
2public:
3    bool pyramidTransition(string bottom, vector<string>& allowed) {
4
5        unordered_map<string, vector<char>> mp;
6        for(auto & s: allowed){
7            mp[s.substr(0,2)].push_back(s.back());
8        }   
9        return helper(bottom, mp, 0, "");
10    }
11private:
12    bool helper(string bottom, unordered_map<string, vector<char>> &mp, int start, string next){
13        if(bottom.size()==1) return true;
14        if(start==(int)bottom.size()-1) return helper(next, mp, 0, "");
15        for(char ch: mp[bottom.substr(start, 2)]){
16            if(helper(bottom, mp, start+1, next+ch)) return true;
17        }
18        return false;
19    }
20};