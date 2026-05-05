1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* rotateRight(ListNode* head, int k) {
14        
15        if(!head) return head;
16        
17        
18        ListNode res = NULL;
19        ListNode* tmp = &res;
20        
21        int cnt = 0;
22        ListNode* curr = head;
23        
24        while(curr!=NULL){
25            curr = curr->next;
26            cnt++;
27        }
28        
29        k = k%cnt;
30        
31        if(k==0) return head;
32        
33        curr = head;
34        curr = reverse(curr);
35        
36        while(k and curr){
37           // cout<<curr->val<<" ";
38            tmp->next = curr;
39            if(k==1){
40                head = curr->next;
41            }
42            tmp = tmp->next;
43            curr = curr->next;
44            k--;
45        }
46        tmp->next = NULL;
47        
48        ListNode* it = res.next;
49        
50        it = reverse(it);
51        
52        ListNode ans = NULL;
53        tmp = &ans;
54        
55        while(it!=NULL){
56            tmp->next = it;
57            it = it->next;
58            tmp = tmp->next;
59        }
60        
61        
62        head = reverse(head);
63        tmp->next = head;
64        
65        return ans.next;
66    }
67private:
68    ListNode* reverse(ListNode* head){
69        
70        ListNode* curr = head;
71        ListNode* prev = NULL;
72        ListNode* tmp;
73        
74        while(curr!=NULL){
75            tmp = curr->next;
76            curr->next = prev;
77            prev = curr;
78            
79            curr = tmp;
80        }
81        
82        return prev;
83    }
84};