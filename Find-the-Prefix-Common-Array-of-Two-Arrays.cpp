1class Solution {
2public:
3    vector<int> findThePrefixCommonArray(vector<int>& teamA, vector<int>& teamB) {
4        
5        int n = teamA.size();
6        unordered_map<int, int> cache;
7        vector<int> res(n, 0);
8
9        int counter = 0;
10        for(int i=0;i<n;i++){
11            if(teamA[i]==teamB[i]){
12                counter++;
13                cache[teamA[i]]++;
14            } else {
15                if(cache.find(teamA[i])!=cache.end()) counter++;
16                if(cache.find(teamB[i])!=cache.end()) counter++;
17                cache[teamA[i]]++;
18                cache[teamB[i]]++;
19            }
20            res[i] = counter;
21        }
22        return res;
23    }
24};