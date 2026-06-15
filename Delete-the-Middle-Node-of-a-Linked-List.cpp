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
13    ListNode* deleteMiddle(ListNode* head) {
14        
15        if(head->next==nullptr) return nullptr;
16        ListNode* slow = head;
17        ListNode* fast = head->next->next;
18        
19        while(fast and fast->next){
20            slow = slow->next;
21            fast = fast->next->next;
22        }
23
24        //*slow = *(slow->next);
25        slow->next = slow->next->next;
26        
27        return head;
28    }
29};