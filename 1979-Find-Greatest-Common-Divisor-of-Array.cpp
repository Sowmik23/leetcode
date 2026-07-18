class Solution {
public:
    int findGCD(vector<int>& nums) {
        
        int smallest=INT_MAX, largest = INT_MIN;
        for (auto& num: nums){
            smallest = min(num, smallest);
            largest = max(num, largest);
        }
        return _gcd(smallest, largest);
        }
private:
    int _gcd(int x, int y){
      if(x==0) return y;
        return _gcd(y%x, x);
    }
};