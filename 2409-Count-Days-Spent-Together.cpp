class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        //Nice explanation
        //https://leetcode.com/problems/count-days-spent-together/?envType=daily-question&envId=2026-10-24
        
        return max(0, min(f(leaveAlice), f(leaveBob)) - max(f(arriveAlice), f(arriveBob)) + 1);
    }
private:
    int f(auto& s) {
        int m = (s[0] - '0') * 10 + (s[1] - '0');
        int q = (s[3] - '0') * 10 + (s[4] - '0');

        return (275 * m) / 9 - 2 * ((m + 9) / 12) + q - 30;
    }
};