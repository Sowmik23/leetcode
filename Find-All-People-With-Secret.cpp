1class Solution {
2public:
3    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, 
4    int firstPerson) {
5        
6        //dfs
7        vector<int> res;
8        unordered_map<int, vector<pair<int, int>>> graph;
9
10        for(auto& meet: meetings){
11            graph[meet[0]].push_back({meet[1], meet[2]});
12            graph[meet[1]].push_back({meet[0], meet[2]});
13        }
14
15        //bfs
16        vector<int> earliest(n, INT_MAX);
17        earliest[0] = 0;
18        earliest[firstPerson] = 0;
19
20        //dfs
21        // dfs(0, 0, graph, earliest);
22        // dfs(firstPerson, 0, graph, earliest);
23
24        //bfs
25        /*
26        queue<pair<int, int>> q;
27        q.push({0, 0});
28        q.push({firstPerson, 0});
29        while(!q.empty()){
30            auto [person, time] = q.front();
31            q.pop();
32
33            for(auto& [nextPerson, t]: graph[person]){
34                if(t>=time and earliest[nextPerson]>t){
35                    earliest[nextPerson] = t;
36                    q.push({nextPerson, t});
37                }
38            }
39        }
40        */
41        //minPQ
42        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
43        pq.push({0, 0});
44        pq.push({0, firstPerson});
45
46        vector<int> visited(n, 0);
47        while(!pq.empty()){
48            auto it = pq.top();
49            int time = it.first;
50            int person = it.second;
51            pq.pop();
52            if(visited[person])continue;
53            visited[person] = true;
54            for(auto &it: graph[person]){
55                if(!visited[it.first] and it.second>=time){
56                    pq.push({it.second, it.first});
57                }
58            }
59        }
60    
61
62        // for(int i=0;i<n;i++){
63        //     if(earliest[i]!=INT_MAX){
64        //         res.push_back(i);
65        //     }
66        // }
67         for(int i=0;i<n;i++){
68            if(visited[i]){
69                res.push_back(i);
70            }
71        }
72
73        return res;
74    }
75private:
76    void dfs(int person, int time, auto &graph, auto &earliest){
77        for(auto [nextPerson, t]: graph[person]){
78            if(t>=time and earliest[nextPerson]>t){
79                earliest[nextPerson] = t;
80                dfs(nextPerson, t, graph, earliest);
81            }
82        }
83    }
84};