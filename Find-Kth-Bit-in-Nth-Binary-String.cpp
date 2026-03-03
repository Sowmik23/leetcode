1class Solution {
2public:
3    char findKthBit(int n, int k) {
4        
5        string x = "0";
6        
7        for(int i=2;i<=n;i++){
8            string invrt = invert(x);
9            string reverse = reverse_(invrt);
10            string str = x+"1"+reverse;
11            x = str;
12            if(i==n) break;
13        }
14        return x[k-1];
15    }
16private:
17    string invert(string str){
18        for(int i=0;i<str.size();i++){
19            if(str[i]=='0') str[i] = '1';
20            else str[i] = '0';
21        }
22        return str;
23    }
24    string reverse_(string str){
25        reverse(str.begin(), str.end());
26        return str;
27    }
28};