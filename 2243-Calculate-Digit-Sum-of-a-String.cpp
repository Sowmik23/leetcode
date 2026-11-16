class Solution {
public:
    string digitSum(string &s, int k) {
        
        if(s.size()>k){
            s = divide(s, k);
            digitSum(s, k);
        }
        return s;
    }
private:
    string divide(string s, int k){
        int cnt = 0;
        string str = "";
        int word = 0;
        for(auto &ch: s){
            word+= (ch-'0');
            cnt++;
            if(cnt==k){
                str+=to_string(word);
                word = 0;
                cnt = 0;
            }
        }
        if(cnt>0){
            str+=to_string(word);
        }
        return str;
    }
};