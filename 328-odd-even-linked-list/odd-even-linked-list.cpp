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
    ListNode* oddEvenList(ListNode* head)
    {
      if(head == NULL || head->next == NULL)
            return head;

        // First odd node
        ListNode* odd = head;

        // First even node
        ListNode* even = head->next;

        ListNode* evenHead = even;

        // Continue while another odd node exists
        while(even && even->next){

            // Link current odd node to the next odd node
            odd->next = even->next;

            // Move odd pointer forward
            odd = odd->next;

            // Link current even node to the next even node
            even->next = odd->next;

            // Move even pointer forward
            even = even->next;
        }

        // Attach even list after odd list
        odd->next = evenHead;

        return head;
    }
};