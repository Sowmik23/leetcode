class Solution {
public:
    bool checkValidString(string s) {
        
        //two pointer
        int openCnt = 0, closeCnt = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' or s[i]=='*') openCnt++;
            else openCnt--;
            
            if(s[s.size()-1-i]==')' or s[s.size()-1-i]=='*') closeCnt++;
            else closeCnt--;
            
            if(openCnt<0 or closeCnt<0) return false;
        }
        return true;
    }
};