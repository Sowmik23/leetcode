class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        
        //awesome problem
        int m = servers.size();
        int n = tasks.size();

        priority_queue<PLI, vector<PLI>, greater<PLI>> busy;
        priority_queue<PII, vector<PII>, greater<PII>> idle;

        for(int i=0;i<m;i++){
            idle.emplace(servers[i], i);
        }
        long long time = 0;

        auto release = [&](){
            while(!busy.empty() and busy.top().first <= time){
                auto &&[_, idx] = busy.top();
                idle.emplace(servers[idx], idx);
                busy.pop();
            }
        };

        vector<int> res;
        for(int i=0;i<n;i++){
            time = max(time, (long long)i);
            release();
            if(idle.empty()){
                time = busy.top().first;
                release();
            }

            auto &&[_, idx] = idle.top();
            res.push_back(idx);
            busy.emplace(time+tasks[i], idx);
            idle.pop();
        }
        return res;
    }
private:
    using PLI = pair<long long, int>;
    using PII = pair<int ,int>;
};