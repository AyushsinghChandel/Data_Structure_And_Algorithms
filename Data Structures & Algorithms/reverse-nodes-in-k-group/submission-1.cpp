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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while(count != k && curr != nullptr){
            curr = curr->next;
            count++;
        }
        if (count != k) {
            return head;
        }
        ListNode* prev = nullptr;
        ListNode* reverseCurr = head; 
        for (int i = 0; i < k; i++) {
            ListNode* nextNode = reverseCurr->next;
            reverseCurr->next = prev;
            prev = reverseCurr;
            reverseCurr = nextNode;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
