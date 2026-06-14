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
13    int pairSum(ListNode* head) {
14        
15        ListNode* slow = head;
16        ListNode* fast = head;
17        ListNode* curr = head;
18
19        while(fast and fast->next){
20            curr = slow;
21            slow = slow->next;
22            fast = fast->next->next;
23        }
24        curr->next = NULL;
25
26        ListNode* half = reverse(slow);
27
28        int mx = 0;
29        while(head and half){
30            mx = max(mx, head->val+half->val);
31            head = head->next;
32            half = half->next;
33        }
34        return mx;
35    }
36private:
37    ListNode* reverse(ListNode* slowNode){
38
39        ListNode* prev = NULL;
40        ListNode* curr = slowNode;
41        
42        while(curr){
43            ListNode* tmp = curr->next;
44            curr->next = prev;
45            prev = curr;
46            curr = tmp;
47        }
48        return prev;
49    }
50};