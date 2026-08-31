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
        if (!head || !head->next || !head->next->next) return {-1, -1};
        
        int min_dist = INT_MAX;
        int first_cp = -1, prev_cp = -1;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;
        
        while (curr->next) {
            ListNode* nxt = curr->next;
            bool is_max = (curr->val > prev->val && curr->val > nxt->val);
            bool is_min = (curr->val < prev->val && curr->val < nxt->val);
            
            if (is_max || is_min) {
                if (first_cp == -1) {
                    first_cp = idx;
                } else {
                    min_dist = min(min_dist, idx - prev_cp);
                }
                prev_cp = idx;
            }
            prev = curr;
            curr = nxt;
            idx++;
        }
        
        if (first_cp == prev_cp) return {-1, -1};
        return {min_dist, prev_cp - first_cp};
    }
};
