class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = target.size();
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;

        // Match target exactly as far as possible, consuming letters from cnt.
        int i = 0;
        for (; i < n; i++) {
            int c = target[i] - 'a';
            if (cnt[c] == 0) break;
            cnt[c]--;
        }

        // Try shrinking the matched prefix, from longest (i) down to 0.
        while (i >= 0) {
            if (i < n) {
                int target_char = target[i] - 'a';
                int next = -1;
                for (int x = target_char + 1; x < 26; x++) {
                    if (cnt[x] > 0) { 
                        next = x; 
                        break; 
                    }
                }
                if (next != -1) {
                    cnt[next]--;
                    string res = target.substr(0, i) + char('a' + next);
                    for (int x = 0; x < 26; x++)
                        res += string(cnt[x], 'a' + x);
                    return res;
                }
            }
            // This position didn't work (or i==n, full match isn't "greater").
            // Back off: un-consume the char target used at the new position.
            i--;
            if (i >= 0) cnt[target[i] - 'a']++;
        }

        return "";
    }
};