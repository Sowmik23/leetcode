class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        
        if (sum > 9 * num) {
            return "";
        }
        int r = sum % 9;

        //breaking sum to make ths res digits sum
        string ans(sum / 9, '9');
        if (r > 0) {
            ans.push_back('0' + r);
        }

        //appending 0 with remaining empty positions
        ans.append(num - (int)ans.size(), '0');
        return ans;
    }
};