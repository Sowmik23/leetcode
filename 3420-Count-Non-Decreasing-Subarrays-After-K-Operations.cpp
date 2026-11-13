class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        
        //segment tree / monotonic stack / sliding window
        int n = nums.size();
        long long ans = 0;
        long long op = 0;
        priority_queue<pair<int, int>> pq;
        vector<vector<int>> cnt(n);
        vector<int> pos(n,n);
        stack<int> stk;

        for(int left =0,right=0;right<n;right++){
            while(!stk.empty() and nums[right]>=nums[stk.top()]){
                pos[stk.top()] = right;
                stk.pop();
            }
            if(!stk.empty()) cnt[stk.top()].push_back(right);
            stk.push(right);
            pq.emplace(nums[right], right);
            op+=max(0, pq.top().first - nums[right]);

            while(op>k){
                for(int i: cnt[left]){
                    op-=(long long) (nums[left]-nums[i])*(min(pos[i], right+1)-i);
                }
                left++;
            }

            while(!pq.empty() and pq.top().second<left) pq.pop();
            ans+=right-left+1;
        }
        return ans;
    }
};