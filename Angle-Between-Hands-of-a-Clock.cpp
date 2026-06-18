1class Solution {
2public:
3    double angleClock(int hour, int minutes) {
4        
5        double minuteAngle = 6.0 * minutes;
6        double hourAngle = 30.0 * (hour % 12) + 0.5 * minutes;
7
8        double diff = abs(hourAngle - minuteAngle);
9
10        return min(diff, 360.0 - diff);
11    }
12};