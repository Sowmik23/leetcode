1class Solution {
2public:
3    int minimumDeletions(string s) {
4        
5        // int firstIdxOfB = -1;
6        // int lastIdxOfA = -1;
7        // bool flag = false;
8        // for(int i=0;i<s.size();i++){
9        //     if(s[i]=='a') lastIdxOfA = i;
10        //     else if(flag==false and s[i]=='b') {
11        //         firstIdxOfB = i;
12        //         flag = true;
13        //     }
14        // }
15        // int cntA = 0, cntB = 0;
16        // if(firstIdxOfB==-1 or lastIdxOfA==-1) return 0;
17        // for(int i=firstIdxOfB;i<=lastIdxOfA;i++){
18        //     if(s[i]=='a') cntA++;
19        //     else cntB++;
20        // }
21        // cout<<firstIdxOfB<<" "<<lastIdxOfA<<" "<<cntA<<" "<<cntB<<endl;
22        // return min(cntA, cntB);
23
24        int cnt = 0;
25        int rmCnt = 0;
26        for(int i=0;i<s.size();i++){
27            if(s[i]=='b') cnt++;
28            else if(cnt) {
29                rmCnt++;
30                cnt--;
31            }
32        }
33        return rmCnt;
34    }
35};