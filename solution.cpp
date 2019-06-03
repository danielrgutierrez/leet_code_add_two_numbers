/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tempRoot = new ListNode(0);
        ListNode* ptr = tempRoot;
        unsigned int carry = 0;
        while (l1 || l2) {
            unsigned int digit = 0;
            if (l1) {
                digit += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                digit += l2->val;
                l2 = l2->next;
            }
            if (carry) {
                digit += carry;
                carry = 0;
            }
            if (digit >= 10) {
                carry = digit / 10;
                digit %= 10;
            }
            ptr->next = new ListNode(digit);
            ptr = ptr->next;
        }
        if (carry) {
            ptr->next = new ListNode(carry);
            ptr = ptr->next;
        }
        ptr = tempRoot->next;
        delete tempRoot;
        return ptr;
    }
};
