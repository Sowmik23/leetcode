/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* curr = head;
        int prev = -1;
        int prevCPoint = -1;
        int firstCPIdx = -1;
        int prevCPIdx = -1;
        int i = 1;
        int mn = INT_MAX;

        while(curr) {
            if(prev==-1) prev = curr->val;
            else {
                if(curr->next){
                    if(curr->val>prev and curr->val>curr->next->val){
                        if(prevCPoint==-1){
                            prevCPoint = curr->val;
                            prevCPIdx = i;
                            firstCPIdx = i;
                        } else {
                            prevCPoint = curr->val;
                            mn = min(mn, i-prevCPIdx);
                            prevCPIdx = i;
                        }
                    }
                    else if(curr->val<prev and curr->val<curr->next->val){
                        if(prevCPoint==-1){
                            prevCPoint = curr->val;
                            prevCPIdx = i;
                            firstCPIdx = i;
                        } else {
                            prevCPoint = curr->val;
                            mn = min(mn, i-prevCPIdx);
                            prevCPIdx = i;
                        }
                    }
                }
            }
            prev = curr->val;
            curr = curr->next;
            i++;
        }
        //cout<<mn<<" "<<prevCPIdx<<" "<<firstCPIdx<<endl;
        if(mn==INT_MAX or prevCPIdx==-1) return {-1, -1};
        return {mn, prevCPIdx-firstCPIdx};
    }
};