class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int right = 0, left = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        int res = 0;

        while(right<n){
            mp[s[right]]++;
            if(mp[s[right]]>2){
                while(mp[s[right]]>2 and left<right){
                    mp[s[left]]--;
                    if(mp[s[left]]==0) mp.erase(s[left]);
                    left++;
                }
            }
            res = max(res, right-left+1);
            right++;
        }
        return res;
    }
};