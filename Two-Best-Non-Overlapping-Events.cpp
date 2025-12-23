1class Solution {
2public:
3    int maxTwoEvents(vector<vector<int>>& events) {
4        
5        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
6        int mx = 0, tmp = 0;
7        sort(events.begin(), events.end());
8
9        for(auto &event: events){
10            while(!pq.empty() and pq.top().first<event[0]){
11                tmp = max(tmp, pq.top().second);
12                pq.pop();
13            }
14            mx = max(mx, tmp+event[2]);
15            pq.push({event[1], event[2]});
16        }
17        return mx;
18    }
19};