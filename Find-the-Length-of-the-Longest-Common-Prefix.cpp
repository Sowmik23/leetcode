1class Solution {
2public:
3    class Trie {
4        public:
5            Trie *digits[10];
6
7            void add(Trie *head, int n){
8                string str = to_string(n);
9                Trie *tmp = head;
10                for(auto &ch: str){
11                    if(!tmp->digits[ch-'0']) tmp->digits[ch-'0'] = new Trie();
12                    tmp = tmp->digits[ch-'0'];
13                }
14            }
15            int getPrefixLen(Trie *head, int n){
16                Trie *tmp = head;
17                string str = to_string(n);
18                int len = 0;
19                for(auto &ch: str){
20                    if(tmp->digits[ch-'0']) len++;
21                    else break;
22                    tmp = tmp->digits[ch-'0'];
23                }
24                return len;
25            }
26    };
27    
28    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
29        
30        //using trie
31        //Time: O(n)
32
33        Trie *trie = new Trie();
34        int res = 0;
35
36        for(auto &num: arr1) trie->add(trie, num);
37        for(auto &num: arr2){
38            res = max(res, trie->getPrefixLen(trie, num));
39        }
40        return res;
41    }
42};