1class Solution {
2    struct TrieNode {
3        int children[26];
4        int bestLen;
5        int bestIdx;
6        
7        TrieNode() {
8            fill(begin(children), end(children), -1);
9            bestLen = 1e9;
10            bestIdx = 1e9;
11        }
12    };
13
14public:
15    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
16        vector<TrieNode> trie;
17        trie.emplace_back();
18        
19        for (int i = 0; i < wordsContainer.size(); i++) {
20            int len = wordsContainer[i].length();
21            int curr = 0;
22            
23            if (len < trie[curr].bestLen || (len == trie[curr].bestLen && i < trie[curr].bestIdx)) {
24                trie[curr].bestLen = len;
25                trie[curr].bestIdx = i;
26            }
27            
28            for (int j = len - 1; j >= 0; j--) {
29                int charIdx = wordsContainer[i][j] - 'a';
30                
31                if (trie[curr].children[charIdx] == -1) {
32                    trie[curr].children[charIdx] = trie.size();
33                    trie.emplace_back();
34                }
35                
36                curr = trie[curr].children[charIdx];
37                
38                if (len < trie[curr].bestLen || (len == trie[curr].bestLen && i < trie[curr].bestIdx)) {
39                    trie[curr].bestLen = len;
40                    trie[curr].bestIdx = i;
41                }
42            }
43        }
44        
45        vector<int> ans;
46        ans.reserve(wordsQuery.size());
47        
48        for (const string& query : wordsQuery) {
49            int curr = 0;
50            int len = query.length();
51            
52            for (int j = len - 1; j >= 0; j--) {
53                int charIdx = query[j] - 'a';
54                if (trie[curr].children[charIdx] == -1) {
55                    break;
56                }
57                curr = trie[curr].children[charIdx];
58            }
59            ans.push_back(trie[curr].bestIdx);
60        }
61        
62        return ans;
63    }
64}; 