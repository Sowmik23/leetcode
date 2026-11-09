class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        
        set<int> free;
        for(int i=0;i<k;i++){
            free.insert(i);
        }
        priority_queue<LLI, vector<LLI>, greater<LLI>> busy;
        vector<int> cnt(k);
        int n = arrival.size();
        for(int i=0;i<n;i++){
            long long t = arrival[i];
            while(!busy.empty() and busy.top().first<=t){
                free.insert(busy.top().second);
                busy.pop();
            }
            if(free.empty()) continue;
            int pref = i%k;
            auto it = free.lower_bound(pref);
            if(it==free.end()) it = free.begin();
            int s = *it;
            free.erase(*it);
            ++cnt[s];
            busy.emplace(t+load[i], s);
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(cnt[i]==mx) ans.push_back(i);
        }
        return ans;
    }
private:
    using LLI = pair<long long, int>;

};