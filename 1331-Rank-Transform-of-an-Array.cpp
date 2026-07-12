class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        //approach-01: sorting: O(nlogn)
        //approach-02: map: O(n)+O(n)

        map<int, vector<int>> mp;
        for(int i=0;i<arr.size();i++) mp[arr[i]].push_back(i);

        vector<int> res(arr.size(), 0);
        int cnt = 1;
        for(auto& m: mp){
            for(auto& idx: m.second){
                res[idx] = cnt;
            }
            cnt++;
        }
        return res;
    }
};