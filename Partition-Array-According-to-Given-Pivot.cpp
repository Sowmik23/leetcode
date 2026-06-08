1class Solution {
2public:
3    vector<int> pivotArray(vector<int>& nums, int pivot) {
4        
5        vector<int> res, sml, lrg;
6        int eqlCnt = 0;
7        for(auto &num: nums){
8            if(num<pivot) sml.push_back(num);
9            else if(num>pivot) lrg.push_back(num);
10            else eqlCnt++;
11        }
12        while(eqlCnt>0){
13            sml.push_back(pivot);
14            eqlCnt--;
15        }
16        //concating sml and lrg vector
17        sml.insert(sml.end(), lrg.begin(), lrg.end());
18        return sml;
19    }
20};