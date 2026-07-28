class Solution {
public:
    string smallestPalindrome(string s) {
        
        //sorting.... O(nlogn)

        /*
        int len = s.length();
        int partition = len / 2;

        sort(s.begin(), s.begin() + partition);

        for (int i = 0; i < partition; ++i) {
            s[len - 1 - i] = s[i];
        }

        return s;
        */

        //counting sort O(n)
        int n = s.length();
        int bucket[26] = {0};

        for (int i = 0; i < n / 2; i++) {
            bucket[s[i] - 'a']++;
        }

        int left = 0;
        int right = n - 1;

        for (int i = 0; i < 26; i++) {
            while (bucket[i] > 0) {
                char c = i + 'a';
                s[left++] = c;
                s[right--] = c;
                bucket[i]--;
            }
        }

        return s;
    }
};