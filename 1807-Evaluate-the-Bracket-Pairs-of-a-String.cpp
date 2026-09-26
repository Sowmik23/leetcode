class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string, string> mp;
        for(auto& k: knowledge){
            mp[k[0]] = k[1];
        }

        int n = s.size();
        int i = 0;
        string res = "";
        while(i<n){
            if(s[i]=='('){
                i++;
                string key = "";
                while(i<n and s[i]!=')'){
                    key+=s[i];
                    i++;
                }
                i++;
                res+= mp.find(key)!=mp.end() ? mp[key] : "?";
            }
            else {
                res+=s[i];
                i++;
            }
        }
        return res;
    }
};