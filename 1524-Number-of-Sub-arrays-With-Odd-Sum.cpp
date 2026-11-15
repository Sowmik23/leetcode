class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
        //creative answer
        const int MOD = 1e9 + 7;
        int res = 0, sum = 0;
        int oddCnt = 0, evenCnt = 1; //as initial sum is even
        for(auto& num: arr){
            sum+=num;
            if(sum%2==0){
                evenCnt++;
                res+=(oddCnt);
            }else {
                oddCnt++;
                res+=(evenCnt);
            }
            res%=MOD;
        }
        return res;
    }
};