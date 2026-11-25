class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {


        //binary search on answer + rooling hash
        const ll MOD = 1e9 + 7;
        const ll BASE = 9e8;

        int n = nums.size();
        vector<ll> h(n+1), p(n+1);
        p[0] = 1;

        for(int i=0;i<n;i++){
            h[i+1] = (h[i]*BASE + nums[i])%MOD;
            p[i+1] = p[i] * BASE %MOD;
        }

        auto check = [&](int len){
            unordered_map<ll, int> cnt;
            for(int l=0;l+len<=n;l++){
                int r = l+len;
                ll key = (h[r]-h[l]*p[len]%MOD + MOD)%MOD;
                cnt[key]++;
            }

            for(auto & [key, times]: cnt){
                if(times==1) return true;
            }
            return false;
        };

        int lo = 1, hi = n;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
private:
    using ll = long long;
};