class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n/2;

        int leftSum = 0, left = 0, rightSum = 0, right = 0;

        //first half
        for(int i=0;i<half;i++){
            if(num[i]=='?') left++;
            else leftSum+=num[i]-'0';
        }

        //second half
        for(int i=half;i<n;i++){
            if(num[i]=='?') right++;
            else rightSum+=num[i]-'0';
        }

        // if(left==right) return false; // that means equal sum

        //bob wins if the diff is not balanced/equal
        // return 2*abs(diff)!= 9*abs(left-right);

        return ( (left + right)%2==1) or (leftSum-rightSum != (right-left)*9/2);
    }
};