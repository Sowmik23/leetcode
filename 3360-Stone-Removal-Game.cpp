class Solution {
public:
    bool canAliceWin(int n) {
        
        int x = 10;
        if(n<x) return false;
        for(int i=1;;i++){
            n-=x;
            x--;
            if(x>n){
                if(i%2==0) return false;
                else return true;
            }
        }
        return true;
    }
};