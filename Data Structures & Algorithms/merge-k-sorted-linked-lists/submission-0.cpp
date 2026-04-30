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
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r){
            return l->val > r->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<ListNode* , vector<ListNode*>, compare> minHeap;

        for(ListNode* listHead : lists){
            if(listHead != nullptr){
                minHeap.push(listHead);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(!minHeap.empty()){
            ListNode* smallestNode = minHeap.top();
            minHeap.pop();
            tail->next = smallestNode;
            tail = tail->next;
            if(smallestNode->next != nullptr){
                minHeap.push(smallestNode->next);
            }
        }

        return dummy.next;
    }
};
