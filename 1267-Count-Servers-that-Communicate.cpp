class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<string, set<pair<int, int>>> mp;
        set<pair<int, int>> st;
        for(int i=0;i<m;i++){
            string row = "row"+to_string(i);
            for(int j=0;j<n;j++){
                string col = "col"+to_string(j);
                if(grid[i][j]==1){
                    mp[row].insert({i,j});
                    mp[col].insert({i,j});
                }
            }
        }

        set<pair<int, int>> st1;
        for(auto& m: mp){
            if(m.second.size()>1){
                for(auto &s: m.second) st1.insert(s);
            }
        }
        return st1.size();
    }
};