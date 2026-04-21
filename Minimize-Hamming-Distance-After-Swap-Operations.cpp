1class Solution {
2public:
3    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
4
5        int n = source.size();
6        group.resize(n);
7        rank.resize(n, 0);
8        for(int i=0;i<n;i++) group[i] = i;
9        for(auto pair: allowedSwaps){
10            Union(pair[0], pair[1]);
11        }
12        unordered_map<int, unordered_map<int, int>> sets;
13        for(int i=0;i<n;i++){
14            int f = find(i);
15            sets[f][source[i]]++;
16        }
17        int ans = 0;
18        for(int i=0;i<n;i++){
19            int f = find(i);
20            if(sets[f][target[i]]>0) sets[f][target[i]]--;
21            else ans++;
22        }
23        return ans;
24    }
25private:
26    vector<int> group;
27    vector<int> rank;
28
29    int find(int x) {
30        if(group[x]!=x) {
31            group[x] = find(group[x]);
32        }
33        return group[x];
34    }
35
36    void Union(int x, int y){
37        x = find(x);
38        y = find(y);
39        if(x==y) return;
40        //merge by rank
41        if(rank[x]<rank[y]){
42            swap(x, y);
43        }
44        group[y] = x;
45        if(rank[x]==rank[y]) rank[x]++;
46    }
47
48};