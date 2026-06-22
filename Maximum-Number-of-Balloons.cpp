1class Solution {
2public:
3    int maxNumberOfBalloons(string text) {
4        
5        int b = 0;
6        int a = 0;
7        int n = 0;
8        int l = 0;
9        int o = 0;
10        
11        int res = 0;
12        
13        for(int i=0;i<text.size();i++){
14            if(text[i]=='b') b++;
15            else if(text[i]=='a') a++;
16            else if(text[i]=='n') n++;
17            else if(text[i]=='o') o++;
18            else if(text[i]=='l') l++;
19        }
20       
21        int k = min(b, a);
22        k = min(k, n);
23        int m = min(l/2, o/2);
24        k = min(k, m);
25        res = max(res, k);
26        
27        return res;
28    }
29};