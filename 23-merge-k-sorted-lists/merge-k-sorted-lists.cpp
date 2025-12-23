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
private:
    struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; 
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;

        for(auto list: lists){
            if(list != nullptr){
                pq.push(list);
            }
        }

        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while(pq.size() > 0){
            ListNode* curr = pq.top();
            pq.pop();
            tail = tail->next = curr;

            if(curr->next != nullptr){
                pq.push(curr->next);
            }
        }
        return dummy.next;
    }
};