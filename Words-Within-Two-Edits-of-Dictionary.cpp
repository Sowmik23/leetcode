1class Solution {
2public:
3    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
4        
5        vector<string> res;
6        for(int i=0;i<queries.size();i++){
7            string str = queries[i];
8            
9            if(findMatch(str, dictionary)){
10                res.push_back(str);
11            }
12        }
13        return res;
14    }
15private:
16    bool findMatch(string str, vector<string>& dictionary){
17        
18        for(auto& d: dictionary){
19            int cnt = 0;
20            for(int j=0;j<d.size();j++){
21                if(d[j]!=str[j]) cnt++;
22                if(cnt>2) break;
23            }
24            if(cnt<=2) return true;
25        }
26        return false;
27    }
28};