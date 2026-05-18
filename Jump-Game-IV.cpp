1class Solution {
2public:
3    int minJumps(vector<int>& arr) {
4        
5        unordered_map<int,vector<int>> mp;
6
7        for(int i=0;i<arr.size();i++){
8            mp[arr[i]].push_back(i);
9        }
10
11        int step = 0;
12        vector<bool> visited(arr.size());
13        queue<int> q;
14        q.push(0);
15        visited[0] = true;
16
17        while(!q.empty()){
18            int n = q.size();
19            for(int i=0;i<n;i++){
20                int top = q.front();
21                q.pop();
22
23                if(top==arr.size()-1) return step;
24
25                vector<int> &next = mp[arr[top]];
26                next.push_back(top-1);
27                next.push_back(top+1);
28
29                for(auto& x: next){
30                    if(x>=0 and x<arr.size() and !visited[x]){
31                        q.push(x);
32                        visited[x] = true;
33                    }
34                }
35                next.clear();
36            }
37            step++;
38        }
39        return -1;
40    }
41};