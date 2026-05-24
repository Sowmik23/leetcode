1class Solution {
2public:
3    int maxJumps(vector<int>& arr, int d) {
4        
5        //  Memoization Search
6        // O(ND)
7        int n = arr.size();
8        f.resize(n, -1);
9        for(int i=0;i<n;i++){
10            dfs(arr, i, d, n);
11        }
12        return *max_element(f.begin(), f.end());
13    }
14private:
15    vector<int> f;
16    void dfs(vector<int> &arr, int id, int d, int n){
17        if(f[id]!=-1) return ;
18        f[id] = 1;
19        for(int i=id-1;i>=0 and id-i<=d and arr[id] > arr[i]; i--){
20            dfs(arr, i, d, n);
21            f[id] = max(f[id], f[i]+1);
22        }
23        for (int i = id + 1; i < n && i - id <= d && arr[id] > arr[i]; ++i) {
24            dfs(arr, i, d, n);
25            f[id] = max(f[id], f[i] + 1);
26        }
27    }
28};