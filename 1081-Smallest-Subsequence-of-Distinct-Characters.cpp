class Solution {
public:
    string smallestSubsequence(string s) {
        
        string res = "";
        int n = s.size();
        vector<int> lastOccur(26), seen(26, 0);
        for(int i=0;i<n;i++){
            lastOccur[s[i]-'a'] = i;
        }
        for(int i=0;i<n;i++){
            if(seen[s[i]-'a']) continue;
            while(!res.empty() and res.back()>s[i] and lastOccur[res.back()-'a']>i) {
                seen[res.back()-'a'] = 0;
                res.pop_back();
            }
            res.push_back(s[i]);
            seen[s[i]-'a']++;
        }
        return res;
    }
};