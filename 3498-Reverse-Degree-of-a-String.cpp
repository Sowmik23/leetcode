class Solution {
public:
    int reverseDegree(string s) {
        
        int ans = 0;
        int i = 1;
        for(auto &ch: s){
            ans += (i*('z'-ch + 1));
            i++;
        }
        return ans;
    }
};