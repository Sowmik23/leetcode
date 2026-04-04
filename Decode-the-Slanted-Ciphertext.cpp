1class Solution {
2public:
3    string decodeCiphertext(string encodedText, int rows) {
4        
5        int n = encodedText.size();
6        if(rows==1) return encodedText;
7
8        int col = n/rows;
9        string res;
10
11        res.reserve(n);
12        for(int c=0;c<col;c++){
13            int r = 0, j = c;
14            while(r<rows and j<col){
15                res+=encodedText[r*col+j];
16                r++;
17                j++;
18            }
19        }
20        while(!res.empty() and res.back() ==' ') res.pop_back();
21        return res;
22    }
23    
24};