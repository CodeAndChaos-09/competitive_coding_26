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
    bool isPalindrome(ListNode* head)
    {
        // first we will find middle of ll and divide it into 2 sub ll
        // then we will reverse the  ll 
        // take slow fast pointer to traverse the ll and slow pointer will return us the middle of ll then slow->next will be the head of second halve and then we will aplly the main logic to reverse the ll.
        // then we will compare both parts and if there is any node which is not equal then it would return false else it will be true(this is to check for palindrome)
           if (head == NULL || head->next == NULL)
            return true;

        // -----------------------------
        // STEP 1: Find the middle node
        // -----------------------------
        ListNode* slow = head;
        ListNode* fast = head;

        // Slow moves 1 step, Fast moves 2 steps.
        // When the loop ends, slow will be at the middle.
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // -----------------------------
        // STEP 2: Reverse the second half
        // -----------------------------
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while (curr != NULL) {

            // Save next node before breaking the link
            ListNode* next = curr->next;

            // Reverse the current node
            curr->next = prev;

            // Move prev and curr forward
            prev = curr;
            curr = next;
        }

        // 'prev' is now the head of the reversed second half
        ListNode* first = head;
        ListNode* second = prev;

        // -----------------------------
        // STEP 3: Compare both halves
        // -----------------------------
        while (second != NULL) {

            // If any value doesn't match,
            // the list is not a palindrome.
            if (first->val != second->val)
                return false;

            // Move both pointers one step
            first = first->next;
            second = second->next;
        }
        // All corresponding values matched.
        return true;
        // again we will reverse the ll to its original form
    }
};