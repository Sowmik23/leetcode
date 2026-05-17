1class Solution {
2public:
3    bool canReach(vector<int>& arr, int start) {
4        
5        if(start<0 or start>=arr.size() or arr[start]<0) return false;
6        
7        arr[start]*=-1;  //making it visited;
8
9        return arr[start]==0 or canReach(arr, start+arr[start]) or canReach(arr, start-arr[start]);
10    }
11};