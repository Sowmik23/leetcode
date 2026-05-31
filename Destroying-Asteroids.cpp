1class Solution {
2public:
3    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
4        
5        //busy day so mark as todo: 
6         sort(asteroids.begin(),
7             asteroids.end());  // Sort by mass in ascending order
8        long long mass1 = mass;
9        for (const int asteroid : asteroids) {
10            // Traverse the asteroids in order, attempt to destroy and update
11            // mass or return the result
12            if (mass1 < asteroid) {
13                return false;
14            }
15            mass1 += asteroid;
16        }
17        return true;  // Successfully destroy all asteroids
18    }
19};