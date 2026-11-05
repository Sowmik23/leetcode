class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        int n = arr2.size();
        sort(arr2.begin(), arr2.end());
        int res = 0;

        for(auto &num: arr1){
            bool flag = true;
            unsigned idx = std::lower_bound(arr2.begin(), arr2.end(), num)-arr2.begin();
            if(idx<n) flag &= (arr2[idx]-num>d);
            if(idx-1>=0 and idx-1<n) flag &= (num - arr2[idx-1]>d);
            if(flag) res++;
        }
        return res;
    }
};