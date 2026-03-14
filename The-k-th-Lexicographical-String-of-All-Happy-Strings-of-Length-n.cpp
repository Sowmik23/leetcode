1class Solution {
2public:
3    string getHappyString(int n, int k) {
4        
5        //backtracking
6        //O(2^n)
7        vector<string> strings;
8        string str = "";
9        generateStrings(n, str, strings);
10
11        if(strings.size()<k) return "";
12        sort(strings.begin(), strings.end());
13        return strings[k-1];
14    }
15private:
16    void generateStrings(int n, string str, vector<string> &strings){
17        if(str.size()==n){
18            strings.push_back(str);
19            return;
20        }
21        for(char i = 'a';i<='c';i++){
22            if(str.size()>0 and str.back()==i) continue;
23            str+=i;
24            generateStrings(n, str, strings);
25            if(str.size()>0) str.pop_back();
26        }
27    }
28};