1class Solution {
2public:
3    int numberOfSubstrings(string s) {
4        
5        unordered_map<int, int> mp;
6        int left = 0, right = 0;
7        int res = 0;
8        int cnt = 0;
9
10        while(right<s.size()){
11            mp[s[right]-'a']++;
12            right++;
13            while(left<s.size() and mp.size()==3){
14                cnt++;
15                mp[s[left]-'a']--;
16                if(mp[s[left]-'a']==0) mp.erase(s[left]-'a');
17                left++;
18            }
19            res+=cnt;
20        }
21        return res;
22    }
23};