class Solution {
public:
    bool checkString(string s) {
        
        bool foundB = false;
        for(auto &ch: s){
            if(ch=='a') {
                if(foundB) return false;
            }
            else if(ch=='b'){
                foundB=true;
            }
        }
        return true;
    }
};