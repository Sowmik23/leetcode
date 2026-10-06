class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char> stk;
        int cnt = 0;
        for(auto &ch: s){
            if(ch=='(') stk.push(ch);
            else if(ch==')'){
                if(!stk.empty() and stk.top()=='(') stk.pop();
                else cnt++;
            }
        }
        return cnt+stk.size();
    }
};