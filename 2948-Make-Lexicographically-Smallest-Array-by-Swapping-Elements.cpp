class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        vector<pair<int, int>> valIdx;
        int n = nums.size();
        for(int i=0;i<n;i++){
            valIdx.push_back({nums[i], i});
        }

        sort(valIdx.begin(), valIdx.end());
        vector<vector<pair<int, int>>> group;
        group.push_back({valIdx[0]});

        for(int i=1;i<n;i++){
            if(valIdx[i].first-valIdx[i-1].first<=limit) {
                group.back().push_back(valIdx[i]);
            } else group.push_back({valIdx[i]});
        }

        for(auto &g: group){
            vector<int> idx;
            for(auto &[val, i]: g){
                idx.push_back(i);
            }
            sort(idx.begin(), idx.end());
            for(int j=0;j<idx.size();j++){
                nums[idx[j]] = g[j].first;
            }
        }
        return nums;
    }
};