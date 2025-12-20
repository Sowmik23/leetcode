1class Solution {
2public:
3    int minDeletionSize(vector<string>& strs) {
4        
5        int n = strs.size();
6        int m = strs[0].size();
7        int cnt = 0;
8
9        for(int i=0;i<m;i++){
10            char prev = -1;
11            for(int j=0;j<n;j++){
12                char ch = strs[j][i];
13                // cout<<"Char: "<<ch<<endl;
14                if(prev==-1) prev = ch;
15                if(prev>ch) {
16                    // cout<<"found: "<<prev<<" "<<ch<<endl;
17                    cnt++;
18                    break;
19                }
20                if(prev<ch) prev = ch;
21                // cout<<prev<<" "<<ch<<endl;
22            }
23            // cout<<"cycle.."<<endl;
24        }
25        return cnt;
26    }
27};
28
29// abc
30// bce
31// cae